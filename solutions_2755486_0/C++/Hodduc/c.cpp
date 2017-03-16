#include<stdio.h>
#include<algorithm>
struct ATTACK{
	int time;
	int left, right;
	int strength;
	int fixed;
	bool friend operator <(ATTACK a, ATTACK b){
		return a.time < b.time;
	}
}attack[500];

int wall[500], N, A;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int cnt = 0;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%d", &N);
		A=0;
		int d, n, w, e, s, deld, delp, dels;
		memset(wall, 0, sizeof(wall));
		for(int k = 1; k <= N; k++){
			scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &deld, &delp, &dels);
			for(int i =0 ; i < n; i++){
				++A;
				attack[A].fixed = 0;
				attack[A].time = d;
				attack[A].left = w;
				attack[A].right = e;
				attack[A].strength = s;

				s += dels;
				d += deld;
				w += delp;
				e += delp;
			}
		}
		std::sort(attack+1, attack+1+A);
		cnt = 0;
		for(int i = 1; i <= A; i++){
			int flag = 0;
			for(int p = attack[i].left; p < attack[i].right; p++)
				if(wall[p+250] < attack[i].strength) flag = 1;
			cnt += flag;
			if(i != A && attack[i].time  != attack[i+1].time)
			{
				for(int j = i; j >= 1; j--){
					if(attack[j].fixed) break;
					for(int p = attack[j].left; p < attack[j].right; p++)
						if(wall[p+250] < attack[j].strength) wall[p+250] = attack[j].strength;
					attack[j].fixed = 1;
				}
			}

		}
		printf("Case #%d: %d\n", t, cnt);
	}
	return 0;
}