#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <assert.h>

#define F(i,n) for(int i = 0, n_ = (n); i<n_; i++)
#define FS(i,s,n) for(int i = (s), n_ = (n); i<n_; i++)
#define AA first
#define BB second
#define XX first.first
#define YY first.second
#define ZZ second
#define PB push_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PRI;
typedef pair<PRI,int> TRI;

template<typename T> inline void updatemin(T &a, T b) {if(a>b) a=b;}
template<typename T> inline void updatemax(T &a, T b) {if(a<b) a=b;}
template<typename T> inline T gcd(T a, T b) {
	T d;
	while(b!=0) d=b, b=a%b, a=d;
	return a;
}


fstream fin, fout;

double minpoint(VI s, int X, double yi){
	int X2 = 0, i;
	F(i,s.size()) X2 += s[i];
	sort(s.begin(), s.end());
	for(i=s.size()-1; i>=0; i--){
		if(X2 + X*(1-yi) >= (i+1)*s[i]) break;
		X2 -= s[i];
	}
	assert(i>=0);
	return double(X2 + X*(1.0-yi))/(i+1);
}



int main(int argc, char* argv[]){
	//fin.open(argv[1], fstream::in);
	//fout.open(argv[1], fstream::out);

	int T, N, X;
	cin>>T;
	F(test,T){
		cin>>N;
		VI s(N);
		X=0;
		F(i,N){
			cin>>s[i];
			X += s[i];
		}

		cout<<"Case #"<<test+1<<": ";
		F(i,N){
			VI ss;
			F(j,N) if(i!=j) ss.PB(s[j]);

			double min = 0, max = 1., mid = (min+max)/2, p1, p2, result;
			while(max-min>1e-7){
				mid = (max+min)/2;
				p1 = s[i] + mid*X;
				p2 = minpoint(ss,X,mid);
				if(p1==p2){
					break;
				} else if(p1>p2){
					max = mid;
				} else if(p1<p2){
					min = mid;
				}
			}

			cout<<setprecision(10)<<mid*100<<" ";
		}

		cout<<endl;

	}

	//fin.close();
	//fout.close();
}