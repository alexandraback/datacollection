#include <bits/stdc++.h>
using namespace std;
string s;
char ss[5000];
int cnt[500];
int v[10];
void de(int x,int y){
	cnt[x]-=cnt[y];
}
int main()
{

	freopen("ina.txt","r",stdin);
	freopen("outa.txt","w",stdout);
	int T,ca=0;
	scanf("%d",&T);
	while(T--){
		scanf("%s",ss);
		int n=strlen(ss);
		for (int i=0;i<n;i++)
			cnt[ss[i]]++;
		v[0]=cnt['Z'];
		de('E','Z');
		de('R','Z');
		de('O','Z');
		de('Z','Z');
		v[6]=cnt['X'];
		de('S','X');
		de('I','X');
		de('X','X');
		v[7]=cnt['S'];
		de('E','S');
		de('V','S');
		de('E','S');
		de('N','S');
		de('S','S');
		v[5]=cnt['V'];
		de('F','V');
		de('I','V');
		de('E','V');
		de('V','V');
		v[4]=cnt['F'];
		de('O','F');
		de('U','F');
		de('R','F');
		de('F','F');
		v[8]=cnt['G'];
		de('I','G');
		de('H','G');
		de('T','G');
		de('E','G');
		de('G','G');
		v[3]=cnt['R'];
		de('E','R');
		de('E','R');
		de('H','R');
		de('T','R');
		de('R','R');
		v[2]=cnt['T'];
		de('O','T');
		de('W','T');
		de('T','T');
		v[9]=cnt['I'];
		de('N','I');
		de('N','I');
		de('E','I');
		de('I','I');
		v[1]=cnt['O'];
		de('N','O');
		de('E','O');
		de('O','O');
		printf("Case #%d: ", ++ca);
		for (int i=0;i<10;i++)
			for (int j=0;j<v[i];j++)
				printf("%d", i);
		puts("");
		for (int i=0;i<n;i++)
			cnt[ss[i]]=0;
	}
}