#include <cstdio>
#include <cstring>

int t[1001];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cases,n,s,p,i;
	scanf("%d",&cases);
	for(int casenum=1;casenum<=cases;casenum++){
		scanf("%d%d%d",&n,&s,&p);
		for(i=0;i<n;i++)scanf("%d",&t[i]);
		int def=0,pos=0;
		for(i=0;i<n;i++){
			int k=t[i]/3;
			int m=t[i]%3;
			if(m==0){
				if(k>=p)def++;
				else if(k+1>=p && k>0)pos++;
			}else if(m==1){
				if(k+1>=p)def++;
			}else if(m==2){
				if(k+1>=p)def++;
				else if(k+2>=p)pos++;
			}
		}
		
		printf("Case #%d: %d\n",casenum,def+((pos<s)?pos:s));
		
	}
	return 0;
}