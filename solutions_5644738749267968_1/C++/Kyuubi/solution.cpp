#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

#define MOD 1000000007
#define SWAP(a,b) {a=(a)^(b);b = (a)^(b);a= (a)^(b);}

using namespace std;
inline long long minOf(long long x, long long y){return (x<y?x:y);}
inline long long maxOf(long long x, long long y){return (x>y?x:y);}
inline long long mabs(long long x){return (x<0?-x:x);}

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n;
	cin >> t;
	vector<long double> naomi,ken;
	long double x;
	for(int tt = 1; tt <= t; tt++){
		cin >> n;
		naomi.clear();
		ken.clear();
		for(int i = 0;i<n;i++){
			cin >> x;
			naomi.push_back(x);
		}
		for(int i = 0;i<n;i++){
			cin >> x;
			ken.push_back(x);
		}
		sort(naomi.begin()	, naomi.end()	);
		sort(ken.begin()	, ken.end()		);
		
		int ii = 0,jj = 0,win = 0,optWin=0;
		while(ii < n && jj < n){
			if(naomi[ii] < ken[jj])
				ii++;
			else{
				win++;
				jj++;
				ii++;
			}
		}
		ii = n-1;jj=0;
		int kk = n-1;
		while(ii >= 0 && jj <= kk){
			if(naomi[ii] > ken[kk] ){
				optWin++;
				jj++;
			}
			else
				kk--;
			ii--;
		}
		cout << "Case #" << tt << ": " << win << " " << optWin << endl;
	}
	return 0;
}