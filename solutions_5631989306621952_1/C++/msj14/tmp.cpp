#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits.h>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <set>
#include <utility>
#include <queue>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <stack>
#include <algorithm>
#include <cstdlib>
#define MAX 100100
#define mod 1000000007
#define MS0(x) memset(x, 0, sizeof(x))
#define ll long long int
#define in(x) scanf("%I64d", &x)
#define ind(x) scanf("%d", &x)

using namespace std;

int main()
{
	//#ifndef ONLINE_JUDGE
//#endif
	//freopen("input1.in", "r", stdin);
    //freopen("output.txt","w",stdout);
	 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t,tc;
 cin>>tc;
 for(t=1;t<=tc;t++)
 {
 	int i,len;
     string s;
     len=s.length();
     cin>>s;
     string x=s.substr(0,1);
     for(i=1;i<s.length();i++)
     {
     	if(s[i]>s[0])
     	{
     		x=s[i]+x.substr(0,x.length());
     		s[0]=x[0];
     	}
     	else if(s[i]<s[0])
     	{
     		x=x.substr(0,x.length())+s[i];
     	}
     	else if(s[i]==s[0])
     	{
     		x=s[i]+x.substr(0,x.length());
     	}
     }
    cout<<"Case #"<<t<<": "<<x<<"\n";
 }
	return 0;
}