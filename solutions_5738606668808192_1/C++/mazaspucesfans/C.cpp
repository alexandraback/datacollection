#include <bits/stdc++.h>
using namespace std;

string get_str(int N, int val)
{
    string result;
    result.resize(N);
    for(int i=0; i<N; i++) result[i]='0';
    result[0]=result[N-1]='1';

    for(int i=1; val!=0; i++)
    {
        result[i]=result[N-1-i]='0'+val%2;
        val/=2;
    }
    return result;
}

void solve(int N, int J)
{
    assert(N%2==0);
    assert(1LL<<((N-2)/2) >= J);



    for(int i=0; i<J; i++)
    {
        cout << get_str(N, i) << ' ';

        //
        for(int base=2; base<=10; base++) cout << base+1 << ' ';
        cout << '\n';
    }

}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        int N, J;
        cin >> N >> J;
        cout << "Case #" << t << ": " << endl;
        solve(N, J);
    }
    return 0;
}
