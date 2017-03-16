#include <iostream>
#include <string>

using namespace std;

int id (int c, int w){
	int res = (c/w)-1;
	c-= res*w;
	if (c==w) return res+w;
	return res+w+1;
}


int main() {
    int i, j, t, cont=0, r, c, w, res;
    cin >>t;

    for (i=0; i<t; i++){
    	cout << "Case #" << ++cont << ": ";
    	cin >> r >> c >> w;
    	res = (c/w)-1;
    	if (c- res*w == w) cout << (res+1)*r +w-1;
    	else cout << (res+1)*r+w;
    	cout << endl;
    }
    return 0;
}
/*

*/
