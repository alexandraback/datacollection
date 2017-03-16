#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<string>
//#include<map>
//setprecision
using namespace std;
class W{
	public:
		//W* l;
		//W* r;
		int l;
		int d;
		int y;
};
bool compare(const W w1,const W w2){
	return w1.d<w2.d;
}
int main(){
	int TT;
	cin>>TT;


	int r,n,m,K;
	int tmp;
	int mi,mj,mk,mii,mjj;
	int mx;
	int a[1000000];
	int b[1000000];
	int th;

	for(int T=1;T<=TT;++T){
		cout<<"Case #"<<T<<": \n";
		cin>>r>>n>>m>>K;
		th=0;
		for(int kk=0;kk<r;++kk){
			for(int i=0;i<K;++i)
				cin>>b[i];
			if(th>=50){
				cout<<"222\n";
				continue;
			}
			mx=0;
			for(int i=2;i<=m;++i){
				for(int j=i;j<=m;++j){
					for(int k=j;k<=m;++k){
						for(int ii=k;ii<=m;++ii){
							for(int jj=ii;jj<=m;++jj){
								for(int l=0;l<=m*m*m*m*m;++l){
									a[l]=0;
								}

								for(int l=0;l<=31;++l){
									tmp=1;
									if(l&1){
										tmp*=i;
									}

									if(l&2){
										tmp*=j;
									}

									if(l&4){
										tmp*=k;
									}
									if(l&8){
										tmp*=mii;
									}
									if(l&16){
										tmp*=mjj;
									}
									a[tmp]=1;
								}

								int tmpx=0;
								for(int l=0;l<K;++l){
									if(b[l]<=m*m*m*m*m&&a[b[l]]==1)
										tmpx++;
								}
								if(tmpx>mx){
									mx=tmpx;
									mi=i;
									mj=j;
									mk=k;
									mii=ii;
									mjj=jj;
								}
							}
						}
					}
				}
			}
			if(mx==0)
			cout<<"222222222222"<<endl;
			else
			cout<<mi<<mj<<mk<<mii<<mjj<<"2222222"<<endl;
			//cout<<endl<<mx;
			//th+=mx;
			//cerr<<th<<"!!!";

		}



		//cout<<"\n";
	}
	return 0;
}




//int compare(const void* a,const void* b){
//	//return *((int*)a)-*((int*)b);
//	return ((W*)a)->d-((W*)b)->d;
//}
//qsort(a,10,sizeof(int),compare);
