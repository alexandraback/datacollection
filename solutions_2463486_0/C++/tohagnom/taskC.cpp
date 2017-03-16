#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <memory.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>

bool isPal(ll a)
{
	ostringstream ous;
	ous << a;
	string s=ous.str();
	int n=s.length();
	for(int i=0; i<n>>1; ++i)
		if(s[i]!=s[n-i-1]) return false;
	return true;
}

int main()
{
	int T;
	cin >> T;
	for(int step=1; step<=T; ++step)
	{
		ll a, b;
		cin >> a >> b;
		int ans=0;
		for(int i=1; i<10; ++i)
		{
			ll c=i*i;
			if(isPal(c) && c>=a && c<=b)
				++ans;
		}
		char buf[20], buf1[20];
		for(int i=1;;++i)	
		{
			sprintf(buf,"%d",i);
			strcpy(buf1,buf);
			int len=strlen(buf);
			for(int j=0; j<len; ++j){
				buf[len+j]=buf[len-j-1];
				buf1[len+j+1]=buf[len-j-1];
			}
			buf[len+len]='\0';
			buf1[len+len+1]='\0';
			ll c;
			sscanf(buf,"%I64d",&c);
			c*=c;
			if(c>b) break;
			if(isPal(c) && c>=a && c<=b) ++ans;
			for(int j=0; j<10; ++j)
			{
				buf1[len]=j+'0';
				sscanf(buf1,"%I64d",&c);
				c*=c;
				if(isPal(c) && c>=a && c<=b) ++ans;
			}
		}
		cout << "Case #" << step << ": ";
		cout << ans;
		cout << endl;
	}
}
