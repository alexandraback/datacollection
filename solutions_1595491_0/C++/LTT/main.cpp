#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef ifstream inft;
typedef ofstream outt;
typedef long int li;
typedef vector <li> vi;
typedef unsigned long int ui;

#define fo(i, a, b) for( int i = (a); i < (b); i++)
#define fr(i,b) fo(i,0,b)
#define ft(b) fo(i,0,b)
#define el endl
#define pb push_back

#define ct cout<<
#define ot outf<<
#define it inf>>

#define otc outf << "Case #" <<
#define ctc cout << "Case #" <<

#define all(v) (v).begin( ), (v).end( )

#define otct(a) ot a; ct a;
#define ocend otct(endl)

void swap(long int& a, long int&b){

    long int temp = a;
    a = b;
    b = temp;
}

int main()
{
    inft inf, a1, a2;
    cout << "Hello world!" << endl;
    string fnamein = "../B-small-attempt0.in";
    string fnameout = "../out3.txt";
    inf.open(fnamein.c_str());
    outt outf;
    outf.open(fnameout.c_str());

    a1.open("../a1.txt");
    a2.open("../a2.txt");
    map <char, char> m;

    while( !a1.eof() ){
        char c1, c2;
        a1 >> c1;
        a2 >> c2;
        m[c1] = c2;

    }
    m[' '] = ' ';


    li N;
    it N;
char ctemp;
inf.get(ctemp);
    fr (ni, N)
    {
        li ng, ns, np;
        it ng;
        it ns;
        it np;
        li r(0), r2(0);
        vi v;

        ft(ng){
            li temp;
            it temp;
            v.pb(temp);
            li te;
            te = temp - np;
            if (te<0) continue;
            long double ld;
            ld = (long double) te/2;
            if (ld > np) r++;
            else if (abs(ld-np)<=1 ) r++;
            else if (abs(ld-np)<=2) r2 ++;


            //cout << temp << " ";

        }
//cout << r2 << " " << r << endl;
                    if (r2 > ns) r2 = ns;
            r +=r2;

        otc ni + 1 << ": ";
        ctc ni + 1 << ": ";


        otct(r)
        ocend;
    }
    outf.close();

    return 0;
}


