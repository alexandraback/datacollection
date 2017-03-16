#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#define MaxLength INT_MAX
#define MaxNode 12
#define MN 1000005
using namespace std;

int D,T,N,H,A,X,Y,L;
char vowels[5] = {'a','e', 'i', 'o', 'u'};
char mem[MN];
int dp[MN];
int s[MN],d[MN];
int main(){
	int i,j,k,tt,a,b,S;
	long long res,cur;
	scanf("%d",&T);
	for(tt=1; tt<=T;tt++){
		memset(s,0,sizeof(s));
		memset(d,0,sizeof(d));
		S = res = cur = 0;

		scanf("%s %lld", &mem ,&N);
		//puts("");
		L = strlen(mem);
		for(i=0; i< L; i++)
		{
			
			bool vowel = false;
			for(j=0; j<5;j++)
				if(vowels[j] == mem[i])
					vowel = true;
			if(vowel)
				cur = 0;
			else
				cur++;

			//printf("S = %d\n",S);
			if(cur >=N)
			{
				res += max(0,(i-N+2) - S) +  max(1,i-N+2 - S) * max(0,L-i-1);
				//for(j=0; j<L; j++)
				//	printf(" %d",s[j]);
				//puts("");
				//printf("%d += %d - %d + %d *%d\n",i,(i-N+2) , S , max(1,i-N+2 - S) , max(0,L-i-1));
				S = i-N+2;
			}
			
		}

		printf("Case #%d: %lld\n",tt,res);
	}
	return 0;
}
