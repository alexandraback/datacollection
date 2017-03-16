#include <iostream>
#include <fstream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <map>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define GCD(a,b)  { return (b==0)?a:GCD(b,a%b); }
#define LCM(a,b)  { return a*b/GCD(a,b);  }
#define FOR(i,n) for(i=0;i<n;i++)
#define FOR_X(i,n,x) for(i=x;i<n;i++)
#define FORN(i,n) for(i=n;i>=0;i--)
#define FORN_X(i,n,x) for(i=n;i>=x;i--)

typedef long long int lld;
using namespace std;

int a[1000006];

int rev(int num){
	int revs = 0;
	while(num!=0){
		revs = revs*10+(num%10);
		num/=10;
	}
	return revs;
}

int main(){
	
	memset(a,0,sizeof a);
	a[0] = 0;
	int i;
	for(i=1;i<1000005;i++){
		
		a[i] = a[i-1]+1;	
		int k = rev(i);
		if((i/10)*10==i)
			continue;
		if(k<i)
			a[i] = MIN(a[i],a[k]+1);
	//	cout<<a[i]<<" ";
	}
	
	int t;	
	int x = 0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	//	cout<<n<<" ";
		x++;
		printf("Case #%d: %d\n",x,a[n]);
	}

	return 0;
}

