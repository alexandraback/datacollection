#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int T , N, app[11] , ans , C = 1;
string s[11];
bool vst[11] , appear[128];
void DFS( int ptr ){
	if ( ptr > N ){
		memset( appear , 0 , sizeof( appear ) );
		char last = -1;
		for ( int k = 1 ; k <= N; k++ )
			for ( int j = 0 , i = s[app[k]].size() ; j < i ; j++ ){
	
				if ( s[app[k]][j] != last ){
					if ( appear[s[app[k]][j]] )	 return;
					appear[s[app[k]][j]] = true;
					last = s[app[k]][j];
				}

			}
		ans++;
		return;
	}
	for ( int i = 1 ; i <= N; i++ )
		if ( !vst[i] ){
			
			vst[i] = true;	app[ptr] = i;
			DFS( ptr+1 );
			vst[i] = false;
		}
}
int main(){
	ifstream fin("B-small-attempt1.in");
	ofstream fout("output.out");
	fin >> T;
	while ( T-- ){
		ans = 0;
		fin >> N;
		for ( int i = 1 ; i <= N; i++ )
			fin >> s[i];
		for ( int i = 1 ; i <= N; i++ ){
			vst[i] = true;	app[1] = i;
			DFS( 2 );
			vst[i] = false;
		}
		fout <<"Case #"<<C++<<": "<<ans<<endl;
		
	}
	
	
	return 0;	
}
