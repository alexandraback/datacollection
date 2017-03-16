#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reg(i,a,b) for(int i=(a);i<=(b);i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=(b);i>=(a);i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX



int main(void){
	
	int qn;
	scanf("%d",&qn);
	reg(qq,1,qn){
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		
		/*
		int qq = 0;
		reg(in,1,4)reg(ix,1,4)reg(iy,1,4){
			int n=in,x=ix,y=iy;
			qq++;
			printf("n..%d x..%d y..%d   ",n,x,y);
		*/
		
		bool ans = false;
		switch(n){
		case 1:
			ans = true;
			break;
		case 2:
			if((x*y)%2==0)ans = true;
			break;
		case 3:
			if(x==1 || y==1)break;
			if((x*y)%3==0)ans = true;
			break;
		case 4:
			if((x*y)%4!=0)break;
			if(x>y)swap(x,y);
			if(y<4)break;
			if(x<=2)break;
			ans = true;
			break;
		case 5:
			if((x*y)%5!=0)break;
			if(x>y)swap(x,y);
			if(y<5)break;
			if(x<=2)break;
			if(x==3 && y==5)break;
			ans = true;
			break;
		case 6:
			if((x*y)%6!=0)break;
			if(x>y)swap(x,y);
			if(y<6)break;
			switch(x){
			case 1:
			case 2:
			case 3:
				break;
			case 4:
			case 5:
			default:
				ans = true;
				break;
			}
			break;
		default:
			break;
		}
		printf("Case #%d: ",qq);
		if(ans)printf("GABRIEL\n");
		else printf("RICHARD\n");
	}
	return 0;
}




