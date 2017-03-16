#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const double EPS=1e-12;

int n,m,w;

bool input(){
	scanf("%d%d%d",&n,&m,&w);
	return 1;
}

void solve(){

	static int cas=1;
	printf("Case #%d: ",cas++);
	if(m%w==0){
		printf("%d\n",(m-w)/w+w+(n-1)*(m/w));
		return;
	}
	printf("%d\n",(m-w)/w+w+1+(n-1)*(m/w));
}

int main()
{
	int zz;
	scanf("%d",&zz);
	while(zz--){
	    input();
		solve();
	}
    return 0;
}
/*

6 2
ioi
1 3

5 2
ioi
1 2

*/