#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double D;
int N,A;
double t[3000];
double x[3000];
double a[250];
double max(double x1,double x2){
	if(x1 > x2)return x1;
	return x2;
}
double calculateV(double tt,double xx,double aa){
	//printf("tt = %lf xx = %lf aa = %lf\n",tt,xx,aa);
	double tmpT = sqrt(2 * xx/ aa);
	//printf("tmpT = %lf\n",tmpT);
	if(tt > tmpT)return aa * tmpT;
	return aa * tt;
}
double solveT(double vv,double aa,double xx){
	return (-vv + sqrt(vv * vv + 2 * aa * xx)) / (aa);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <=T;ca++){
		printf("Case #%d:\n",ca);
		scanf("%lf %d %d",&D,&N,&A);
		for(int i=0;i<N;i++){
			scanf("%lf %lf",&t[i], & x[i]);
		}
		if(x[N - 1] > D){
			for(int i=N - 1;i > 0;i--){
				if(x[i] == D){
					break;
				}
				if(x[i - 1] - 1 >= D){
					N--;
				}else{
					double v = (x[i] - x[i - 1]) / (t[i] - t[i - 1]);
					t[i] = (D - x[i - 1]) / (v) + t[i - 1];
					x[i] = D;
					break;
				}
			}
		}


		for(int i=0;i<A;i++){
			scanf("%lf",&a[i]);
		}

		for(int aa = 0;aa < A;aa++){
			double na = a[aa];
			double maxV = calculateV(t[N - 1], x[N - 1], na);
			//printf("maxV = %lf\n",maxV);
			for(int i=N-2;i>=0;i--){
				double tmpV = calculateV(t[i],x[i],na) + na * (t[N - 1] - t[i]);
				//printf("tmpV = %lf\n",tmpV);
				if(tmpV > maxV){
					continue;
				}
				maxV = tmpV;
			}
			double ans = max(t[N - 1], maxV / na) + solveT(maxV,na,D - x[N - 1]);
			int flag = 0;
			for(int i = 0;i<N;i++){
			//	printf("%lf %lf<%lf>",na,t[i],na / 2.0  * t[i] * t[i]);
				if(na /2.0 * t[i] * t[i] > x[i]){
					flag = 1;
					break;
				}
			}
			//printf("flag = %d\n",flag);
			if(flag == 1)
				printf("%lf\n",ans);
			else
				printf("%lf\n",solveT(0,na,D));
		}

	
	}
	return 0;
}
