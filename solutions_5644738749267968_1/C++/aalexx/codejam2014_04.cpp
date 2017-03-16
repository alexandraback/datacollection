#include<stdio.h>
#include<vector>
#include<algorithm>
bool bts(double a, double b){ return (a < b);}
using namespace std; 
int main(){
	int T,t=0;
	int n;
	int ans1,ans2;
	double dummy;
	vector<vector<double> > log(2);
	scanf("%d",&T);
	while(++t<=T){
		log[0].clear();
		log[1].clear();
		scanf("%d",&n);
		for(int i=0 ; i<2 ; i++)
			for(int j=0 ; j<n ; j++){
				scanf("%lf",&dummy);
				log[i].push_back(dummy);
			}
		sort(log[0].begin(), log[0].end(), bts);
		sort(log[1].begin(), log[1].end(), bts);
		ans1=ans2=0;
		int tmp=0;
		for(int i=0 ; i<n ; i++){
			if(log[0][i] > log[1][tmp]){
				ans1++;
				tmp++;
			}
		}
		tmp=0;
		for(int i=0 ; i<n ; i++){
			if(log[1][i] > log[0][tmp]){
				ans2++;
				tmp++;
			}
		}
		ans2=n-ans2;
		printf("Case #%d: %d %d\n",t,ans1,ans2);
	}
return 0;
}
