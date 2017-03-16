#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
//#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <fstream>

using namespace std;
//can D be 0 ? this should be checked

ifstream cin("/users/naginahas/Documents/D-large.in");
ofstream cout("/users/naginahas/Documents/D-largeout.txt");

int main(){
    int T=0;
    cin >> T;
    for(int t=0;t<T;t++){
        int X, R,C;
        cin >> X >> R >> C;
        int r,c;
        r = min(R,C);
        c = max(R,C);
        if(X==1)
            cout << "Case #" << t+1 << ": " << "GABRIEL" << endl;
        else if(X==2){
            if( (R*C)%2 == 1) cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            else cout << "Case #" << t+1 << ": " << "GABRIEL" << endl;

        }
        else if(X==3){
            if( (R*C)%3 != 0) cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            else if(r <2) cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            else cout << "Case #" << t+1 << ": " << "GABRIEL" << endl;

        }
        else if(X==4){
            if( (R*C)%4 != 0)  cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            else if(r<3) cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            else cout << "Case #" << t+1 << ": " << "GABRIEL" << endl;
        }
        else if (X==5){
            if( (R*C)%5 != 0)  cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            else if(r<3) cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            else if (r == 3 && c == 5) cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            else cout << "Case #" << t+1 << ": " << "GABRIEL" << endl;
        }
        else if(X==6){
            if( (R*C)%6 != 0)  cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            else if(r<4) cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
            
            else cout << "Case #" << t+1 << ": " << "GABRIEL" << endl;
        }
        else{
            cout << "Case #" << t+1 << ": " << "RICHARD" << endl;
        }
    }
    
            
}


