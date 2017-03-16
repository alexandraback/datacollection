#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
#include<iomanip>
using namespace std;
ifstream in("1.in");
ofstream out("1.out");
int a[10000];
int main(){
	int testsum;
	in >> testsum;
	for (int iTest = 1; iTest <= testsum; iTest++){
		out << "Case #" << iTest << ": ";

		int x, n;
		in >> x >> n;
		for (int i = 1; i <=n; i++){
			in >> a[i];
		}
		sort(a+1, a+n+1);
//		cout << a[1];

		int now = n+1;
		for (int i = 1; i <= n; i++){
			if (a[i] < x) x += a[i];
			else {now = i;break;}
		}

		int ans = n-now+1;
		int sum = 0;
		bool flag = true;
		if (x != 1)
		for (int i = now; i <= n; i++){
			while (x <= a[i]){
				sum++;
				x = x*2-1;
			}
			x = x + a[i];
			if (sum + n - i < ans) ans = sum+n-i;
		}
		out << ans;
		out << endl;
	}
}
