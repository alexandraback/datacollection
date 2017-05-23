#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int test,tc=1,ans1,ans2,n,i,j;
	double in;
	vector<double> w1,w2;
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %d %d\n",tc++,ans1,ans2) ){
		w1.clear();
		w2.clear();
		scanf("%d",&n);
		for( i=0 ; i<n ; i++ ){
			scanf("%lf",&in);
			w1.push_back(in);
		}
		for( i=0 ; i<n ; i++ ){
			scanf("%lf",&in);
			w2.push_back(in);
		}
		sort(w1.begin(),w1.end());
		sort(w2.begin(),w2.end());
		
		for( ans2=0,i=j=n-1; i>=0 ; i-- ){
			if( w2[j]>w1[i] ) j--;
			else ans2++;
		}
		
		for( ans1=0,i=j=n-1; i>=0 ; i-- ){
			if( w1[j]>w2[i] ) ans1++,j--;
		}
	}
	
	return 0;
}

