#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long 
int change(char c){
	switch(c){
		case '1': return 0;
		case 'i': return 1;
		case 'j': return 2;
		case 'k': return 3;
	} 
	return 0;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int table[4][4]={ // 1  i   j  k
	{1,2 ,3 ,4},    //1  1  i   j  k
	{2,-1,4,-3},    //i  i -1   k -j
	{3,-4,-1,2},    //j  j -k  -1  i
	{4,3,-2,-1}};   //k  k  j  -i -1
	int T;
	scanf("%d",&T);
	for(int in=1;in<=T;in++){
		int inum=0,knum=0;
		LL l,x;
		char c[10001];
		scanf("%lld%lld%s",&l,&x,c);
		bool Icom=false,Kcom=false,ans=true; 
		// 判斷 i (也就是2)
		int state=table[0][change(c[0])];
		for(int ic=1;ic<=l*4;ic++){
			inum++;
			if(state==2){
				Icom=true;
				break;
			}
			state=(state-1<0?-1:1)*table[abs(state)-1][change(c[ic%l])];
		}
		if(!Icom)ans=false;
		//判斷 k (也就是4)
		state=table[0][change(c[l-1])];
		for(int ic=1;ic<l*4;ic++){ 
			int temp=(l*4-1-ic)%(l);
			knum++;
			if(state==4){
				Kcom=true;
				break;
			}
			state=(state-1<0?-1:1)*table[change(c[temp])][abs(state)-1];
		} 
		if(!Kcom)ans=false;
		//判斷-1
		state=table[0][change(c[0])];
		for(int ic=1;ic<l*(x%4);ic++){
			state=(state-1<0?-1:1)*table[abs(state)-1][change(c[ic%l])];
		}
		if(state!=-1){ans=false;}
		//判斷 i k需求量是否符合
		if(inum+knum>l*x){
			ans=false;
		} 
		printf("Case #%d: ",in);
		puts(ans?"YES":"NO");
	}
}
