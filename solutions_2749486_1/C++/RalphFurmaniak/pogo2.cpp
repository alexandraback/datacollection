#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <cassert>
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
		int X,Y;
		cin >> X >> Y;
		int A=X+Y, B=X-Y;
		vector<int> va,vb;
		int n=0, tot=0;
		while(tot<max(abs(A),abs(B))) tot+=(++n);
		while(tot%2 != abs(A)%2) tot+=(++n);
		for(int i=1; i<=n; i++) va.push_back(A>0?1:-1);
		for(int i=1; i<=n; i++) vb.push_back(B>0?1:-1);
		for(int totA=tot-abs(A), i=n; totA; i--) {
			assert(i);
			if(totA>=2*i) {
				totA-=2*i;
				va[i-1]*=-1;
			}
		}
		for(int totB=tot-abs(B), i=n; totB; i--) {
			assert(i);
			if(totB>=2*i) {
				totB-=2*i;
				vb[i-1]*=-1;
			}
		}
		//for(int i=0; i<va.size(); i++) cout << va[i]; cout << endl;
		//for(int i=0; i<va.size(); i++) cout << vb[i]; cout << endl;
		int x=0, y=0, a=0, b=0;
		for(int i=0; i<va.size(); i++) {
			if(va[i]==1 && vb[i]==1) { cout << 'E'; x+=i+1; a+=i+1, b+=i+1; }
			if(va[i]==-1 && vb[i]==-1) { cout << 'W'; x-=i+1; a-=i+1, b-=i+1; }
			if(va[i]==1 && vb[i]==-1) { cout << 'N'; y+=i+1; a+=i+1, b-=i+1; }
			if(va[i]==-1 && vb[i]==1) { cout << 'S'; y-=i+1; a-=i+1, b+=i+1; }
		}
		//cout << a << " " << b << " " << A << " " << B << endl;
		assert(a==A && b==B);
		//cout << x << " " << y << " " << X << " " << Y << endl;
		assert(x==X && y==Y);
		cout << endl;
        }
}
