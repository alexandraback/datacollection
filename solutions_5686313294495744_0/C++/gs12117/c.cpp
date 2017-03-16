#include<stdio.h>
#include<string.h>
#include<vector>
int tcn,tc;
int n;
char s[1010][2][25];
int an,bn;
int edge[1010][2];
std::vector<int> ael[1010][2];
std::vector<int> bel[1010][2];
int ans=0;
int am[1010];
int bm[1010];
int amr[1010];
int bmr[1010];
int achk[1010];
int bchk[1010];
int aq[1010];
int bq[1010];
int bback[1010];
int aqn,bqn;
int main(){
	int i,j,k,t;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d",&n);
		an=0;
		bn=0;
		for(i=0;i<n;i++){
			scanf("%s%s",s[i][0],s[i][1]);
			for(j=0;j<i;j++){
				if(strcmp(s[i][0],s[j][0])==0){
					break;
				}
			}
			if(j==i){
				edge[i][0]=an;
				an++;
			}
			else{
				edge[i][0]=edge[j][0];
			}
			for(j=0;j<i;j++){
				if(strcmp(s[i][1],s[j][1])==0){
					break;
				}
			}
			if(j==i){
				edge[i][1]=bn;
				bn++;
			}
			else{
				edge[i][1]=edge[j][1];
			}
		}
		for(i=0;i<an;i++){
			ael[i][0].clear();
			ael[i][1].clear();
		}
		for(i=0;i<bn;i++){
			bel[i][0].clear();
			bel[i][1].clear();
		}
		for(i=0;i<n;i++){
			ael[edge[i][0]][0].push_back(edge[i][1]);
			ael[edge[i][0]][1].push_back(i);
			bel[edge[i][1]][0].push_back(edge[i][0]);
			bel[edge[i][1]][1].push_back(i);
		}
/*		for(i=0;i<an;i++){
			for(j=0;j<ael[i][0].size();j++){
				printf("a%d %d %d %d\n",i,j,ael[i][0][j],ael[i][1][j]);
			}
		}
		for(i=0;i<bn;i++){
			for(j=0;j<bel[i][0].size();j++){
				printf("b%d %d %d %d\n",i,j,bel[i][0][j],bel[i][1][j]);
			}
		}*/
		ans=0;
		for(i=0;i<an;i++){
			am[i]=0;
		}
		for(i=0;i<bn;i++){
			bm[i]=0;
		}
		while(1){
			for(i=0;i<an;i++){
				achk[i]=0;
			}
			for(i=0;i<bn;i++){
				bchk[i]=0;
			}
			aqn=0;
			for(i=0;i<an;i++){
				if(am[i]==0){
					achk[i]=1;
					aq[aqn]=i;
					aqn++;
				}
			}
			while(aqn>0){
				bqn=0;
				for(i=0;i<aqn;i++){
					for(j=0;j<ael[aq[i]][0].size();j++){
						t=ael[aq[i]][0][j];
						if(bchk[t]==0){
							bchk[t]=1;
							bback[t]=aq[i];
							if(bm[t]==0)goto end;
							bq[bqn]=t;
							bqn++;
						}
					}
				}
				aqn=0;
				for(i=0;i<bqn;i++){
					t=bmr[bq[i]];
					if(achk[t]==0){
						achk[t]=1;
						aq[aqn]=t;
						aqn++;
					}
				}
			}
			break;
end:
			ans++;
			bm[t]=1;
			while(am[bback[t]]==1){
				i=amr[bback[t]];
				amr[bback[t]]=t;
				bmr[t]=bback[t];
				t=i;
			}
			am[bback[t]]=1;
			amr[bback[t]]=t;
			bmr[t]=bback[t];
		}
		printf("Case #%d: %d\n",tc,n-an-bn+ans);
	}
	return 0;
}