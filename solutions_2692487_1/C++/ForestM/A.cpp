#include "stdio.h"
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;

ll boa[101];
int N;
ll Ans[101];

int findAns(int &A, int s) {
	if(s+1-A<A) {A = 2*A-1;
		return 1;}
	A = 2*A-1;
	return findAns(A, s)+1;
}

ll findN(ll A) {
	ll ans=0;
	while(A!=0) {
		++ans;
		A=A>>1;
	}
	return ans-1;
}
ll find2N(ll N) {
	ll ret=1;
	for(ll i=0; i<N; ++i)
		ret=ret<<1;
	return ret;
}
ll findAns2(ll &A, ll s) {
	ll ans2=2*(s-1)/(A-1);
	ll ans=findN(ans2);
	A = find2N(ans)*(A-1)+1;
	return ans;
}
int calc(int &A, int i) {
	int ans=0;
	int tmp;
	for(int j=i; j<N; ++j) {
		if(A<=boa[j]) {
			if(A==1) {
				ans+=N-j; break;
			}
			tmp = findAns(A, boa[j]);
			ans+=tmp;
		}
		A+=boa[j];
	}
	return ans;
}
int main() {
	FILE *fp, *fp2;
	int num;
	ll A;

	ll ans;
	ll tmp;

	fopen_s(&fp, "A-large.in", "r");
	fopen_s(&fp2, "A-large.out", "w");
	fscanf_s(fp, "%d", &num);

	for(int i=0; i<num; ++i) {
		fprintf(fp2,"Case #%d: ",i+1);
		fscanf_s(fp,"%lld %d", &A, &N);

		for(int j=0; j<N; ++j)
			fscanf_s(fp, "%lld", &boa[j]);
		sort(boa, boa+N);

//		ans = 0;
//		int tmp2;
		if(A<=1) {fprintf(fp2, "%d\n", N);continue;}
		for(int j=0; j<N; ++j) {
			Ans[j]=0;
			if(A<=boa[j]) {
				Ans[j]=findAns2(A, boa[j]);
			}
/*			tmp = calc(A,j);
			if(tmp<N-j) ans+=tmp;
			if(A<=boa[j]) {
				if(A==1) {
					ans+=N-j; break;
				}
				tmp = findAns(A, boa[j]);
				if(tmp<N-j) ans+=tmp;
				else {ans+=(N-j);break;}
			}*/
			A+=boa[j];
		}

		ll fin=N;
		ll sum=0;
		for(int j=0; j<N;++j) {
			sum += Ans[j];
			if(sum+N-j-1 < fin) {
				fin = sum+N-j-1;
			}
		}
		fprintf(fp2, "%lld\n", fin);
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}
