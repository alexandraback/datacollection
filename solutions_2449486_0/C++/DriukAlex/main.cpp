#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stack>
using namespace std;

int mas[100][100];
int cur[100][100];
int maxr[100];
int maxc[100];

void solveCase(int t) {
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) {
			cin>>mas[i][j];
			cur[i][j]=100;
		}
	for (int i=0;i<100;i++)
		maxr[i]=maxc[i]=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			maxr[i]=max(maxr[i],mas[i][j]);
	for (int j=0;j<m;j++)
		for (int i=0;i<n;i++)
			maxc[j]=max(maxc[j],mas[i][j]);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cur[i][j]=min(cur[i][j],maxr[i]);
	for (int j=0;j<m;j++)
		for (int i=0;i<n;i++)
			cur[i][j]=min(cur[i][j],maxc[j]);
	bool can=true;
	printf("Case #%d: ",t+1);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (cur[i][j]!=mas[i][j]) {
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	cout<<"YES"<<endl;
}

int main()
{
   freopen("in.in", "rt", stdin);
   freopen("out.out", "wt", stdout);
   int T;
   cin>>T;
   for (int i=0;i<T;i++)
	   solveCase(i);
   return 0;
}