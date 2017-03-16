#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#define sz size()
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fu(i,n) for(int i=0; i<(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define cl(a,co) memset(a,co,sizeof a)
#define un(a) sort(ALL(a)),a.erase( unique(ALL(a)), a.end() )
typedef long long ll;
//istringstream is(s); is >> a;

using namespace std;

int ileTestow;

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		int N, s, p, t[101], res=0;

		scanf("%d%d%d", &N, &s, &p);
		
		for(int i=0; i<N; i++){
			int sum;
			scanf("%d", &sum);

			if( sum/3 + (int)(sum%3>0) >= p ){
				res++;
			} else if( s > 0 && sum > 0 ){
				switch(sum%3){
					case 0:
						if( sum/3 + 1 >= p ){
							s--;
							res++;
						}
						break;
					case 2:
						if( sum/3 + 2 >= p ){
							s--;
							res++;
						}
						break;
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
