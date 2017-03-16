#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int LIM = 1000000;
vector<int> levels;
vector< vector<double> > pascal;

int main(){
	levels.push_back(1);
	for(int i=3; levels[levels.size()-1] <= LIM; i+=2){
		levels.push_back( (i*(i+1))/2 );
	}
	vector<double> first;
	first.push_back(0.5);
	first.push_back(0.5);
	pascal.push_back(first);
	for(int i=0; i<2830; i++){
		vector<double> cur = pascal[i];
		vector<double> next;
		for(int j=0; j<cur.size(); j++){
			if(j == 0){
				next.push_back(cur[j]/2);
				next.push_back(cur[j]/2);
			}else{
				next[j] += cur[j]/2;
				next.push_back(cur[j]/2);
			}
		}
		pascal.push_back(next);
	}
	
	int cases;
	scanf("%d", &cases);
	for(int z=1; z<=cases; z++){
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		if( (abs(x)+abs(y))%2 != 0){
			printf("Case #%d: 0.0\n", z);
			continue;
		}
		int layer = (abs(x)+abs(y))/2;
		int b = layer*2+1;
		if( (b*(b+1))/2 <= n ){
			printf("Case #%d: 1.0\n", z);
		}else if( ((b-1)*(b-2))/2 >= n){
			printf("Case #%d: 0.0\n", z);
		}else{
			int diff = n - ((b-1)*(b-2))/2;
			vector<double> check = pascal[diff-1];
			y++;
			if(diff >= b+y-1){
				printf("Case #%d: 1.0\n", z);
			}else if(x == 0){
				printf("Case #%d: 0.0\n", z);
			}else{
				int top = diff;
				double ans = 0;
				for(int i=0; i<check.size() && top >= y; i++, top--){
					ans += check[i];
				}
				double ansb = round(ans*100);
				if(ans == ansb){
					printf("Case #%d: %.2f\n", z, ans);
				}else{
					printf("Case #%d: %g\n", z, ans);
				}
			}
		}
	}
}