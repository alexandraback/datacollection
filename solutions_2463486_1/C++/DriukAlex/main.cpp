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

bool palindr(long long num) {
	vector<int> n;
	while (num>0) {
		n.push_back(num%10);
		num/=10;
	}
	int sz=n.size();
	for (int i=0;i<sz/2;i++)
		if (n[i]!=n[sz-1-i])
			return false;
	return true;
}

vector<long long> res;

void solveCase(int t) {
	long long A,B;
	cin>>A>>B;
	int cnt=0;
	for (int i=0;i<res.size();i++)
		if (res[i]>=A&&res[i]<=B)
			cnt++;
	printf("Case #%d: %d\n",t+1,cnt);
}

int main()
{
   freopen("in.in", "rt", stdin);
   freopen("out.out", "wt", stdout);
   for (int i=1;i<10000;i++) {
	   int ii=i;
	   vector<int> num,num1;
	   while (ii>0) {
		   num.push_back(ii%10);
		   ii/=10;
	   }
	   reverse(num.begin(), num.end());
	   num1=num;
	   int sz=num.size();
	   for (int k=sz-1;k>=0;k--)
		   num.push_back(num[k]);
	   for (int k=sz-2;k>=0;k--)
		   num1.push_back(num1[k]);
	   long long n1=0,n2=0;
	   for (int k=0;k<num.size();k++) {
		   n1*=10;
		   n1+=num[k];		   
	   }
	   long long nn1=n1*n1;
	   if (palindr(nn1))
		   res.push_back(nn1);
	   for (int k=0;k<num1.size();k++) {
		   n2*=10;
		   n2+=num1[k];		   
	   }
	   long long nn2=n2*n2;
	   if (palindr(nn2))
		   res.push_back(nn2);
   }
   sort(res.begin(),res.end());
   int t;
   cin>>t;
   for (int i=0;i<t;i++)
	   solveCase(i);
   return 0;
}