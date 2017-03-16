#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

int a[1100],b[1100];
int n,T;
int vi[1100];

int main(){
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		int ans=0,now=0;
		memset(vi,0,sizeof(vi));
		for (;now<n+n;){
			bool f=false;
			for (int i=0;i<n;i++) if (vi[i]<2&&b[i]<=now){
				now+=2-vi[i];vi[i]=2;
				ans++;
				f=true;
				break;
			}
			if (!f){
				int j=-1;
				for (int i=0;i<n;i++) if (vi[i]==0&&a[i]<=now){
					if (j==-1) j=i;
					if (b[j]<b[i]) j=i;
				}
				if (j!=-1){
					f=true;
					now++;
					vi[j]=1;
					ans++;
				}
			}
			if (!f) break;
		}
		if (now==n+n){
			printf("Case #%d: %d\n",ti,ans);
		}
		else printf("Case #%d: Too Bad\n",ti);
	}
    return 0;
}
