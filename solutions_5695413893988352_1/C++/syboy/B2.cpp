#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
string A,B;
ll Min=-1;
string Mini,Minj;
void checkmin(string A,string B){
	ll pt=1;
	ll df=0;
	for(ll i=A.size()-1;i>=0;i--){
		df+=(A[i]-B[i])*pt;
		pt*=10;
	}
	if(df<0){
		df*=-1;
	}
	if(Min==-1 || Min>df){
		Min=df;
		Mini=A;
		Minj=B;
	}
	if(Min==df){
		if(A<Mini){
			Mini=A;
			Minj=B;
		}else{
			if(A==Mini){
				if(B<Minj){
					Mini=A;
					Minj=B;
				}
			}
		}
	}
}


void addtodata(string A,string B,ll vz,ll pt){
	cerr<<endl;
	cerr<<A<<"-"<<B<<endl;
	for(ll i=pt;i<A.size();i++){
		if(A[i]=='?'){
			if(vz==1){
				A[i]='0';
			}else{
				A[i]='9';
			}
		}
		if(B[i]=='?'){
			if(vz==1){
				B[i]='9';
			}else{
				B[i]='0';
			}
		}
	}
	cerr<<A<<"-"<<B<<endl;
	checkmin(A,B);
}

int main(){

	ll tt;
	cin>>tt;
	for(ll ii=0;ii<tt;ii++){
		cin>>A>>B;
		cerr<<A.size()<<" "<<B.size()<<endl;
		Min=-1;
		ll sz=A.size();
		ll vz=0;
		ll pt=0;
		for(ll i=0;i<A.size();i++){
			if(A[i]=='?'){
				if(B[i]=='?'){

					A[i]='1';
					B[i]='0';
					addtodata(A,B,1,i);

					A[i]='0';
					B[i]='1';
					addtodata(A,B,0,i);

					A[i]='0';
					B[i]='0';

				}else{
					for(ll j=0;j<=9;j++){
						A[i]=j+'0';
						if(A[i]!=B[i]){
							addtodata(A,B,(A[i]>B[i]),i);
						}
					}
					A[i]=B[i];
				}
			}else{
				if(B[i]!='?'){
					if(B[i]!=A[i]){
					pt=i;
					if(A[i]>B[i]){
						vz=1;
					}else{
						vz=0;
					}
					break;
					}
				}else{

					for(ll j=0;j<=9;j++){
						B[i]=j+'0';
						if(A[i]!=B[i]){
							addtodata(A,B,(A[i]>B[i]),i);
						}
					}
					B[i]=A[i];
				}
			}
		}

		addtodata(A,B,vz,pt);
		cout<<"Case #"<<ii+1<<": "<<Mini<<" "<<Minj<<endl;
/*

		ll mx=1;
		for(ll i=0;i<sz;i++){
			mx*=10;
		}
		ll Min=10000000;
		ll Mini;
		ll Minj;
		for(ll i=0;i<mx;i++){
			for(ll j=0;j<mx;j++){
				if(abs(i-j)<=Min){
					if(ok(i,A) && ok(j,B)){
						if(abs(i-j)<Min){
							Min=abs(i-j);
							Mini=i;
							Minj=j;
						}
					}
				}
			}
		}
		cerr<<Mini<<" "<<Minj<<endl;
		cout<<"Case #"<<ii+1<<": ";
		prllt(Mini,A);
		cout<<" ";
		prllt(Minj,A);
		cout<<endl;

		*/
		}
}
