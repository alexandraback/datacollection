#include <iostream>
#include <cstdio>
using namespace std;

int ar[1000000];
int ar_n;

int main(){
	int t;
	scanf("%d",&t);
	for(int Case=1; Case<=t; Case++){
		getchar();
		ar_n=0;
		int tmp=0,n,L=0;
		bool vow=false;
		char c=getchar();
		if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
			ar[ar_n++]=0;
			vow=true;
		}
		while(c!=' '){
			L++;
			if(vow){
				if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') tmp++;
				else{
					ar[ar_n++]=tmp;
					vow=false;
					tmp=1;
				}
			}
			else{
				if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
					ar[ar_n++]=tmp;
					vow=true;
					tmp=1;
				}
				else tmp++;
			}
			c=getchar();
		}
		ar[ar_n++]=tmp;
		scanf("%d",&n);
		long long int ans=0,total=0;
		for(int i=0; i<ar_n; i++){
			for(int j=1; j<=ar[i]; j++){
				int Num=total+j;
				int tmp_tol=L-total-ar[i]+1;
				for(int k=i; k<ar_n; k++){
					int tt;
					if(k==i) tt=ar[i]-j+1;
					else {tt=ar[k]; tmp_tol-=ar[k];}
					if(k%2==0 && tt>=n){
						ans+=(tmp_tol+(tt-n));
//						printf("%d %d\n",Num,tmp_tol);
//						if(k==i) tmp_tol=tmp_tol+j-ar[i];
						break;
					}
//					if(k==i) tmp_tol=tmp_tol+j-ar[i];
				}
			}
			total+=ar[i];
		}
//		for(int i=0; i<ar_n; i++) printf("%d ",ar[i]); printf("\n");
		printf("Case #%d: %lld\n",Case,ans);
	}
	return 0;
}
