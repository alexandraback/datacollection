#include<cstdio>
int main(){
	freopen("D-large.bin","r",stdin);
	freopen("output.txt","w",stdout);
	int t;scanf("%d",&t);
	int k,c,s,i,j;
	long long one,p;
	for(int cas=1;cas<=t;cas++){
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:",cas);
		if(k>c*s){printf(" IMPOSSIBLE\n");continue;}
                i=0;
		while(i<k){
                        j=i;one=0;
                        p=1;
                        for(s=1;s<c;s++)p=p*k;
                        for(s=0;s<c;s++){
                            one+=p*j;
                            j++;
                            p=p/k;
                            if(j==k)j--;
                        }
			printf(" %lld",++one);
			i+=c;
		}
		printf("\n");
	}
	return 0;
}
