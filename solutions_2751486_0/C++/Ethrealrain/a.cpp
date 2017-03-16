#include <cstdio>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <memory.h>
#include <iostream>
#include<list>
#include <iomanip>
using namespace std;

#define pb push_back
#define sz size()
#define mp make_pair
#define mset(ar,val) memset(ar,val,sizeof ar)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))


void scan(int* i) {int t = 0;char c;bool negative = false;c = getchar_unlocked();while (c < '0' || c > '9') {if (c == '-')negative = true;c = getchar_unlocked();}while (c >= '0' && c <= '9') {t = (t << 3) + (t << 1) + c - '0';c = getchar_unlocked();}if (negative)t = ~(t - 1);*i = t;}
void scan(long long int* i) {long long int t = 0;char c;bool negative = false;c = getchar_unlocked();while (c < '0' || c > '9') {if (c == '-')negative = true;c = getchar_unlocked();}while (c >= '0' && c <= '9') {t = (t << 3) + (t << 1) + c - '0';c = getchar_unlocked();}if (negative)t = ~(t - 1);*i = t;}


int main() {
	int T,t,n,i,j,vcount,k;
	int res;
	bool flag;
	string l;
	scan(&T);
	for(t=1;t<=T;++t){
		res=0;
		cin>>l>>n;
		for(i=0;i<l.length()-1;++i){
			for(k=i+1;k<l.length();++k){
				vcount=0;
				flag=0;
				for(j=i;j<=k;++j){
					if((l[j]=='a'||l[j]=='e'||l[j]=='i'||l[j]=='o'||l[j]=='u'))
					vcount=0;
					else
						++vcount;
					if(vcount>=n && flag==0)
						flag=1,++res;
				}

			}
		}
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;
}

