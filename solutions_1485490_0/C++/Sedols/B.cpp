#include<iostream>
#include<fstream>
#include<cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<vector>
#include<set>
using namespace std;
   vector<pair<long long, long long> > box;
   vector<pair<long long, long long> > toy, save1,save2;
long long calc1(int i, int k)
{
   i++;
   while(i < toy.size() && toy[i].second != box[k].second) i++;
   return min(toy[i].first, box[k].first);
}
long long calc2(int i, int k)
{
   i++;
   while(i < toy.size() && toy[i].second != box[k].second) i++;
   if(i == toy.size()) return 1000000000000000000LL;
   long long score = 0;
   int st = 0;
   for(int j = k + 1; j < i; j++)
   {
        while(st < toy.size() && box[j].second != toy[st].second) st++;
            if(st < toy.size())
            {
               score += min(box[j].first, toy[st].first);
            } 
    }
    return score;
}
int main()
{
 ifstream in("in.txt");
 ofstream out("out.txt");
 int t,N,M;
 
 in >> t;
 for(int k = 1; k <= t; k++)
 {
   in >> N >> M;
   box.clear();
   toy.clear();
   for(int j = 0; j < N; j++)
   {
     long long f, s;
     in >> f >> s;
     box.push_back(make_pair(f,s));
   }
   for(int j = 0; j < M; j++)
   {
     long long f, s;
     in >> f >> s;
     toy.push_back(make_pair(f,s));
   }
   long long  ma = 0LL;
   save1 = box;
   save2 = toy;
   for(int b = 1; b < (1 << N); b++)
   {
        int st = 0;
        long long cur = 0;
        box = save1;
        toy = save2;
        for(int j = 0; j < N; j++)
        {
            
            if(b &(1 << j))
            {
                while(st < M && box[j].second != toy[st].second) st++;
                if(st < M)
                {
                  if(box[j].first <= toy[st].first)
                  {
                    cur += box[j].first;
                    toy[st].first -= box[j].first;
                  }
                  else
                  {
                    cur += toy[st].first;
                    box[j].first -= toy[st].first;
                    while(st < toy.size() && calc1(st,j) > calc2(st,j))
                    {
                        st++;
                        while(st < toy.size() && toy[st].second != box[j].second) st++;
                        if(st >= toy.size()) break;
                        if(toy[st].first > box[j].first)
                        {
                            cur +=  box[j].first;
                            toy[st].first -= box[j].first;
                            box[j].first = 0;
                            break; 
                        }
                        else
                        {
                            cur += toy[st].first;
                            box[j].first -= toy[st].first;
                            toy[st].first = 0;
                        }
                    }   
                  }
                }
            }
        }

        if(cur > ma) ma = cur;
   }
   out<<"Case #"<<k<<": "<<ma<<endl;

 }

}
