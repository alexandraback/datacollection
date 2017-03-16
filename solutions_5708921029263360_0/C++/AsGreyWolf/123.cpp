#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <deque>

using namespace std;
typedef long long lint;

struct pairs{
int a,b;
pairs(int aa,int bb){
	a=aa;b=bb;
};
bool operator<(const pairs &ss) const{
	return a==ss.a?b<ss.b:a<ss.a;
};
};
struct triplets{
int a,b,c;
triplets(int aa,int bb,int cc){
	a=aa;b=bb;c=cc;
};
bool operator<(const triplets &ss) const{
	return a==ss.a?(b==ss.b?c<ss.c:b<ss.b):a<ss.a;
};
};

int main() {
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int j,p,s,k;
		cin>>j>>p>>s>>k;
		map<pairs,lint> twojp;
		map<pairs,lint> twojs;
		map<pairs,lint> twops;
		map<triplets,char> three;
		vector<triplets> answer;
		for(int ji=1;ji<=j;ji++){
			for(int pi=1;pi<=p;pi++){
				for(int si=1;si<=s;si++){
					if(!three[triplets(ji,pi,si)] && twojp[pairs(ji,pi)]<k && twojs[pairs(ji,si)]<k && twops[pairs(pi,si)]<k){
						answer.push_back(triplets(ji,pi,si));
						three[triplets(ji,pi,si)]=true;
						twojp[pairs(ji,pi)]++;
						twojs[pairs(ji,si)]++;
						twops[pairs(pi,si)]++;
					}
				}
			}
		}
		cout<<"Case #"<<(i+1)<<": "<<answer.size()<<endl;
		for(auto &a:answer)
			cout<<a.a<<" "<<a.b<<" "<<a.c<<endl;
	}
	return 0;
}
