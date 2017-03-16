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

double P[10000001];
double get_right_up_to[10000001];

int main (void)
{	
	int t, caso = 0;

	scanf("%d", &t);

	
	int A, B;

	while(t--) {
		printf("Case #%d: ", ++caso);
		scanf("%d %d", &A, &B);

		for(int i = 1; i <= A; i++) 
			scanf("%lf", &P[i]);

		
		double got_right = 1.0;
		get_right_up_to[0] = 1.0;

		for(int i = 1; i <= A; i++) {
			got_right *= P[i];
			get_right_up_to[i] = get_right_up_to[i-1] * P[i];
		}

		double keep = got_right * (B-A+1) + (1 - got_right) * (B + 1 + (B-A+1));
		
		

		double curr = 1.0;
		for(int i = 0; i <= A; i++) {
			// Se deletar até o i-ésimo
			curr = 
				get_right_up_to[i] * (B - i + (A - i) + 1) +
				(1 - get_right_up_to[i]) * ((B-i+1) + B+1 + (A-i));
			
			if(curr < keep) {
				keep = curr;
			}
		}

		if(B+2 < keep) keep = B+2;
		

		printf("%.7lf\n", keep);
	}
	return 0;
}
