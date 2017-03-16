#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
using namespace std;



int t;

int n;

int tt = 0;

#define MAX 1002
int a[MAX][MAX];


vector<vector<int> > v;
vector<int> vv;

map<int, int> mp;
int main(){
	cin >> t;
	while (t--){
		tt++;
		cin >> n;
		mp.clear();
		v.clear();
		for (int i = 0; i < n * 2 - 1; i++){
			vv.clear();
			for (int j = 0; j < n; j++){
				scanf("%d", &a[i][j]);
				vv.push_back(a[i][j]);
				mp[a[i][j]]++;
			}
			v.push_back(vv);
		}
		printf("Case #%d: ", tt);
		bool outt = false;
		for (auto it = mp.begin(); it != mp.end(); it++){
			if ((*it).second % 2){
				if (outt){
					printf(" ");
				}
				outt = true;
				printf("%d", (*it).first);
			}
		}
		puts("");
	}
	return 0;
}