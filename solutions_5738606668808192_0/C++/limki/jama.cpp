#include <cstdio>
#include <cstring>
using namespace std;
int T,N,J;
bool isj;
long long proo[11];
long long text;
bool iscomp(long long a,int index){
	long long p,tmp;
	if (index!=2){
		tmp=0;
		while(a>0){
			tmp = tmp * index + (a%2);
			a/=2;
		}
		while(tmp>0){
			a = a * index + (tmp%index);
			tmp/=index;
		}
	}
	text = a;
	//printf("%d %lld\n",index,a);
	for(p=2;p*p<=a;p++)
		if (a%p == 0){
			//printf("--%lld\n",p);
			proo[index] = p;
			return true;
		}
	return false;
}

int main(){
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d %d",&N,&J);
		printf("Case #%d:\n",t);
		//N/=2;
		for(long long i=1 + (1ll<<(N-1));J>0;i+=2){
			//printf("%lld\n",i);
			isj = true;
			for(int p=2;p<11 && isj;p++){
				isj = iscomp(i,p);
			}
			if (isj){
				printf("%lld ",text);
				//printf("%lld%lld ",text,text);
				for(int p=2;p<11;p++)
					printf("%lld%c",proo[p],(p==10)?'\n':' ');
					
				J--;
			}
		}
		
	}	
}

