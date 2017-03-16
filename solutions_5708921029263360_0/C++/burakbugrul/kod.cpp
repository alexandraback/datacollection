#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef pair<int,int> ii;

struct tri{
	int a,b,c;
	tri( int a_=0 , int b_=0 , int c_=0 ){
		a=a_,b=b_,c=c_;
	}
};

int A,B,C,K,T;

vector<tri> res;
map<ii,int> cnt1,cnt2,cnt3;

int main(){
	
	scanf("%d",&T);
	
	for( int Case=1 ; Case <= T ; Case++ ){
		
		scanf("%d%d%d%d",&A,&B,&C,&K);
		
		for( int i=C ; i ; i-- )
			for( int j=B ; j ; j-- )
				for( int k=A ; k ; k-- )
					if( cnt1[ii(i,j)]<K && cnt2[ii(i,k)]<K && cnt3[ii(j,k)]<K ){
						cnt1[ii(i,j)]++;
						cnt2[ii(i,k)]++;
						cnt3[ii(j,k)]++;
						res.pb(tri(k,j,i));
					}
		
		printf("Case #%d: %d\n",Case,(int)res.size());
		
		for( vector<tri>::iterator it=res.begin() ; it!=res.end() ; it++ )
			printf("%d %d %d\n",it->a,it->b,it->c);
		
		res.clear();
		cnt1.clear();
		cnt2.clear();
		cnt3.clear();
	}
	
	return 0;
}
