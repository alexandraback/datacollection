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
lint binpow (lint a, lint n) {
	lint res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}
int main() {
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		lint B,M;
		cin>>B>>M;
		if(M<=binpow(2,B-2)){
			cout<<"Case #"<<(i+1)<<": POSSIBLE"<<endl;
			for(int j=1;j<B;j++){
				for(int k=1;k<B;k++){
					if(j!=k)
					cout<<1;
					else cout<<0;
				}
				if(j==1 && M==binpow(2,B-2)){
					cout<<1;
					M--;
				}
				else if(j>1 && ((M>>(j-2))&1)!=0)
					cout<<1;
				else
					cout<<0;
				cout<<endl;
			}
			for(int k=1;k<=B;k++){
					cout<<0;
				}
			cout<<endl;
		}else{
			cout<<"Case #"<<(i+1)<<": IMPOSSIBLE"<<endl;
		}
	}
	return 0;
}
