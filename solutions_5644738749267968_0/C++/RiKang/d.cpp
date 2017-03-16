#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

int n;
double me[1005];
double en[1005];
bool e[1005];

void process(){
	int ans1=0,ans2=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lf",&me[i]);
	for(int i=0;i<n;i++) scanf("%lf",&en[i]);
	sort(me,me+n),sort(en,en+n);
	
	for(int i=0;i<n;i++) e[i]=true;
	for(int i=0;i<n;i++){
		bool chk=true;
		for(int j=0;j<n;j++) if(e[j] && en[j]>me[i]){
			e[j]=chk=false;
			break;
		}
		if(chk){
			for(int j=0;j<n;j++) if(e[j]){
				e[j]=false;
				break;
			}
			ans2++;
		}
	}
	int i1=0;
	for(int i=0;i<n;i++){
		while(i1<n){
			if(me[i1]>en[i]){
				ans1++;
				i1++;
				break;
			}
			i1++;
		}
	}
	printf("%d %d\n",ans1,ans2);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}