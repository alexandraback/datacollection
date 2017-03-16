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
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;

template<class T>
void splitline(const string &s, vector<T> &dest) {
    istringstream in(s);
    dest.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(dest));
}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
// }}}
int main(){
    int t;
    scanf("%d\n",&t);
    for(int z=0;z<t;z++) {
        int x,y;
        scanf("%d %d",&x,&y);
        /*
            int r=1;
            int ctr;
            if(x<0) ctr=-1;
            x = x>=0?x:-x;
            int ctr1=0;
        while(x>=0){
            x =x-r;
            r++;
            ctr1++;
        }
        */
        string x1="";
        if(x>0){
            x1+="E";
            for(int i=2;i<=x;i++)
                x1+="WE";
        }
        else if(x<0){
            x1+="W";
            for(int i=2;i<=-x;i++)
                x1+="EW";
        }
        string y1="";
        if(y>0){
            for(int i=1;i<=y;i++)
                x1+="SN";
        }
        else if(y<0){
            for(int i=1;i<=-y;i++)
                x1+="NS";
        }
        /*
        int next=sz(x1)+1;
        //s1=s1*(s1-1)/2;
        //y=y-next;
        //cout<<y;
        while(y>=next){
            x1+="NS";
            next++; next++;
        }
        int f=next-y;
        cout<<f;
        for(int i=1;i<=f;i++)
            x1+="SN";
            x1+="N";
            int xx=
            for(int i=2;i<=y;i++)
                x1+="SN";
        }
        else if(y<0){
            x1+="S";
            for(int i=2;i<=-y;i++)
                x1+="NS";
        }
        */

        printf("Case #%d: ",z+1);
        cout<<x1<<endl;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
