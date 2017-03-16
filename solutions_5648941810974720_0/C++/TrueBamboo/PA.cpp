#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#include<fstream>
FILE *fin=freopen("a.in","r",stdin);
FILE *fout=freopen("a.out","w",stdout);

string s[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string input;
int c[26],i,j,ans[10];

int main() {
	int T,t;
	cin>>T;
	for (t=1;t<=T;t++) {
		cin>>input;
		memset(c,0,sizeof(c));
		for (i=0;i<input.length();i++)
		c[input[i]-'A']++;
		memset(ans,0,sizeof(ans));
		//only 6 has X
		ans[6]=c['X'-'A'];
		c['S'-'A']-=c['X'-'A'];
		c['I'-'A']-=c['X'-'A'];
		c['X'-'A']=0;
		//only 0 has Z
		ans[0]=c['Z'-'A'];
		c['E'-'A']-=c['Z'-'A'];
		c['R'-'A']-=c['Z'-'A'];
		c['O'-'A']-=c['Z'-'A'];
		c['Z'-'A']=0;
		//only 2 has W
		ans[2]=c['W'-'A'];
		c['T'-'A']-=c['W'-'A'];
		c['O'-'A']-=c['W'-'A'];
		c['W'-'A']=0;
		//only 4 has U
		ans[4]=c['U'-'A'];
		c['F'-'A']-=c['U'-'A'];
		c['O'-'A']-=c['U'-'A'];
		c['R'-'A']-=c['U'-'A'];
		c['U'-'A']=0;
		//only 5 has F
		ans[5]=c['F'-'A'];
		c['I'-'A']-=c['F'-'A'];
		c['V'-'A']-=c['F'-'A'];
		c['E'-'A']-=c['F'-'A'];
		c['F'-'A']=0;
		//only 8 has G
		ans[8]=c['G'-'A'];
		c['E'-'A']-=c['G'-'A'];
		c['I'-'A']-=c['G'-'A'];
		c['H'-'A']-=c['G'-'A'];
		c['T'-'A']-=c['G'-'A'];
		c['G'-'A']=0;
		//now only 7 has V
		ans[7]=c['V'-'A'];
		c['S'-'A']-=c['V'-'A'];
		c['E'-'A']-=2*c['V'-'A'];
		c['N'-'A']-=c['V'-'A'];
		c['V'-'A']=0;
		//now only 1 has O
		ans[1]=c['O'-'A'];
		c['N'-'A']-=c['O'-'A'];
		c['E'-'A']-=c['O'-'A'];
		c['O'-'A']=0;
		//now only 3 has R
		ans[3]=c['R'-'A'];
		c['T'-'A']-=c['R'-'A'];
		c['H'-'A']-=c['R'-'A'];
		c['E'-'A']-=2*c['R'-'A'];
		c['R'-'A']=0;
		//now 9 is left
		ans[9]=c['I'-'A'];
		printf("Case #%d: ",t);
		for (i=0;i<10;i++)
		for (j=0;j<ans[i];j++)
		printf("%d",i);
		printf("\n");
	}
    return 0;
}

