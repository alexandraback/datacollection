#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> naomi;
vector<double> ken;
int main (int argc, char *argv[])
{
	int TC;
	scanf("%d", &TC);
	
	for(int c = 1; c <= TC; c++){
		naomi.clear();
		ken.clear();
		int N;
		scanf("%d", &N);
		
		double a;
		for(int i = 0; i < N; i++){
			scanf("%lf", &a);
			naomi.push_back(a);
		}
		for(int i = 0; i < N; i++){
			scanf("%lf", &a);
			ken.push_back(a);
		}
		sort(ken.begin(), ken.end());
		sort(naomi.begin(), naomi.end());
		
		int ansW = 0;
		int index = N - 1;
		for(int i = N - 1; i >= 0 && index >= 0; i--){
			while(index >= 0 && ken[i] < naomi[index]){
				index--;	
			}
			if(index != -1) ansW++;
			index--;
		}
		ansW = N - ansW;
		
		int ansD = 0;
		index = 0;
		for(int i = 0; i < N && index < N; i++){
			while(index < N && ken[i] > naomi[index]){
				index++;
			}
			if(index != N) ansD++;
			index++;
		}
		
		printf("Case #%d: %d %d\n", c, ansD, ansW);
	}
	
	return 0;
}

