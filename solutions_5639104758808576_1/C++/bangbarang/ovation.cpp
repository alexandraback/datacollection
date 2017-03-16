#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define eps 1e-9
#define MOD 1000000007

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A-large.in", "r", stdin);
		freopen("a.out","w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    int test, n;
    char c;
    //int t[2000], s[2000];
    int res = 0;
    string s1;
    cin >> test;
    FOR(i, 1, test){
    	cin >> n;
    	cin >> s1;
    	int t[2000]= {0}, s[2000]={0};
    	res = 0;
    	//cout << n << endl;
    	FOR(j, 0, n){
    		//cin >> c;
    		s[j] = int(s1[j]) - int('0');
    		if (j == 0) t[j] = s[j];
			else t[j] = t[j-1] + s[j];    		    		
    	}
    	//getline(cin, s1);
    	FOR(j, 1, n){
    		if (j > t[j-1] + res) res = j - t[j-1];
    	}
    	cout << "Case #" << i << ": " << res << endl;
    }
	return 0;
}

