#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
#define X first
#define Y second
#define RED 0
#define GREEN 1
#define BLUE 2
typedef long long LL;
//typedef __int128_t VL;
typedef long double LD;

#define ZERO 500
int height[1000];
int N;

struct attack{
	int day;
	int left;
	int right;
	int strength;
}attacks[1000];
int num_attacks;

inline bool cmp_day(attack a, attack b){
	return a.day < b.day;
}

int main(){
	int testy;
	scanf("%d", &testy);
	for(int t = 1; t <= testy; t++){
		fill(height, height+1000, 0);
		scanf("%d", &N);
		num_attacks = 0;
		for(int i = 0; i < N; i++){
			int d, n, w, e, s, delta_d, delta_p, delta_s;
			scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);
			for(int i = 0; i < n; i++){
				attacks[num_attacks].day = d;
				attacks[num_attacks].left = w;
				attacks[num_attacks].right = e-1;
				attacks[num_attacks].strength = s;
				
				d += delta_d;
				w += delta_p;
				e += delta_p;
				s += delta_s;
				
				num_attacks++;
			}
		}
		sort(attacks, attacks+num_attacks, cmp_day);
		
		int res = 0;
		for(int i = 0; i < num_attacks; i++){
			bool successful = false;
			for(int j = attacks[i].left+ZERO; j <= attacks[i].right+ZERO; j++){
//if(attacks[i].right==9){
//printf("%d\n", height[j+ZERO]);
//}
				if(height[j] < attacks[i].strength){
					successful = true;
				}
			}
			if(successful)
				res++;
//printf("%d %d %d %d\n", attacks[i].left, attacks[i].right, (int)successful, attacks[i].strength);
			if(attacks[i].day != attacks[i+1].day){
				int begin = i;
				while(begin > 0 && attacks[i].day==attacks[begin-1].day)
					begin--;
				for(int j = begin; j <= i; j++){
					for(int k = attacks[j].left+ZERO; k <= attacks[j].right+ZERO; k++)
						height[k] = max(height[k], attacks[j].strength);
				}
			}
		}
	
		printf("Case #%d: %d\n", t, res);
	}
	return 0;
}
