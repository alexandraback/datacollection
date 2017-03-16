#include <stdio.h>
#include <string.h>
#include <algorithm>
// 0 1 2 3 4 5 6 7 8 9
// Z O W H U F X S G I
void solve(int);
int main()
{
	freopen("inputA1.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) solve(i);
}

char x[2010];
int count[30];
int ans[2010];
void solve(int T)
{
	int a;
	int t = 0;
	for(int i=0;i<=2000;i++) ans[i] = -1;
	scanf("%s",x+1);
	a = strlen(x+1);
	for(int i=1;i<=a;i++) count[x[i]-'A']++;
	
	//0
	for(int i=1;i<=count['Z'-'A'];i++) ans[i] = 0;
	count['E'-'A'] -= count['Z'-'A'];
	count['R'-'A'] -= count['Z'-'A'];
	count['O'-'A'] -= count['Z'-'A'];
	
	t += count['Z'-'A'];
	count['Z'-'A'] = 0;
	
	//2
	for(int i=t+1;i<=t+count['W'-'A'];i++) ans[i] = 2;
	count['T'-'A'] -= count['W'-'A'];
	count['O'-'A'] -= count['W'-'A'];
	
	t += count['W'-'A'];
	count['W'-'A'] = 0;
	
	//4
	for(int i=t+1;i<=t+count['U'-'A'];i++) ans[i] = 4;
	count['F'-'A'] -= count['U'-'A'];
	count['O'-'A'] -= count['U'-'A'];
	count['R'-'A'] -= count['U'-'A'];
	
	t += count['U'-'A'];
	count['U'-'A'] = 0;
	
	//6
	for(int i=t+1;i<=t+count['X'-'A'];i++) ans[i] = 6;
	count['S'-'A'] -= count['X'-'A'];
	count['I'-'A'] -= count['X'-'A'];
	
	t += count['X'-'A'];
	count['X'-'A'] = 0;
	
	//8
	for(int i=t+1;i<=t+count['G'-'A'];i++) ans[i] = 8;
	count['E'-'A'] -= count['G'-'A'];
	count['I'-'A'] -= count['G'-'A'];
	count['H'-'A'] -= count['G'-'A'];
	count['T'-'A'] -= count['G'-'A'];
	
	t += count['G'-'A'];
	count['G'-'A'] = 0;
	
	//1
	for(int i=t+1;i<=t+count['O'-'A'];i++) ans[i] = 1;
	count['N'-'A'] -= count['O'-'A'];
	count['E'-'A'] -= count['O'-'A'];
	
	t += count['O'-'A'];
	count['O'-'A'] = 0;
	
	//3
	for(int i=t+1;i<=t+count['H'-'A'];i++) ans[i] = 3;
	count['T'-'A'] -= count['H'-'A'];
	count['R'-'A'] -= count['H'-'A'];
	count['E'-'A'] -= count['H'-'A'];
	count['E'-'A'] -= count['H'-'A'];
	
	t += count['H'-'A'];
	count['H'-'A'] = 0;
	
	//5
	for(int i=t+1;i<=t+count['F'-'A'];i++) ans[i] = 5;
	count['I'-'A'] -= count['F'-'A'];
	count['V'-'A'] -= count['F'-'A'];
	count['E'-'A'] -= count['F'-'A'];
	
	t += count['F'-'A'];
	count['F'-'A'] = 0;
	
	//7
	for(int i=t+1;i<=t+count['S'-'A'];i++) ans[i] = 7;
	count['E'-'A'] -= count['S'-'A'];
	count['V'-'A'] -= count['S'-'A'];
	count['E'-'A'] -= count['S'-'A'];
	count['N'-'A'] -= count['S'-'A'];
	
	t += count['S'-'A'];
	count['S'-'A'] = 0;
	
	//9
	for(int i=t+1;i<=t+count['I'-'A'];i++) ans[i] = 9;
	count['N'-'A'] -= count['I'-'A'];
	count['N'-'A'] -= count['I'-'A'];
	count['E'-'A'] -= count['I'-'A'];
	
	t += count['I'-'A'];
	count['I'-'A'] = 0;
	
	std::sort(ans+1,ans+t+1);
	printf("Case #%d: ",T);
	for(int i=1;i<=t;i++) printf("%d",ans[i]);
	printf("\n");
}
