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
//                     #define SMALL
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
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.txt","wt",stdout);
#endif
	int Numcase;
	cin>>Numcase;

	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		Solve();
	}
}

void Solve(){
	string a;
	cin>>a;
	int len=a.length();
	string ans="";
	if(len==1) {cout<<a<<endl;return;}
	else ans+=a[0];
	for(int i=1;i<len;i++){
		if(a[i]>=ans[0]) ans= a[i]+ans;
		else ans = ans+a[i];
	}
	cout<<ans<<endl;
	return;
}
