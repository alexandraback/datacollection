// User :: lovelotus ( Prem Kamal )

//#include<bits/stdc++.h>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<cctype>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<deque>

#define lli long long int
#define ulli unsigned long long int
#define F first
#define S second
#define pii pair<int,int>
#define pip pair<int,pii>
#define pis pair<int,string>
#define pll pair<lli,lli>

using namespace std;

string s1,s2;

double maxm,tot,poss;
int k,l,n;

int chk( string s )
{
    //cout<<s<<endl;
    int cnt=0,j,i;
    for(i=0;i<n-l+1;i++)
    {
        for(j=0;j<l;j++)
        {
            if(s2[j]!=s[i+j]) break;
        }
        if(j==l) cnt++;
    }
    tot+=cnt;
    if(cnt>maxm) maxm=cnt;
}


void rec( int pos, string s)
{
    //cout<<pos<<" "<<n<<" : "<<s<<endl;
    if(pos==n)
    {
        chk(s);
        poss++;
        return;
    }
    for(int i=0;i<k;i++)
    {
        rec(pos+1,s+s1[i]);
    }
}

int hsh[26];

int main()
{
    freopen("C:\\Users\\lovelotus\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\lovelotus\\Desktop\\output.txt","w",stdout);
    int t,tst=1,err=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&k,&l,&n);
        cin>>s1>>s2;
        maxm=0.0;
        tot=0.0;
        poss=0.0;
        err=0;
        for(int i=0;i<26;i++) hsh[i]=0;
        for(int i=0;i<k;i++) hsh[s1[i]-65]=1;
        for(int i=0;i<l;i++)
        {
            //printf("%d %d\n",s2[i],hsh[s2[i]-65]);
            if(!hsh[s2[i]-65])
            {
                err=1;
                break;
            }
        }
        if(err) printf("Case #%d: 0.000000\n",tst);
        else
        {
            string s="";
            rec(0,s);
            //printf("%lf %lf %lf\n",maxm,tot,poss);
            printf("Case #%d: %.6lf\n",tst,maxm-tot/poss);
        }
        tst++;
    }
    return 0;
}
