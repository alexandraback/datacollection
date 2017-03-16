#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define VI vector<int>
#define MAP map<int,VI >
#define pb push_back
const int MAXN=200;
int n,a[MAXN+10],b[MAXN+10];
MAP myMap;
bool solve()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	myMap.clear();
	int maxS=1<<n;
	for (int i=0;i<maxS;i++) {
		int sum=0;
		for (int j=0;j<n;j++)
			if (i&(1<<j)) 
				sum+=a[j];
		myMap[sum].pb(i);
	}
	for (MAP::iterator it=myMap.begin();it!=myMap.end();it++) {
		VI now=it->second;
		if (now.size()==1) continue;
		for (int j=0;j<now.size();j++)
			for (int k=j+1;k<now.size();k++)
				if ((now[k]|now[j])==(now[j]+now[k])) {
					VI ans;
					for (int x=0;x<n;x++)
						if (now[j]&(1<<x))
							ans.pb(x);
					for (int x=0;x<ans.size();x++) {
						printf("%d",a[ans[x]]);
						if (x==ans.size()-1) puts("");
						else putchar(' ');
					}
					ans.clear();
					for (int x=0;x<n;x++)
						if (now[k]&(1<<x))
							ans.pb(x);
					for (int x=0;x<ans.size();x++) {
						printf("%d",a[ans[x]]);
						if (x==ans.size()-1) puts("");
						else putchar(' ');
					}
					return true;
				}
	}
	return false;
}
int main()
{
	int cases;
	scanf("%d",&cases);
	for (int c=1;c<=cases;c++) {
		printf("Case #%d:\n",c);
		if (!solve()) puts("Impossible");
	}
	return 0;
}
