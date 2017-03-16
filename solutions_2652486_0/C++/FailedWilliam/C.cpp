#include<stdio.h>
const int maxcnt=1000;
const int maxK=12;
const char inf[]="C-small-1-attempt0.in";
const char ouf[]="C-small-1-attempt0.out";

int R,n,m,K;
int a[maxK+1];

int list[maxcnt+1][maxcnt+1],cnt;

void input(){
    scanf("%ld",&R);
    scanf("%ld%ld%ld%ld",&R,&n,&m,&K);    
}

void dfs(int h,int now){
    int i,j,k;
    if(h>n){
	int i;
	cnt++;
	list[cnt][0]=now;
	for(i=1;i<=maxcnt;i++)
	    list[cnt][i]=0;
	return;
    }
    for(i=2;i<=m;i++)
	dfs(h+1,now*10+i);
}

void get(int no,int num,int h,int now){
    if(h>n){
	list[no][now]++;
	return;
    }
    get(no,num/10,h+1,now);
    get(no,num/10,h+1,now*(num%10));
}

void prepare(){
    int i,j,k;
    cnt=0;
    dfs(1,0);
    for(i=1;i<=cnt;i++)
	get(i,list[i][0],1,1);
}

void work(){
    int i,j,k,ok;
    prepare();
    printf("Case #1:\n");
    for(i=1;i<=R;i++){
	for(j=1;j<=K;j++){
	    scanf("%ld",a+j);
	}
	for(j=1;j<=cnt;j++){
	    ok=1;
	    for(k=1;k<=K;k++){
		if(!list[j][a[k]]){
		    ok=0;
		    break;
		}
	    }
	    if(ok){
		printf("%ld\n",list[j][0]);
		break;
	    }
	}
    }
}

int main(){
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    input();
    work();
    return 0;
}
