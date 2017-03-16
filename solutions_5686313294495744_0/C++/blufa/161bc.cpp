#include <bits/stdc++.h>
using namespace std;
map<string,int> H[2];
int p,q;
int K[1006][2];
int C[2][1006];
int main(){
	int T,test,i,j,n,m;
	cin>>T;string a,b;
	for(test=1;test<=T;++test){
		cin>>n;p=0,q=0;
		int x,y;
	memset(C,0,sizeof(C));

		for(i=0;i<n;++i){
			cin>>a>>b;
			if(!H[0].count(a))
				H[0][a]= p++;
			if(!H[1].count(b))
				H[1][b]= q++;
			K[i][0]= H[0][a],K[i][1]= H[1][b];
			x= H[0][a], y= H[1][b];
			C[0][x]++,C[1][y]++;
		}
			H[0].clear(),H[1].clear();
		int ret=0;
		for(i=0;i<n;++i){
			x = K[i][0],y =K[i][1];
			if(C[0][x]>1 && C[1][y]>1){
				--C[0][x],--C[1][y];
				++ret;
			}
		}
		printf("Case #%d: %d\n",test,ret);
	}
}
