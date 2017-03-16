#include<stdio.h>
#include<algorithm>
#include<memory.h>
FILE *in = fopen("A-small-attempt1.in", "r");
FILE *out= fopen("output.txt", "w");

int main()
{
	int cn, T, ans, list[110];
	int i, j, A, N, s, cnt;
	fscanf(in, "%d", &T);
	for(cn = 1; cn <= T; cn++){
		ans = 0;
		fscanf(in, "%d%d", &A, &N);
		for(i = 1; i <= N; i++)
			fscanf(in, "%d", &list[i]);
		if(A == 1) ans = N;
		else{
			std::sort(list+1, list+N+1);
			ans = 10000;
			for(i = 0; i <= N; i++){
				cnt = 0;
				s = A;
				for(j = 1; j <= i; j++){
					if(s > list[j]){
						s += list[j];
					}
					else{
						while(1){
							s = s + s - 1;
							cnt++;
							if(s > list[j]){
								s += list[j];
								break;
							}
						}
					}
				}
				cnt += (N - i);
				if(ans > cnt) ans = cnt;
			}
		}
		fprintf(out, "Case #%d: %d\n", cn, ans);
	}
}