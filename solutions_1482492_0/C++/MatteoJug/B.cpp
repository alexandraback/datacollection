#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
#define abs(X) (((X)<0)?-(X):(X))
using namespace std;
typedef pair<int,int> PI;
typedef long long ll;
int T,N,A;
float D;
float car[10][2];
float me;
float acc;
void check(){
	//cout<<"CHECK "<<acc<<endl;
	float best = 0.0, vel = 0.0, ss = 0.0, s, tc = 0.0;
	for (int i = 0; i < N; i++){
		s = car[i][1]-ss;
		me = (-vel+sqrt(vel*vel+2*acc*s))/acc;
		if (car[i][0]-tc>me)
			vel = (car[i][1]-ss)/(car[i][0]-tc);
		else
			vel += me*acc;
		ss = car[i][1];
		//cout<<"TRACK "<<i<<"_"<<ss<<" ME:"<<me<<endl;
		best+=max(me,car[i][0]-tc);
		tc = car[i][0];
	}
	printf("%f\n",best);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for (int i = 0; i < T; i++){
		scanf("%f %d %d",&D,&N,&A);
		int tN = N;
		for (int j = 0; j < N; j++){
			scanf("%f %f",&car[j][0],&car[j][1]);
			if (car[j][1]>=D && tN>j)
				if (j){
					float v = (car[j][1]-car[j-1][1])/(car[j][0]-car[j-1][0]);
					car[j][0] = (D-car[j-1][1])/v;
					car[j][1] = D;
					tN = j+1;
				} else
					car[j][1] = D, tN = j+1;
		}
		N = tN;
		printf("Case #%d:\n",i+1);
		for (int j = 0; j < A; j++)
			scanf("%f",&acc), check();
	}
	return 0;
}
