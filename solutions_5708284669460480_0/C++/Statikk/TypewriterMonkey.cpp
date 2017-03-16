#include <cstdio>
#include <cstring>
int rnd=1,rr;
int r,c,w,ac,base,rem,lo,cb;
int k,t,n,cur,ex,all,end;
double chance,ans;
char a[111];
char b[111];
char kb[111];
int freq[999];
int findLO(){
	int mx=0;
	int cnt;
	for(int i=1;i<=t-1;i++){
		cnt=0;
		for(int j=1;j<=i;j++){
			if(a[t-i+j]==a[j]) cnt++;
			//printf("%d %d %d %d\n",i,t-i+j,j,cnt);
		}
		if(cnt==i) mx=i;
	}
	return mx;
}
void solve(){
	memset(freq,0,sizeof(freq));
	memset(a,0,sizeof(a));
	all=0;
	ex=0;
	chance=1;
	memset(b,0,sizeof(b));
	scanf("%d %d %d",&k,&t,&n);
	for(int i=1;i<=k;i++) {scanf(" %c",&kb[i]);freq[kb[i]]++;}
	for(int i=1;i<=t;i++){
		scanf(" %c",&a[i]);
	}
	//printf("%s\n",&a[1]);
	lo=0;
	lo=findLO();
	for(int i=1;i<=n-lo;i++){
		b[i]=a[i];
	}
	cb=n-lo+1;
	if(lo==0) cb=1;
	cur=cb;
	//printf("%d\n",lo);
	while(cur<=n){
		b[cur]=a[cb];
		//printf("%d %d\n",cur,cb);
		if(cb>t){ cb-=(t-lo); all++;end=cur-1;}
		if(cb==t){ cb-=(t-lo); all++;end=cur;}
		cur++;
		cb++;
	}
	//printf("%d %d %d\n",lo,all,end);
	//printf("%s\n",&b[1]);
	for(int i=1;i<=n&&i<=end;i++){
		if(freq[b[i]]==0){
			all=0;
			chance=0;
			break;
		}
		chance*=((double)freq[b[i]]/(double)k);
	}
	//printf("%d %d %.2lf\n",lo,all,chance);
	//printf("%c\n",a[1]);
	if(t==1) chance=(double)freq[a[1]]/(double)k;
	ans=(double)all-(chance*(double)all);
	//printf("%d\n",t);
	printf("CASE #%d: %.6lf\n",rnd++,ans);
}

int main(){
	//freopen("output.out","w",stdout);
	//freopen("input.in","r",stdin);
	scanf("%d",&rr);
	while(rr--) solve();
	return 0;
}