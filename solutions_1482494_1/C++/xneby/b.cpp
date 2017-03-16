#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

const int N = 1007;

int A[N];
int B[N];
bool ozn[N];

int test(){
	int n;
	scanf("%d", &n);
	set<P> prz;
	vector<P> zd;

	for(int i=1; i<=n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		ozn[i] = false;
		A[i] = a;
		B[i] = b;
		zd.push_back(P(a,i));
		zd.push_back(P(b,-i));
	}
	sort(zd.begin(), zd.end());

	int gw = 0;
	int wy = 0;
	
	vector<P>::iterator it = zd.begin();

	while(gw < 2*n){
		if(it->first > gw){
			if(prz.empty()) return -1;
			P x = *prz.begin();
			prz.erase(prz.begin());
			wy ++;
			gw ++;
			ozn[x.second] = true;
//			printf("z prz %d\n", x.second);
		} else {
			if(it->second > 0){
				if(!ozn[it->second])
				prz.insert(P(-B[it->second], it->second));
//				printf("na prz %d\n", it->second);
			} else {
				gw += 2;
				if(ozn[-it->second]) gw --;
				ozn[-it->second] = true;
				prz.erase(P(-B[-it->second], -it->second));
//				printf("robię %d\n", -it->second);
			}
			it++;
		}
//		printf("gwiazdki %d\n", gw);
	}

	return n+wy;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		int w = test();
		if(w<0){
			printf("Case #%d: Too Bad\n", i);
		} else {
			printf("Case #%d: %d\n", i, w);
		}
	}	
}
