#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double LD;
typedef pair<LD, LD> PLDLD;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))


int main()
{
    int t;
    string s,c,anss,ansc;
    cin>>t;
    REP(k,t)
    {
        cin>>s>>c;
        anss="";
        ansc="";
        bool bigger=false,order=false,reconst=false;
        REP(i,s.size())
        {
            if(bigger)
            {
                if(s[i]=='?')
                {
                    
                    if(c[i]=='?')
                    {
                        anss+='0';
                        ansc+='9';
                    }
                    else
                    {
                        anss+='0';
                        ansc+=c[i];
                    }
                }
                else
                {
                    
                    if(c[i]=='?')
                    {
                        anss+=s[i];
                        ansc+='9';
                    }
                    else
                    {
                        anss+=s[i];
                        ansc+=c[i];
                    }
                }
            }
            else
            {
                if(s[i]=='?' || c[i] == '?')
                {
                    if(s[i]!='?')
                        anss+=s[i];
                    else if(c[i]!='?')
                        anss+=c[i];
                    else
                        anss+='0';
                }
                else
                {
                    if(s[i]>c[i])
                    {
                        bigger=true;
                        ansc=anss;
                        anss+=s[i];
                        ansc+=c[i];
                        
                        if(s[i]-c[i]>5)
                        {
                                string tmp=s;
                                s=c;
                                c=tmp;
                                tmp=anss;
                                anss=ansc;
                                ansc=tmp;
                                order=true;
                            for(int j=i-1;j>=-1;j--)
                            {
                                if(j==-1)
                                {
                                    reconst=true;
                                    break;
                                }
                                if(s[j]=='?')
                                {
                                    if(c[j]=='?')
                                    {
                                        anss[j]='1';
                                    }
                                    else
                                    {
                                        anss[j]=c[j]+1;
                                        if(c[j]+1>'9')
                                        {
                                            anss[j]='0';
                                            continue;
                                        }
                                    }
                                }
                                else
                                {
                                        ansc[j]=s[j]-1;
                                        if(s[j]-1<'0')
                                        {
                                            ansc[j]='9';
                                            continue;
                                        }
                                }
                                break;
                            }
                        }
                    }
                    else if(s[i]<c[i])
                    {
                        string tmp=s;
                        s=c;
                        c=tmp;
                        bigger=true;
                        order=true;
                        ansc=anss;
                        anss+=s[i];
                        ansc+=c[i];
                        
                        
                        if(s[i]-c[i]>5)
                        {
                                string tmp=s;
                                s=c;
                                c=tmp;
                                tmp=anss;
                                anss=ansc;
                                ansc=tmp;
                                order=false;
                            for(int j=i-1;j>=-1;j--)
                            {
                                if(j==-1)
                                {
                                    reconst=true;
                                    break;
                                }
                                if(s[j]=='?')
                                {
                                    if(c[j]=='?')
                                    {
                                        anss[j]='1';
                                    }
                                    else
                                    {
                                        anss[j]=c[j]+1;
                                        if(c[j]+1>'9')
                                        {
                                            anss[j]='0';
                                            continue;
                                        }
                                    }
                                }
                                else
                                {
                                        ansc[j]=s[j]-1;
                                        if(s[j]-1<'0')
                                        {
                                            ansc[j]='9';
                                            continue;
                                        }
                                }
                            break;
                            }
                        }
                    }
                    else
                    {
                        anss+=s[i];
                    }
                }
            }
        }
        if(!bigger)
        {
            ansc=anss;
        }
        if(order)
        {
            string tmp=ansc;
            ansc=anss;
            anss=tmp;
            tmp=s;
            s=c;
            c=tmp;
        }
        
        if(reconst)
        {
        anss="";
        ansc="";
        bigger=false;
        order=false;
        REP(i,s.size())
        {
            if(bigger)
            {
                if(s[i]=='?')
                {
                    
                    if(c[i]=='?')
                    {
                        anss+='0';
                        ansc+='9';
                    }
                    else
                    {
                        anss+='0';
                        ansc+=c[i];
                    }
                }
                else
                {
                    
                    if(c[i]=='?')
                    {
                        anss+=s[i];
                        ansc+='9';
                    }
                    else
                    {
                        anss+=s[i];
                        ansc+=c[i];
                    }
                }
            }
            else
            {
                if(s[i]=='?' || c[i] == '?')
                {
                    if(s[i]!='?')
                        anss+=s[i];
                    else if(c[i]!='?')
                        anss+=c[i];
                    else
                        anss+='0';
                }
                else
                {
                    if(s[i]>c[i])
                    {
                        bigger=true;
                        ansc=anss;
                        anss+=s[i];
                        ansc+=c[i];
                        
                    }
                    else if(s[i]<c[i])
                    {
                        string tmp=s;
                        s=c;
                        c=tmp;
                        bigger=true;
                        order=true;
                        ansc=anss;
                        anss+=s[i];
                        ansc+=c[i];
                        
                    }
                    else
                    {
                        anss+=s[i];
                    }
                }
            }
        }
        }
        
        
        
        cout<<"Case #"<<k+1<<": "<<anss<<" "<<ansc<<endl;
    }
    
}