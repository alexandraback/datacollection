/*Reordering Train Cars*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out3.txt","w",stdout);
    int i;
    long long fact[102];
    fact[0]=fact[1]=1;
    for(i=2;i<=101;i++)
        fact[i]=i*fact[i-1];
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {   int n;
        cin>>n;
        string s[n];
        int i;
        for(i=0;i<n;i++)
            cin>>s[i];
        int visit[102]={0},flag=1,flag1=1,count=0,i1;
        string g="";
        long long ans=1;
        for(i=0;i<n;i++)
        {   if(visit[i])
                continue;
            count++;
            //cout<<"*\n";
            vector<int> v;
            char start=s[i][0],end=s[i][s[i].size()-1];
            v.push_back(i);
            visit[i]=1;
            flag=1;
            while(flag)
            {   flag=0;
                for(i1=0;i1<n;i1++)
                {   if(!visit[i1])
                    {   if(s[i1][0]==end)
                        {   flag=1;
                            visit[i1]++;
                            end=s[i1][s[i1].size()-1];
                            v.push_back(i1);
                            break;
                        }
                        else if(s[i1][s[i1].size()-1]==start)
                        {   flag=1;
                            visit[i1]++;
                            start=s[i1][0];
                            v.insert(v.begin(),i1);
                            break;
                        }
                    }
                }
            }
            string temp="";
            for(i1=0;i1<v.size();i1++)
                temp+=s[v[i1]];
            g+=temp;
            int j;
            flag=1;
            for(i1=1;i1<temp.size();i1++)
            {   if(temp[i1]==temp[i1-1])
                    continue;
                for(j=i1;j<temp.size();j++)
                {   if(temp[j]==temp[i1-1])
                    {   flag=0;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(!flag)
            {   flag1=0;
                cout<<"Case #"<<cas<<": ";
                cout<<0<<endl;
                cas++;
                break;
            }
            int count1=1;
            //cout<<temp<<endl;
            for(i1=1;i1<v.size();i1++)
            {   //cout<<v[i-1]<<" "<<v[i]<<endl;
                if(s[v[i1]][s[v[i1]].size()-1]==s[v[i1-1]][0])
                {   count1++;
                    //cout<<"**"<<count1<<endl;
                    continue;
                }
                //cout<<"*"<<count1<<endl;
                ans*=fact[count1];
                count1=1;
            }
            ans*=fact[count1];
        }
        if(!flag1)
            continue;
        int j;
        for(i1=1;i1<g.size();i1++)
            {   if(g[i1]==g[i1-1])
                    continue;
                for(j=i1;j<g.size();j++)
                {   if(g[j]==g[i1-1])
                    {   flag=0;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(!flag)
            {   flag1=0;
                cout<<"Case #"<<cas<<": ";
                cout<<0<<endl;
                cas++;
                continue;
            }
        //cout<<count<<endl;
        ans*=fact[count];
        cout<<"Case #"<<cas<<": ";
        cout<<ans<<endl;
        cas++;
    }
    return 0;
}

