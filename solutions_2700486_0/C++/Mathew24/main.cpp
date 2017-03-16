#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(a,b) for(int a=0; a<b; a++)
#define ABS(a) ((a)<0 ? (-(a)) : (a))

using namespace std;

//fill shell n
int fshelln(int n){
	return (n+1)*(2*n+1);
}

double solveCase(){
	int N, x,y;
	scanf("%d", &N);
	scanf("%d", &x);
	scanf("%d", &y);
	
//	printf("%d %d %d\n", N, x, y);
	
	x=ABS(x);
	if(ABS(x+y)%2==1)
		return 0;
	
	int shell = ABS(x+y)/2;
	
	//this shell is full
	if(N >= fshelln(shell))
		return 1;

	//this shell is empty
	if(N <= fshelln(shell-1))
		return 0;
	
	//this shell is not full and midle is empty
	if(x==0)
		return 0;
	
	int here = N - fshelln(shell-1);
//	printf("Shell %d\n", shell);
//	printf("X %d\n", x);
//	printf("Diamonds in this shell %d\n", here);
	
	vector < vector < double > > prob;
	prob.resize(shell*2+1);
	FOR(i, prob.size())
		prob[i].resize(i+1);
	
	FOR(i, prob.size()){
		FOR(j, prob[i].size()){
			if(i==0 && j==0){
				prob[i][j]=1;
			}else if(j==0){
				prob[i][j]=prob[i-1][j]/2;
			}else if(i==j){
				prob[i][j]=prob[i][j-1];
			}else if(i==prob.size()-1 && j==prob.size()-1){
				prob[i][j]=prob[i-1][j]+prob[i][j-1];
			}else if(i==prob.size()-1){
				prob[i][j]=prob[i-1][j]/2 +prob[i][j-1];
			}else{
				prob[i][j]=prob[i-1][j]/2 +prob[i][j-1]/2;
			}
//			printf("%7lf  ", prob[i][j]);
		}
//		printf("\n");
	}
	
	
	double probSum=0;
	for ( int i = shell*2-x+1; i<prob.size(); i++){
		int j = here - i;
		if(j >= 0 && j <prob.size()){
//			printf("i j, %d %d\n", i, j);
			if(i<j)
				probSum+=prob[j][i];
			else
				probSum+=prob[i][j];
		}
	}
	
	return probSum;
}

int main(){
	int T;
	scanf("%d", &T);
	FOR(i,T)
		printf("Case #%d: %.10lf\n", i+1, solveCase());	
}
