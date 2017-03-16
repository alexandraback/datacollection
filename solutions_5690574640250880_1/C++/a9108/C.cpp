#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
#include <fstream>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

int main(int argc,char** argv){
	int T;
	cin>>T;
	for (int r=1;r<=T;r++){
		printf("Case #%d:\n",r);
		int n,m,k;
		cin>>n>>m>>k;
		if (n*m-k==1){
			printf("c");
			for (int i=0;i<n;i++){
				for (int j=0;j<m;j++)
					if (i+j>0) printf("*");
				puts("");
			}
		}
		else if (n==1){
			printf("c");
			for (int i=1;i<n*m-k;i++) printf(".");
			for (int i=0;i<k;i++) printf("*");
			puts("");
		}
		else if (m==1){
			puts("c");
			for (int i=1;i<n*m-k;i++) puts(".");
			for (int i=0;i<k;i++) puts("*");
		}
		else {
			bool f=false;
			for (int ma=2;ma<=m;ma++){
				int le=n*m-k-ma*2;
				if (ma>2||le%2==0)
				if (le==0||(le>1&&le<=ma*(n-2))){
					f=true;
					vector<int> res;
					res.clear();res.PB(ma);res.PB(ma);
					for (int i=2;i<n;i++){
						int cur=min(ma,le);
						if (le-cur==1) cur--;
						res.PB(cur);
						le-=cur;
					}
					for (int i=0;i<n;i++){
						for (int j=0;j<m;j++)
							printf("%c",(i+j==0)?'c':(j<res[i]?'.':'*'));
						puts("");
					}
					break;
				}
			}
			if (!f) puts("Impossible");
		}
	}
	return 0;
}