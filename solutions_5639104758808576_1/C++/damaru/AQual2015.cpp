#include <iostream>

using namespace std;


int main() {
    int i, j, t, cont=1, s, b, acum, res;
    char a;
    cin >>t;

    for (i=0; i<t; i++){
    	cout << "Case #" << cont++ << ": ";
    	cin >> s;
    	acum=0;
    	res=0;
    	for (j=0; j<s; j++){
    		cin >> a;
    		b= (int)(a-'0');
    		acum+=b;
    		if (acum <= j){
    			res += j+1-acum;
    			acum = j+1;
    		}
    	}
    	cin >> a;
    	cout << res << endl;
    }

    return 0;
}
/*
4
4 11111
1 09
5 110011
0 1
 * */

