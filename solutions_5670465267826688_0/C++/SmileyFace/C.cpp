#include <bits/stdc++.h>

using namespace std;

char s[170009];
int arr[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

int mult(int x,int y){
	int c=1;
	if(x<0){x=-x,c=-c;}
	if(y<0){y=-y,c=-c;}
	return arr[x][y]*c;
}

int main(){
	freopen("C-small-attempt3.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;scanf("%d",&tc);
	for(int tcno=1;tcno<=tc;tcno++){
		int l;long long int x;scanf("%d%I64d",&l,&x);
		scanf("%s",s);
		if(l*x<3){
			printf("Case #%d: NO\n",tcno);continue;
		}
		//x=min(x,x%4+17);
		for(int i=0;i<l;i++)s[i]-='g';
		for(int i=l;i<l*x;i++)s[i]=s[i%l];
		s[l*x]=0;
		l*=x;
		int fv=s[0];
		for(int i=1;i<l;i++){
			fv=mult(fv,s[i]);
		}
		if(fv!=-1){
			printf("Case #%d: NO\n",tcno);continue;
		}
		int lv=s[0],lpos=-1;
		if(lv==2)lpos=0;
		else{
			for(int i=1;i<l;i++){
				lv=mult(lv,s[i]);
				if(lv==2){lpos=i;break;}
			}
		}
		int rv=s[l-1],rpos=-1;
		if(rv==4)rpos=l-1;
		else{
			for(int i=l-2;i>=0;i--){
				rv=mult(s[i],rv);
				if(rv==4){rpos=i;break;}
			}
		}
		if(lpos!=-1&&rpos!=-1&&lpos<rpos){
			printf("Case #%d: YES\n",tcno);continue;
		}
		else{
			printf("Case #%d: NO\n",tcno);continue;
		}
	}
}
