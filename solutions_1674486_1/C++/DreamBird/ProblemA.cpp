//A Moolla (6 May 2012)

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <list>


using namespace std;

//T is the number of trials
//N is the

int t,n;
list<int> infrom[1001];
bool marked[1001];
queue<int> reached;


void emptyIt ()
{
   for (int i=1;i<=n;++i)
   {
       while (!infrom[i].empty())
             infrom[i].pop_back();  
   }     
}

bool go()
{
     if (reached.size()==0)
        return false;
     int cur = reached.front();
     reached.pop();
    
    
    int temp = infrom[cur].size();
    int paths[temp];
    for (int i=0;i<temp;++i)
    {
        paths[i] = infrom[cur].back();
        infrom[cur].pop_back();
     }
     
    // cout<<"=====================\n";
    // for (int i=0;i<temp;i++)
     //    cout<<paths[i]<<" ";
    // cout<<"\n===================\n";
     
     for (int i=0;i<temp;i++)
     {
         
         
         if (marked[paths[i]])
         {
            return true;    
         }
         marked[paths[i]] = true;
         reached.push(paths[i]);
     }
     
     for (int i=0;i<temp;++i)
     {
         infrom[cur].push_back(paths[i]);
     }
     return go();
}

int main ()
{
    freopen("A-large.in","r",stdin);   
    freopen("A-large.out","w",stdout);
    
    scanf ("%d",&t);
    for (int trial=1;trial<=t;trial++)
    {
     cout<<"Case #"<<trial<<": ";
                 scanf ("%d",&n);
                 int m,x;
                 for (int i=1;i<=n;++i)
                 {
                     scanf ("%d",&m);
                     for (int j=0;j<m;++j)
                     {
                         scanf("%d",&x);
                         infrom[i].push_back(x);    
                     }
                 }
                 bool diamond = false;
                 //Algorithm
                 for (int end=1;end<=n;end++)
                 {
                                           
                    // cout<<" Starting on "<<end<<": ";
                     for (int i=1;i<=n;++i)
                         marked[i] = false;
                     marked[end] = true;
                     reached.push(end);
                     
                     
                     diamond = go();
                     if (diamond)
                        break;
                 }
                 
                 if (diamond)
                    cout<<"Yes\n";
                 else
                     cout<<"No\n";                                  
     emptyIt();
    // for (int i=1;i<n;i++)
        // marked[i] = false;            
     while (reached.size()>0)
           reached.pop();
    }
    return 0;    
}
