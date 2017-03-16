#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstring>
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

bool isVowel(char c)
{
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main()
{
	int T;
	scanf("%d",&T);
	char S[1001000];
	for(int step=1; step<=T; ++step)
	{
		int n;
		ll ans=0;
		scanf("%s%d",S,&n);
		int k=0;
		int L=strlen(S);
		set<int> lft;
		for(int i=0; i<L; ++i)
		{
			if(!isVowel(S[i])){
				++k;
				if(k>=n){
					lft.insert(i-n+1);
				}
			}else k=0;
		}
		for(int i=0; i<L; ++i)
		{
			if(lft.lower_bound(i)==lft.end())
				break;
			ll p=*lft.lower_bound(i);
			p+=n-1;
			ans+=L-p;
		}
		cout << "Case #"<<step<<": "<<ans<<endl;
	}
}
