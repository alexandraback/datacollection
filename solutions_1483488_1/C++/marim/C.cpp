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
int t[10];

int main(){

	t[0] = 1;
	for(int i=1; i<10; i++) t[i] = t[i-1]*10;

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		int skad, dokad, pot=0, res=0;

		scanf("%d%d", &skad, &dokad);

		while( t[pot] <= skad ) pot++;	

		while( skad <= dokad ){
			int tmp = (skad%t[pot-1]) * 10 + skad / t[pot-1]; 
			
			while( tmp != skad ){
				if( tmp > skad && tmp <= dokad ) res++;
				tmp = (tmp%t[pot-1]) * 10 + tmp / t[pot-1]; 
			}

			skad++;
			while( t[pot] <= skad ) pot++;	
		}

		printf("%d\n", res);
	}

	return 0;
}
