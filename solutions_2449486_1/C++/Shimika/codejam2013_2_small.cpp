#include <cstdio>
int q,w,x,y;
int a[105][105];

bool recall(){
	int i,j,k,c;
	for(i=1;i<=x;i++){
		for(j=1;j<=y;j++){
			c=2;
			for(k=1;k<=x;k++){
				if(a[k][j]>a[i][j]){
					c--; break;
				}
			}
			for(k=1;k<=y;k++){
				if(a[i][k]>a[i][j]){
					c--; break;
				}
			}
			if(!c){ return false; }
		}
	}
	return true;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&q);
	int i,j,gt;
	for(w=1;w<=q;w++){
		scanf("%d %d",&x,&y);
		for(i=1;i<=x;i++){
			for(j=1;j<=y;j++){
				scanf("%d",&a[i][j]);
			}
		}
		gt=recall();
		if(!gt){
			printf("Case #%d: NO\n",w);
		}else{ printf("Case #%d: YES\n",w); }
	}
}
