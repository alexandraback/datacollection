#include <iostream>
#include <string>

using namespace std;


int main() {
    int i, j, t, c, d, v, cont=0, res;
    int mon[100];
    long long int h;
    cin >>t;


    for (i=0; i<t; i++){
    	res=0;
    	cout << "Case #" << ++cont << ": ";
    	cin >> c >> d >> v;
    	for (j=0; j< d; j++){
    		cin >> mon[j];
    	}
    	if (mon[0]>1) {h = c; res=1;j=0;}
    	else {h=c; j=1;}
    	while (h < v){
    		if (j<d){
				if(mon[j] <= h+1){
					h = mon[j]*c+h;
					++j;
				}
				else{
					++res; h = (h+1)*c+h;
				}
    		}
    		else{
    			++res; h=(h+1)*c+h;
    		}
    	}
    	cout << res << endl;
    }
    return 0;
}
/*

*/
