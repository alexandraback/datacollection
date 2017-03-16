#include<cstdio>
using namespace std;
int cas,a,b,ans,nm,tmp,bs;
int alan[10],als;
int main(){
	//freopen("C-large.in","r",stdin);
	//freopen("C-large.out","w",stdout);
	scanf("%d",&cas);
	for(int ca=1;ca<=cas;ca++){
		scanf("%d%d",&a,&b);
		ans=nm=0,tmp=a,bs=1;
		while(tmp>0)tmp/=10,nm++,bs*=10;
		bs/=10;	
		for(int i=a;i<b;i++){
			tmp=i;
			als=0;
			for(int j=0;j<nm;j++){
				tmp=tmp/10+tmp%10*bs;
				if(tmp>i&&tmp<=b){
					bool ok=true;
					for(int k=0;k<als&&ok;k++){
						if(alan[k]==tmp)ok=false;	
					}
					if(ok){
						alan[als++]=tmp;
						ans++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;	
}
