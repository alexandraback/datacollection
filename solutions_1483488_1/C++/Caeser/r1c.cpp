#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>


using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;
typedef vector<string> vs;
typedef long long ll;

typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int main(int argc, const char **argv)
{

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
		int a,b,i,j,t=1,res=0;
        cin >> a >> b;
		while(a/t>9)t=t*10;
		for(i=a;i<=b;i++){
			j=i;
			do{
				j=(j%10)*t+j/10;
				if(j>i && j<=b)res++;
			}while(j!=i);
		}
		cout<<"Case #"<<cas+1<<": "<<res<<endl;
    }
    return 0;
}