#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char a[5][5];
int s[256];

int judge()
{
	for (int i=1; i<=4; i++)
	{
		s['X']=s['O']=s['T']=s['.']=0;
		for (int j=1; j<=4; j++) s[a[i][j]]++;
		if (s['X']==4||(s['X']==3&&s['T']==1)) return 1;		
		if (s['O']==4||(s['O']==3&&s['T']==1)) return 2; 
		s['X']=s['O']=s['T']=s['.']=0;
		for (int j=1; j<=4; j++) s[a[j][i]]++;
		if (s['X']==4||(s['X']==3&&s['T']==1)) return 1;		
		if (s['O']==4||(s['O']==3&&s['T']==1)) return 2;
	}
	s['X']=s['O']=s['T']=s['.']=0;
	for (int i=1; i<=4; i++) s[a[i][i]]++;
	if (s['X']==4||(s['X']==3&&s['T']==1)) return 1;		
	if (s['O']==4||(s['O']==3&&s['T']==1)) return 2;
	s['X']=s['O']=s['T']=s['.']=0;
	for (int i=1; i<=4; i++) s[a[i][5-i]]++;
	if (s['X']==4||(s['X']==3&&s['T']==1)) return 1;		
	if (s['O']==4||(s['O']==3&&s['T']==1)) return 2;
	for (int i=1; i<=4; i++)
		for (int j=1; j<=4; j++) if (a[i][j]=='.') return 0;
	return -1;
}

void doit()
{
	for (int i=1; i<=4; i++) scanf("%s",a[i]+1);
	int t=judge();
	if (t==1) printf("X won\n");
	else if (t==2) printf("O won\n");
	else if (t==0) printf("Game has not completed\n");
	else printf("Draw\n");
}

int main()
{
	//freopen("A.in","r",stdin);
	//freopen("aa.out","w",stdout);
	int T,i;
	for (scanf("%d",&T),i=1; i<=T; i++) printf("Case #%d: ",i),doit();
	return 0;
}
