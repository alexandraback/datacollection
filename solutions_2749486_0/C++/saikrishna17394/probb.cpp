#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<map>
#include<set>
using namespace std;
typedef long long lli;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)

int main() {
	freopen("B-small-attempt0.in", "r", stdin); freopen("B-small.out", "w", stdout);
	//freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);

	int t,x,y,num;

	scanf("%d\n",&t);
	for(int j=1;j<=t;j++) {
		scanf("%d %d",&x,&y);
		string ans;
		num=0;
		if(abs(x)>0) {
			if(x>0) {
				for(int i=1;i<x;i++) {
					ans+='E';
					ans+='W';
					}
				ans+='E';
				}
			else {
				for(int i=1;i<abs(x);i++) {
					ans+='W';
					ans+='E';
					}
				ans+='W';
				}
			num+=2*abs(x)-1;
			}


		if(abs(y)>0) {
			if(y>0) {
				for(int i=0;i<abs(y);i++) {
					ans+='S';
					ans+='N';
					}
				}

			else {
				for(int i=0;i<abs(y);i++) {
					ans+='N';
					ans+='S';
					}
				}

			}

		printf("Case #%d: ",j);cout<<ans<<endl;
		}

	return 0;
	}
