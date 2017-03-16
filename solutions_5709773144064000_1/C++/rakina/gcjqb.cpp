#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAXN 1005
#define INF 1000000
#define S 0
#define T m+n+1
using namespace std;
int t;
double c,f,x,cur,rate,ans,udah;
int main(){
	scanf("%d",&t);
	for (int tc = 1; tc <= t; ++tc){
		scanf("%lf %lf %lf",&c,&f,&x);
		cur = 0.0; rate = 2.0;
		ans = x/rate;
		udah = 0;
		while (1){
			// buy a farm?
			if (cur >= c){
				// cukup duitnya
				//guna
				if ((x-cur+c)/(rate+f)+udah<ans){
					ans = (x-cur+c)/(rate+f)+udah;
					cur -= c;
					rate += f;
				}
				else break;
				//ga guna
			}
			else{
				// kerja dolo
				udah += (c-cur)/rate;
				cur = c;
			}
		}
		printf("Case #%d: %.10lf\n",tc,ans);
	}
}