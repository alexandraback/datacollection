#include<iostream>
#include<set>
#include<queue>
using namespace std;
int main()
{
    freopen("inp.txt","r",stdin);
    freopen("output.txt","w",stdout);
    set<int> myset;
    queue<int> myq;
    set<int>::iterator it;
    int test,m,n,num,temp,inh[1002][12],i,j,k,siz,flag;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>n;
        flag=0;
        myset.clear();
        for(j=0;j<1002;j++)
        for(k=0;k<12;k++)
        inh[j][k]=0;
        for(j=0;j<n;j++)
        {
            cin>>m;
            for(k=0;k<m;k++)
            {
                cin>>inh[j][k];
            }
        }
       /* for(j=0;j<n;j++)
        {
            k=0;
            while(inh[j][k]!=0)
            {
                cout<<inh[j][k]<<" ";
                k++;
            }
            cout<<endl;
        }*/
        for(j=0;j<n;j++)
        {
            k=0;
            while(!myq.empty())
            {
                myq.pop();
            }
            myset.clear();
            while(inh[j][k]!=0)
            {
                myq.push(inh[j][k]);
                k++;
            }
            while(!myq.empty())
            {
               siz=myset.size();
               num=myq.front();
               myq.pop();
               k=0;
               while(inh[num-1][k]!=0)
               {
                   myq.push(inh[num-1][k]);
                   k++;
               }
               myset.insert(num);
           //    cout<<"num:"<<num<<"j:"<<j<<endl;
               if(siz==myset.size())
               {
                   flag=1;
               /*     for(it=myset.begin();it!=myset.end();it++)
                    {
                        cout<<(*it)<<endl;
                    }*/
                   break;
               }
            }
            if(flag==1) break;
        }
       /* for(it=myset.begin();it!=myset.end();it++)
        {
            cout<<(*it)<<endl;
        }*/
        if(flag==1) cout<<"Case #"<<i+1<<": "<<"Yes"<<endl;
        else cout<<"Case #"<<i+1<<": "<<"No"<<endl;
    }
    return 0;
}
