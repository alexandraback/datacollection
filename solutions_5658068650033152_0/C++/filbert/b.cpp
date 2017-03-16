#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define N 2
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(){
	int t,ver,hor,n,m,k,clos;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		ver=1;
		hor=1;
		printf("Case #%d: ",1+i);
		clos=1;
		scanf("%d%d%d",&n,&m,&k);
		n--;
		m--;
		if(k==1) printf("1\n");
		else if(k==2) puts("2");
		else if(k==3) puts("3");
		else if(m<=1||n<=1) printf("%d\n",k);
		else{
			while(clos+ver*2+hor*2<k){
				if(clos+ver*2+hor*2+1==k)
				break;
				if(ver+1<n&&hor+1<m){
					if(clos+ver*2+hor*2+2==k)
					break;
					if(ver>hor){
						clos+=ver;
						hor++;
					}
					else{
						clos+=hor;
						ver++;
					}
				}
				else if(ver+1<n){
					if(clos+ver*2+hor*2+2==k)
					break;
					ver++;
					clos+=hor;
				}
				else if(hor+1<m){
					if(clos+ver*2+hor*2+2==k)
					break;
					hor++;
					clos+=ver;
				}
				else{
					break;
				}
			}
			k=k-clos-hor-hor-ver-ver;
			if(k<=0){
				printf("%d\n",hor+hor+ver+ver);
			}
			else{
				printf("%d\n",hor+hor+ver+ver+k);
			}
		}
	//	printf("%d %d\n",hor,ver);
	}
}