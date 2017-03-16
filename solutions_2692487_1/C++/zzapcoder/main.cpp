#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <map>
#include <list>
#include <cstdio>
#include <cctype>
#include <sstream>
#include <fstream>
#include <windows.h>
using namespace std;

#define ll long long
#define ms1(m) memset((m),-1,sizeof((m)))
#define ms0(m) memset((m),0,sizeof((m)))
#define SORT(v) sort((v).begin(),(v).end())
#define CINFASTER cin.sync_with_stdio(false)
#define sz size()
#define pb(x) push_back(x)
#define mp(a,b) make_pair((a),(b))
#define all(x) (x).begin(),(x).end()

const ll MAX = 1e16 ;

int firstMot, mots;
ll msiz[100111] ;
//google codeJam~!
int main (){
	ifstream fin("A-large.in");
	ofstream fout("output.txt");
	int tc; fin>> tc ;

	for(int k=0;k<tc; ++k){
		fin>>firstMot >> mots ;
		for(int i=0;i<mots;++i) fin>>msiz[i] ;
		sort(msiz, msiz+mots) ;
		ll ans = MAX , pans = 0 , greedy = 0;
		greedy = firstMot ;
		bool usedpans = false ;
		
		for(int i=0;i<mots;++i){

			//현재 모트는 greedy.
			if(greedy > msiz[i]){
				greedy += msiz[i] ;
				continue ;
			}
			else{
				//1. just remove all left mots
				ans = min(ans , pans + (ll)mots - i);
				if(greedy == 1) break ;
				//2. greedy
				ll cur = greedy, ops=0 ;
				while(cur <= msiz[i]){
					ops++ ;
					cur = cur*2 -1 ;
					usedpans = true ;
				}
				greedy = cur += msiz[i] ;
				pans += ops ;
			}
		}
		if(usedpans)ans = min(ans , pans) ;
		if(ans > 1000000000000000ll) ans = 0 ;

		fout<<"Case #"<<k+1<<": "<< ans << endl ;
	}

	fin.close() ;
	fout.close();
	return 0;
}