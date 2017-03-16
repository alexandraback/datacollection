
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())


int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
        int X,r,c;
        cin >> X >> r >> c;
        bool good;
        if(X==1) {
            good = true;
        } else if(X==2) {
            good = ((r*c)%2==0);
        } else if(X==3) {
            if(min(r,c)==1) good=false;
            else good = ((r*c)%3==0);
        } else if(X==4) {
            if(min(r,c)<=2) good=false;
            else good = ((r*c)%4==0);
        } else if(X==5) {
            if(min(r,c)<=2) good=false;
            else if(min(r,c)==3) good=(max(r,c)>=10 && ((r*c)%5)==0);
            else good = ((r*c)%5==0);
        } else if(X==6) {
            if(min(r,c)<=3) good=false;
            else good = ((r*c)%6==0);
        } else {
            good=false;
        }
        cout << (good ? "GABRIEL": "RICHARD") << endl;
	}
}
