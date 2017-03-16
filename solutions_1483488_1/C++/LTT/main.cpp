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

int numDig (long int a);

long int change(long int a, int ind ){

    int nd = numDig(a);

    long int tt =pow(10,ind);
    long int r = (a%tt)*pow(10,nd-ind) + a/tt;
    return r;
}

int numDig (long int a){
    int r = 1;

    while (a/10 > 0){
        r++;
        a /=10;
    }
    return r;
}

int main()
{
    inft inf, a1, a2;
    cout << "Hello world!" << endl;
    string fnamein = "../C-large.in";
    string fnameout = "../out3c.txt";
    inf.open(fnamein.c_str());
    outt outf;
    outf.open(fnameout.c_str());

    a1.open("../a1.txt");
    a2.open("../a2.txt");
    li N;
    it N;



    fr (ni, N)
    {

        set <long int> sett;
        li A, B;
        it A;
        it B;
            //cout << A << B << el;
            long int r=0;
            for (long int ind = A; ind <=B; ind++){

                for (int i=1; i < numDig(ind); i++){

                    li b = change(ind,i);
                    if ( numDig(ind) != numDig( change(ind,i) ) ) continue;
                    if (b > B) continue;
                    if (b < A) continue;
                    if (ind==b) continue;

                    //ct numDig(ind) << numDig( change(ind,i) ) << el;

                    sett.insert( min(ind,b)*pow(10,numDig(ind))+max(ind,b) );
                    //cout << ind << " " << b <<el;
                    r++;
                }
            }



       // set< long int> :: iterator its;



        //ct sett.size() <<el;
        r = sett.size();
        //cout << r <<el;

        otc ni + 1 << ": ";
        ctc ni + 1 << ": ";
        //cin.get();

        otct(r)
        ocend;
    }
    outf.close();

    return 0;
}


