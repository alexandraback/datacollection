#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <functional>
using namespace std;


char a[100];
int K,L,S;
string s;
string tmp;
int sum = 0;
int maxn = 0;

void cal()
{
    int t = 0;
    for (int i = 0; i <=S-L; i++){
        int flag = 2;
        for (int j = 0; j < L; j++){
            if (tmp[i+j] != s[j]) 
            {
                flag = 0;
                break;
            }

        }
        if (flag){
            t++;
            sum++;
        }
    }
   maxn = max(t,maxn); 
}

void dfs(int k){
    if (k == S)
    {
        cal();
        return;
    }else
    {
        for (int i = 0; i < K; i++){
            tmp[k] = a[i];
            dfs(k+1);
        }
    }
}

void solve()
{
    cin>>K>>L>>S;
    maxn = 0;
    sum  = 0;
    for (int i = 0; i< K; i++)
        cin >> a[i];
    cin >> s;
    tmp = s;
    dfs(0); 
    double tot = 1;
    for (int i = 1; i <= S; i++){
        tot = tot * K;
    }
    printf("%.9lf\n",maxn - sum/tot);
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cout << "Case #"<<i<<": ";
        solve();
    }
    return 0;
}
