#include <iostream>
#include <string>
using namespace std;

char t[256];
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    t['a']='y';
    t['b']='h';
    t['c']='e';
    t['d']='s';
    t['e']='o';
    t['f']='c';
    t['g']='v';
    t['h']='x';
    t['i']='d';
    t['j']='u';
    t['k']='i';
    t['l']='g';
    t['m']='l';
    t['n']='b';
    t['o']='k';
    t['p']='r';
    t['q']='z';
    t['r']='t';
    t['s']='n';
    t['t']='w';
    t['u']='j';
    t['v']='p';
    t['w']='f';
    t['x']='m';
    t['y']='a';
    t['z']='q';
    int T;
    string s;
    cin >> T; getline(cin,s);
    for (int z=1;z<=T;++z) {
        getline(cin,s);
        cout << "Case #" << z << ": ";
        for (int i=0;i<s.size();++i) {
            if (s[i]==' ') cout << ' ';
            else cout << t[s[i]];
        }
        cout << "\n";
    }
    return 0;
}
