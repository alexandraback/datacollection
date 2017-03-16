#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
                int x, w, h;
                cin>>x>>w>>h;
                bool rich = false;
                int a = max(w,h);
                int b = min(w,h);
                
                if (w * h % x != 0) rich = true;
                if (x > a) rich = true;
                if ((x+1)/2 > b) rich = true;
                if (x >= 7) rich = true;
                if (x == 4 && b == 2) rich = true; // TODO
                
		cout << "Case #" << i << ": " << (rich ? "RICHARD" : "GABRIEL") << endl;
	}
        
}
