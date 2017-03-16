#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cmath>
using namespace std;

int T,a[10],ch[26];
char s[20000];

int main()
{
//	freopen("A-large.in","r",stdin);
//	freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	for (int id=1; id<=T; id++)
	{
		scanf("%s",s);
		int n=strlen(s);
		for (int i=0; i<26; i++) ch[i]=0;
		for (int i=0; i<10; i++) a[i]=0;
		for (int i=0; i<n; i++) ch[s[i]-'A']++;
		a[0]+=ch['Z'-'A'];
		ch['O'-'A']-=ch['Z'-'A'];
		ch['R'-'A']-=ch['Z'-'A'];
		ch['E'-'A']-=ch['Z'-'A'];
		ch['Z'-'A']-=ch['Z'-'A'];
		a[4]+=ch['U'-'A'];
		ch['R'-'A']-=ch['U'-'A'];
		ch['O'-'A']-=ch['U'-'A'];
		ch['F'-'A']-=ch['U'-'A'];
		ch['U'-'A']-=ch['U'-'A'];
		a[2]+=ch['W'-'A'];
		ch['T'-'A']-=ch['W'-'A'];
		ch['O'-'A']-=ch['W'-'A'];
		ch['W'-'A']-=ch['W'-'A'];
		a[1]+=ch['O'-'A'];
		ch['E'-'A']-=ch['O'-'A'];
		ch['N'-'A']-=ch['O'-'A'];
		ch['O'-'A']-=ch['O'-'A'];
		a[6]+=ch['X'-'A'];
		ch['S'-'A']-=ch['X'-'A'];
		ch['I'-'A']-=ch['X'-'A'];
		ch['X'-'A']-=ch['X'-'A'];
		a[7]+=ch['S'-'A'];
		ch['N'-'A']-=ch['S'-'A'];
		ch['E'-'A']-=ch['S'-'A'];
		ch['V'-'A']-=ch['S'-'A'];
		ch['E'-'A']-=ch['S'-'A'];
		ch['S'-'A']-=ch['S'-'A'];
		a[8]+=ch['G'-'A'];
		ch['T'-'A']-=ch['G'-'A'];
		ch['H'-'A']-=ch['G'-'A'];
		ch['I'-'A']-=ch['G'-'A'];
		ch['E'-'A']-=ch['G'-'A'];
		ch['G'-'A']-=ch['G'-'A'];
		a[3]+=ch['R'-'A'];
		ch['E'-'A']-=ch['R'-'A'];
		ch['E'-'A']-=ch['R'-'A'];
		ch['H'-'A']-=ch['R'-'A'];
		ch['T'-'A']-=ch['R'-'A'];
		ch['R'-'A']-=ch['R'-'A'];
		a[5]+=ch['F'-'A'];
		ch['E'-'A']-=ch['F'-'A'];
		ch['V'-'A']-=ch['F'-'A'];
		ch['I'-'A']-=ch['F'-'A'];
		ch['F'-'A']-=ch['F'-'A'];
		a[9]+=ch['I'-'A'];
		ch['N'-'A']-=ch['I'-'A'];
		ch['E'-'A']-=ch['I'-'A'];
		ch['N'-'A']-=ch['I'-'A'];
		ch['I'-'A']-=ch['I'-'A'];
		printf("Case #%d: ",id);
		for (int i=0; i<10; i++)
		  for (int j=1; j<=a[i]; j++)
		    printf("%d",i);
		printf("\n");
	}
	return 0;
}
