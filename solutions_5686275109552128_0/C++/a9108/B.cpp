#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n;
int a[10000];

int getans(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int s=0;
	for (int i=0;i<n;i++) s+=a[i];
	int ans=10000000;
	for (int ma=1;ma<ans;ma++){
		int cnt=0;
		for (int i=0;i<n;i++)
			cnt+=(a[i]-1)/ma;
		ans=min(ans,cnt+ma);
	}
	return ans;
}

int main(){
	int N;
	scanf("%d",&N);
	for (int r=1;r<=N;r++){
		printf("Case #%d: %d\n",r,getans());
	}
	return 0;
}