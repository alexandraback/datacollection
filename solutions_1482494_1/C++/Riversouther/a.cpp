#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
	int tp,val,id;
	bool operator <(const Node &nd)const{
		if(val==nd.val)	return tp<nd.tp;
		else	return val<nd.val;
	}
};


int a[2005][2];
Node nd[2005];

int main(){
	int i,j,k,m,n,c,r,ans,t;
	Node tnd;
	bool f,ff;

	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	scanf("%d",&r);
	for(c=1;c<=r;++c){
		scanf("%d",&n);
		for(i=0;i<n;++i){
			scanf("%d",&nd[2*i].val);
			nd[2*i].tp=1;
			nd[2*i].id=i;
			scanf("%d",&nd[2*i+1].val);
			nd[2*i+1].tp=2;
			nd[2*i+1].id=i;
		}
		sort(nd,nd+2*n);
		k=0;
		ans=0;
		f=true;
		for(i=0;i<2*n;++i){
			if(nd[i].val>k){
				f=false;
				break;
			}
			a[i][1]=nd[i].id;
			if(nd[i].tp==2){
				for(t=0;t<i;++t){
					if(a[t][1]==nd[i].id)	break;
				}
				ff=true;
				for(j=t+1;j<i;++j){
					if(a[j][0]==0){
						ff=false;
						break;
					}
				}
				if(nd[i].val==k)	ff=false;
				if(ff==false){
					a[i][0]=k-nd[i].val;
				}
				else{
					a[t][0]=300000;
					for(j=t+1;j<i;++j)	--a[j][0];
					a[i][0]=k-nd[i].val-1;
					--ans;
				}
			}
			else{
				a[i][0]=k-nd[i].val;
			}
			++k;
			++ans;
//			cout<<a[i][0]<<" "<<a[i][1]<<endl;
		}
		if(!f)	printf("Case #%d: Too Bad\n",c);
		else printf("Case #%d: %d\n",c,ans);
	}
}

/*
double p[100005],a[100005];

int main(){
	int i,j,k,m,n,r,c,A,B;
	double t,ans;
	freopen("1.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	scanf("%d",&r);
	for(c=1;c<=r;++c){
		scanf("%d%d",&A,&B);
		for(i=1;i<=A;++i)	scanf("%lf",&p[i]);
		a[0]=1;
		ans=B+1+1;
		for(i=1;i<=A;++i){
			a[i]=a[i-1]*p[i];
			t=(A-i)+(B-i)+1+(1-a[i])*(B+1);
			if(t<ans)	ans=t;
		}
		printf("Case #%d: %.6lf\n",c,ans);
	}
}
*/