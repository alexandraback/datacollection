#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
  
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, n) FOR(i, 0, n)
#define sz(e) (int)e.size()
#define all(e) e.begin(), e.end()
#define pb push_back
#define CLR(x, a) memset(x, a, sizeof(x))
  
#define ll long long
#define ull unsigned ll
#define ii pair<int, int>
#define vi vector<int>
  
using namespace std;

int vet1[1000], vet2[1000];

int deceitful (int N){
	int cnt = 0;
	for (int i = N-1; i >= 0; i--){
		if (vet2[i]<vet1[N-cnt-1]) cnt++; 
	} 
	return cnt;
}

int war (int N){
	int val = 0, lb = 0;
	FORR (i, N){
		while (lb<N && vet2[lb]<vet1[i]) lb++;
		if (lb==N) break;
		lb++;
		val++;
	}
	return N-val;
}

int main (){
	int T;
	scanf (" %d", &T);
	FORR (cx, T){
		
		int N;
		scanf (" %d", &N);
		char str[20];
		FORR (i, N){	
			scanf (" 0.%s", str);
			FORR (j, 5) if (str[j]=='\0') str[j] = '0', str[j+1] = '\0';
			 //itoa (vet1[i], str, 10);
			sscanf (str, "%d", &vet1[i]);
		}

		FORR (i, N){	
			scanf (" 0.%s", str);
			FORR (j, 5) if (str[j]=='\0') str[j] = '0', str[j+1] = '\0';
			 //itoa (vet1[i], str, 10);
			sscanf (str, "%d", &vet2[i]);
		}
		
		sort (vet1, vet1+N);
		sort (vet2, vet2+N);
		//FORR (i, N) cout <<vet1[i]<< " "; cout << endl;

		//FORR (i, N) cout <<vet2[i]<< " "; cout << endl;
		printf ("Case #%d: %d %d\n", cx+1, deceitful(N), war(N));
		
		

	}
}

