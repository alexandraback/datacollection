#include <iostream>
#include <vector>

using namespace std;

int run() {
    int x,r,c;
    cin >> x >> r >> c;
    if(x >= 7) return 'r';//Holes
    if(x > r && x > c) return 'r';//long piece
    if(x == 1) return 'g';//trivial
    if((r*c)%x != 0) return 'r';//div
    if(x == 2) return 'g';//trivial
    if(r > x && c > x) return 'g';//rest is connected
    if(r < c) {
        int tmp = r;
        r=c;
        c=tmp;
    }//Now r>=c
    if(c == 1) return 'r';//Too narrow, piece hits outside
    if(x == 3) return 'g';//Can always place in corner
    if(x == 4) {
        if(r%2 == 0)
            if(c == 2) return 'r';
            else return 'g';
        else
            return 'g';
    }
}

int main() {
    int ncases;
    cin >> ncases;
    for(int i=0; i<ncases; i++) {
        cout << "Case #"<<(i+1) << ": ";
        if(run() == 'g')
            cout << "GABRIEL";
        else cout << "RICHARD";

        cout <<"\n";

    }
}
