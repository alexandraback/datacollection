#include<iostream>
using namespace std;
int main(){
	int T,kase,x,r,mark,tmp,c;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small.out","w",stdout);
	scanf("%d",&T);
	for(kase=1;kase<=T;kase++){
		scanf("%d%d%d",&x,&r,&c);
		if(r>c) tmp=c,c=r,r=tmp;
		switch(x){
			case 1: mark=1; break;
			case 2: mark=!((r&1)&&(c&1)); break;
			case 3: 
					mark=(r==2&&c==3)||(r==3&&c==3)||(r==3&&c==4); 
					break;
			case 4:
					mark=(r==3&&c==4)||(r==4&&c==4);
		};
		
		printf("Case #%d: %s\n",kase,(mark?"GABRIEL":"RICHARD"));
	}
	return 0;
}
