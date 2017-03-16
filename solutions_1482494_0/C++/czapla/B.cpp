#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 1000123000

int s1[1123], s2[1123];

int main(){
	int testy;
	scanf("%d", &testy);
	for(int t = 1; t <= testy; t++){
		int wyn = 0;
		int stars = 0;
		int n = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d %d", &s1[i], &s2[i]);
		
		bool p2 = true;
		while(p2){
			p2 = false;
			bool p1 = true;
			while(p1){
				p1 = false;
				for(int i = 0; i < n; i++)
					if(stars >= s2[i]){
						wyn++;
						stars += 1;
						if(s1[i] < INF)
							stars += 1;
						s2[i] = INF;
						s1[i] = INF;
						p1 = true;
						p2 = true;
					}
			}
			
			
			int maxs2 = -1;
			for(int i = 0; i < n; i++)
				if(stars >= s1[i]){	
					maxs2 = max(maxs2, s2[i]);
				}
			for(int i = 0; i < n; i++)
				if(stars >= s1[i] && s2[i] == maxs2){	
					wyn++;
					stars += 1;
					s1[i] = INF;
					p2 = true;
					break;
				}
			
		}
		
		bool ukonczona = true;
		for(int i = 0; i < n; i++)
			if(s2[i] < INF)
				ukonczona = false;
				
		if(ukonczona)
			printf("Case #%d: %d\n", t, wyn);
		else
			printf("Case #%d: Too Bad\n", t);
	}
	return 0;
}
