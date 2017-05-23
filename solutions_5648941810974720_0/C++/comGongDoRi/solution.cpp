#include <stdio.h>

FILE* in=fopen("A-small-attempt0.in","r");
FILE* out=fopen("out.txt","w");

void solve()
{
	int i,ch[200]={},num[10]={};
	char *c,A[2001];
	fscanf(in,"%s",A);
	for(c=A;*c;c++) ch[*c]++;
	num[0]=ch['Z'];
	num[2]=ch['W'];
	num[6]=ch['X'];
	num[8]=ch['G'];
	num[7]=ch['S']-num[6];
	num[5]=ch['V']-num[7];
	num[4]=ch['F']-num[5];
	num[3]=ch['H']-num[8];
	num[9]=ch['I']-num[8]-num[6]-num[5];
	num[1]=ch['O']-num[0]-num[2]-num[4];
	
	for(i=0;i<10;i++) while(num[i]--) fprintf(out,"%d",i);
	
	fprintf(out,"\n");
}

int main()
{
	int i,t;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fprintf(out,"Case #%d: ",i);
		solve();
	}
	return 0;
}
