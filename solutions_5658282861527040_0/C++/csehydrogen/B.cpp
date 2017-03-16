#include <cstdio>

int const MAXB=32;
long long cache[MAXB][2][2][2][2][2][2];
bool a[MAXB],b[MAXB],k[MAXB];

// index, k,kbound,a,abound,b,bbound

long long foo(int index, bool kk, bool kbound, bool aa, bool abound, bool bb, bool bbound){
	if(index+1==MAXB){
		return (1 && !kbound && !abound && !bbound);
	}
	if(cache[index][kk][kbound][aa][abound][bb][bbound]!=0)
		return cache[index][kk][kbound][aa][abound][bb][bbound];
	long long ret=0;
	bool klimit=!kbound || k[index+1];
	bool alimit=!abound || a[index+1];
	bool blimit=!bbound || b[index+1];
	if(klimit){
		if(alimit){
			if(blimit){
				ret+=foo(index+1,1,kbound,1,abound,1,bbound);
			}
			//ret+=foo(index+1,1,kbound,1,abound,0,bbound && !b[index+1]);
		}
		if(blimit){
			//ret+=foo(index+1,1,kbound,0,abound && !a[index+1],1,bbound);
		}
		//ret+=foo(index+1,1,kbound,0,abound && !a[index+1],0,bbound && !b[index+1]);
	}
	if(alimit){
		if(blimit){
			//ret+=foo(index+1,0,kbound && !k[index+1],1,abound,1,bbound);
		}
		ret+=foo(index+1,0,kbound && !k[index+1],1,abound,0,bbound && !b[index+1]);
	}
	if(blimit){
		ret+=foo(index+1,0,kbound && !k[index+1],0,abound && !a[index+1],1,bbound);
	}
	ret+=foo(index+1,0,kbound && !k[index+1],0,abound && !a[index+1],0,bbound && !b[index+1]);

	cache[index][kk][kbound][aa][abound][bb][bbound]=ret;
	return ret;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,ti,aa,bb,kk,i,j;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++){
		scanf("%d%d%d",&aa,&bb,&kk);
		for(i=0;i<MAXB;i++){
			a[i]=aa&(1<<(MAXB-i-1));
			b[i]=bb&(1<<(MAXB-i-1));
			k[i]=kk&(1<<(MAXB-i-1));
		}
		for(i=0;i<MAXB;i++){
			for(j=0;j<64;j++){
				cache[i][(j&1)>0][(j&2)>0][(j&4)>0][(j&8)>0][(j&16)>0][(j&32)>0]=0;
			}
		}
		printf("Case #%d: %d\n",ti,foo(0,0,1,0,1,0,1));
	}
}