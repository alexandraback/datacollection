#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int pendientes[1000];
int fin;
int N,S,P;		
int ans;
void procesa(int n)
{
	if ( n == 0 )
	{
		if ( P == 0 ) ans++;
		return;
	}
	int c = n/3;
	double r = (double)n/3;
	if (r>c && r < c+0.5){
		if ( c + 1 >= P )
			ans++;
	}else if(r>c+0.5){
		if ( c + 1 >= P )
			ans++;
		else if ( S > 0 && c+2 >= P ){
			ans++;
			S--;
		}
	}else{
		if ( c >= P )
			ans++;
		else if ( S > 0 && c+1 >= P ){
			ans++;
			S--;
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		fin = 0;
		ans = 0;
		int temp;		
		scanf("%d %d %d",&N,&S,&P);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&temp);
			procesa(temp);			
		}	
		printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}