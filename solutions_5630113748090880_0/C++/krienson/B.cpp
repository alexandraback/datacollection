#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		vector< int > v;
		map< int , int > heights;
		int N, h;
		cin >> N;
		for( int n = 0; n + 1 < 2*N; n++ ){
			for( int n2 = 0; n2 < N; n2++ ){
				cin >> h;
				heights[ h ]++;
			}
		}
		for( map<int,int>::iterator it = heights.begin(); it != heights.end(); it++ ){
			if( (it->second)&1 ){
				v.push_back( it->first );
			}
		}
		sort( v.begin() , v.end() );

		cout << "Case #" << kase << ":";
		for( int i = 0; i < v.size(); i++ ){
			cout << " " << v[i];		
		}	
		cout << endl;
	}
}
