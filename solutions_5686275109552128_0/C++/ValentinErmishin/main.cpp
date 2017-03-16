#include <bits/stdc++.h> 

using namespace std;
      
int n;
int add;
int ans;
int T;
int mas[1111];

int main () {
#ifdef LOCAL
	freopen ("file.in", "r", stdin);
	freopen ("file.out", "w", stdout);
#endif                                
	//freopen (".in", "r", stdin);
	//freopen (".out", "w", stdout);

	cin >> T;  

	for (int t = 1; t <= T; t++) {
	    	
    	add = 0;
    	ans = INT_MAX;
    	int ans1 = 0;
		scanf ("%d", &n);

    	for (int i = 0, a; i < n; i++) {
    		scanf ("%d", &a);
    		mas[i] = a;
			ans1 = max (a, ans1);
    	}

		ans = ans1;

		for (int i = 1; i <= ans1; i++) {
			int sum = 0;			
			for (int j = 0; j < n; j++) 
				sum += (mas[j] / i) + (mas[j] % i != 0) - 1;
			ans = min (ans, sum + i);
		}

    	printf ("Case #%d: %d\n", t, ans);
    }

	return 0;
}