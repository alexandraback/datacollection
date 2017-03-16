#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
#include<cstring>
#include<cmath>
#define INF 0x3fffffff
#define pb push_back
#define pn(x) cerr<<x<<endl

using namespace std;
typedef long long ll;
const int maxv=1e6+20;
typedef pair<int,int> P;///num,pos

struct S{
	int num,spd,pos;
};
int  T,t=0;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	while(T--){
		t++;
		int n;
		cin>>n;
		int ans;
		if(n==1){
			int num,spd,pos;
			cin>>pos>>num>>spd;
			if(num==1){
				ans=0;
			}
			else{
				double dspd1=360.0/spd,dspd2=360.0/(spd+1);
				double t1=(360.0-pos)/dspd2;
				int round=(t1*dspd1-(360.0-pos))/360.0+0.00000000001;
				ans=round?1:0;
			}
		}
		else{
			S g[2];
			cin>>g[0].pos>>g[0].num>>g[0].spd;
			cin>>g[1].pos>>g[1].num>>g[1].spd;
			double t1=(360.0-g[0].pos)/g[0].spd;
			double t2=(360.0-g[1].pos)/g[1].spd;
			if(t1<t2){
				swap(g[1],g[0]);
				swap(t1,t2);
			}
			int round=(t1*g[1].spd-(360.0-g[1].pos))/360.0+0.00000000001;
				ans=round?1:0;
		}
		printf("Case #%d: %d\n",t,ans);
	}
	
    return 0;
}