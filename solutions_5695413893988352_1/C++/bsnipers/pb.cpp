#include <stdio.h>
#include <string.h>

#include <vector>

using namespace std;

typedef long long ll;

char cod[30];
char jam[30];

int up[20];
int down[20];

ll cs,js;

ll mabs(ll n)
{
	return n<0?-n:n;
}

int len;

void go(int pos, ll tcs, ll tjs, ll bas)
{
	if(pos==len){
		if(mabs(cs-js)>mabs(tcs-tjs)){
			cs=tcs;
			js=tjs;
		}else if(mabs(cs-js)==mabs(tcs-tjs)){
			if(cs>tcs){
				cs=tcs;
				js=tjs;
			}else if(cs==tcs){
				if(js>tjs){
					cs=tcs;
					js=tjs;
				}
			}
		}
		return ;
	}
	if(cod[pos]!='?' && jam[pos]!='?'){
		go(pos+1,tcs+bas*cod[pos],tjs+bas*jam[pos],bas/10);
	}else if(cod[pos]!='?'){
		if(tcs==tjs){
			go(pos+1,tcs+bas*cod[pos],tjs+bas*up[cod[pos]],bas/10);
			go(pos+1,tcs+bas*cod[pos],tjs+bas*cod[pos],bas/10);
			go(pos+1,tcs+bas*cod[pos],tjs+bas*down[cod[pos]],bas/10);
		}else if(tcs>tjs){
			go(pos+1,tcs+bas*cod[pos],tjs+bas*9,bas/10);
		}else{
			go(pos+1,tcs+bas*cod[pos],tjs,bas/10);
		}
	}else if(jam[pos]!='?'){
		if(tcs==tjs){
			go(pos+1,tcs+bas*up[jam[pos]],tjs+bas*jam[pos],bas/10);
			go(pos+1,tcs+bas*jam[pos],tjs+bas*jam[pos],bas/10);
			go(pos+1,tcs+bas*down[jam[pos]],tjs+bas*jam[pos],bas/10);
		}else if(tcs>tjs){
			go(pos+1,tcs,tjs+bas*jam[pos],bas/10);
		}else{
			go(pos+1,tcs+bas*9,tjs+bas*jam[pos],bas/10);
		}
	}else{
		if(tcs==tjs){
			go(pos+1,tcs,tjs,bas/10);
			go(pos+1,tcs+bas,tjs,bas/10);
			go(pos+1,tcs,tjs+bas,bas/10);
		}else if(tcs>tjs){
			go(pos+1,tcs,tjs+bas*9,bas/10);
		}else{
			go(pos+1,tcs+bas*9,tjs,bas/10);
		}
	}
}



int main()
{
	for(int i=0; i<10; i++){
		up[i]=(i+1)%10;
		down[i]=(i+9)%10;
	}
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		scanf("%s %s",cod,jam);
		cs=1ll<<62;
		js=0;
		len=strlen(cod);
		for(int i=0; i<len; i++){
			if(cod[i]!='?') cod[i]-='0';
			if(jam[i]!='?') jam[i]-='0';
		}
		ll bas=1;
		for(int i=1; i<len; i++)
			bas*=10;
		go(0,0,0,bas);
		printf("Case #%d: %0*I64d %0*I64d\n",T,len,cs,len,js);
	}
	return 0;
}
