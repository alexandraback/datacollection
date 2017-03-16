#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int MAXN = 1000;

int compare (const void * a, const void * b)
{
	double diff = *(double*)a - *(double*)b;
	return (diff > 0 ? 1 : (diff < 0 ? -1 : 0));
}

int n;
double naomi[MAXN], ken[MAXN];

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		printf("Case #%d: ", t+1);
		cin >> n;
		for(int i=0; i<n; i++)
			scanf("%lf", &naomi[i]);
		for(int i=0; i<n; i++)
			scanf("%lf", &ken[i]);
		qsort(naomi, n, sizeof(double), compare);
		qsort(ken, n, sizeof(double), compare);
		int y = 0, z = 0;
		int p_low = 0, p_high = n-1;
		for(int i=0; i<n; i++){
			if (naomi[i] > ken[p_low]){
				p_low++;
				y++;
			} else
				p_high--;
		}
		p_high = n-1, p_low = 0;
		for(int i=n-1; i>=0; i--){
			if (naomi[i] > ken[p_high]){
				p_low++;
				z++;
			} else
				p_high--;
		}
		cout << y << ' ' << z << endl;
	}
}

