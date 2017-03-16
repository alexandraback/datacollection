#include <cstdio>
#include <cstring>

bool v[256]={};
struct Queue{
	int l,r;
} Q[1000000];
int max(int a,int b){
	return (a>b)?a:b;
}
char s[1000001];
int main()
{
	v['a']=v['e']=v['i']=v['o']=v['u']=true;
	int cases,n;
	scanf("%d",&cases);
	for (int t=1;t<=cases;t++){
		scanf("%s %d",s,&n);
		int l=0,r=0,len=strlen(s);
		for (int i=0;i<len;i++)
			if (!v[s[i]]){
				int j;
				for (j=i;j<len;j++)
					if (v[s[j]])
						break;
				j--;
				if (j-i+1>=n)
					Q[r].l=i,Q[r].r=j,r++;
				i=j;
			}
		//for (int i=0;i<r;i++)
		//	printf("Q %d %d\n",Q[i].l,Q[i].r);
		long long ans=0;
		for (int i=0;i<len;i++){
			while (l<r&&Q[l].r-i+1<n)
				l++;
			if (l==r)
				break;
			ans+=(long long)len-(max(Q[l].l,i)+n-1);
		}
		printf("Case #%d: %lld\n",t,ans);
	}
}
/*
4
quartz 3
straight 3
gcj 2
tsetse 2
*/
