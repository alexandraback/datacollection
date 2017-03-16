#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
long long n,t,res,tmp,dl;
int bff[1001];
int cyc_pom[1001];
int cyc[1001];
int lo[1001];
int odl[1001];
int wyn[1001];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>t;
	for(int test_nr=1;test_nr<=t;test_nr++){
		std::cin>>n;
		for(int i=1;i<=n;i++){
			std::cin>>bff[i];
			cyc_pom[i]=0;
			cyc[i]=0;
			lo[i]=0;
			wyn[i]=0;
			odl[i]=0;
		}
		int max_cyc=0;
		int cyc_2=0;
		for(int i=1;i<=n;i++){
			if(cyc_pom[i]==0){
				int j;
				int dl=0;
				for(j=bff[i];cyc_pom[j]==0;j=bff[j]){
					dl++;
					cyc_pom[j]=dl;
					lo[j]=i;
				}
				if(lo[j]==i){
					int dl_cyc=dl-cyc_pom[j]+1;
					if(dl_cyc>max_cyc)
						max_cyc=dl_cyc;
					if(dl_cyc==2){
						cyc_2+=dl+1;
					//std::cout<<"i:"<<i<<" "<<dl+1<<std::endl;
						wyn[j]=dl-1;
						dl=cyc_pom[j];
						cyc[j]=j;
						cyc[bff[j]]=bff[j];
						for(int k=i;dl>0;dl--,k=bff[k]){
							//std::cout<<"odl:"<<k<<" "<<dl<<std::endl;
							odl[k]=dl;
							cyc[k]=j;
						}
							
					}
				}else{
					if(cyc[j]!=0){
						dl+=odl[j]+1;
						if(dl>wyn[cyc[j]]){
							cyc_2+=dl-wyn[cyc[j]];
							//std::cout<<"wyn"<<i<<" "<<dl-wyn[cyc[j]]<<std::endl;
							wyn[cyc[j]]=dl;
							
						}
						for(int k=i;dl>odl[j];dl--,k=bff[k]){
							//std::cout<<"odlx:"<<k<<" "<<dl<<std::endl;
							odl[k]=dl;
							cyc[k]=j;
						}
					}
				}
			}
		}
				
				
				
				
				/*cyc[i]=1;
				lo[i]=i;
				dl=1;
				int j;
				for(j=bff[i];cyc[j]==0;j=bff[j]){
					dl++;
					cyc[j]=dl;
					//lo[j]=i;
				}
				
				if(lo[j]=i){
					dl=dl-cyc[j]+1;
					std::cout<<dl<<std::endl;
					if(dl==2){
						cyc_2+=2;
						cyc[j]=-1;
						cyc[bff[j]==-1];
					}
					
				}else
					for(int k=bff[i];k!=j;k=bff[k]){
						dl++;
						cyc[k]=dl;
						lo[k]=lo[j];
					}
			}
		}*/
		//std::cout<<cyc_2<<" "<<max_cyc<<std::endl;
		std::cout<<"Case #"<<test_nr<<": "<<std::max(cyc_2,max_cyc)<<std::endl;
		
		
	}
}
