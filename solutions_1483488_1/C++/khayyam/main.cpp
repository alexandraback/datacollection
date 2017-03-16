#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

void get_n(int m, set<int> &S){
	ostringstream os;
	os<<m;
	string s=os.str();
	for(unsigned p=1;p<s.size();++p){
		string a=s.substr(0,p);
		string b=s.substr(p,s.size()-p);
		istringstream is(b+a);
		int n;
		is>>n;
		if(n<m){
			S.insert(n);
		}
	}
}


int main(int argc, char *argv[]){
	map<int, set<int> > N;
	cerr<<"Init..."<<endl;
	for(int m=1;m<=2000000;++m){
		if(m%100000==0){
			cerr<<m<<endl;
		}
		get_n(m, N[m]);
	}
	cerr<<"Done."<<endl;
	int T;
	cin>>T;
	for(int c=1;c<=T;++c){
		int A,B;
		cin>>A>>B;
		int total=0;
		for(int m=A;m<=B;++m){
			for(set<int>::iterator it=N[m].begin();(it!=N[m].end()) && (*it<=B);++it){
				if(A<=*it){
					++total;
				}
			}
		}
		cout<<"Case #"<<c<<": "<<total<<endl;
	}
	return 0;
}

