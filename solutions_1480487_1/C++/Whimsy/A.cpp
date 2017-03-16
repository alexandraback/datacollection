#include<iostream>
#include<cstdio>

using namespace std;

int Test;
int n;
int a[400];
int bo[400];

void work(){
	cin >> n;
	double tot = 0;

	for (int i = 0;i<n;++i){
		cin >> a[i];
		tot += a[i];
		bo[i] = 0;
	}
	double tmp = tot;
	tot = tot * 2;
	int div = n;
	for (int k = 1;k<=n;++k){
		for (int i = 0;i<n;++i){
			if (bo[i] == 0 && a[i]>=tot / div){
				bo[i] = 1;
				tot -= a[i];
				--div;
				break;
			}
		}
	}
	double zero = 0.0;
	double avg = tot/div;
//	cout << avg << endl;
	for (int i = 0;i<n;++i){
		if (bo[i] == 1){
			printf("%.6lf ",zero*100);
		} else {
			printf("%.6lf ",(avg-a[i])/tmp*100 );
		}
	}
	printf("\n");
	
}

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin >> Test;
	for (int ii = 0;ii<Test;++ii){
		printf("Case #%d: ",ii+1); 
		work();
	}
	return 0;
}
