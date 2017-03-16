/*
	Mac Crabtree
	Not elegant.cc


	//Do elegantly later, cheap points for now

*/

#include <iostream>
#include <vector>
using namespace std;





int main() {


	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++) {
	    int n;
	    cin >> n;
	    int r, c;
	    bool lose = false;
	    cin >> r >> c;
	    if(r*c % n != 0) lose = true;
	    else if(n <= 1 && r != 1 && c != 1) lose = false;
	    else if((r == 1 && c == 2) || (r == 2 && c == 1)) {
		if(n == 1) lose = false;
		else if(n > 2) lose = true;
	    }
	    else if((r == 1 && c == 4) || (r == 4 && c == 1)) {
		if(n > 2) lose = true;
		else lose = false;
	    }
	    else if(r == 3 && c == 1) {
		if(n == 2) lose = true;
		else if(n==3) lose = true;
		else if(n==1) lose = false;
	    	else lose = true;
	    }
	    else if((r == 2 && c == 3) || (r == 3 && c == 2)) {
		if(n == 1) lose = false;
		else if(n == 2) lose = false;
		else if(n == 3) lose = false;
		else lose = true; 
	    }
            else if(r == 1 && c == 3) {
		if(n == 1) lose = false;
		else if(n == 2) lose = true;
		else if(n == 3) lose = true;
	    }
	    else if((r == 1 && c == 4) || (r == 4 && c == 1)) {
		if(n == 1) lose = false;
		else if(n == 2) lose = false;
		else if(n == 3) lose = true;
		else if(n == 4) lose = true;
		else lose = true;
	    }
	    else if((r == 2 && c == 2)) {
		if(n > 2) lose = true;
	    }
	    else if((r == 2 && c == 4) || (r == 4 && c == 2)) {
		if(n > 2) lose = true;
	    }
	    else if((r == 3 && c == 4) || (r == 4 && c == 3)) {
		if(n == 2) lose = false;
		else if(n == 3) lose = false;
		else if(n == 4) lose = false;
	    }	       
	    else if((r == 4 && c == 4)) {
		if(n < 4) lose = false;
	    }
 
	    cout << "Case #" << i+1 << ": ";
	    if(lose)   cout << "RICHARD" << endl;
	    else       cout << "GABRIEL" << endl;
	}

	




}
