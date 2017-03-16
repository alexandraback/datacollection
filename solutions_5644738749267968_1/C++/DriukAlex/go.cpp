#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void solveCase(int t) {
	int n;
	cin>>n;
	vector<double> naomi(n), ken(n);
	for (int i=0;i<n;i++)
		cin>>naomi[i];
	for (int i=0;i<n;i++)
		cin>>ken[i];
	sort(naomi.begin(),naomi.end());
	sort(ken.begin(),ken.end());
	int pointsTwo = n;
	int i1=0, i2=0;
	while (true) {
		while (i2<n&&naomi[i1]>ken[i2])
			i2++;
		if (i2==n)
			break;
		i1++;
		i2++;
		pointsTwo--;
	}
	int pointsOne = 0;
	i1=0, i2=0;
	while (true) {
		while (i1<n&&naomi[i1]<ken[i2])
			i1++;
		if (i1==n)
			break;
		i1++;
		i2++;
		pointsOne++;
	}
	printf("Case #%d: %d %d\n",t+1,pointsOne, pointsTwo);
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int t;
	cin>>t;
	for (int i=0;i<t;++i) {
		solveCase(i);
	}
	return 0;
}