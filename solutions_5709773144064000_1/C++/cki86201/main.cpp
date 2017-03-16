#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> Pi;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tc;
	scanf("%d",&Tc);
	for(int tt=1;tt<=Tc;tt++){
		double C, F, X;
		scanf("%lf%lf%lf",&C,&F,&X);
		int i;
		double u = X/C - 1 - 2.0/F;
		double ans = 0;
		for(i=0;i<u;i++){
			ans += C / (2+F*i);
		}
		ans += X / (2+F*i);
		printf("Case #%d: %.7f\n",tt, ans);
	}
	return 0;
}
