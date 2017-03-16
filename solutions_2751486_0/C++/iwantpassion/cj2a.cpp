#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
#define vi             vector<int>
#define vvi            vector<vector<int> >
#define gcd            ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
#define INF            2147483647
#define LIMIT          1000
#define mod            1000000007
#define pi             pair<int,int>
#define mp             make_pair
#define pb(v)          v.push_back
#define sz(x)          x.size()

using namespace std;
 int main()
 {
    int test_cases,iter=1,n_link,n,c;
    string s;
    freopen("in.in","r",stdin);
    freopen("d.out","w",stdout);
    cin>>test_cases;
    for(int iter=1;iter<=test_cases;iter++)
    {
        n_link=0;
        cin>>s;
        cin>>n;
        for(int i=0;i<s.length();i++)
            for(int j=i+n;j<=s.length();j++)
            {
                c=0;
                for(int k=i;k<j;k++){
                  
                    if(s[k]=='a' || s[k]=='e' || s[k]=='i'|| s[k]=='o' || s[k]=='u')
                        c=0;
                    else
                        c++;
                    if(c>=n)
                    {
                        n_link++;
                        break;
                    }
                }
               
            }
 
        printf("Case #%d: %d\n",iter,n_link);
    }
}
 
