
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

int data[1024][1024];
int path[1024];
int nodes;

int recurse( const int node );

int recurse( const int node ){

	int ei;

	if (path[node]) return true;
	path[node]++;

	for (ei = 1 ; ei <= data[node][0] ; ei++ ){
		if (recurse ( data[node][ei] )) return true;
	}

	return false;

}



int main(){

	int c, ci;
	int  di;
	int e, ei;
	
	bool diamond;

	cin >> c;

// follow each path 

	for (ci = 1 ; ci <= c ; ci++ ){
		
		cin >> nodes;
		
		memset (path , 0 , sizeof(path));
		diamond = false;

		for (di = 1 ; di <= nodes ; di++ ){

			cin >> data[di][0]; 
			for (ei = 1 ; ei <= data[di][0] ; ei++ ){	
				cin >> data[di][ei];				
			}		
		}	


		for (di = 1 ; di <= nodes ; di++ ){
			
			memset (path , 0 , sizeof(path));
			diamond = recurse(di);
			if (diamond) break;
		}

		cout << "Case #" << ci << ": "  << (diamond ? "Yes" : "No") <<  endl ;
	}
	return 0;

}

