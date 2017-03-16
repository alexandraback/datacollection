#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int pt[20];
string A,B;
bool ok(int n,string A){
	for(int i=0;i<A.size();i++){
		if(A[i]!='?'){
			int ip=A.size()-i-1;
			if((n/pt[ip])%10!=A[i]-'0'){
				return false;
			}
		}
	}
	return true;
}
void printt(int n,string A){
	string s;
	for(int i=0;i<A.size();i++){
		s+=n%10+'0';
		n/=10;
	}
	reverse(s.begin(),s.end());
	cout<<s;
}
int abs(int l){
	if(l<0){
		l*=-1;
	}
	return l;
}
int main(){

	pt[0]=1;
	pt[1]=10;
	pt[2]=100;
	pt[3]=1000;
	int tt;
	cin>>tt;
	for(int ii=0;ii<tt;ii++){
		cin>>A>>B;
		int sz=A.size();
		int mx=1;
		for(int i=0;i<sz;i++){
			mx*=10;
		}
		int Min=10000000;
		int Mini;
		int Minj;
		for(int i=0;i<mx;i++){
			for(int j=0;j<mx;j++){
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
		printt(Mini,A);
		cout<<" ";
		printt(Minj,A);
		cout<<endl;
	}
}
