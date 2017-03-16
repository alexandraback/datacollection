#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <cstdio>
#include <list>
#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> PII;
typedef pair <int, double> PID;
typedef pair <double, double> PDD;
typedef vector <int> VI;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout

//freopen("in.txt", "r", stdin);
//freopen ("myfile.txt","w",stdout);
//fclose (stdout);
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t, cases=0;
	scanf("%d",&t);
	while(t--) {
		string s;
		string res="";
		cin >> s;
		int n=0;
		int k = s.length();
		for(int i=0;i<k;i++) {
			if(n==0) {
				res+=s[i];
			}
			else if(s[i]>=res[0]) {
				res = s[i]+res;
			}
			else {
				res=res+s[i];
			}
			n++;
		}
		cout << "Case #" << ++cases << ": " << res << endl;
	}
	fclose(stdout);
	return 0;
}
