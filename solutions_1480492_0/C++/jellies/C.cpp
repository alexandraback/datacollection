#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-9)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

int n;
double speed[100];
double init[100];

double ans;
bool possible;

int rane[100];
vector<pair<double,pair<int,int> > > ev;

double pos(int i,double t){
	return speed[i]*t+init[i];
}

bool free(int p,int q,double t,int r){
	for(int i=0;i<n;i++){
		if(i==p || i==q)continue;
		if(rane[i]!=r)continue;
		if(fabs(pos(i,t)-pos(p,t))<5+EPS)return false;
	}
	return true;
}

void saiki(int evpos){

	if(possible)return;

	if(evpos==ev.size()){
		possible=true;
		return;
	}

	double t=ev[evpos].first;
	int p=ev[evpos].second.first;
	int q=ev[evpos].second.second;

	/*printf("%d (%f) (%d,%d)\n",evpos,t,p,q);
	for(int i=0;i<n;i++){
		printf("%d ",rane[i]);
	}
	printf("\n");*/

	int pre_p_rane=rane[p];
	int pre_q_rane=rane[q];

	ans=max(ans,t);

	if(free(p,q,t,0) && free(q,p,t,1)){
		rane[p]=0;
		rane[q]=1;
		saiki(evpos+1);
		rane[p]=pre_p_rane;
		rane[q]=pre_q_rane;
	}
	if(free(p,q,t,1) && free(q,p,t,0)){
		rane[p]=1;
		rane[q]=0;
		saiki(evpos+1);
		rane[p]=pre_p_rane;
		rane[q]=pre_q_rane;
	}

	return;
}

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		scanf("%d",&n);
		for(int i=0;i<n;i++){
			char ch[10];
			scanf("%s %lf %lf",ch,&speed[i],&init[i]);
			if(ch[0]=='L')rane[i]=0;
			else rane[i]=1;
		}

		ev.clear();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				if(!(init[j]+5+EPS<init[i]))continue;
				if(!(speed[i]+EPS<speed[j]))continue;
				double d=init[i]-init[j]-5;
				double s=speed[j]-speed[i];
				ev.push_back(MP(d/s,MP(i,j)));
			}
		}
		sort(ev.begin(),ev.end());

		possible=false;
		ans=0;
		saiki(0);

		printf("Case #%d: ",casecnt);
		if(possible)printf("Possible\n");
		else printf("%.10f\n",ans);
		fflush(stdout);
	}
	return 0;
}
