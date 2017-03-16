#include <bits/stdc++.h>
/*#include <boost/multiprecision/cpp_int.hpp> */
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define gc getchar_unlocked
#define pp pair<int,int>
#define bigint boost::multiprecision::cpp_int
#define bsize 600
using namespace std;

double prob[105][105][105],lett[30];
string S,L;
int pi[105];

void pre()
{
    memset(pi,-1,sizeof(pi));
    pi[0]=-1;
    int p=-1;
    for(int i=1;i<L.length();i++)
    {
        while(L[i]!=L[p+1] && p>-1)
        {
            p=pi[p];
        }
        
        if(L[i]==L[p+1])
        {
            p++;
        }
        else p=-1;
        
        
        pi[i]=p;
    }
    
}
int main()
{
   int t,k,l,s,cas=1;
   scanf("%d",&t);
   while(t--)
   {
      
       scanf("%d %d %d",&k,&l,&s);
       int cnt[27]={0};
       
       cin>>S>>L;
       for(auto i:S)cnt[i-'A']++;
       for(int i=0;i<26;i++)lett[i]=((double)cnt[i])/((double)k);
       
       int n=s;
       pre();
       
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=n;j++)
           {
               for(int k=0;k<=100;k++)prob[i][j][k]=0.0;
           }
       }
       
       
       prob[0][0][0]=1.0;
       
       int fin=L.length();
       int mbana=0;
       
       for(int i=1;i<=n;i++)
       {
           for(int j=0;j<=n;j++)  //no. of matches
           {
               for(int q=-1;q<fin;q++) //prev state
               {
                 
                   for(int cc=0;cc<26;cc++)  //curr letter
                   {
                       
                       if(q==fin-2 && L[fin-1]==cc+'A')
                       {
                           int fino=pi[fin-1];
                           
                           
                          prob[i][j+1][fino+1]+=prob[i-1][j][fin-1]*lett[cc];
                          if(prob[i][j+1][fino+1]>0.0)mbana=max(mbana,j+1);
                          continue;
                       }
                       
                       int temp=q;
                       while(L[temp+1]!=cc+'A' && temp>-1)
                       {
                           temp=pi[temp];
                       }
                       if(L[temp+1]==cc+'A')temp++;
                       else temp=-1;
                       
                       prob[i][j][temp+1]+=prob[i-1][j][q+1]*lett[cc];
                       
                       
                   }
               }
           }
       }
       double ans=0.0;
       
       for(int j=0;j<=n;j++)
       {
           for(int q=0;q<=fin;q++)
           {
               ans+= ((double)(mbana-j))*prob[n][j][q];
              // cout<<j<<" "<<prob[n][j][q]<<endl;
           }
       }
       
      // cout<<mbana<<endl;
       printf("Case #%d: %.6f\n",cas++,ans);
   }
    
return 0;
}