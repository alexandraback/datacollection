#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<iostream>
#include<queue>
#include<set>

using namespace std;

long long int in_base(long long int n, long long int b)
{
   if(n==0) return 0;
   else return ((n % 2) + (b * in_base(n/2,b)));
}

pair<bool, vector<long long int> > is_ok(long long int n)
{
   vector<long long int> ans;
   for(long long int b = 2; b < 11; b++)
   {
      long long int in_b = in_base(n,b);
      bool flag = true;
      for(long long int i = 2; i <= sqrt(in_b) && flag && i < 100000; i++)
      {
         if(in_b % i == 0) {flag = false; ans.push_back(i);}
      }
      if(flag) {return (make_pair(false,ans));}
   }
   return (make_pair(true,ans));
} 

pair<long long int,vector<long long int> > rand_one(set<long long int> alr)
{
   long long int test = 2147483648 + 1 + 2 * ((rand()) % (2147483640 / 2));
   if((alr.count(test) == 0) && (is_ok(test).first))
        return make_pair(test, is_ok(test).second);
   else return (rand_one(alr));
}

void prin_bas_tw(long long int n)
{
   if(n > 0) {prin_bas_tw(n/2); cout << (n % 2);}
}

int main()
{
   int t, n;
   cin >> t >> n;
   set<long long int> alr;
   int j;
   cin >> j;
   cout << "Case #1:";
   for(int i = 0; i < j; i++)
   {
      cout << endl;
      pair<long long int,vector<long long int> > ans = rand_one(alr);
      alr.insert(ans.first);
      prin_bas_tw(ans.first);
      for(int i = 0; i < ans.second.size(); i++) cout << " " << ans.second[i];
   }
}
