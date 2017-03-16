# include <iostream>
# include <vector>
# include <map>
# include <deque>
# include <set>
# include <algorithm>
# include <memory>
# include <cstring>
# include <cstdio>
# include <cctype>
# include <cstdlib>
# include <cmath>
# include <utility>
# include <string>
# include <queue>

using namespace std;

# define I(n)   scanf("%d",&(n))
# define read(x) freopen(x,"r",stdin)
double dp[100005];
double p[100005];
int main()
{
	read("A.in");
	freopen("A.out","w",stdout);
	int T;
	I(T);
	for(int cas=1;cas<=T;cas++)
	{
	    int A,B;

	    I(A);I(B);
        for(int i=1;i<=A;i++) scanf("%lf",&p[i]);



        double ans=A+B+1;
        dp[0] = 1;
        for(int i=1;i<=A;i++){
            dp[i] = dp[i-1] * p[i];
            double temp;
            temp = ((A-i)+(B-i)+1) + (1-dp[i]) * ( B+1 );
            ans = min(ans,temp);
        }
        ans = min ( ans,B+2.);

        printf("Case #%d: %.6lf\n",cas,ans);

	}

	return 0;
}
