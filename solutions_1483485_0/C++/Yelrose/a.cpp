#include <iostream>
#include <cstring>
#include <map>
using namespace std;
char k[200];
char z[200];
map<char ,char >zz;


int main(){

    zz[' '] = ' ';
    zz['a'] = 'y';
    zz['b'] = 'h';
zz['c'] = 'e';
zz['d'] = 's';
zz['e'] = 'o';
zz['f'] = 'c';
zz['g'] = 'v';
zz['h'] = 'x';
zz['i'] = 'd';
zz['j'] = 'u';
zz['k'] = 'i';
zz['l'] = 'g';
zz['m'] = 'l';
zz['n'] = 'b';
zz['o'] = 'k';
zz['p'] = 'r';
zz['q'] = 'z';
zz['r'] = 't';
zz['s'] = 'n';
zz['t'] = 'w';
zz['u'] = 'j';
zz['v'] = 'p';
zz['w'] = 'f';
zz['x'] = 'm';
zz['y'] = 'a';
zz['z'] = 'q';
    int T;
    cin >> T;
    cin.getline(z,200);
    for(int i = 1;i <= T;i ++){
        cin.getline(k,200);
        for(int i = 0;i < strlen(k);i ++){
            z[i] = zz[k[i]];
        }
        z[strlen(k)] = '\0';
        cout << "Case #" << i << ": " <<z << endl;
    }

}
