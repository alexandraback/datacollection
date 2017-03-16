#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm> 
#include <math.h> 
#include <vector>
#include <set>
#include <map> 
#include <string.h> 
#include <cstdlib> 
#include <limits.h> 
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <functional> 
#include <stack>
#include <queue>
using namespace std;

#define EPS 0.0000000001

double naomi[1010], ken[1010];
bool used[1010];

int main()
{
	int t,cn=1;
	cin>>t;
	for(;cn<=t;cn++){
		int n,i,j;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>naomi[i];
		for(i=0;i<n;i++)
			cin>>ken[i];
		sort(naomi,naomi+n);
		sort(ken,ken+n);
		i=j=0;
		int dw = 0;
		for(;i<n;i++){
			if(naomi[i]<ken[j])
				continue;
			dw++;
			j++;
		}
		int w = 0;
		memset(used,0,sizeof(used));
		for(i=n-1;i>=0;i--){
			double c = naomi[i];
			for(j=0;j<n;j++){
				if(used[j])
					continue;
				if(ken[j]>c)
					break;
			}
			if(j==n) w++;
			else used[j] = true;
		}
		printf("Case #%d: %d %d\n",cn,dw,w);
	}
	return 0;
}



