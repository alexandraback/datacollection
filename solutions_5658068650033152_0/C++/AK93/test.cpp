#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>

using namespace std;
typedef long long ll;
const double eps = 1e-10;
vector<int> arr, kol;
int n, m, k;

int check2(int count){
	bool res = true;
	if(count % 4 == 0){
		int sz = arr[count];
		if(sz <= n && sz <= m)
			return kol[count];
	}
	else{
		int sz = arr[count-2];
		if((sz+1 <= n && sz <= m) || (sz <= n && sz+1 <= m) )
			return kol[count-2] + sz;
	}
	return -1;
}

int check(int n, int m){
	return n*m - 4;
}

int main(){
	//freopen("input.txt", "r", stdin);
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	arr.assign(400, 0);
	kol.assign(400, 0);
	kol[0] = 1;
	int st = 3;
	for(int i=0; i<400; i++){
		if(i >= 4){
			if(i % 4 == 0){
				arr[i] = st;
				kol[i] = kol[i-4] + i;
				st += 2;			
			}
		}
	}
	int test_count;
	cin>>test_count;
	for(int test = 0; test < test_count; test++){
		int res = INT_MAX;
		int razn = INT_MAX;
		cin>>n>>m>>k;
		if(n < 3 || m < 3){
			cout<<"Case #"<<test+1<<": "<<k<<endl;
			continue;
		}

		for(int i=3; i<=n; i++){
			for(int j=3; j<=m; j++){
				int buf = check(i, j);
				if(buf >= k){
					res = min(res, (i+j)*2 - 8);
				}
				else{
					if(abs(buf - k) == 1){
						res = min(res, (i+j)*2 - 7);
					}
				}
				razn = min(razn, abs(buf - k));
			}
		}
		
		if(res == INT_MAX)
			res = (n+m)*2 - 8 + razn;

		for(int i=4; i<=k; i++){
			int buf;
			if(i % 2 == 0)
				buf = check2(i);
			else{
				buf = check2(i-1);
				buf++;
			}
			if(buf >= k)
				res = min(res, i);
		}
		if(res > k)
			res = k;
		cout<<"Case #"<<test+1<<": ";
		cout<<res;
		cout<<"\n";
	}

	return 0;
}