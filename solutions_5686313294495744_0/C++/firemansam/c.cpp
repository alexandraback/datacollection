#include <bits/stdc++.h>
using namespace std;
int tcs, n, la, lb;
map<string, int> tc1, tc2;
typedef pair<int, int> ii;
vector<ii> pts;
int main(){
	scanf("%i\n", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		pts.clear();
		char buf[100000], buf2[100000];
		tc1.clear();
		tc2.clear();
		la = 0; lb = 0;
		scanf("%i", &n);
		for(int i=0;i<n;i++){
			scanf("%s%s", buf, buf2);
			string a = string(buf);
			string b = string(buf2);
			if(tc1.find(a) == tc1.end()){
				tc1[a] = la;
				la++;
			}
			if(tc2.find(b) == tc2.end()){
				tc2[b] = lb;
				lb++;
			}
			pts.push_back(ii(tc1[a], tc2[b]));
		}
		printf("Case #%i: %i\n", tc, n- max(la, lb));
	}
}