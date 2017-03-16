#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int main()
{
	freopen("in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i,j,k, TC, T, A,B,K;
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
        cin>>A>>B>>K;
        int res=0;
        for(i=0;i<A;i++)
            for(j=0;j<B;j++)
                if((i&j)<K)
                    res++;
		printf("%d\n", res);
	}
	return 0;
}
