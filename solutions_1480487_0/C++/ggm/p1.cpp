#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>

const int inf = 1000000000;
const double G = 1e-8;
using namespace std;

vector<int> score;
vector<double> ans;
int X;

bool check(int index,double ratio) {

	int my_min= inf;
	double remain = 1-ratio;
	double target = score[index]+ratio*X;

	for(int i=0;i<score.size();i++) {
		if(i==index) continue;
		if(score[i] >= target) continue;
		double d = target - score[i];
		remain -= d / X;
	}
//	printf("ration=%lf remain=%lf\n",ratio,remain);	
	
	return remain < 0;
}


int main() {

	int T,N;
	scanf("%d",&T);

	for(int t=1;t<=T;t++) {
		
		scanf("%d",&N);
		
		score.resize(N);
		ans.resize(N);
		X = 0;

		for(int i=0;i<N;i++) {
			scanf("%d",&score[i]);
			X += score[i];
		}

		for(int i=0;i<N;i++) {

			double l=0, r=1, mid;
			bool done = false; 
			while(r>=l) {
				mid = (l+r)/2;
//				printf("%lf %lf %lf\n",l,mid,r);
//				getchar();
				if( check(i,mid) ) {
					done = true;
//					puts("y");
//					printf("%lf\n",mid);
					ans[i] = mid;
					r = mid-G;
					if( fabs(r-l)<G )
						break;
				} else {
//					puts("n");
					l = mid+G;	
				}
			}
			if(done == false) 
				ans[i] = 1;
		}

		printf("Case #%d: ",t);	

		for(int i=0;i<N;i++) {
			printf("%.6lf ",ans[i]*100);
		}
		puts("");
	}

}
