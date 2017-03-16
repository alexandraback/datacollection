#include <bits/stdc++.h>

using namespace std;
int ap[30],N;
struct numb{
    string s;
}val[11];
string rez;

string Solve()
{
    sort(rez.begin(),rez.end());
    return rez;
}

void Read()
{
    string s;
    cin >> s;
    N = s.length();
    for(auto it : s)
    {
        char c = it;
        ap[it-'A'] ++;
    }
}

void Init()
{
    val[0].s = "ZERO";
    val[1].s = "ONE";
    val[2].s = "TWO";
    val[3].s = "THREE";
    val[4].s = "FOUR";
    val[5].s = "FIVE";
    val[6].s = "SIX";
    val[7].s = "SEVEN";
    val[8].s = "EIGHT";
    val[9].s = "NINE";
}
int ok = 0,gata;
void Backt(int k)
{
    if(gata == 1)
        return;
    if(k == 0)
    {
        gata = 1;
        return;
    }

    for(int i = 0; i <= 9; ++i)
    {
        ok = 1;
        for(auto it : val[i].s)
        {
            ap[it-'A'] --;
            if(ap[it-'A'] < 0)
                ok = 0;
        }
        if(ok){

            rez.push_back(i+'0');
            Backt(k - (int)val[i].s.length());
            if(gata == 1)
                return;
            rez.pop_back();
        }
        for(auto it : val[i].s)
            ap[it-'A'] ++;
    }
}

int main()
{
    freopen("pbA.in","r",stdin);
    freopen("pbA.out","w",stdout);
    int T;
    cin >> T;
    Init();
    for(int test = 1; test <= T; ++ test)
    {
        gata = 0;
        Read();
        Backt(N);
        cout << "Case #" <<test<< ": " << Solve() << "\n";
        rez = "";

    }
    return 0;
}
