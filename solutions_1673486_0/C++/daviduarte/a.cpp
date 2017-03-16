#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>

#define ln printf("\n")
#define rep(a,b) for(int a = 0; a < b; a++)

using namespace std;

int a, b;
double p[222222];

bool read(){
	scanf("%d%d", &a, &b);
	
	rep(i,a){
		scanf("%lf", &p[i]);
		p[i] = 1-p[i];
	}
	
	return true;
}

int cn = 1;

double acum[222222];

void process(){
	printf("Case #%d: ", cn++);
	acum[0] = 0;
	
	rep(i,a){
		acum[i+1] = acum[i] + (1-acum[i]) * p[i];
	}
	
	//rep(i, a+1){
	//	printf("%d - %lf\n", i, acum[i]);
//	}
	
	double res = 2 + b;
	
	//printf("\n%d %d\n", a, b);
	//printf("Starting with %lf at best\n", res);
	
	rep(i,a+1){
		int stok = (b-a + 2*i + 1);
		int stnok = (b-a + 2*i + 1 + b + 1);
		double probok = (1-acum[a-i]);
		double probnok = (acum[a-i]);
		double temp = stok*probok + stnok*probnok;
		
		//printf("Erasing %d chars leaving %d chars unsure\n", i, a-i);
	//	printf("%d %d %lf %lf = %lf\n", stok, stnok, probok, probnok, temp);
		
		if(temp < res) res = temp;
	}
	
	printf("%lf\n", res);
}

int main(){
	freopen("a.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t = -1;
	scanf("%d", &t);
	while(t-- && read()) process();
	
	//while(1);
}
