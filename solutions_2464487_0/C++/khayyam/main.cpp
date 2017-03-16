#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define SQR(x) ((x)*(x))

int main(int argc, char *argv[]){
	int T;
	scanf("%d", &T);
	for(int c=1;c<=T;++c){
		int r,t;
		scanf("%d%d", &r, &t);
		int i=0;
		int current=0;
		int next=SQR(r+(2*(i+1)-1))-SQR(r+(2*(i+1)-2));
		while((current+next)<=t){
			++i;
			current+=next;
			
			next=SQR(r+(2*(i+1)-1))-SQR(r+(2*(i+1)-2));
		}
		printf("Case #%d: %d\n", c, i);
	}
	return 0;
}

