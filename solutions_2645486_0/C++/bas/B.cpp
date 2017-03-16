#include<iostream>
#include<vector>
#include<string>
#define big 1000000000

using namespace std;
	int C, E, R, n;
         vector<int> v;
long long f(int b, int e, int sE, int fE, int & rE){
	if(e<b) {rE=sE; return 0;}
	if(e==b){
		long long usable = min(-fE+R+sE, sE);
		if(usable<0){
			rE = min(sE+R, E); 
			return 0;
		}else{
			rE=fE;
			return usable*v[b];
		}
	}
	int mx=0; int mi=0;	
	 for(int i=b; i<=e; i++)if(v[i]>mx){mi=i; mx=v[i];}
	int re1=rE;
	long long res=0;
	long long v1 = f(b, mi-1, sE, E, re1);
//	long long usable = min(-fE+R+sE, sE);
	long long v3 = f(mi, mi, re1, max(R, fE-R*(e-mi)), re1);
//	res+=usable*mx;
	int nE = re1;
//cout<<nE;
	long long v2=f(mi+1, e, nE, fE, re1);
	res+=v1+v2+v3;
//cout<<b<<" "<<e<<" "<<res<<" "<<v1<<" "<<v2<<" "<<v3<<"\n";
	return res;
}
int main(){
	v = vector<int>(10001);
	
	cin>>C; 
	for(int j=0; j<C; j++){
		cin>>E>>R>>n;
		for(int i=0; i<n; i++){cin>>v[i];}
		int re=E;
		long long  res=f(0, n-1, E, 0, re);
		cout<<"Case #"<<j+1<<": " <<res<<"\n";
	}
	
}
