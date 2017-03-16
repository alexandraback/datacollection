#include<stdio.h>
#include<algorithm>
using namespace std;



int mn[200][200];

int main(){
	int n,i,j,k,T,l,m;
//	freopen("B-small-attempt1.in","r",stdin);
//	freopen("B.txt","w",stdout);


	bool res,mc;
	scanf("%d",&T);
	for(i=1;i<=T;i++){

		printf("Case #%d: ",i);
		scanf("%d%d",&n,&m);

		for(j=1;j<=n;j++){
			for(k=1;k<=m;k++){
				scanf("%d",&mn[j][k]);
			}
		}




		res=true;

		for(j=1;j<=n;j++){
			for(k=1;k<=m;k++){

				if(mn[j][k]==1){

					for(l=1;l<=m;l++){
						if(mn[j][l]!=1){res=false;break;}
					}

					if(!res){
						mc=true;
						for(l=1;l<=n;l++){
							if(mn[l][k]!=1){mc=false;break;}
						}

						res=mc;
					}
				}

				if(!res)
					break;
			}

			if(!res)
				break;
		}



		if(res){
			printf("YES\n");
		}
		else
			printf("NO\n");

	}


return 0;
}
