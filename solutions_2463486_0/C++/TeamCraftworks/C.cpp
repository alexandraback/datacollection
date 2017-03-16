#include<iostream>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull hako[] ={
  1,
  4,
  9,
  121,
  484,
  10201,
  12321,
  14641,
  40804,
  44944,
  1002001,
  1234321,
  4008004,
  100020001,
  102030201,
  104060401,
  121242121,
  123454321,
  125686521,
  400080004,
  404090404,
  10000200001,
  10221412201,
  12102420121,
  12345654321,
  40000800004,
  1000002000001,
  1002003002001,
  1004006004001,
  1020304030201,
  1022325232201,
  1024348434201,
  1210024200121,
  1212225222121,
  1214428244121,
  1232346432321,
  1234567654321,
  4000008000004,
  4004009004004,
  100000020000001,
  100220141022001
};

ull my_pow(ull a,ull e)
{
  return !e?1:
    (e%2?a*my_pow(a,e-1):my_pow(a*a,e/2));
}

ull rev(ull x){
  ull y = 0;
  while(x){
    y *= 10ULL;
    y += x%10ULL;
    x /= 10ULL;
  }
  return y;
}

bool check(ull e)
{
  ull re = rev(e);
  return re == e;
}


int main()
{
  //ull e = 100000000000000;
  //cout << e << endl;
  int Nari = 1;
  int T;
  vector<ull> S;
  //vector<ull> FX;
  for(int i=0;i<41;i++)
    S.push_back(hako[i]);


  cin >> T;
  /*
  for(int i=1;i<=100000000;i++)
    {
      if(i == rev(i))
	FX.push_back(i);    
    }

  for(int i=0;i<FX.size();i++)
    {
      ull e = my_pow(FX[i],2);
      if(check(e))
	S.push_back(e);
    }



  for(vector<ull>::iterator it = S.begin();it != S.end();it++)
    cout << *it << endl;
  */

  while(T-- > 0)
    {
      ull a,b;
      cin >> a >> b;
      cout << "Case #" << Nari++ << ": ";
      cout << upper_bound(S.begin(),S.end(),b)-lower_bound(S.begin(),S.end(),a) << endl;
    }
  return 0;
}
