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
vector<string>v,v1,v2;
int func(string s)
{
    int i,num=0,n=s.size();
    for(i=0;i<n;i++)
        num=(num*10)+s[i]-'0';
    return num;
}
int main()
{
    freopen("2.in","r",stdin);
    freopen("2-out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,k,n;
        string s1,s2;
        cin>>s1>>s2;
        n=s1.size();
        //cout<<n<<" "<<s1<<" "<<s2<<endl;
        v1.clear();
        v2.clear();
        for(i=0; i<n; i++)
        {
            if(s1[i]=='?')
            {
                if(v1.size()==0)
                {
                    for(j=0; j<=9; j++)
                    {
                        string s="";
                        char ch='0'+j;
                        s+=ch;
                        v1.pb(s);
                    }
                    continue;
                }
                v.clear();
                for(j=0; j<v1.size(); j++)
                {
                    for(k=0; k<=9; k++)
                    {
                        string h=v1[j];
                        char ch='0'+k;
                        h+=ch;
                        v.pb(h);
                    }
                }
                v1.clear();
                for(j=0;j<v.size();j++)
                    v1.pb(v[j]);
            }
            else
            {
                if(v1.size()==0)
                {
                    string s="";
                    s+=s1[i];
                    v1.pb(s);
                }
                else
                {
                    for(j=0; j<v1.size(); j++)
                        v1[j]+=s1[i];
                }
            }
        }
        for(i=0; i<n; i++)
        {
            if(s2[i]=='?')
            {
                if(v2.size()==0)
                {
                    for(j=0; j<=9; j++)
                    {
                        string s="";
                        char ch='0'+j;
                        s+=ch;
                        v2.pb(s);
                    }
                    continue;
                }
                v.clear();
                for(j=0; j<v2.size(); j++)
                {
                    for(k=0; k<=9; k++)
                    {
                        string h=v2[j];
                        char ch='0'+k;
                        h+=ch;
                        v.pb(h);
                    }
                }
                v2.clear();
                for(j=0;j<v.size();j++)
                    v2.pb(v[j]);
            }
            else
            {
                if(v2.size()==0)
                {
                    string s="";
                    s+=s2[i];
                    v2.pb(s);
                }
                else
                {
                    for(j=0; j<v2.size(); j++)
                        v2[j]+=s2[i];
                }
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int ans=1000000000,loc1=-1,loc2=-1;
        for(i=0;i<v1.size();i++)
        {
            for(j=0;j<v2.size();j++)
            {
                int n1=func(v1[i]);
                int n2=func(v2[j]);
                if(abs(n2-n1)<ans)
                {
                    ans=abs(n1-n2);
                    loc1=i;
                    loc2=j;
                }
            }
        }
        printf("Case #%d: ",cs);
        cout<<v1[loc1]<<" "<<v2[loc2]<<endl;
        cs++;
    }
    return 0;
}

