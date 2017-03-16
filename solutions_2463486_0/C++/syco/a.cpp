#include<iostream>
#include<set>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std ;
#define INF (int)1e9

string decrement(string a)
{
 for(int i = a.size() - 1;i >= 0;i--)
  if(a[i] > '0')
  {
   a[i]-- ;
   break ;
  }
  else a[i] = '9' ;
 if(a[0] == '0') a = a.substr(1) ;
 return a ;
}

string square(string a)
{
 int c[200] = {} ;
 int n = a.size() ;
 for(int i = 0;i < n;i++)
  for(int j = 0;j < n;j++)
   c[i + j] += (a[i] - '0') * (a[j] - '0') ;
 for(int i = 0;i < 199;i++)
 {
  c[i + 1] += c[i] / 10 ;
  c[i] %= 10 ;
 }
 string ret ;
 int i ;
 for(i = 199;i >= 0;i--) if(c[i]) break ;
 for(;i >= 0;i--) ret.push_back(c[i] + '0') ;
 return ret ;
}

bool lesser_or_equal(string a,string b)
{
 if(a.size() != b.size()) return a.size() < b.size() ;
 for(int i = 0;i < a.size();i++)
  if(a[i] != b[i])
   return a[i] < b[i] ;
 return true ;
}

int sz ;
string all[100000] ;
void check(string &half,int len)
{
 string rev = half ;
 reverse(rev.begin(),rev.end()) ;
 if(half.size() + rev.size() > len) rev = rev.substr(1) ;
 string total = half + rev ;

 int sum = 0 ;
 for(int i = 0;i < total.size();i++) sum += (total[i] - '0') * (total[i] - '0') ;
 if(sum >= 10) return ;

 all[sz++] = square(total) ;
}

void precompute()
{
 all[sz++] = "1" ;
 all[sz++] = "4" ;
 all[sz++] = "9" ;
 all[sz++] = "121" ;
 all[sz++] = "484" ;
 for(int len = 3;len <= 55;len++)
 {
  int half = (len + 1) / 2 ;
  for(int i = 1;i <= 2;i++)
   for(int j = 0;j <= 2;j++)
   {
    string s = string(half, '0') ;
    s[0] = i + '0' ;
    s[half - 1] = j + '0' ;

    // no 1's in middle
    check(s,len) ;
    
    // single 1 in middle
    for(int k = 1;k + 1 < half;k++)
    {
     s[k] = '1' ;
     check(s,len) ;
     s[k] = '0' ;
    }

    // 2 1's in middle
    for(int k1 = 1;k1 + 1 < half;k1++)
    for(int k2 = k1 + 1;k2 + 1 < half;k2++)
    {
     s[k1] = '1' ;
     s[k2] = '1' ;
     check(s,len) ;
     s[k1] = '0' ;
     s[k2] = '0' ;
    }
    
    // 3 1's in middle
    for(int k1 = 1;k1 + 1 < half;k1++)
    for(int k2 = k1 + 1;k2 + 1 < half;k2++)
    for(int k3 = k2 + 1;k3 + 1 < half;k3++)
    {
     s[k1] = '1' ;
     s[k2] = '1' ;
     s[k3] = '1' ;
     check(s,len) ;
     s[k1] = '0' ;
     s[k2] = '0' ;
     s[k3] = '0' ;
    }
   }
 }
}

int solve(string lim)
{
 int ret = 0 ;
 for(int i = 0;i < sz;i++)
  if(lesser_or_equal(all[i],lim))
   ret++ ;
 return ret ;
}

int solve(string a,string b)
{
 int ret = solve(b) ;
 if(a != "1")
 {
  a = decrement(a) ;
  ret -= solve(a) ;
 }
 return ret ;
}

bool check(long long n)
{
 long long ret = 0 ;
 long long t = n ;
 while(t > 0)
 {
  ret = ret * 10 + t % 10 ;
  t /= 10 ;
 }
 return ret == n ;
}

int brute(int n)
{
 int ct = 0 ;
 for(int i = 1;i * i <= n;i++)
  if(check(i) && check(1LL * i * i))
   ct++ ;
 return ct ;
}

int brute(int a,int b)
{
 return brute(b) - brute(a - 1) ;
}

int to_int(string s)
{
 int ret = 0 ;
 for(int i = 0;i < s.size();i++)
  ret = ret * 10 + s[i] - '0' ;
 return ret ;
}

string to_string(int a)
{
 stringstream ss ;
 ss << a ;
 return ss.str() ;
}

void test()
{
 for(int t = 1;t < 10000;t++)
 {
  int a = rand() % 1000000000 + 1 ;
  int b = rand() % 1000000000 + 1 ;
  if(a > b) swap(a,b) ;
  
  int ret1 = solve(to_string(a),to_string(b)) ;
  int ret2 = brute(a,b) ;
  
  cout << ret1 << " " << ret2 << endl ;
  
  if(ret1 != ret2)
  {
   cout << a << " " << b << endl ;
   while(1) ;
  }
 }
}

int main()
{
 precompute() ;
// cout << sz << endl ;
// for(int i = 0;i < sz;i++) cout << all[i] << endl ;

// test() ;
 
 int runs ;
 cin >> runs ;
 for(int t = 1;t <= runs;t++)
 {
  string a,b ;
  cin >> a >> b ;
 
  int ret = solve(a,b) ;
  
// int ret2 = brute(to_int(a),to_int(b)) ;
// cout << ret << " " << ret2 << endl ;
  
  printf("Case #%d: %d\n",t,ret) ;
 }

 return 0 ;
}
