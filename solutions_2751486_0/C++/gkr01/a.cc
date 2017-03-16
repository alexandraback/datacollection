//#includes {{{
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <complex>
#include <list>
#include <stack>
#include <queue>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;
// }}}
// #defines {{{

#define sz(a) int((a).size())
#define pb push_back

#define all(c) (c).begin(),(c).end()
#define fro(i,n) for (int i=0; i<(int(n)); i++)
#define tr(it, container) \
    for(typeof(container.begin()) it = container.begin(); it == container.end(); it++)

#define present(c,x) ((c).find(x) == (c).end())
#define cpresent(c,x) (find(all(c),x) == (c).end())

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
// }}}
int main(){
    int t;
    scanf("%d\n",&t);
    for(int z=0;z<t;z++) {
        string name; int n;
        cin >> name;
        cin>> n;
        int zz=-1;
        //cout<<sz(name);
        int ctr=0;
        for(int i=0;i<=sz(name)-n;i++){
            string s=name.substr(i,n);
            if(s.find_first_of("aeiou")==string::npos)
            { //its good
                //cout<<zz<<" XX " << i << " YY "<<s<<endl;;
                // s contains valid string
                // zz start index of valid string previous;
                // i start index of valid string current;
                int newz = sz(name) - (i+n-1);
                int newp=0;
                if(zz!=-1)
                    newp = i - (zz+1);
                else if (zz==-1)
                    newp = i;
                //cout << newz << "\t"<<newp<<endl;
                ctr += newz + newz*newp;
                zz=i;
            }
            else continue;

        //while(name.find_first_not_of("aeiou",zz)!=string::npos){

        }

        printf("Case #%d: %d\n",z+1,ctr);
        /*
    string s=C;
    string s2=ab;
    int pos = -1;
    bool ok = true;
    for (int i = 0 ; ok && i != sz(s) ; i++) {
        ok = (pos = s2.find(s[i], pos+1)) != string::npos;
    }
        cout<<(ok?"YES":"NO")<< endl;

    }
    */

        /*
        int ctr=0;
        int panic=0;
        int zz=0;
        vector<int> index;
            //if( name[i]=='a'||name[i]=='e'||name[i]=='i'||name[i]=='o'||name[i]=='u'){
            for(;name.find_first_of("aeiou",zz)!=string::npos;){
                int zz3=zz;
            //while(name.find_first_not_of("aeiou",zz)!=string::npos){
                zz=name.find_first_not_of("aeiou",zz);
                int zz2=name.find_first_of("aeiou",zz);
                if(zz2-zz>=n){
                    int cc=zz2-zz+1;
                }
            }
            */


    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
