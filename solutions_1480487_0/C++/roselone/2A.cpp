#include <iostream>
using namespace std;

int n;
int score[201];
int sum;
double ans;

void init(){
	cin>>n;
	sum=0;
	for (int i=0;i<n;i++){
		cin>>score[i];
		sum+=score[i];
	}
	return ;
}

void solve(){
	for (int i=0;i<n;i++){
		double st=0,ed=1,ans;
		while((ed-st)>0.0000001){
			ans=(ed+st)/2;
			double tt=score[i]+sum*ans;
			int m=n-1;
			int msum=sum-score[i];
			for (int j=0;j<n;j++){
				if (j!=i && score[j]>=tt){
					m--;
					msum-=score[j];
				}
			}
			if (m==0){st=ans;continue;} 
			double qq=((1-ans)*sum+msum)/m;
			if (tt==qq) break;
			if (tt>qq) ed=ans;
			if (tt<qq) st=ans;
		}
		printf("%.6lf ",ans*100);
	}
	cout<<endl;
	return ;
}

int main (){
	freopen("A-small-attempt1.in","r",stdin);
	freopen("2A.out","w",stdout);
	int T;
	cin>>T;
	for (int t=1;t<=T;++t){
		init();
		printf("Case #%d: ",t);
		solve();
	}
	return 0;
}