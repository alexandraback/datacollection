#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void solve();
void runCase();

const int N = 1000001;
char s[N];
int n;
int L;

int isA[256] = {0};
int go(int a,int l,int n) {
	//cout << string(s+a,l) << endl;
	int b = a+l;
	int cnt = 0;
	for(int i = a; i < b; i++) {
		if(isA[s[i]-0]==1) cnt=0;
		else {
			cnt++;
			if(cnt>=n) {
				return 1;
			}
		}
	}
	return 0;
}

void runCase()
{
	scanf("%s %d",s,&n);
	L = strlen(s);
	
	int res = 0;
	for(int i = 0; i < L; i++) {
		for(int j = 1; j <= L-i; j++) {
			res += go(i,j,n);
		}
	}
	printf("%d\n",res);
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
	isA['a'-0] = 1;
	isA['e'-0] = 1;
	isA['i'-0] = 1;
	isA['o'-0] = 1;
	isA['u'-0] = 1;
	solve();
	return 0;
}
