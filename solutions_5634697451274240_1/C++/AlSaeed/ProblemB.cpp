#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string S;

void read()
{
  cin >> S;
}

int solve()
{
  int s=0;
  int e=S.length()-1;
  int d=-1;
  int rst=0;
  while(s<=e)
    if(d==-1)
      {
	while(e>=s && S[e]=='+')
	  e--;
	if(e<s)
	  break;
	char x = S[s];
	while(s<e && x==S[s])
	  s++;
	if(x=='+')
	  rst++;
	rst++;
	d=1;
      }
    else
      {
	while(e>=s && S[s]=='-')
	  s++;
	if(e<s)
	  break;
	char x = S[e];
	while(s<e && x==S[e])
	  e--;
	if(x=='-')
	  rst++;
	rst++;
	d=-1;
      }
  return rst;
}

int main()
{
  int T;
  cin >> T;
  for(int t=1;t<=T;t++)
    {
      read();
      cout << "Case #"<<t<<": "<<solve()<< endl;
    }
  return 0;
}
