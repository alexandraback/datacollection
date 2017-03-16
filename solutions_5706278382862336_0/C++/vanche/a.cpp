#include <cstdio>
#include <cstring>
int tc,tcn,len;
long long a,b,g,t,cnt,re;
char s[111];
long long gcd(long long i, long long j){
	long long r=i%j;
	if(!r)
		return j;
	else return gcd(j,r);
}
int main(void){
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&tc);
	while(tc--){
		scanf("%s",s);
		len=strlen(s);
		a=b=0;
		for(int i = 0 ; i< len; i++){
			if(s[i]=='/'){
				for(int j=i+1; j < len ; j++){
					b*=10;
					b+=s[j]-'0';
				}
				break;
			}
			else{
				a*=10;
				a+=s[i]-'0';
			}
		}
		g=gcd(a,b);
		a/=g;
		b/=g;
		t=b;
		cnt=0;
		while(t%2==0){
			t/=2;
			cnt++;
		}
		if(t>1){
			printf("Case #%d: impossible\n",++tcn);
			continue;
		}
		for(long long i=1,j=cnt; ; i=i<<1,j--){
			if(a>=i){
				re=j;
			}
			else break;
		}
		printf("Case #%d: %lld\n",++tcn,re);
	}

	return 0;
}