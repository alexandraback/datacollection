#include<iostream>
#include<cstdio>

#define forloop(i,a,b) for(int i=(a);i<(b);i++)

int solve(){
	int in_list[1100]={0},queue[1100]={0},top,bottom,n,size[1100],matrix[1100][1100],is_d=0,index,base;

	scanf("%d",&n);

	forloop(i,1,n+1){
		scanf("%d",&size[i]);
		forloop(j,0,size[i]){
			scanf("%d",&matrix[i][j]);
			//matrix[i][j]-=1;
		}
	}
/*
	forloop(i,1,n+1){
		printf("%d -> %d: ",i, size[i]);
		forloop(j,0,size[i]){
			printf(" %d ",matrix[i][j]);
		}
		putchar('\n');
	}
*/
	for(int i=1;i<=n && !is_d;i++){
		if(!in_list[i] && !is_d){
			top=0;
			bottom=0;
			base=queue[top]=i;
			while(bottom <= top && !is_d){
				index=queue[bottom++];
				forloop(j,0,size[index]){
//printf("top=%d, bottom=%d, element=%d, in_list=%d, base=%d\n",top,bottom,matrix[index][j],in_list[matrix[index][j]],base);
					if(in_list[matrix[index][j]] != base){
						in_list[matrix[index][j]]=base;
						queue[++top]=matrix[index][j];
					}else{
						is_d=1;
					}
				}
			}
		}
	}

	return is_d;
}

main(){
	int testcases;
	scanf("%d",&testcases);
	forloop(i,0,testcases){
		printf("Case #%d: ",i+1);
		if(solve()){
			printf("Yes\n");
		}else{
			printf("No\n");		
		}
	}
}
