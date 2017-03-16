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
		int n,s,p,i,j;
        cin >> n >> s >> p;
		int a1=0,a2=0,a3=0,res=0;
		
		    for(i=0;i<n;i++){
			    cin>>j;
				if(p==0)res++;
			    else if(p==1){
					if(j>0)res++;
				}else{
					if(j<2)continue;
					else if(j>28)res++;
					else if(j>(p-1)*3)a1++;
					else if(j>(p-2)*3+1)a2++;
					else a3++;
				}
		    }
			if(s<=a2)res=res+a1+s;
			else res = res + a1+a2;
		
		cout<< "Case #"<<cas+1<<": "<<res<<endl;
    }
    return 0;
}