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

using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()

int main() {
	int testcase;scanf("%d" , &testcase );
	for( int cs = 1; cs <= testcase; cs++ ) {
		int N; cin >> N;
		int A[N+5] , B[N+5] , stat[N+5];
		for( int i = 0; i < N; i++ ){ cin >> A[i] >> B[i];stat[i] = 0; }
		
		int ans = 0 , star = 0;
		while( true ) {
			int flag = false;	
			for( int i = 0; i < N; i++ ) if( stat[i] < 2 ) flag = true;
			if( !flag ) break;	
			
			int maxp = 0;int id = 0;int solved = 0;int sec = 0;
			for( int i = 0; i < N; i++ ) {	
				if( stat[i] == 0  && star >= A[i] && maxp <= 1 && solved <= 1 && B[i]>=sec ) { maxp = 1; id = i;solved = 1;sec=B[i]; }
				if( stat[i] == 0  && star >= B[i] && maxp <= 2 && solved <= 2 ) { maxp = 2; id = i;solved = 2; }
				if( stat[i] == 1  && star >= B[i] && maxp <= 1 && solved <= 2 ) { maxp = 1; id = i;solved = 2; }     
			}
			if( maxp == 0 ) break;
			if ( stat[id] == 0 ) stat[id] = maxp;
			else  stat[id] = 2;
//			cout <<star << " "<<  id << "\n";
		
			ans  += 1;  
			star += maxp;
		}
		int flag = true;
		for( int i = 0; i < N; i++ ) if( stat[i] < 2 ) flag = false;;
		if( flag ) cout << "Case #" << cs << ": " << ans << "\n";
		else cout << "Case #" << cs << ": Too Bad\n";
	}
	return 0;
}
