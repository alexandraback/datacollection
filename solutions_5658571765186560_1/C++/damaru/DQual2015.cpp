#include <iostream>
#include <string>

using namespace std;

const string g="GABRIEL", ri="RICHARD";


int main() {
    int i, j, k, t, cont=1, x, r, c;


    cin >>t;

    for (i=0; i<t; i++){
    	cout << "Case #" << cont++ << ": ";
    	cin >> x >> r >> c;
    	if (c<r) {k=r; r=c; c=k;}//r es el minimo
    	if ((r*c)%x != 0) cout << ri << endl;
    	else if (x>=7) cout << ri << endl;
    	else if (x<=2 ) cout << g << endl;
    	else if (x==3){
    		if (r == 1) cout << ri << endl;
    		else cout << g << endl;
    	}
    	else if (x==4){
    		if (r <= 2) cout << ri << endl;
    		else cout << g << endl;
    	}
    	else if (x==5){
    		if (r <= 2 || (r==3 && c == 5)) cout << ri<< endl;
    		else cout << g << endl;
    	}
    	else if (x==6){
    		if (r<= 3) cout << ri << endl;
    		else cout << g <<endl;
    	}
    }

    return 0;
}

