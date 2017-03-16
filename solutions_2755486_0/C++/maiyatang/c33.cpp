//#include<iostream>
#include<fstream>
using namespace std;
ifstream cin ("temp.in");
ofstream cout ("temp.out");
struct node
{
       int d;
       int n;
       int w;
       int e;
       int s;
       int dd;
       int dp;
       int ds;
};
struct node people[11]; 
int wall[2001];
int temp[2001];
int main ()
{
    int t;
    cin>>t;
    int i,j;
    for (i=0;i<t;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        for (j=0;j<=2000;j++) wall[j]=0;
        int answer=0;
        int n;
        cin>>n;
        for (j=0;j<n;j++)
        {
            cin>>people[j].d>>people[j].n>>people[j].w>>people[j].e>>people[j].s>>people[j].dd>>people[j].dp>>people[j].ds;
            people[j].w+=1000;
            people[j].e+=1000;
        }
        bool can=true;
        while (can)
        {
              for (j=0;j<=2000;j++) temp[j]=wall[j];
              can=false;
              int min=-1;
              for (j=0;j<n;j++)
                  if (people[j].n>0)
                     if (min==-1||people[j].d<min) min=people[j].d;
              if (min!=-1)
              {
                 can=true;
                 for (j=0;j<n;j++)
                 {
                    if (people[j].d==min&&people[j].n>0) 
                    {
                       int z;
                       bool first=true;
                       for (z=people[j].w;z<people[j].e;z++)
                           if (wall[z]<people[j].s)
                           {
                              if (first==true) 
                              {
                                               answer++;
                                               first=false;
                                               
                              }
                              if (temp[z]<people[j].s) temp[z]=people[j].s;
                           }
                       people[j].d+=people[j].dd;
                       people[j].n--;
                       people[j].w+= people[j].dp;
                       people[j].e+= people[j].dp;
                       people[j].s+= people[j].ds;
                    }
                 }
              }
              for (j=0;j<=2000;j++) wall[j]=temp[j];
        }
        cout<<answer<<endl;
    }
    return 0;
}
