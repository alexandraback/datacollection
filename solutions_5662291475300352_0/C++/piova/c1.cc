#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <set>


#define mk make_pair
#define pb push_back
#define eps 1e-9
typedef  long long  LL;

using namespace std;

int main(){
	int T,n;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		printf("Case #%d: ",cas);
		scanf("%d",&n);
		int m1,m2;
		int d1,d2;
		int x,y,z;
		if(n==1){
			scanf("%d%d%d",&x,&y,&z);
			if(y==1){
				puts("0");
				continue;
			}
			// y==2
			else{
				m1=z;
				m2=z+1;
				d1=x;
				d2=x;
			}
		}
		else{
			scanf("%d%d%d",&x,&y,&z);
			d1=x,m1=z;
			scanf("%d%d%d",&x,&y,&z);
			d2=x,m2=z;
		}
		
		if(d1<d2){
			swap(m1,m2);
			swap(d1,d2);
		}
		if(m1<m2){
			int dis= 720-d1;
			double tim = (360-d2) * (m2*1.0/360.0);
			double over = dis*1.0 / (360.0/(m1*1.0)) ;
			if( over > tim+eps ) 
				puts("0");
			else	
				puts("1");
			continue;
		}
		if(m1==m2)
			puts("0");
		if(m1>m2){
			int dis =720-d2;
			double tim = (360-d1) * (m1*1.0/360.0);
			double over = dis*1.0 / (360.0/(m2*1.0)); 
			if( over > tim+eps ) 
				puts("0");
			else	
				puts("1");
			continue;
		}
	
	}
	return 0;
}