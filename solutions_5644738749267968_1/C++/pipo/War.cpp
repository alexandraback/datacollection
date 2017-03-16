#include <cstdio>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < n; i++)
#define forn1(i,n) for(int i = 1; i <= n; i++)
using namespace std;
vector<double> n,k;
int T,B;
int a(){
	int i=0, j=0;
	while(i < B && j < B){
		if(n[i] < k[j])
			i++;
		j++;
	}
	return B - i;
}
int b(){
	int i=0, j=0;
	while(i < B && j < B){
		if(n[i] > k[j])
			j++;
		i++;
	}
	return j;
}
int main(){

	double w;
	scanf("%d", &T);
	forn1(t,T){
		n.clear();
		k.clear();
		scanf("%d", &B);
		forn(i,B){
			scanf("%lf", &w);
			n.push_back(w);
		}
		forn(i,B){
			scanf("%lf", &w);
			k.push_back(w);
		}
		sort(n.begin(), n.end());
		sort(k.begin(), k.end());
		
		printf("Case #%d: %d %d\n", t, b(), a());
	}
	
	return 0;
}
