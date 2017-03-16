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

void i2s(int i,char *s,int n) {
    for(;n--;) {
        s[n] = i%10+'0';
        i /= 10;
    }
}

void runCase()
{
    string C,J;
    cin >> C >> J;
    int n = C.length();
    int maxval = 1;
    rep(i,n) maxval *= 10;
    
    int bc = maxval,bj = maxval,diff = maxval;
    
    for(int c = 0; c < maxval; c++) {
        for(int j = 0; j < maxval; j++) {
            char cc[10],jj[10];
            // if(n==1) {sprintf(cc,"%01d",c);sprintf(jj,"%01d",j);}
            // if(n==2) {sprintf(cc,"%02d",c);sprintf(jj,"%02d",j);}
            // if(n==3) {sprintf(cc,"%03d",c);sprintf(jj,"%03d",j);}
            i2s(c,cc,n);i2s(j,jj,n);
            int f = 1;
            rep(i,n) {
                if(C[i]!='?' && C[i] != cc[i]) f = 0;
                if(J[i]!='?' && J[i] != jj[i]) f = 0;
            }
            if(f) {
                if(diff > abs(c-j)) {
                    diff = abs(c-j);
                    bc = c; bj = j;
                } else if(diff == abs(c-j)) {
                    if(bc > c) {
                        bc = c; bj = j;
                    } else if(bc == c) {
                        if(bj > j) {
                            bc = c; bj = j;
                        }
                    }
                }
            }
        }
    }
    if(n==1) printf("%01d %01d\n",bc,bj);
    if(n==2) printf("%02d %02d\n",bc,bj);
    if(n==3) printf("%03d %03d\n",bc,bj);
}

void solve()
{
	int n;
    cin >> n;
	// scanf("%d",&n);
	// getchar();

	for(int i = 0; i < n; i++) {
        cout << "Case #" << i+1 << ": ";
		// printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
    // ios::sync_with_stdio(false); cin.tie(0);
	solve();
	return 0;
}
