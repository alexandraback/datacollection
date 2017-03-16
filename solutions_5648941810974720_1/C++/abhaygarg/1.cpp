#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define all(v) v.begin(),v.end()
#define inf 1000000000
string num[]= {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int c[30],req[20][30]= {{0}};
int main()
{
    freopen("1.in","r",stdin);
    freopen("1-out.txt","w",stdout);
    int t,cs=1;
    for(int i=0; i<=9; i++)
    {
        for(int j=0; j<num[i].size(); j++)
            req[i][num[i][j]-'A']++;
    }
    vector<int>v[4];
    v[0].pb(0);
    v[0].pb(2);
    v[0].pb(4);
    v[0].pb(6);
    v[0].pb(8);
    v[1].pb(1);
    v[1].pb(3);
    v[1].pb(7);
    v[2].pb(5);
    v[2].pb(9);
    scanf("%d",&t);
    while(t--)
    {
        int i,j,k,n,l;
        string ans="";
        string s;
        cin>>s;
        for(i=0; i<26; i++)
            c[i]=0;
        n=s.size();
        for(i=0; i<n; i++)
            c[s[i]-'A']++;
        for(i=0; i<3; i++)
        {
            for(j=0; j<v[i].size(); j++)
            {
                int mn=1000000,ind=v[i][j];
                for(k=0; k<26; k++)
                {
                    if(req[ind][k]==0)
                        continue;
                    mn=min(mn,c[k]/req[ind][k]);
                }
                for(k=0; k<mn; k++)
                {
                    char ch='0'+v[i][j];
                    ans+=ch;
                    for(l=0;l<26;l++)
                        c[l]-=req[ind][l];
                }
            }
        }
        sort(ans.begin(),ans.end());
        printf("Case #%d: ",cs);
        cout<<ans<<endl;
        cs++;
    }
    return 0;
}
