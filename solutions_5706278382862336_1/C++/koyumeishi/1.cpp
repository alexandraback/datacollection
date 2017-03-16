#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cfloat>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

#define ll long long 

ll gcd(ll a, ll b){
	if(b>a) swap(a,b);
	if(b == 0) return a;
	return gcd(b, a%b);
}

typedef struct{
	ll P;
	ll Q;
}pq;

int main(int argc, char *argv[]){
	int T;
	
	ifstream ifs(argv[1]);
	ofstream ofs("output.txt");

	ifs >> T;
	
	for(int t=0; t<T; t++){
		string s;
		ifs >> s;
		int d = s.find('/', 0);
		ll P, Q;
		stringstream ssp;
		ssp << s.substr(0, d);
		ssp >> P;
		stringstream ssq;
		ssq << s.substr(d+1, s.size());
		ssq >> Q;
		
		ll tmp=gcd(P,Q);
		P /= tmp; Q /= tmp;
		ll n = Q & -Q;
		if(Q - n == 0){
			int count=1;
			for(ll a=0; a<=P/2; a++){
				ll b=P-a;
				//cout << b << "/" << (Q>>1) << endl;
				if(b > Q>>1) continue;
				else if(b == Q>>1) break;
				else{
					P=b;
					Q=Q>>1;
					a=-1;
					count++;
				}
				if(count >40) break;
			}
			if(count <= 40){
				cout << "Case #" << t+1 << ": " << count << endl;
				ofs << "Case #" << t+1 << ": "  << count << endl;
			}else{
				cout << "Case #" << t+1 << ": " << "impossible" << endl;
				ofs << "Case #" << t+1 << ": "  << "impossible" << endl;
			}
		}else{
			cout << "Case #" << t+1 << ": " << "impossible" << endl;
			ofs << "Case #" << t+1 << ": "  << "impossible" << endl;
		}
	}
	return 0;
}