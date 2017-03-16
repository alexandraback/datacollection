/*********************
****SHASHANK GUPTA****
***@(my_blue_luck)****
**********************/

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int ll;

//#define gc getchar_unlocked
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

/*void scanint(long long int &x)
{
    register long long int c = gc();
    x = 0;
    long long int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}*/

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int t,i,j,k,k1,k2,l1,l2,l,mn,m;
    cin >> t ;
    for(i=1;i<=t;i++)
    {
        vector<int> v1;
        vector<int> v2;
        v1.clear();
        v2.clear();
         char s1[20],s2[20];
        cin >> s1 >> s2;
        l=strlen(s1);
        cout << "Case #" << i << ":" << " " ;
        if(l==1)
        {
            if(s1[0]==s2[0] && s1[0]=='?')
                cout << "0 0\n";
            else
            {
                if(s1[0]!='?')
                    cout << s1[0] << " " << s1[0] << endl ;
                else
                    cout << s2[0] << " " << s2[0] << endl ;
            }
        }
        else if(l==2)
        {
            if(s1[0]!='?' && s1[1]!='?')
            {
                k1=s1[0]-'0';
                k2=s1[1]-'0';
                v1.pb(k1*10+k2);
            }
            else if(s1[0]=='?' && s1[1]=='?')
            {
                for(j=0;j<=99;j++)
                    v1.pb(j);
            }
            else
            {
                if(s1[0]=='?')
                {
                    k=(s1[1]-'0');
                    for(j=0;j<=9;j++)
                        v1.pb(j*10+k);
                }
                else
                {
                    k=(s1[0]-'0');
                    for(j=0;j<=9;j++)
                        v1.pb(k*10+j);
                }
            }
            if(s2[0]!='?' && s2[1]!='?')
            {

                k1=s2[0]-'0';
                k2=s2[1]-'0';
                v2.pb(k1*10+k2);
            }
            else if(s2[0]=='?' && s2[1]=='?')
            {
                for(j=0;j<=99;j++)
                    v2.pb(j);
            }
            else
            {
                if(s2[0]=='?')
                {
                    k=(s2[1]-'0');
                    for(j=0;j<=9;j++)
                        v2.pb(j*10+k);
                }
                else
                {
                    k=(s2[0]-'0');
                    for(j=0;j<=9;j++)
                        v2.pb(k*10+j);
                }
            }
            l1=v1.size();
            l2=v2.size();
            mn=10000;
            pair<int,int> pr;
            for(j=0;j<l1;j++)
            {
                for(m=0;m<l2;m++)
                {
                    if(abs(v1[j]-v2[m])<mn)
                    {
                        mn=abs(v1[j]-v2[m]);
                        pr.first=v1[j];
                        pr.second=v2[m];
                    }
                    else if(abs(v1[j]-v2[m])==mn)
                    {
                        if(v1[j]<pr.first)
                            pr.first=v1[j];
                        if(pr.first==v1[j] && v2[m]<pr.second)
                            pr.second=v2[m];
                    }
                }
            }
            k1=pr.first;
            if(k1==0)
                k1=1;
            k2=0;
            while(k1)
            {
                k1=k1/10;
                k2++;
            }
            if(k2==l)
            cout << pr.first << " " ;
            else
            {
                k2=l-k2;
                while(k2)
                {
                    cout << "0";
                    k2--;
                }
                cout << pr.first << " ";
            }
            k1=pr.second;
            if(k1==0)
                k1=1;
            k2=0;
            while(k1)
            {
                k1=k1/10;
                k2++;
            }
            if(k2==l)
            cout << pr.second << endl ;
            else
            {
                k2=l-k2;
                while(k2)
                {
                    cout << "0";
                    k2--;
                }
                cout << pr.second << endl;
            }
        }
        else if(l==3)
        {
            if(s1[0]!='?' && s1[1]!='?' && s1[2]!='?')
            {
                k1=s1[0]-'0';
                k2=s1[1]-'0';
                k=s1[2]-'0';
                v1.pb((k1*10+k2)*10+k);
            }
            else if(s1[0]=='?' && s1[1]=='?' && s1[2]=='?')
            {
                for(j=0;j<=999;j++)
                    v1.pb(j);
            }
            else if(s1[0]=='?' && s1[1]=='?')
            {
                k=(s1[2]-'0');
                for(j=0;j<=9;j++)
                {
                    for(m=0;m<=9;m++)
                    {
                        v1.pb((j*10+m)*10+k);
                    }
                }
            }
            else if(s1[0]=='?' && s1[2]=='?')
            {
                k=(s1[1]-'0');
                for(j=0;j<=9;j++)
                {
                    for(m=0;m<=9;m++)
                    {
                        v1.pb((j*10+k)*10+m);
                    }
                }
            }
            else if(s1[1]=='?' && s1[2]=='?')
            {
                k=(s1[0]-'0');
                for(j=0;j<=9;j++)
                {
                    for(m=0;m<=9;m++)
                    {
                        v1.pb((k*10+j)*10+m);
                    }
                }
            }
            else if(s1[0]=='?')
            {
                k1=(s1[1]-'0');
                k2=(s1[2]-'0');
                for(j=0;j<=9;j++)
                    v1.pb((j*10+k1)*10+k2);
            }
            else if(s1[1]=='?')
            {
                k1=(s1[0]-'0');
                k2=(s1[2]-'0');
                for(j=0;j<=9;j++)
                    v1.pb((k1*10+j)*10+k2);
            }
            else if(s1[2]=='?')
            {
                k1=(s1[0]-'0');
                k2=(s1[1]-'0');
                for(j=0;j<=9;j++)
                    v1.pb((k1*10+k2)*10+j);
            }

            if(s2[0]!='?' && s2[1]!='?' && s2[2]!='?')
            {
                k1=s2[0]-'0';
                k2=s2[1]-'0';
                k=s2[2]-'0';
                v2.pb((k1*10+k2)*10+k);
            }
            else if(s2[0]=='?' && s2[1]=='?' && s2[2]=='?')
            {
                for(j=0;j<=999;j++)
                    v2.pb(j);
            }
            else if(s2[0]=='?' && s2[1]=='?')
            {
                k=(s2[2]-'0');
                for(j=0;j<=9;j++)
                {
                    for(m=0;m<=9;m++)
                    {
                        v2.pb((j*10+m)*10+k);
                    }
                }
            }
            else if(s2[0]=='?' && s2[2]=='?')
            {
                k=(s2[1]-'0');
                for(j=0;j<=9;j++)
                {
                    for(m=0;m<=9;m++)
                    {
                        v2.pb((j*10+k)*10+m);
                    }
                }
            }
            else if(s2[1]=='?' && s2[2]=='?')
            {
                k=(s2[0]-'0');
                for(j=0;j<=9;j++)
                {
                    for(m=0;m<=9;m++)
                    {
                        v2.pb((k*10+j)*10+m);
                    }
                }
            }
            else if(s2[0]=='?')
            {
                k1=(s2[1]-'0');
                k2=(s2[2]-'0');
                for(j=0;j<=9;j++)
                    v2.pb((j*10+k1)*10+k2);
            }
            else if(s2[1]=='?')
            {
                k1=(s2[0]-'0');
                k2=(s2[2]-'0');
                for(j=0;j<=9;j++)
                    v2.pb((k1*10+j)*10+k2);
            }
            else if(s2[2]=='?')
            {
                k1=(s2[0]-'0');
                k2=(s2[1]-'0');
                for(j=0;j<=9;j++)
                    v2.pb((k1*10+k2)*10+j);
            }
            l1=v1.size();
            l2=v2.size();
            mn=10000;
            pair<int,int> pr;
            for(j=0;j<l1;j++)
            {
                for(m=0;m<l2;m++)
                {
                    if(abs(v1[j]-v2[m])<mn)
                    {
                        mn=abs(v1[j]-v2[m]);
                        pr.first=v1[j];
                        pr.second=v2[m];
                    }
                    else if(abs(v1[j]-v2[m])==mn)
                    {
                        if(v1[j]<pr.first)
                            pr.first=v1[j];
                        if(pr.first==v1[j] && v2[m]<pr.second)
                            pr.second=v2[m];
                    }
                }
            }
            k1=pr.first;
            if(k1==0)
                k1=1;
            k2=0;
            while(k1)
            {
                k1=k1/10;
                k2++;
            }
            if(k2==l)
            cout << pr.first << " " ;
            else
            {
                k2=l-k2;
                while(k2)
                {
                    cout << "0";
                    k2--;
                }
                cout << pr.first << " ";
            }
            k1=pr.second;
            if(k1==0)
                k1=1;
            k2=0;
            while(k1)
            {
                k1=k1/10;
                k2++;
            }
            if(k2==l)
            cout << pr.second << endl ;
            else
            {
                k2=l-k2;
                while(k2)
                {
                    cout << "0";
                    k2--;
                }
                cout << pr.second << endl;
            }
        }
    }
    return 0;
}
