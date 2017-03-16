#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <utility>

using namespace std;

vector <long long> pals;
vector <int> ans;

long long a[100];


int get (long long x) {
	int cnt = 0;
	for (int i = 0; i < 39; i++)
		if (a[i] <= x)
			cnt++;
		else
			break;		
	return cnt;
}
//vector <int> a, b;	
  /*
bool ok (long long x) {
		a.clear();
		b.clear();
		while (x) {
			a.push_back(x % 10);
			b.push_back(x % 10);
			x /= 10;
		}			
		reverse(b.begin(), b.end());
		int g = 1;
		for (int j = 0; j < a.size(); j++)
			if (b[j] != a[j])
				g = 0;
		return g?true:false;
}
    */
void init(){
a[0] = 1;
a[1] = 4;
a[2] = 9;
a[3] = 121;
a[4] = 484;
a[5] = 10201;
a[6] = 12321;
a[7] = 14641;
a[8] = 40804;
a[9] = 44944;
a[10] = 1002001;
a[11] = 1234321;
a[12] = 4008004;
a[13] = 100020001;
a[14] = 102030201;
a[15] = 104060401;
a[16] = 121242121;
a[17] = 123454321;
a[18] = 125686521;
a[19] = 400080004;
a[20] = 404090404ll;
a[21] = 10000200001ll;
a[22] = 10221412201ll;
a[23] = 12102420121ll;
a[24] = 12345654321ll;
a[25] = 40000800004ll;
a[26] = 1000002000001ll;
a[27] = 1002003002001ll;
a[28] = 1004006004001ll;
a[29] = 1020304030201ll;
a[30] = 1022325232201ll;
a[31] = 1024348434201ll;
a[32] = 1210024200121ll;
a[33] = 1212225222121ll;
a[34] = 1214428244121ll;
a[35] = 1232346432321ll;
a[36] = 1234567654321ll;
a[37] = 4000008000004ll;
a[38] = 4004009004004ll;

}                           

int main () {
                                     
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	/*int ind = 0;
	for (long long i = 1; i < 10000000ll; i++) {
		if (ok(i) && ok((long long)(i * i))) {
			pals.push_back((long long)(i * i));
			printf("a[%d] = ", ind++);
			cout << i * i << ";\n";
		}
	}*/
	init();
	int now = 0;
	while (t--) {
		long long l, r;
		cin >> l >> r;
		printf("Case #%d: %d\n", ++now, get (r) - get (l - 1));
	}
	
	
	return 0;
}
