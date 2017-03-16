#include <stdio.h>


char str[80005];

int mmap[10][10];

void build()
{
	for(int i=0; i<4; i++){
		mmap[i][0]=i;
		mmap[0][i]=i;
	}
	for(int i=1; i<4; i++)
		mmap[i][i]=4;
	mmap[1][2]=3;
	mmap[1][3]=6;
	mmap[2][1]=7;
	mmap[2][3]=1;
	mmap[3][1]=2;
	mmap[3][2]=5;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			mmap[i][j+4]=(mmap[i][j]+4)%8;
			mmap[i+4][j]=(mmap[i][j]+4)%8;
			mmap[i+4][j+4]=mmap[i][j];
		}
	}
}

int square(int state=0, int tim=1){
	int tmp=0;
	while(tim--){
		tmp=mmap[tmp][state];
	}
	return tmp;
}

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("pc1.out","w",stdout);
	int cas;
	build();
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		long long l,x,tx,tl;
		scanf("%I64d %I64d",&l,&x);
		if(x>=8)
			tx=8;
		else
			tx=x;
		tl=l*tx;
		scanf("%s",str);
		int state=0;
		for(int i=0; i<l; i++){
			str[i]-='h';
			state=mmap[state][str[i]];
			for(int j=1; j<tx; j++){
				str[i+j*l]=str[i];
			}
		}
		printf("Case #%d: ",T);
		if(square(state,x%4)==4){
			int pos=tl+3,pos2=-3;
			state=0;
			for(int i=0; i<tl; i++){
				state=mmap[state][str[i]];
				if(state==1){
					pos=i;
					break;
				}
			}
			state=0;
			for(int i=tl-1; i>=0; i--){
				state=mmap[str[i]][state];
				if(state==3){
					pos2=i;
					break;
				}
			}
			if(pos<pos2){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
