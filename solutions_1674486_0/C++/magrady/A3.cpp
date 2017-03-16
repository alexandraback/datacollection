#include<stdio.h>
#include<string.h>
#include<algorithm>
int a[1001][1001],aa[1001][1001],ua[1001];
int map[1001][1001],c[1001];
int in[1001],out[1001];
int t[1001],used[1001];
int d[1001];
main(){
	int i,j,k,bk,p;
	int T,TN;
	int n,m;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d",&n);
		printf("Case #%d: ",T);
		for(i=0;i<n;i++){
			in[i]=out[i]=0;
			used[i]=0;
			ua[i]=0;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)map[i][j]=0;
		}
		for(i=0;i<n;i++){
			scanf("%d",&c[i]);
			for(j=0;j<c[i];j++){
				scanf("%d",&a[i][j]);
				a[i][j]--;
				map[i][a[i][j]]=1;
				aa[a[i][j]][ua[a[i][j]]++]=i;
				in[a[i][j]]++;
				out[i]++;
			}
		}
		/*for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					if(map[i][k]&&map[k][j])map[i][j]++;
				}
			}
		}*/
		
		/*for(i=0;i<n;i++){
			printf("%d ",in[i]);
		}
		puts("");
		for(i=0;i<n;i++){
			printf("%d ",out[i]);
		}
		puts("");*/
		bk=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(in[j]==0&&!used[j]){
					used[j]=1;
					break;
				}
			}
			if(j<n){
				t[bk++]=j;
				for(p=0;p<c[j];p++){
					in[a[j][p]]--;
					out[j]--;
				}
			}
		}
		
		/*for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(map[t[i]][t[j]]>1)goto XDDD;
			}
		}*/
		/*if(bk!=n)puts("XXXX");
		for(i=0;i<n;i++){
			printf("%d ",t[i]);
		}*/
		//puts("");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)d[j]=0;
			d[t[i]]=1;
			
			for(j=i+1;j<n;j++){
				d[t[j]]=0;
				//printf("%d,%d %d\n",i,j,ua[t[j]]);
				for(k=0;k<ua[t[j]];k++){
					d[t[j]]+=d[aa[t[j]][k]];
					//printf("%d<-%d\n",t[j],aa[t[j]][k]);
					//if(aa[t[j]][k])
				}
				if(d[t[j]]>1){
					//printf("%d %d\n",i,j);
					break;
				}
			}
			if(j<n)break;
		}
			
					
		if(i>=n)printf("No\n");
		else
		printf("Yes\n");
	}
}
