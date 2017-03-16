#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int T,i,a[30],ts,n;
char s[3000];
char ans[3000];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",&s);
		for(i=0;i<26;i++)
			a[i]=0;
		for(i=0;s[i];i++)
			a[s[i]-'A']++;
		n=0;
		while(a['z'-'a'])
		{
			ans[n++]='0';
			a['z'-'a']--;
			a['e'-'a']--;
			a['r'-'a']--;
			a['o'-'a']--;
		}
		while(a['w'-'a'])
		{
			ans[n++]='2';
			a['t'-'a']--;
			a['w'-'a']--;
			a['o'-'a']--;
		}
		while(a['u'-'a'])
		{
			ans[n++]='4';
			a['f'-'a']--;
			a['o'-'a']--;
			a['u'-'a']--;
			a['r'-'a']--;
		}
		while(a['x'-'a'])
		{
			ans[n++]='6';
			a['s'-'a']--;
			a['i'-'a']--;
			a['x'-'a']--;
		}
		while(a['g'-'a'])
		{
			ans[n++]='8';
			a['e'-'a']--;
			a['i'-'a']--;
			a['g'-'a']--;
			a['h'-'a']--;
			a['t'-'a']--;
		}

		while(a['o'-'a'])
		{
			ans[n++]='1';
			a['o'-'a']--;
			a['n'-'a']--;
			a['e'-'a']--;
		}
		while(a['h'-'a'])
		{
			ans[n++]='3';
			a['t'-'a']--;
			a['h'-'a']--;
			a['r'-'a']--;
			a['e'-'a']--;
			a['e'-'a']--;
		}
		while(a['f'-'a'])
		{
			ans[n++]='5';
			a['f'-'a']--;
			a['i'-'a']--;
			a['v'-'a']--;
			a['e'-'a']--;
		}
		while(a['s'-'a'])
		{
			ans[n++]='7';
			a['s'-'a']--;
			a['e'-'a']--;
			a['v'-'a']--;
			a['e'-'a']--;
			a['n'-'a']--;
		}
		while(a['i'-'a'])
		{
			ans[n++]='9';
			a['n'-'a']--;
			a['i'-'a']--;
			a['n'-'a']--;
			a['e'-'a']--;
		}
		sort(ans,ans+n);
		ans[n]=0;
		printf("Case #%d: %s\n",++ts,ans);
	}
	return 0;
}