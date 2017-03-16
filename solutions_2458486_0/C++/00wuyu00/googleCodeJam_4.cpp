#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
int open[201],key[201],havekey[201][401],lenhav[201];
list<int> map[1000000];
vector<int> listKey[1000000];
int pre[1000000],prelist[1000000];
void output(int begin)
{
   int out[201],len=0;
   while(prelist[begin]!=-1)
   {
    out[len]=pre[begin];
    len++;
    begin=prelist[begin];
   }
   for(int i=len-1;i>=0;--i)
   if(i)
    cout<<out[i]<<" ";
   else  cout<<out[i]<<endl;
}
int main()
{
   freopen("D-small-attempt1.in","r",stdin);
   freopen("output.out","w",stdout);
   int t;
   cin>>t;
   for(int m=0;m<t;m++)
   {
        int k,n,key[201];
        int check=0;
        cin>>k>>n;
        for(int i=0;i<=200;i++)
            key[i]=0;
        for(int i=0;i<k;i++)
        {   int temp;
            cin>>temp;
            key[temp]++;
        }
        for(int i=0;i<n;i++)
        {
         int temp1,temp2;
         cin>>temp1>>temp2;

         open[i+1]=temp1;
         lenhav[i+1]=temp2;
         for(int j=0;j<temp2;j++)
         {
             int temp3;
             cin>>temp3;
             havekey[i+1][j]=temp3;
         }
        }
         printf("Case #%d: ",m+1);

        int i=0,len=0;map[0].clear();listKey[0].clear();
        prelist[0]=-1;
        for(int j=0;j<=200;j++)
            listKey[0].push_back(key[j]);
        for(int j=0;j<n;j++)
        {

            map[0].push_back(j+1);
        }
        do
        {
          list<int> flag=map[i];
          for(list<int>::iterator iter=flag.begin();iter!=flag.end();iter++)
           if(listKey[i][open[*iter]])
          {

              len++;
              if(len==1000000)
                len=0;
              int temp=*iter;
              pre[len]=*iter;
              prelist[len]=i;
              listKey[len]=listKey[i];

              listKey[len][open[temp]]--;
              for(int j=0;j<lenhav[temp];j++)
              {
               listKey[len][havekey[temp][j]]++;
              }

              map[len]=flag;
              list<int>::iterator u;
              u=find(map[len].begin(),map[len].end(),temp);
              map[len].erase(u);
              if (map[len].empty())
              {
                   output(len);
                   check=1;
                   break;
              }

          }

        i++;
        if(i==1000000)
                i=0;
       if(check) break;
        }
        while(i<=len);
        if(!check) cout<<"IMPOSSIBLE"<<endl;
   }
   return 0;
}
