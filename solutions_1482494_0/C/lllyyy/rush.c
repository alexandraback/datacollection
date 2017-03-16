#include <stdio.h>

int lvcmp(const void *r1,const void *r2){
	int *v1=(int *)r1,*v2=(int *)r2;
	if(*(v1+1)!=*(v2+1)){
		return *(v1+1)-*(v2+1);
	}
	return *v1-*v2;
}


int castle[1000][2];
int visited[1000][2];

int nlevels;

void print(){
	int i,j;
	printf("===\n");
	for(i=0;i<nlevels;i++){
		printf("%d %d\n",castle[i][0],castle[i][1]);
	}
	printf("====\n");
}

int main(){
	int i,j,k,m,n,p,numcase,nsteps,possible,currs;
	FILE *out=fopen("rush.out","w");
	scanf("%d",&numcase);
	for(i=0;i<numcase;i++){
		scanf("%d",&nlevels);
		for(j=0;j<nlevels;j++)
			visited[j][0]=0;
		for(j=0;j<nlevels;j++){
			scanf("%d %d",&castle[j][0],&castle[j][1]);
		}
		//has gotten all inputs
		printf("case#%d:\n",i+1);
		//print();
		qsort(castle,nlevels,2*sizeof(int),lvcmp);
		print();
		possible=1;nsteps=0;currs=0;
		for(j=0;j<nlevels&&possible;j++){
			while(currs<castle[j][1]){
				for(k=nlevels-1;k>=0;k--){
					if(!visited[k][0]&&currs>=castle[k][0]){
						//printf("%d %d\n",k,0);
						visited[k][0]=1;currs++;nsteps++;break;
					}
				}
				if(k==-1){
					possible=0;break;
				}
			}
			//printf("%d %d\n",j,1);
			if(visited[j][0]){
				currs+=1;
			}else{
				currs+=2;
			}
			nsteps++;
		}
		if(possible){
			fprintf(out,"Case #%d: %d\n",i+1,nsteps);
		}else{
			fprintf(out,"Case #%d: Too Bad\n",i+1);
		}
	}
	return 0;

}
