#include<iostream>
#include<fstream>
#include<cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<vector>
#include<set>
using namespace std;
int dp[21][1000001];
int keep[500];
int main()
{
 ifstream in("in.txt");
 ofstream out("out.txt");
 int t,n;
 in >> t;
 for(int k = 1; k <= t; k++)
 {
   in >> n;
   vector<long long> v(n);
   long long sum = 0;
   for(int j  =0; j < n; j++)
   {
     in >> v[j];
     sum += v[j];
   }
   out<<"Case #"<<k<<":"<<endl;
   srand ( time(NULL) );
   sort(v.begin(),v.end());
   int g = 0;
   for(int z = 0; z < 150000; z++)
   {
        long long s2 = 0;
   while(1)
   {
     int f = rand() % 105 + 1;
     set<long long > S;
     S.clear();
     memset(keep,0,sizeof(keep));
     s2 = 0;
     while(S.size() < f)
     {
        int k = rand() % 500;
        S.insert(v[k]);
        keep[k] = 1;
     }
     for(set<long long>::iterator it = S.begin(); it != S.end(); it++)
       s2 += *it;
     if(s2 < sum/2) break;
   } 
   long long s1 = 0;
   for(int j = 0; j < v.size(); j++)
   {
        if(keep[j] != 1 && v[j] + s1 <= s2)
        {
            s1 += v[j];
            keep[j] = 2;
            if(s1 == s2)
            {
                g = 1;
                vector<long long> v1,v2;
                for(int i = 0; i < 500; i++)
                {
                    if(keep[i] == 1) v1.push_back(v[i]);
                    if(keep[i] == 2) v2.push_back(v[i]);
                }
                for(int i = 0; i < v1.size() - 1; i ++)
                  out<<v1[i]<<" ";
                out<<v1[v1.size()-1]<<endl;
                for(int i = 0; i < v2.size() - 1; i ++)
                  out<<v2[i]<<" ";
                out<<v2[v2.size()-1]<<endl;
                break;
            }
        }
        if(g) break;
   }
    if(g) break;
   }   
   if(g == 0)
     out<<"Impossible"<<endl;
     
  }

}
