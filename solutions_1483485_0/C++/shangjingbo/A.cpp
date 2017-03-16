#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

const char input[3][100]=
{
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
 	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
const char output[3][100]=
{
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up",
};

char f[300];

int main()
{
	f['z']='q';
	f['q']='z';
	for (int i=0;i<3;++i){
		for (int j=0;input[i][j];++j)
		if (input[i][j]>='a' && input[i][j]<='z'){
			f[input[i][j]]=output[i][j];
		}
	}
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	
	int T,test=1;
	for (scanf("%d\n",&T);test<=T;++test){
		char s[105];
		gets(s);
		for (int i=0;s[i];++i) if (s[i]>='a' && s[i]<='z'){
			s[i]=f[s[i]];
		}
		printf("Case #%d: %s\n",test,s);
	}
	return 0;
}

