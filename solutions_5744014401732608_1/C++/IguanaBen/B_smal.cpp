#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>

#define ll long long

using namespace std;

bool gr[55][55];
ll ways[55];

void solve(int t) {


	for(int i=0; i<55; ++i)
		for(int j=0; j<55; ++j)
			gr[i][j] = 0;

	for(int i=0; i<55; ++i)
		ways[i] = 0;

	ll b, m;
	cin>>b>>m;

	ll p2 = 1;
	for(int i=0; i<b-2; ++i)
		p2 *= 2;


	ways[0] = m;

	if(m > p2) {
		cout<<"Case #"<<t<<": IMPOSSIBLE\n";
		return;
	}

	cout<<"Case #"<<t<<": POSSIBLE\n";

	for(int i=1; i<b-1; ++i)
		for(int j=i+1; j<b; ++j)
			gr[i][j] = 1;

	ll cp2 = p2;
	for(int i=1; i<b; ++i){
		cp2 /= 2;
		// cout<<m<<" "<<cp2<<"\n";
		if(m >= cp2 && m) {
			m -= cp2;
			gr[0][i] = 1;
		}

		// if(m >= cp2){
		// 	cout<<"ok "<<i<<"\n";
		// 	for(int j=i; j<b-1; ++j){
		// 		for(int k=j+1; k<b-1;++k)
		// 			gr[j][k] = 1;

		// 		if(m){
		// 			cp2 /=2;

		// 			if(m >= cp2){
		// 				m-=cp2;
		// 				gr[0][j] = 1;
		// 			}

		// 		}

		// 	}

		// 	break;
		// }

		// cp2 /= 2;
		// ll cm = ways[i];
		// // if(cm >  )
		// ll scp2 = cp2;
		// int add = 0;
		// for(int j=i+1; j<b; ++j) {
		// 	if(cm > scp2){
		// 		cm -= scp2;
		// 		gr[i][j] = 1;
		// 		// ways[j] = 
		// 		add++;
		// 		for(int k=j+1; k < b; ++k) {
		// 			gr[j][k] = 1;
		// 		}

		// 	} else {

		// 	}

		// 	scp2 /= 2;
		// }
	}

	// cout<<"dd\n";
	for(int i=0; i<b; ++i) {
		for(int j=0; j<b; ++j)
			cout<<gr[i][j];

		cout<<"\n";
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin>>T;
	int t = 1;;
	while(T--)
		solve(t++);

	return 0;

}