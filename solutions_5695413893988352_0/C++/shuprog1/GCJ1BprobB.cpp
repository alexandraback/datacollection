#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll findDiff(string C, string J, int N)
{
    ll c,j;
    c = j = 0LL;
    for(int i = 0; i < N; i++)
    {
        c += (ll)((C[i] - '0')*pow(10,N-i));
        j += (ll)((J[i] - '0')*pow(10,N-i));
    }
    return abs(c - j);
}
void solve(string C, string J, int N, int ind, string& ansC, string& ansJ, ll& minSoFar)
{
    //printf("ind : %d\n",ind);
    //cout << "C : " << C << " J : " << J << "\n";

    if(ind == N)
    {
        ll diff = findDiff(C,J,N);
        //cout << "diff : " << diff << "\n";
        if(diff < minSoFar)
        {
            minSoFar = diff;
            ansC.assign(C);
            ansJ.assign(J);
            //cout << "C : " << C << " J : " << J << "\n";
            //cout << "ansC : " << ansC << " ansJ : " << ansJ << "\n";
        }
        else if(diff == minSoFar)
        {
            if(C < ansC)
            {
                ansC.assign(C);
                ansJ.assign(J);
            }
            else if(C == ansC)
            {
                if(J < ansJ)
                {
                    ansC.assign(C);
                    ansJ.assign(J);
                }
            }
        }
    }
    else
    {
        if(C[ind] == '?' && J[ind] == '?')
        {
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    C[ind] = i + '0';
                    J[ind] = j + '0';
                    solve(C,J,N,ind+1,ansC,ansJ,minSoFar);
                }
            }
        }
        else if(C[ind] == '?')
        {
            for(int i = 0; i < 10; i++)
            {
                C[ind] = '0' + i;
                solve(C,J,N,ind+1,ansC,ansJ,minSoFar);
            }
        }
        else if(J[ind] == '?')
        {
            for(int i = 0; i < 10; i++)
            {
                J[ind] = '0' + i;
                solve(C,J,N,ind+1,ansC,ansJ,minSoFar);
            }
        }
        else
            solve(C,J,N,ind+1,ansC,ansJ,minSoFar);
    }
}
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int T; string C,J;
    scanf("%d",&T);
    for(int t = 1; t <= T; t++)
    {
        cerr << "Case # " << t << "\n";
        cin >> C >> J;
        string ansC,ansJ;
        int N = C.length();
        ll minSoFar = LONG_LONG_MAX;
        printf("Case #%d: ",t);
        solve(C,J,N,0,ansC,ansJ,minSoFar);
        cout << ansC << " " << ansJ << "\n";
    }
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}


