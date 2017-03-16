									/*	In the name of God	*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
typedef long long ll;

using namespace std;

const int maxn=2000001;
int a[1001],m[maxn],b[1001],n;

bool rec(int x){
	if (!x)
		return 1;
	int i;
	rep(i,n){
		if (!b[i] && x-a[i]>=0 && m[x-a[i]]){
			b[i]=1;
			if (rec(x-a[i])){
				m[x]--;
				printf("%d ",a[i]);
				return 1;
			}
			else
				b[i]=0;
		}
	}
	return 0;
}

int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);	
	int ti,tc,i,j,k,r;
	scanf("%d",&tc);
	rep(ti,tc){
		scanf("%d",&n);
		rep(i,n)
			scanf("%d",&a[i]);
		memset(m,0,sizeof m);
		m[0]=1;
		rep(i,n)
			for (j=maxn;j>=a[i];j--)
				m[j]+=m[j-a[i]];
		printf("Case #%d:\n",ti+1);
		rep(i,maxn)
			if (m[i]>=2)
				break;
		if (i==maxn){
			printf("Impossible\n");
			continue;
		}
		memset(b,0,sizeof b);
		rec(i);
		printf("\n");
		//memset(b,0,sizeof b);
		rec(i);
		printf("\n");
		/*k=i;
		memset(b,0,sizeof b);
		while(i>0){
			m[i]--;
			rep(j,n){
				if (!b[j] && i-a[j]>=0 && m[i-a[j]]){
					i=i-a[j];
					printf("%d ",a[j]);
					b[j]=1;
					break;
				}
			}
		}
		printf("\n");
		memset(b,0,sizeof b);
		i=k;
		while(i>0){
			m[i]--;
			rep(j,n){
				if (!b[j] && i-a[j]>=0 && m[i-a[j]]){
					i=i-a[j];
					printf("%d ",a[j]);
					b[j]=1;
					break;
				}
			}
		}
		printf("\n");
*/
	}
	
	return 0;
}