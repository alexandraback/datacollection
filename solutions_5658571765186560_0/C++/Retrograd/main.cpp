#include<fstream>
#include<vector>

using namespace std;
typedef int var;

ifstream fin("debug.in");
ofstream fout("debug.out");


bool GabrielBeats(var x, var l, var c) {
    if(l*c % x) {
        return false;
    }

    if(x == 1) return true;

    if(l > c) swap(l, c);

    if(c < x) return false;

    if(x == 2) return true;

    if(x == 4) return l >= 3;
    if(x == 3) return l > 1;
}


int main() {

    var t, x, l, c;
    fin>>t;

    for(var tt=1; tt<=t; tt++) {
        fin>>x>>l>>c;
        fout<<"Case #"<<tt<<": ";
        //fout<<"(x = "<<x<<", l = "<<l<<", c = "<<c<<") ";

        fout<<( GabrielBeats(x, l, c) ? "GABRIEL" : "RICHARD" );

        fout<<'\n';
    }

    return 0;
}
