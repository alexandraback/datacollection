#include <iostream>
#include <algorithm>
using namespace std; 
const double eps = 1e-8;
int s[300];
int o[300];
double a, b, avg; 
int X; 
int n; 

double fabs(double a){
	return a < 0 ? -a : a; 
}

void input(){
	scanf("%ld", &n);
	X = 0; 
	for (int i = 0 ; i < n; i++) {
		scanf("%ld", &s[i]);
		X += s[i];
		o[i] = s[i];
	}
}

double findavg(){
	sort(o, o + n);
	//for (int i = 0; i< n; i++) printf("%ld ", o[i]);
	int cursum = 0; 
	double avg = 2 * X * 1.0 / n; 
	for (int i = 1; i < n; i++){ 
		if (cursum + i * (o[i] - o[i-1]) > X){
			avg = o[i-1] + (X - cursum) * 1.0 / i;
			break;
		}
		cursum += i * (o[i] - o[i-1]);
	}
	//printf(" avg = %.3lf curSum = %ld", avg, cursum);
	return avg; 
}

void output(double avg){
	//printf("here avg = %.3lf", avg);
	for (int i = 0;i < n; i++){
		//printf(" %ld %.3lf ", s[i], avg);
		if (s[i] < avg) printf(" %.6lf", (avg - s[i]) * 100 / X);
		else printf(" 0");
	}
	printf("\n");
}

int main(){
	freopen("/Users/qiaomiao/Downloads/A-small-attempt0.in", "r", stdin);
	freopen("/Users/qiaomiao/code/googlejam/out.txt", "w", stdout);
	int t; 
	scanf("%ld", &t);
	for (int testCase = 0; testCase < t; testCase ++){
		input();
		avg = findavg();
		printf("Case #%ld:", testCase + 1);
		output(avg);
	}
	fclose(stdin);
	fclose(stdout);
}