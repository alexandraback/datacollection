
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <set>
#include <map>
#include <numeric>
#include <ctime>
#include <functional>
#include <queue>

using namespace std;
struct stars
{
       int one;
       int two;
};
bool decide1 (stars x,stars y)
{
     if (x.one!=y.one)
     {
        return x.one<y.one;
     }
     else return x.two>y.two;
}
int main()
{
    FILE *f,*fw;
    int t,n,flag,flag1,earn,ans,n1;
    int ai,bi;
    char c;
    int i=0,j;
    string s;
    vector<int> a,b,done;
    vector<int>::iterator it;
    vector<stars> rat;
    stars curr;
    f=fopen("B-small-attempt3.in","r");
    fw=fopen("ans1_2.txt","w");
    fscanf(f,"%d",&t);
    //cin>>t;
    //while (i>=0)
    //{
    //      if (i%100000==0)cout<<i<<" ";i+=100000;}
    //system("pause");
    //cout<<t;
    //system("pause");
    for (i=0;i<t;i++)
    {
        fscanf(f,"%d",&n);
        //cin>>n;
        n1=n;
        a.clear();
        b.clear();
        rat.clear();
        done.clear();
        earn=0;
        ans=0;
        flag1=0;
        for (j=0;j<n;j++)
        {
            fscanf(f,"%d%d",&ai,&bi);
            //cin>>ai>>bi;
            a.push_back(ai);
            b.push_back(bi);
            curr.one=ai;curr.two=bi;
            rat.push_back(curr);
            done.push_back(0);
        }
        sort(rat.begin(),rat.end(),decide1);
        for (j=0;j<n;j++)
        {
            a[j]=rat[j].one;
            b[j]=rat[j].two;
        } 
        while (n=rat.size())
        {
              flag=0;
              for (j=0;j<rat.size();j++)
              {
                  if (b[j]<=earn)
                  {
                       if (!done[j])
                       earn+=2;
                       else
                        earn+=1;
                       ans+=1;
                       b.erase(j+b.begin());
                       a.erase(j+a.begin());
                       rat.erase(j+rat.begin());
                       done.erase(j+done.begin());
                       flag=1;
                  }
                  
              }
              if (flag)continue;
              //flag=0;
              if (a[0]<=earn)
              {
                  for (j=0;a[j]<=earn&&j<rat.size();j++)
                  {
                      if (!done[j])
                      {
                        earn+=1;
                        ans+=1;
                        done[j]=1;
                        flag=1;
                        break;
                      }
                  }
                  if (flag)
                     continue;
                  else 
                  {
                       cout<<"Case #"<<i+1<<": "<<"Too Bad"<<endl;
                       fprintf(fw,"Case #%d: Too Bad\n",i+1);
                       flag1=1;
                       break;
                  }
              }
              else 
              {
                   cout<<"Case #"<<i+1<<": "<<"Too Bad"<<endl;
                   fprintf(fw,"Case #%d: Too Bad\n",i+1);
                   flag1=1;
                   break;
              }
        }           
        if (flag1)continue;      
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
        fprintf(fw,"Case #%d: %d\n",i+1,ans); 
        //system("pause");
    }
        
    fclose(fw);    
    //fclose(f);
    system("pause");
    return 0;
}
