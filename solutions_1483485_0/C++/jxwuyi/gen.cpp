#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<complex>
#include<numeric>
using namespace std;

string input[]={"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string output[]={"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};

int idx[256], rep[256];
char buf[256];

int main()
{
	int mask = (1 << 26) - 1;
	idx['a']='y';
	idx['o']='e';
	idx['z']='q';
	mask ^= 1 << 'y' - 'a';
	mask ^= 1 << 'e' - 'a';
	mask ^= 1 << 'q' - 'a';
	for(int i=0;i<3;++i)
		for(int j=0;j<input[i].size();++j) {
			idx[input[i][j]]=output[i][j];
			mask &=~(1 << output[i][j] - 'a');
		}
	idx['q'] = __builtin_ctz(mask) + 'a';
	
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int test;
	sscanf(gets(buf), "%d", &test);
	for(int no=1;no<=test;++no)
	{
		gets(buf);
		int l = strlen(buf);
		printf("Case #%d: ",no);
		for(int j=0;j<l;++j)
			putchar(char(idx[buf[j]]));
		puts("");
	}
}
