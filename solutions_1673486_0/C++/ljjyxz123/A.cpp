#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<list>
using namespace std;
/*************************************************************************************/
int T;
int A, B;
double prob[1000];
/*************************************************************************************/

/*************************************************************************************/
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	int tcase = 1;
	double ans = 0.0;
	double Max = -1.0;
	scanf("%d", &T);
	for(int k=0; k<T; k++)
	{
		ans = 0.0;
		Max = 99999;
		scanf("%d %d", &A, &B);
		for(int j=0; j<A; j++)
		{
			cin >> prob[j];
		//	cout << prob[j] << " " << j << endl;
		}
		
		//keep typing
		ans = 0.0;
		double tmp_prob = 1.0;
		for(int i=0; i<A; i++)
			tmp_prob *= prob[i];
		
		ans = ans + (double)(B-A+1) * tmp_prob;
		ans = ans + (1.0-tmp_prob) * (2.0*B - A + 2);
		//cout << "ans1: " << ans << endl;
		if(ans < Max) Max = ans;
		
		//press backspace i'th
		ans = 0.0;
		for(int i=1; i<=A; i++)
		{
			tmp_prob = 1.0;
			//回退i次可以成功 
			for(int j=0; j<A-i; j++)
				tmp_prob *= prob[j];
			ans = ans + (tmp_prob * (i + B - (A - i) + 1));
			
			//回退i次也不成功
			ans = ans + ((1.0 - tmp_prob) * (2.0 * B + 2.0 * i + 2.0 - A));
			if(ans < Max) Max = ans; 
			//cout << "ans" << i << " : " << ans << endl;
		}
		
		//press enter rightway
		ans = 0.0;
		tmp_prob = 1.0;
		ans = B + 2.0;
		if(ans < Max) Max = ans;
		//cout << "ansn: " << ans << endl;
		
		printf("Case #%d: %.6lf\n", tcase++, Max);
	}
	
	return 0;
}
