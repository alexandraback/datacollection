#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair

int main (void)
{
	int t;
	int N, P, S;

	int V[101], T;

	int t_1, t_2, t_3, t_4, t_5;

	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++) {

		t_1 = t_2 = t_3 = t_4 = t_5 = 0;

		scanf("%d %d %d", &N, &S, &P);

		for(int i = 0; i < N; i++) {
			scanf("%d", &V[i]);
		}

		for (int i = 0; i < N; ++i)
		{
			T = 0; // 0 Nao consegue nem surprising nem sem surprising

			for(int j = max(0, P-1); j <= 10; j++) {
				if(3*j == V[i]) {
					if(j >= P) 
						T = T | 1;
				} 
				if(3*j+1 == V[i] || 3*j+2 == V[i]) {
						T = T | 1;
				}
			}

			for(int j = 0; j <= 10; j++) {
		//		printf("%d %d %d\n", 3*j + 2, 3*j + 3, 3*j + 4);
				if(3*j+2 == V[i] || 3*j+3 == V[i] || 3*j+4 == V[i]) {
					if(j+2 >= P) {
						T = T | 4;
						if(T & 2) T -= 2;
						break;
					}
					else {
						if(!(T & 4)) T = T | 2;	
					} 
				} 
			}

			// T1 = Consegue sem ser surprising
			// T2 = Consegue só ser surprising (sem respeitar o limite do P)
			// T3 = Consegue ser surprising mas sem respeitar P, e consegue sem ser surprising
			// T4 = Consegue só como surprising
			// T5 = Consegue com e sem surprising
			if(T == 1) {
				t_1++;
			} else if(T == 2) {
				t_2++;
			} else if(T == 3) {
				t_3++;
			} else if(T == 4) {
				t_4++;
			} else if(T == 5) {
				t_5++;
			}
		}

		//printf("- : %d %d %d %d %d \n", t_1, t_2, t_3, t_4, t_5);
		printf("Case #%d: ", caso);

		int answ = t_1;

		if(S - t_4 > 0) {
			answ += t_4;
			S -= t_4;
		} else {
			answ += S;
			S = 0;
		}

		S = max(0, S-t_2);

		answ += t_5;
		S = max(0, S - t_5);

		if(S > 0) {
			answ += (t_3 - S);
		} else answ += t_3;

		printf("%d\n", answ);
	
	}

	return 0;
}
