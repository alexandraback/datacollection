#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;
string buf[200];

#define CALLPROC(x) ((x)<=c && (c-(x))<=maxc && (x)+m>=c && process(r-1,c,m-(c-(x)),min(maxc,((c-(x)))) ) && ((""!=(buf[r-1]=string((x),'.')+string(c-(x),'*')))) )

bool process(int r, int c, int m, int maxc){
	int x,i,opts[]={0,1,2,3,4,5,6};
	if (m>r*c-1) return false;
	if (m<0) m=0;
	int gap=r*c-m;
	if (r==2){
		if (c==1);
		else if (gap==1);
		else if (m%2==1 || m/2>(c-2) || m/2>maxc) return false;
		if (!CALLPROC(c-(m+1)/2)) return false;
	}
	else if (r==1){
		if (m>c-1) return false;
		buf[r-1]="c"+string(c-1-m,'.')+string(m,'*');
	}
	else{
		int x=c-m;
		if (x>opts[sizeof(opts)/sizeof(opts[0])-1]){
			if (!CALLPROC(x)) return false;
		}
		else{
			for (i=0; i<sizeof(opts)/sizeof(opts[0]); i++){
				if (opts[i]==1 && c!=1) continue;
				if (CALLPROC(opts[i])) break;
			}
			if (i==sizeof(opts)/sizeof(opts[0])) return false;
		}
	}
	return true;
}

int main(){
	int r,c,n,i,j,m,t,u,swapped;
	bool impossible;
	cin>>t;
	for (u=0; u<t; u++){
		cin>>r>>c>>m;
		impossible=false;
		swapped=0;
		if (r<c){
			swapped=1;
			swap(r,c);
		}
		int gap=r*c-m;
		cout<<"Case #"<<(u+1)<<":"<<endl;
		if (gap==0) impossible=true;
		else if (gap==1 || r==1 || c==1);
		else if (r==2 || c==2) impossible=(m%2==1);
		else if (gap==2 || gap==3 || gap==5 || gap==7) impossible=true;
		if (!impossible){
			if (!process(r,c,m,c)) 
				impossible=true;
			else{
				if (swapped){
					for (i=0; i<c; i++){
						for (j=0; j<r; j++) cout<<buf[j][i];
						cout<<endl;
					}
				}
				else{
					for (i=0; i<r; i++){
						for (j=0; j<c; j++) cout<<buf[i][j];
						cout<<endl;
					}
				}
			}
		}
		if (impossible){ 
//			cout<<r<<" "<<c<<" "<<m<<" "<<"Impossible"<<endl;	
			cout<<"Impossible"<<endl;
		}
	}
	return 0;
}
