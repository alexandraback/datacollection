
#include <cmath>
#include <string>
#include <iostream>

using namespace std;




int main(){

	
	int cases, caseidx;
	char data[1000];
	char mapping[36] = "yhesocvxduiglbkrztnwjpfmaq";
	char res[1000];
	int ichar ;

	cin >> cases;

	for (caseidx = 0 ; caseidx <= cases ; caseidx++ ){

		cin.getline( data , 101 );
		
		for (ichar = 0 ; data[ichar] ; ichar++ ){
			if (data[ichar] != ' ' )	res[ichar] = mapping[static_cast<int>(data[ichar]-'a')];
			else res[ichar] = ' ' ; 
		}
		res[ichar] = 0;
		if (caseidx )		
		cout << "Case #" << caseidx << ": " << res << endl  ; 
	}

	return 0;

}

