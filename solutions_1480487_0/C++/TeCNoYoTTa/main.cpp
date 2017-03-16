#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <cstring>
#include <string.h>
using namespace std;
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define SZ size()
#define rep(i,m) for(int i=0;i<m;i++)
#define sqr(x) (x)*(x)
#define For(i,n,m) for(int i=n;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair

#define getBit(code,i) (code &  (1LL << i))
#define setBit(code,i) (code |  (1LL << i))
#define resetBit(code,i) (code & ~(1LL << i))

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int CN;
	cin >> CN;

	int N,J,X;
	vector<int> allJ;
	for(int k=1;k<=CN;k++)
	{
		printf("Case #%d: ",k);
		
		cin >> N;
		X = 0;
		allJ.resize(N);
		rep(i,N)
		{
			cin >> J;
			allJ[i] = J;
			X += J;
		}
		double target = double(X+X)/N;
		double newTarget = X;
		int cnt = 0;
		vector<double> allRes(N,-1);
		rep(i,N)
		{
			if(target <= allJ[i])
				allRes[i] = 0;
			else
			{
				newTarget += allJ[i];
				cnt++;
			}
		}
		newTarget = newTarget/cnt;
		
		
		rep(i,N)
		{
			if(allRes[i] < 0)
			{
				allRes[i] = (newTarget-allJ[i])/X;
			}
			double res = allRes[i]*100;
			if(i != N-1)
				printf("%.7f ", res);
			else
				printf("%.7f\n", res);
		}
	}
	return 0;
}