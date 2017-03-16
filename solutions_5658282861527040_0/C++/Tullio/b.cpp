#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

#define pii pair<int,int>
#define pci pair<char,int>
#define f first
#define s second
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)
#define db if(1)
#define pb push_back

typedef long long ll;

int a, b, k;

bool read(){
    if(scanf("%d%d%d", &a, &b, &k) == EOF) return false;
    return true;
}

int cn = 1;

void process(){
	int res = 0;
	rep(i,a) {
		rep(j,b) {
			if ((i&j) < k) {
				res++;
			}
		}
	}

	printf("Case #%d: %d\n", cn++, res);
}

int main(){  
	int t = -1;
	
	scanf("%d", &t);

    while(t-- && read()){
        process();
    }
    
    return 0;
}
