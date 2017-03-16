#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace::std;

__int64 la;
int ca;
int n,m;

char v[7];
char a[1000005];

void input(){
	scanf("%s %d",a,&n);
	m=strlen(a);
}

void process(){
	int i,j,st=0,p=0;
	bool vv;
	bool posi=false;
	for(i=0;i<m;i++){
		vv=true;
		for(j=1;j<=5;j++)
			if(a[i]==v[j])
				vv=false;
		if(vv){
			++p;
			if(p>=n){
				posi=true;
				st=i-n+1;
			}
		}
		else{
			p=0;
		}

		if(posi)
			la+=st+1;
	}
}

void output(){
	printf("Case #%d: %d\n",ca,la);
}

int main(){
	int i,t;
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small-attempt0.out","wt", stdout);
	scanf("%d",&t);
	v[1]='a';
	v[2]='e';
	v[3]='i';
	v[4]='o';
	v[5]='u';
	while(t--){
		la=0;
		ca++;
		input();
		process();
		output();
	}
	return 0;
}