#include<iostream>
#include<string>

using namespace std;

string unsigned_multi(const char& a, const char& b)
{
    if(a == '1')
        return "+" + string(1, b);
    else if(b == '1')
       return "+" + string(1, a);
    else if(a == b)
       return "-1";
    else if(a == 'i') {
        if(b == 'j')
            return "+k";
        else
            return "-j";
    } else if(a == 'j') {
        if(b == 'i')
            return "-k";
        else
            return "+i";
    } else {
        if(b == 'i')
            return "+j";
        else
            return "-i";
    }
}

string multi(const string& a, const string& b)
{
    string ret = unsigned_multi(a[1], b[1]);
    if(a[0] != b[0] && ret[0] == '-')
        ret[0] = '+';
    else if(a[0] != b[0] && ret[0] == '+')
        ret[0] = '-';
    return ret;
}

bool solvable(long long L, long long X, string s)
{
    X = min(X, 8 + (X-8)%4);
    string S = "";
    for(int i = 0; i < X; ++i)
        S += s;

    string begin = "+1";
    int b_it = 0;
    while(begin != "+i") {
        if(b_it >= S.size())
            return false;

        begin = multi(begin, "+" + string(1, S[b_it]));
        ++b_it;
    }

    string end = "+1";
    int e_it = S.size()-1;
    while(end != "+k") {
        if(e_it < 0)
            return false;

        end = multi("+" + string(1, S[e_it]), end);
        --e_it;
    }

    if(b_it > e_it)
        return false;

    string mid = "+1";
    for(int i = b_it; i <= e_it; ++i)
        mid = multi(mid, "+" + string(1, S[i]));

    return mid == "+j";
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        long long L, X;
        string s;
        cin >> L >> X >> s;
        cout << "Case #" << t << ": " << (solvable(L, X, s) ? "YES" : "NO") << endl;
    }

    return 0;
}
