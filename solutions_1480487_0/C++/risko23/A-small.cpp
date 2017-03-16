#include <sstream>
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

#define FOR(i,a) for (int (i)=0;(i)<(a);++(i))
#define FORR(i,a,b) for (int (i)=(a);(i)<(b);++(i))
#define sz(a) int((a).size()) 
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end() 


main(){
	ofstream fout ("A-small-0.out");
	ifstream fin ("A-small-0.in");
	int T;
	fin>>T;
	FOR(num,T){
		vector<int> a;
		int N;
		fin>>N;
		int X=0;
		FOR(i,N){
			int tmp;
			fin>>tmp;
			a.push_back(tmp);
			X+=tmp;
		}
		vector<double> out(N,0.0);
		FOR(i,N){
			double low=0.0;
			double high=1.0;
			while(abs(low-high)>0.00000001){
				double mid = (high+low)/2;
				double val = a[i] + X*mid;
				double votes=1.0-mid;
				FOR(j,N){
					if (i!=j && (a[j] < val)){
						double take = (val - a[j])/X;
						votes-=take;
					}
				}
				if (votes<=0.0) high=mid;
				else low=mid;
			}
			out[i]=low;
		}
		fout.precision(10);

		fout<<"Case #"<<num+1<<":";
		FOR(i,N){
			fout<<" "<<100*out[i];
		}
		fout<<endl;
	}
	fout.close();
}
