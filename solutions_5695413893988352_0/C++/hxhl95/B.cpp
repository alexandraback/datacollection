#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

long long toint(string s)
{
    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
        res += s[i];
        if (i != s.size()-1) res *= 10;
    }
    return res;
}

void update(string Cs, string Js, string& Cres, string& Jres, long long& res)
{
    long long newres = abs(toint(Cs) - toint(Js));
    if (newres < res ||
        (newres == res && toint(Cs) < toint(Cres) ||
         (toint(Cs) == toint(Cres) &&
          toint(Js) < toint(Jres)))) {
        Cres = Cs;
        Jres = Js;
        res = newres;
    }
}

void test(char Cnew, char Jnew,
          string Clarge, string Jlarge,
          string Csmall, string Jsmall,
          string Cclose, string Jclose,
          string& Cres, string& Jres)
{
    if (Cnew > '9' || Cnew < '0' || Jnew > '9' || Jnew < '0') return;
    long long res = abs(toint(Cres) - toint(Jres));
    if (Cres.size() == 0) res = (1ll << 62);
    if (abs(toint(Cnew + Clarge) - toint(Jnew + Jsmall)) <= res)
        update(Cnew + Clarge, Jnew + Jsmall, Cres, Jres, res);
    if (abs(toint(Cnew + Csmall) - toint(Jnew + Jlarge)) <= res)
        update(Cnew + Csmall, Jnew + Jlarge, Cres, Jres, res);
    if (abs(toint(Cnew + Csmall) - toint(Jnew + Jsmall)) <= res)
        update(Cnew + Csmall, Jnew + Jsmall, Cres, Jres, res);
    if (abs(toint(Cnew + Cclose) - toint(Jnew + Jclose)) <= res)
        update(Cnew + Cclose, Jnew + Jclose, Cres, Jres, res);
}

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        string C, J;
        cin >> C >> J;

        string Clarge, Jlarge, Csmall, Jsmall, Cclose, Jclose;
        for (int i = C.size()-1; i >= 0; i--) {
            if (C[i] == '?' && J[i] == '?') {
                string Cres, Jres;
                test('0', '0', Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                test('0', '1', Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                test('1', '0', Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                Cclose = Cres;
                Jclose = Jres;
                
                Clarge = '9' + Clarge;
                Jlarge = '9' + Jlarge;
                Csmall = '0' + Csmall;
                Jsmall = '0' + Jsmall;
            }
            else if (C[i] == '?') {
                string Cres, Jres;
                test(J[i], J[i], Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                test(J[i]+1, J[i], Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                test(J[i]-1, J[i], Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                Cclose = Cres;
                Jclose = Jres;

                Clarge = '9' + Clarge;
                Jlarge = J[i] + Jlarge;
                Csmall = '0' + Csmall;
                Jsmall = J[i] + Jsmall;
            }
            else if (J[i] == '?') {
                string Cres, Jres;
                test(C[i], C[i], Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                test(C[i], C[i]+1, Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                test(C[i], C[i]-1, Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                Cclose = Cres;
                Jclose = Jres;

                Clarge = C[i] + Clarge;
                Jlarge = '9' + Jlarge;
                Csmall = C[i] + Csmall;
                Jsmall = '0' + Jsmall;
            }
            else {
                string Cres, Jres;
                test(C[i], J[i], Clarge, Jlarge, Csmall, Jsmall,
                     Cclose, Jclose, Cres, Jres);
                Cclose = Cres;
                Jclose = Jres;
                
                Clarge = C[i] + Clarge;
                Jlarge = J[i] + Jlarge;
                Csmall = C[i] + Csmall;
                Jsmall = J[i] + Jsmall;
            }
        }
        
        cout << "Case #" << c << ": " << Cclose << " " << Jclose << endl;
    }
    return 0;
}
