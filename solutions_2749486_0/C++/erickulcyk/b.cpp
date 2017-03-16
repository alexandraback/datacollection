#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <complex>
#include <valarray>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>

using namespace std;

#define f(i,n) for(int i=0; i <n;i++)
#define fi(i,s,n) for(int i=s; i<n;i++)
typedef long long ll;
int main(){
	int tc;
	scanf("%d",&tc);
	f(i,tc){
		printf("Case #%d: ",i+1);

		int x,y;
		scanf("%d %d",&x,&y);
		
		int a[500];
		while(true){
			f(j,500){
				a[j]=rand()%4;
			}
			ll cx = 0, cy=0;
			ll dist = 0;
			bool w =false;
			int ind =0;
			f(j,500){
				dist++;
				if(a[j]==0)
					cy+=dist;
				else if(a[j]==1)
					cy-=dist;
				else if(a[j]==2)
					cx+=dist;
				else
					cx-=dist;
				if(cx==x&& cy==y){
					w =true;
					ind = j+1;
					break;
				}
			}
			if(w){
				f(j,ind){
					char c;
					if(a[j]==0)
						c='N';
					else if (a[j]==1)
						c='S';
					else if (a[j]==2)
						c='E';
					else
						c='W';
					printf("%c",c);
				}
				printf("\n");
				break;
			}
		}
	}

	return 0;
}
