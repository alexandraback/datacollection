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
int N,X,Y,T;

int main(){
	int i,j,k,tt,a,b,S;
	long long res,cur;
	scanf("%d",&T);
	for(tt=1; tt<=T;tt++){
		printf("Case #%d: ",tt);
		res = 0;
		scanf("%d %d", &X ,&Y);
		while(X != 0)
		{
			if(X>0)
			{
				printf("WE");
				X--;
			}
			else
			{
				printf("EW");
				X++;
			}
			res++;
		}

		while(Y != 0)
		{
			if(Y>0)
			{
				printf("SN");
				Y--;
			}
			else
			{
				printf("NS");
				Y++;
			}
			res++;
		}
		puts("");
		if(res >500)
			puts("ERROR");
	}
	return 0;
}
