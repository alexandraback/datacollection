#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<map>
using namespace std;
typedef long long lli;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)

int main() {
	freopen("A-small-attempt1.in", "r", stdin); freopen("A-small.out", "w", stdout);
	//freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int a,n,A[1000],t,ans,num;
	scanf("%d",&t);
	for(int j=1;j<=t;j++) {
		scanf("%d %d",&a,&n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		ans=n;
		sort(A,A+n);

		num=0;
		for(int i=0;i<n;i++) {
			//cout<<i<<" "<<a<<endl;
			if(A[i]<a) {
				a+=A[i];
				ans=min(n-i+num-1,ans);
				continue;
				}
			if(a==1) {
				ans=min(n-i+num,ans);
				break;
				}
			while(A[i]>=a) {
				a=2*a-1;
				num++;
				}
			a+=A[i];
			ans=min(n-i+num-1,ans);
			}
		printf("Case #%d: %d\n",j,ans);
		}

	return 0;
	}
