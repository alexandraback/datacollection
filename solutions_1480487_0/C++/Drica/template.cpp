#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


pair<int, int> s[300];
int orig[300];
double resp[300];

int n;

int main() {
	int casos; scanf("%d", &casos);
	int caso = 0;
	while(casos--){
		double sum = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &s[i].first);
			s[i].second = i;
			sum += s[i].first;
			
			orig[i] = s[i].first;
		}
		double sum2 = 2.0*sum;
		double total = (2.0*sum)/n, r;
		sort(s, s+n, greater<pair<int, int> >());
		double aux;
		for(int i = 0; i < n; i++){
			if(s[i].first >= total){
				sum2 -= s[i].first;
				total = sum2/(n-i-1);
				resp[s[i].second] = 0.0;
			} else {
				resp[s[i].second] = ((double)(total-s[i].first)*100.0)/sum;
			}
			
		}
		 
		printf("Case #%d:", ++caso);
		for(int i = 0; i < n; ++i){
			printf(" %lf", resp[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}
