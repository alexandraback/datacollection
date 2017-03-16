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


double p[100010],p1[100010],p2[100010],pall=1.0,seed=1.0,seed1=1.0;
int main(int argc, const char **argv)
{

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
		int a,b,i,j;
		double a1=0.0,a2=0.0,a3=1000000.0;
		cin>>a>>b;
		pall = 1.0;
		seed = seed1=1.0;
		for(i=0;i<a;i++)
			cin>>p[i];

		for(i=0;i<a;i++)pall = pall * (p[i]);
		a1 = pall * (double)(b-a+1) + (1.0-pall) * (double)(2*b-a+2);
		a2 = 2.0+(double)b;

		for(i=0;i<a;i++){
			p1[i]=seed * (1.0-p[i]);
			p2[i]=seed1*p[i];
			seed1=p2[i];
			seed = seed * (p[i]);
		}

		for(i=a-1,j=1;i>=0;i--,j++){
			double a4 = p1[i]*(double)(2*j+b-a+1) + p2[i] * (2*j+b-a+1) + (1.0-p2[i]/p[i])*(double)(2*j+2*b-a+2);
			a3 = a3<a4?a3:a4;
		}
		a2 = a2<a3?a2:a3;
		a1 = a1<a2?a1:a2;
		printf("Case #%d: %.6f\n",cas+1,a1);
		//cout<<"Case #"<<cas+1<<": "<<a1<<endl;
    }
    return 0;
}