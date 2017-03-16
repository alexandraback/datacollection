#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

vector<int> V;
long long int num[11000000];

int main() {

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	long long int n,i,a,b,a_sq;
	int t,T,j,V_n;
	bool chk;

	for(i=1 ; i<=10000000 ; i++) {	// solve start.
		for(n=i,V.clear() ; n>0 ; n/=10) V.push_back(n%10);
		for(j=0,chk=true,V_n=V.size()-1 ; j<=V_n/2 ; j++) {
			if(V[j]!=V[V_n-j]) {
				chk=false;
				break;
			}
		}

		if(chk) {
			for(n=i*i,V.clear() ; n>0 ; n/=10) V.push_back(n%10);
			for(j=0,chk=true,V_n=V.size()-1 ; j<=V_n/2 ; j++) {
				if(V[j]!=V[V_n-j]) {
					chk=false;
					break;
				}
			}
		}

		if(chk) num[i]=num[i-1]+1;
		else num[i]=num[i-1];
	}	// solve end.


	scanf("%d", &T);

	for(t=1 ; t<=T ; t++) {
		scanf("%lld %lld", &a, &b);

		a_sq=(int)sqrt((double)a);
		a=(a_sq*a_sq<a)?a_sq+1:a_sq;

		b=(int)sqrt((double)b);

		printf("Case #%d: %lld\n", t, num[b]-num[a-1]);
	}

	return 0;
}