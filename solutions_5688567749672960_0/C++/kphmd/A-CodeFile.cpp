#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

void runCase()
{
	int n;
	scanf("%d",&n);
	int r = 0;
	char s[32];
	int i = 0;
	for(;;) {
		sprintf(s,"%d",i);
		int m = strlen(s);
		reverse(s,s+m);
		int a,b,c;
		a = i+1;
		sscanf(s,"%d",&b);
		if(s[0]=='9'&&b<=n&&b>a) {
			i = b;
		} else {
			s[0] += 1;
			sscanf(s,"%d",&c);
			if(c>n && b <= n && b>a) {
				i = b;
			} else {
				i = a;
			}
		}
		r++;
		// cout << i << endl;
		if(n<=i) break;
	}
	printf("%d\n",r);
}

void runSample()
{
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
