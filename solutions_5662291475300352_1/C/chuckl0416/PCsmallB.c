#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TCC, TC;
long long int Groups, S, H, T, People;
long long int Start[10];
long long int Time[10];
long long int i, x, y, Ans, Key, FAns;

int main(){
	freopen("C-small-2-attempt0.in", "r", stdin);
	freopen("C-small-2-attempt0.out", "w", stdout);
	
	scanf("%d", &TCC);
	for (TC=1; TC<=TCC; TC++){
		printf("Case #%d: ", TC);
		People = 0;
		scanf("%lld", &Groups);
		for (i=0; i<Groups; i++){
			scanf("%lld%lld%lld", &S, &H, &T);
			for (x=0; x<H; x++){
				Start[People+x] = S;
				Time[People+x] = T+x;
			}
			People += H;
		}
		
		if (People==1){
			puts("0");
			continue;
		}
		
		for (x=0; x<People; x++) for (y=x+1; y<People; y++) if (Start[x]>Start[y]){
			Key = Start[x];
			Start[x] = Start[y];
			Start[y] = Key;
			Key = Time[x];
			Time[x] = Time[y];
			Time[y] = Key;
			
		}
		
		FAns = 0;
		for (x=0; x<People; x++) for (y=x+1; y<People; y++){
			if (Time[x]>=Time[y]){
				if ( (360-Start[x])*(Time[x]) >= (720-Start[y])*(Time[y]) ) FAns++;
			}
			if (Time[x]<Time[y]){
				if ( (360-Start[y])*(Time[y]) >= (720-Start[x])*(Time[x]) ) FAns++;
			}
			
		}
		
		printf("%lld\n", FAns);
		
		
		
	}
	
	return 0;
}

