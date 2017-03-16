#include<stdio.h>
#include<string.h>

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.txt","w", stdout);

	int test;
	double oc = 0.0000001;
	scanf("%d", &test);
	for(int testCase = 1; testCase <= test; testCase++){
		printf("Case #%d: ", testCase);
		__int64 a=0, b=0, aa, bb, c;
		char inp[100] = {0,};
		double min, max, na;
		scanf("%s", &inp);

		for(int i = 0; i < strlen(inp); i++){
			if(inp[i] == '/'){
				for(int j = i+1; j < strlen(inp); j++){
					b = b*10 + (inp[j] - '0');
				}
				break;
			}
			a = a*10 + (inp[i] - '0');
		}
		if(a == b || a == 0){
			printf("0\n");
			continue;
		}
		if(a > b){
			printf("impossible\n");
			continue;
		}
		aa = a;
		bb = b;
		while(1){
			c = b % a;
			if(c == 0)break;
			b = a;
			a = c;
		}
		b = bb / a;
		a = aa / a;
		bb = b;
		int flag = 0;
		int i;
		for(i = 1; i <= 40; i++){
			if(b % 2 != 0){
				break;
			}
			b /= 2;
			if(b == 1) {
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			b = bb;
			na = min = max = double(a)/b;
			for(int cnt = 1; ; cnt++){
				min = min*2 - 1;
				max = max*2; 
				if(min-oc <= 1 && max+oc >= 1){
					printf("%d\n", cnt);
					break;
				}
				if(min-oc > 1){
					printf("%d\n", cnt);
				}
			}
		}
		else{
			printf("impossible\n");
		}
		
	}

}