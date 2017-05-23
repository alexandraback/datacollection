#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
#include <sstream>

using namespace std;

#define TRY
//#define SMALL
#define LARGE

void Solve();

void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("C-large.txt","wt",stdout);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.txt","wt",stdout);
#endif
	int Numcase;
	cin>>Numcase;

	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<":";
		Solve();
	}
}

void Solve(){
	int a,N;
	cin>>N;
	int tmp[2502]={0};
	for(int i=0;i<(2*N-1) *N;i++){	
		cin>>a;
		tmp[a]++;
	}
	for(int i=0;i<2502;i++){
		if(tmp[i]%2==1) {cout<<" "<<i;}
	}
	cout<<endl;
}
