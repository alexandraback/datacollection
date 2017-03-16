#include <cstdio>
int q,w,a[5][5],xi,yi;
char t[5],e[4]={'X','.','O'};

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&q);
	int i,j,flag,c,z;
	for(w=1;w<=q;w++){
		xi=yi=c=flag=0;
		for(i=1;i<=4;i++){
			scanf("%s",t+1);
			for(j=1;j<=4;j++){
				switch (t[j])
				{
				case 'X':a[i][j]=-1;c++;break;
				case 'O':a[i][j]=1;c++;break;
				case 'T':xi=i,yi=j;c++;break;
				case '.':
					a[i][j]=0;break;
				}
			}
		}
		a[xi][yi]=-1;
		for(j=1;j<=4;j++){
			if(flag){ break; }

			z=0;
			for(i=1;i<=4;i++){ z+=a[j][i]; }
			if(z==4){ flag=1; }
			if(z==-4){ flag=-1; }
			
			z=0;
			for(i=1;i<=4;i++){ z+=a[i][j]; }
			if(z==4){ flag=1; }
			if(z==-4){ flag=-1; }

			if(flag){ break; }
		}
		if(!flag){
			z=0;
			for(i=1;i<=4;i++){
				z+=a[i][i];
			}
			if(z==4){ flag=1; }
			if(z==-4){ flag=-1; }
		}
		if(!flag){
			z=0;
			for(i=1;i<=4;i++){
				z+=a[5-i][i];
			}
			if(z==4){ flag=1; }
			if(z==-4){ flag=-1; }
		}

		a[xi][yi]=1;
		for(j=1;j<=4;j++){
			if(flag){ break; }

			z=0;
			for(i=1;i<=4;i++){ z+=a[j][i]; }
			if(z==4){ flag=1; }
			if(z==-4){ flag=-1; }
			
			z=0;
			for(i=1;i<=4;i++){ z+=a[i][j]; }
			if(z==4){ flag=1; }
			if(z==-4){ flag=-1; }

			if(flag){ break; }
		}
		if(!flag){
			z=0;
			for(i=1;i<=4;i++){
				z+=a[i][i];
			}
			if(z==4){ flag=1; }
			if(z==-4){ flag=-1; }
		}
		if(!flag){
			z=0;
			for(i=1;i<=4;i++){
				z+=a[5-i][i];
			}
			if(z==4){ flag=1; }
			if(z==-4){ flag=-1; }
		}

		printf("Case #%d: ",w);
		if(flag){
			printf("%c won\n",e[flag+1]);
		}else{
			if(c==16){
				printf("Draw\n");
			}else{
				printf("Game has not completed\n");
			}
		}
	}
	return 0;
}
