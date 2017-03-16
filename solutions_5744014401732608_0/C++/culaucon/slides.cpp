#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

LL n, m;
int a[55][55];
LL f[55];

int main() {
	freopen("slides.in", "r", stdin);
	freopen("slides.out", "w", stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		memset(a,0,sizeof(a));
		cout<<"Case #"<<nt++<<": ";
		LL base = 1;
		for (int i=0;i<n-2;i++) base *= 2LL;
		/*if (m>base) {
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		if (n==2) {
			cout<<"POSSIBLE"<<endl;
			if (m==0) {
				cout<<"00"<<endl<<"00"<<endl;
			} else {
				cout<<"01"<<endl<<"00"<<endl;
			}
			continue;
		}*/
		
		for (int i=1;i<n-1;i++) a[0][i]=1;
		memset(f,0,sizeof(f));
		
		for (int i=n-2;i>0;i--) {
			for (int j=n-2;j>i;j--) {
				if (m>=f[j]) {
					a[i][j]=1;
					m-=f[j];
					f[i]+=f[j];
				}
			}
			if (m>0) {
				a[i][n-1]=1;
				m--;
				f[i]++;
			}
		}
		

		if (m>1) {
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		if (m==1) a[0][n-1]=1;
		cout<<"POSSIBLE"<<endl;
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++)
				if (a[i][j]) cout<<1;
				else cout<<0;
			cout<<endl;
		}
	}
}
