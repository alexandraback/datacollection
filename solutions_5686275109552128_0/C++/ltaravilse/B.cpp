#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<sstream>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define all(v)v.begin(),v.end()

bool solvable2(vector<int> vec, int n, int a)
{
    int b = n-a,c=0;
    for(int i=0;i<vec.size();i++)
    {
        while(vec[i]>a)
        {
            vec[i]-=a;
            c++;
        }
    }
    return c<=b;
}

bool solvable(vector<int> vec, int n)
{
    for(int i=1;i<=1000;i++)
    {
        if(solvable2(vec,n,i))
            return true;
    }
    return false;
}

int main()
{
    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int casos;
    cin >> casos;
    for(int casito = 1; casito <= casos; casito++)
    {
        int t;
        cin >> t;
        vector<int> vec(t);
        forn(i,t)
            cin >> vec[i];
        sort(all(vec));
        reverse(all(vec));
        int mx = 1000,mn = 0;
        while(mx-mn > 1){
            int n = (mx+mn)/2;
            if(solvable(vec,n))
                mx = n;
            else
                mn = n;
        }
        printf("Case #%d: %d\n",casito,mx);
    }
}
