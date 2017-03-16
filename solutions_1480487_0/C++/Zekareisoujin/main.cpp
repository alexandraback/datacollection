#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define NMAX 200

int n;
double s[NMAX];
double safes[NMAX];

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int tci=0; tci<tc; tci++){
		cin >> n;
		double sum = 0;
		for(int i=0; i<n; i++){
			cin >> s[i];
			sum += s[i];
		}
		double curSum = sum*2;
		double avg = curSum/(double)n;

		int needAud = n;
		bool allOk = false;
		for (int i=0; i<n; i++)
			safes[i] = s[i];
		sort(safes, safes+n);

		for (int i=needAud-1; i>=0 && !allOk; i--){
			if (safes[i] <= avg)
				allOk = true;
			else{
				curSum -= safes[i];
				needAud--;
				avg = curSum/(double)needAud;
			}
		}

		printf("Case #%d:", tci+1);
		for (int i=0; i<n; i++)
			printf(" %lf", max((double)0, 100*(avg-s[i])/sum));
		printf("\n");
	}
}