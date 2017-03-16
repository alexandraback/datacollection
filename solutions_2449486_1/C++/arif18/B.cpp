#include<stdio.h>
#include<algorithm>
using namespace std;



int mn[200][200];

int main(){
	int n,i,j,k,T,l,m,v;
//	freopen("B-large.in","r",stdin);
//	freopen("B2.txt","w",stdout);


	bool res,mc;
	int Max;
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

				v=mn[j][k];
				Max=0;
				for(l=1;l<=m;l++) if(Max<mn[j][l]) Max=mn[j][l];


				if(v!=Max){
					for(l=1;l<=m;l++){
						if(mn[j][l]>v){res=false;break;}
					}

					if(!res){
						mc=true;
						for(l=1;l<=n;l++){
							if(mn[l][k]>v){mc=false;break;}
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
