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
	char trans[50] = "yhesocvxduiglbkrztnwjpfmaq";
	char ch;
	cin.get(ch);
    for (int cas = 0; cas < cases; cas++)
    {
		char is[200], os[200];
		cin.getline(is,200);
		string str = is;
		int i;
		for(i=0;i<str.size();i++){
			if(is[i]==' ')os[i]=is[i];
			else os[i]=trans[is[i]-'a'];
		}
		os[i]='\0';
		cout<<"Case #"<<cas+1<<": "<<os<<endl;
    }
    return 0;
}