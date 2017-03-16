#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <gmpxx.h>

using namespace std;

// 0.1M is enough
mpz_class rNums[100000];
int rncnt = 0;
char curNumStr[233];
char tmp[233];
int maxDigit = 0;
int dfs(int cur,int csum,int start=0)
{
	if(csum > 9) return 0;
	int mid = (maxDigit+1)/2;
	if(cur == mid)
	{
		strcpy(tmp,curNumStr);
		strcat(tmp,curNumStr);
		reverse(tmp+mid,tmp+maxDigit);
		tmp[maxDigit] = 0;
		rNums[rncnt++] = mpz_class(tmp);
		return 0;
	}
	for(int i = start;i < 4;i++)
	{
		int nsum = csum+i*i;
		if(!(maxDigit % 2 == 1 && cur == mid-1)) nsum += i*i;
		curNumStr[cur] = '0'+i;
		dfs(cur+1,nsum);
		curNumStr[cur] = 0;
	}
	return 0;
}

int precalc(int digiLimit)
{
	//fprintf(stderr,"[+] Generating all \"super-squared\" palindrome numbers...\n");
	for(int i = 1;i <= digiLimit;i++)
	{
		int ocnt = rncnt;
		maxDigit = i;
		dfs(0,0,1);
		//fprintf(stderr,"[+] Found %d numbers with %d digits.\n",rncnt-ocnt,i);
	}
	//fprintf(stderr,"[+] Done! In total %d numbers found.\n",rncnt);
	//fprintf(stderr,"[x] Sorting and squaring...");
	sort(rNums,rNums+rncnt);
	for(int i = 0;i < rncnt;i++) rNums[i] = rNums[i]*rNums[i];
	//fputs("Done.\n",stderr);
	return 0;
}

int main(void)
{
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.out","wt",stdout);
	precalc(50);
	int T = 0;
	scanf("%d",&T);
	int TK = 0;
	while(T--)
	{
		printf("Case #%d: ",++TK);
		mpz_class l;
		mpz_class r;
		cin >> l >> r;
		printf("%d\n",upper_bound(rNums,rNums+rncnt,r)-lower_bound(rNums,rNums+rncnt,l));
	}
	return 0;
}
