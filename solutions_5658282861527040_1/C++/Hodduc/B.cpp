#include<stdio.h>
#include<memory.h>
long long A, B, C;
long long d[100][2][2][2];
void proc(long long i, int Ba, int Bb, int Bc, long long al, long long bl, long long cl, long long refv)
{
	if(refv == 0) return;
	if ( i == 2)
		i = i;

	for(long long aa = 0; aa <= al; aa++)
	for(long long bb = 0; bb <= bl; bb++)
	{
		if((aa & bb) > cl) continue;
		d[i][(aa==al)&Ba][(bb==bl)&Bb][((aa&bb)==cl)&Bc] += refv;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%lld %lld %lld", &A, &B, &C);
		A--; B--; C--;
		memset(d, 0, sizeof(d));
		d[32][1][1][1] = 1;
		for(long long i = 31, BIT = (1LL << 31); i >= 0; i--, (BIT>>=1)){
			long long AL, BL, CL;
			AL = (A&BIT) ? 1 : 0;
			BL = (B&BIT) ? 1 : 0;
			CL = (C&BIT) ? 1 : 0;

			proc(i, 1, 1, 1, AL, BL, CL, d[i+1][1][1][1]);
			proc(i, 1, 1, 0, AL, BL, 1, d[i+1][1][1][0]);
			proc(i, 1, 0, 1, AL, 1, CL, d[i+1][1][0][1]);
			proc(i, 1, 0, 0, AL, 1, 1, d[i+1][1][0][0]);
			proc(i, 0, 1, 1, 1, BL, CL, d[i+1][0][1][1]);
			proc(i, 0, 1, 0, 1, BL, 1, d[i+1][0][1][0]);
			proc(i, 0, 0, 1, 1, 1, CL, d[i+1][0][0][1]);
			proc(i, 0, 0, 0, 1, 1, 1, d[i+1][0][0][0]);
			//printf("%lld %lld %lld\n", AL, BL, CL);
			//printf("%lld %lld %lld %lld %lld %lld %lld %lld\n", d[i][0][0][0] , d[i][0][0][1] , d[i][0][1][0] , d[i][0][1][1] , d[i][1][0][0] , d[i][1][0][1] , d[i][1][1][0] , d[i][1][1][1]);
		}

		long long s = d[0][0][0][0] + d[0][0][0][1] + d[0][0][1][0] + d[0][0][1][1] + d[0][1][0][0] + d[0][1][0][1] + d[0][1][1][0] + d[0][1][1][1];
		printf("Case #%d: %lld\n", t, s);
	}
	return 0;
}
