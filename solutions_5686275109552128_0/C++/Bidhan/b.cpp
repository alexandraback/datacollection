/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;
#include <bits/stdc++.h>

#define mx 0

priority_queue<long long> pq;

int call(vector<int> &v) {
	auto temp = v;
	//cout << "v="; for(int xx:v) cout << " " << xx; cout << endl;
	int f = 0;
	for(int &x: v) if(x) { f = 1; x--; }
	int ret = INT_MAX;
	
	if(f) ret = call(v) + 1;
	
	//cout << "<-- back!" << endl;
	
	v = temp;
	
	if(!f) return 0;
	
	//cout << "here" << endl;
	
	
	for( int i =0; i < int(temp.size()); i++) {
		//cout << "i=" << i << endl << temp[i];
		if( temp[i] < 2 ) continue;
		
		//cout << "here" << endl;
		v[i] = temp[i] / 2;
		v.push_back( temp[i] - (temp[i]/2) );
		ret = min( ret, call(v) + 1 );
		
		v.pop_back();
		v[i] = temp[i];
	}
	return ret;
}

int main(){
    time_t start=clock();
    freopen("bin","r",stdin);
    freopen("bout","w",stdout);
    ios_base::sync_with_stdio(0);
    int test, kas=0;
    cin>>test;
    while( test-- ){
		int n;
		cin >> n;
		
		while( !pq.empty() ) pq.pop();
		
		//vector<int> ttt;
		
		for(int i =0; i<n; i++ ) {
			int temp;
			cin >> temp;
			pq.push(temp);
			
			//ttt.push_back( temp );
		}
		
		long long answer = LONG_LONG_MAX;
		long long special = 0;
		
		while( pq.top() > 1 ) {
			answer = min( answer, pq.top() + special );
			int top = pq.top(); pq.pop();
			pq.push( top/2 );
			pq.push( top - (top/2) );
			special++;
		}
		
		answer = min( answer, pq.top() + special );
		
		//cout << "----------->" << call(ttt) << endl;
		
		//assert( call(ttt) == answer );
		
        cout<<"Case #"<<++kas<<": ";
        cout << answer << endl;
    }
    cerr << " Program has run "<< ( clock()-start ) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}

