#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
using namespace std;
int dp[21][1000001];
int keep[21][1000001];
int main()
{
 ifstream in("in.txt");
 ofstream out("out.txt");
 int t,n;
 in >> t;
 for(int k = 1; k <= t; k++)
 {
   in >> n;
   vector<int> v(n);
   int sum = 0;
   for(int j  =0; j < n; j++)
   {
     in >> v[j];
     sum += v[j];
   }
   out<<"Case #"<<k<<":"<<endl;
   int g = 0;
   for(int b = 1; b <= (1 << 10); b++)
   {
        int sum1 = 0;
        for(int j = 0; j < 20; j++)
        {
            if(b & (1 << j))
                sum1 += v[j];   
            if(sum1 > sum/2) break;             
        } 
        if(sum1 > sum/2) continue;
        memset(keep,0,sizeof(keep));
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= 20; i++)
          for(int j = 0; j <= sum1; j++)
          {
             if(j >= v[i-1] && v[i-1] + dp[i-1][j-v[i-1]]> dp[i-1][j] && !(b & (1 << (i-1))))
             {
               dp[i][j] = dp[i-1][j-v[i-1]] + v[i-1];
               keep[i][j]= 1;
             }
             else
             {
               dp[i][j] = dp[i-1][j];
               keep[i][j]= 0;
             }
          }
        if(dp[20][sum1] == sum1)
        {
            g = 1;
            vector<int> v1, v2;
            v1.clear();
            v2.clear();
            for(int j = 0; j < 20; j++)
              if(b & (1 << j))
                v1.push_back(v[j]);
            int K = sum1;
            for(int i = 20; i >= 1; i--)
              if(keep[i][sum1] == 1)
              {
                v2.push_back(v[i-1]);
                sum1 -= v[i-1];
              }
            for(int j = 0; j < v1.size()-1; j++)
                out<<v1[j]<<" ";
            out<<v1[v1.size()-1]<<endl;
            for(int j = 0; j < v2.size()-1; j++)
                out<<v2[j]<<" ";
            out<<v2[v2.size()-1]<<endl;
            break;
        }
        if(g) break;
   } 
   if(g == 0)
     out<<"Impossible"<<endl;
     
  }

}
