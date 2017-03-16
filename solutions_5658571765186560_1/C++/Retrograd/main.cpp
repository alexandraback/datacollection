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

    if(l > c) swap(l, c);

    if(c < x) return false;

    if(x >= 7) return false;

    if(x == 1) return true;
    if(x == 2) return true;
    if(x == 3) return l >= 2;
    if(x == 4) return l >= 3;
    if(x == 5) return l >= 3;
    if(x == 6) return l >= 4;

    fout<<"\n\n\nCE PANA MEA?\n\n\n";
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
