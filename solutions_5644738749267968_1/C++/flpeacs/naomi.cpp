#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	int t, cases, n, x, p1, p2, i;
	double aux;
	deque<double> vet1, vet2, vet3, vet4;

	scanf("%d", &t);

	for(cases = 1; cases <= t; cases++){
		p1 = 0; p2 = 0;
		scanf("%d", &n);

		for(i = 0; i < n; i++){
			scanf("%lf", &aux);
			vet1.push_back(aux);
			vet3.push_back(aux);	
		}

		for(i = 0; i < n; i++){
			scanf("%lf", &aux);
			vet2.push_back(aux);
			vet4.push_back(aux);	
		}

		sort(vet1.begin(), vet1.end());
		sort(vet2.begin(), vet2.end());
		sort(vet3.begin(), vet3.end());
		sort(vet4.begin(), vet4.end());

		for(i = 0; i < n; i++){
			if(vet1.back() > vet2.back()){
				vet1.pop_back();
				vet2.pop_front();
				p1++; 
			} else {
				vet1.pop_back();
				vet2.pop_back();
			}
		}

		p2 = 0;

		for(i = 0; i < n; i++){
			if(vet3.back() > vet4.back()){
				p2++;
				vet3.pop_back();
				vet4.pop_back();
			} else {
				vet3.pop_front();
				vet4.pop_back();
			}				
		}
	
		printf("Case #%d: %d %d\n", cases, p2, p1);
	}
}
