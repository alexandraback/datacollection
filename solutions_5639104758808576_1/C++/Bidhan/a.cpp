/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;
#include <bits/stdc++.h>

#define mx 0

int main(){
    time_t start=clock();
    freopen("ain","r",stdin);
    freopen("aout","w",stdout);
    //rite("out.txt");
    ios_base::sync_with_stdio(0);
    int test, kas=0;
    cin>>test;
    while( test-- ){
		int n;
		string lev;
		cin >> n >> lev;
		
		int stand = 0, answer = 0;
		for(int i=0; i<=n; i++) {
			if( stand < i ) {
				answer += i - stand;
				stand = i;
			}
			stand += lev[i] - '0';
		}
		
        cout<<"Case #"<<++kas<<": ";
        cout << answer << endl;
    }
    cerr << " Program has run "<< ( clock()-start ) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}
