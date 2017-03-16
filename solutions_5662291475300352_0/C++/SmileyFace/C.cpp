#include <bits/stdc++.h>
#define eps 0.00000001
#define fi first
#define sc second
using namespace std;
typedef pair<long long ,long long > pi;//pos,speed

pi d[2];

int main(){
	freopen("C-small-1-attempt4.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;scanf("%d",&tc);
	for(int tcno=1;tcno<=tc;tcno++){
		int n;
		scanf("%d",&n);
		if(n==2){
			int tp;
			for(int i=0;i<n;i++){
				scanf("%I64d %d %I64d",&d[i].fi,&tp,&d[i].sc);
			}
		}
		else{
			int tp;
			scanf("%I64d %d %I64d",&d[0].fi,&tp,&d[0].sc);
			d[1].fi=d[0].fi;
			d[1].sc=d[1].sc+1;
		}
		/*for(int i=0;i<n;i++){
			printf("%d %d ",d[i].fi,d[i].sc);
		}*/
		if(d[0].sc<d[1].sc)swap(d[0],d[1]);//first one is always slower.
		if(d[0].sc==d[1].sc){printf("Case #%d: 0\n",tcno);continue;}
		if(d[0].fi<d[1].fi){//faster guy in front
			//double s1=(double)360LL.0/(double)(d[1].sc);
			//double s0=(double)360LL.0/(double)(d[0].sc);
			//double x=(double)(360LL.0-(d[1].fi-d[0].fi))*(s1-s0)*(s1)+(double)d[1].fi;
			//printf("%f ",x);
			if((360LL-d[1].fi+d[0].fi)*(d[0].sc-d[1].sc)+d[1].fi*d[1].sc*d[1].sc*d[0].sc>=360LL*d[1].sc*d[1].sc*d[0].sc){printf("Case #%d: 0\n",tcno);continue;}
			else {printf("Case #%d: 1\n",tcno);continue;}
		}
		else if(d[0].fi>d[1].fi){//slower guy in front
			//double s1=(double)360LL.0/(double)(d[1].sc);
			//double s0=(double)360LL.0/(double)(d[0].sc);
			//double x=(double)(d[0].fi-d[1].fi)*(s1-s0)*(s1)+(double)d[1].fi;//first x
			if((d[0].fi-d[1].fi)*(d[0].sc-d[1].sc)+d[1].fi*d[1].sc*d[1].sc*d[0].sc>=360LL*d[1].sc*d[1].sc*d[0].sc){printf("Case #%d: 0\n",tcno);continue;}
			else {printf("Case #%d: 1\n",tcno);continue;}
		}
		else{//same pace
			//double s1=(double)360LL.0/(double)(d[1].sc);
			//double s0=(double)360LL.0/(double)(d[0].sc);
			//double x=(double)360LL.0*(s1-s0)*(s1)+(double)d[1].fi;//first x
			//printf("%f",x);
			if((360LL)*(d[0].sc-d[1].sc)+d[1].fi*d[1].sc*d[1].sc*d[0].sc>=360LL*d[1].sc*d[1].sc*d[0].sc){printf("Case #%d: 0\n",tcno);continue;}
			else {printf("Case #%d: 1\n",tcno);continue;}
		}
		int ans=0;
		printf("Case #%d: %d\n",tcno,ans);
	}
}
