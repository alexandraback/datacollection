#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
bool check(ll p, ll q){
	int i = 0;
	double res = ((double)p / q);
	while(i < 40){
		res *= 2;
		i++;
	}
//	printf("%lf   ",res);
//	printf("aici-sa %lld\n",(ll)(res * 1E6) % (ll)1E6);
	if((ll)(res * 1E6) % (ll)1E6 != 0)
		return false;
	return true;
}
int solve(ll p,ll q){
	double res = ((double)p / q);
	int i = 0;
	if(check(p,q) == true){
		while(i < 40 && res < 1){
			res *= 2;
			i++;
		}
		return i;
	}
	else
		return -1;

}

void read(){
	int t;
	scanf("%d",&t);
	ll p,q;
	for(int i = 0; i < t; i++)
	{
		scanf("%lld",&p);
		getchar();
		scanf("%lld",&q);
		int value = solve(p,q);
		if(value == -1)

			printf("Case #%d: impossible\n",i + 1);
		else
			printf("Case #%d: %d\n",i + 1,value);

	}

}

int main(){
	freopen("f.txt","r",stdin);
	freopen("fout.txt","w",stdout);
	read();

	return 0;
}