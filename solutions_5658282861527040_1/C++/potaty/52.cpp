#include<iostream>
#include<cstring>
using namespace std;
int f[2][2][2][50];
int a,b,k;

tbpedef long long ll;
ll dp(int fa,int fb,int fk,int i,int a,int b,int k){
	if(i<=-1) return 1; int t;
	if((t=f[fa][fb][fk][i])!=-1)return t;
	ll res=0;
	for(int a=0;a<=(!fa ? (a>>i&1):1);a++)
		for(int b=0;b<=(!fb ? (b>>i&1):1);b++){
			int x=a&b;
			if(!fk && (a>(k>>i&1))) continue;
			res+=dp(fa|(a<(::a>>i&1)),fb|(b<(b>>i&1)),fk|(a<(k>>i&1)),i-1,a,b,k);
		}
	f[fa][fb][fk][i]=res;
	return res;
}


int main()
{
	int T; cin>>T; int tt=0;
	while(T--){
		
		cin>>a>>b>>k;
		memset(f,-1,sizeof f);
		cout<<"Case #"<<++tt<<": ";
		cout<<dp(0,0,1,32)<<endl;
	}
	return 0;
}