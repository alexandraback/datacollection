#include<cstdio>

using namespace std;

int T,I=0,n,s,p,t,ans,i;
int yes[30],no[30];

int main(){
	for (int i=0;i<=10;++i)
		for (int j=i;j>=i-2 && j>=0;--j)
			for (int k=j;k>=i-2 && k>=0;--k)
				if (k==i-2) yes[i+j+k]=i;
				else no[i+j+k]=i;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&n,&s,&p);
        ans=0;
        for (i=0;i<n;++i){
			scanf("%d",&t);
			if(no[t]>=p) ans++;
			else if (s&&yes[t]>=p) ans++,--s;
        }
        printf("Case #%d: %d\n",++I,ans);
    }
}
