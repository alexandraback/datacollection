#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

int N=32,J=500;

vector<unsigned> ans;

void init(){
	for(unsigned s=1U<<(N-1)|1;;s+=2){
		bool ok=true;
		for(int b=2;b<=10;b++){
			int val=0;
			for(int i=N-1;i>=0;i--){
				val=(val*b+(s>>i&1U))%11;
			}
			if(val) ok=false;
		}
		if(ok){
			ans.push_back(s);
			if(ans.size()>=J) return;
		}
	}
}

int main(){
//	freopen("C-small-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);
	init();
	int T=1;
	for(int Case=1;Case<=T;Case++){
		printf("Case #%d:\n",Case);
		for(int _=0;_<ans.size();_++){
			unsigned n=ans[_];
			for(int i=N-1;i>=0;i--) putchar('0'+(n>>i&1));
			for(int b=2;b<=10;b++) printf(" 11");
			printf("\n");
		}
	}
}