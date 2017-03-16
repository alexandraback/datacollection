#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct abcd{
	int day,nt,west,east,str,Dd,Dp,Ds;
}a[1000];
	

int main(){
//freopen("C-small-attempt0.in","r",stdin);
//freopen("C-small-attempt0.out","w",stdout);
     int tc,i,j,k,ii,n;
     scanf("%d",&tc);
     for(ii=1;ii<=tc;ii++){
    	scanf("%d",&n);
    	int h[3000],ans=0;
    	for(i=0;i<=2000;i++)h[i]=0;
    	for(i=1;i<=n;i++){
			scanf("%d %d %d %d %d %d %d %d",&a[i].day,&a[i].nt,&a[i].west,&a[i].east,&a[i].str,&a[i].Dd,&a[i].Dp,&a[i].Ds);
    	    a[i].west+=1000;
    	    a[i].east+=999;
		}
		int day=0;
		int succ[20];
		while(1){
			for(i=1;i<=n;i++)succ[i]=0;
			int ntt=0;
			for(i=1;i<=n;i++){
				if(a[i].nt>0)ntt=1;
				
				if(a[i].day==day){
					if(a[i].nt>0){
						a[i].nt--;
						a[i].day+=a[i].Dd;
						
						for(j=a[i].west;j<=a[i].east;j++){
							if(a[i].str>h[j])succ[i]=1;
						}
						ans+=succ[i];
						a[i].east+=a[i].Dp;
						a[i].west+=a[i].Dp;
						a[i].str+=a[i].Ds;
						
					}
				}
			}
			for(i=1;i<=n;i++){
				if(succ[i]==1){
					for(j=a[i].west-a[i].Dp;j<=a[i].east-a[i].Dp;j++){
						h[j]=max(a[i].str-a[i].Ds,h[j]);
					}
				}
			}
			if(ntt==0){
				break;
		    }	
		    //printf("%d    ",day);
		    //for(i=1000;i<=1010;i++)printf("%d ",h[i]);
		   // printf("    %d\n",ans);
			day++;
		}
					
					
					
		printf("Case #%d: %d\n",ii,ans);			
					
    	
    	
    	
    	
     }
	




	return 0;
}
	
