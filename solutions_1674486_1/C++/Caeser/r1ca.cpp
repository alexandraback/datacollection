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

int n;
int g[1010][1010],v[1010];
vi r;

bool bfs(int root)
{
	int i,j;
	if(v[root]==1)return false;
	v[root]=1;
	for(i=0;i<n;i++){
		if(g[root][i]==1){
			if(!bfs(i))
				return false;
		}
	}
}
int main(int argc, const char **argv)
{

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
		int i,j,k;
		cin >> n;
		r.clear();
		memset(g,0,sizeof(g));
		for(i=0;i<n;i++){
			int n1;
			cin >> n1;
			if(n1==0)r.push_back(i);
			for(j=0;j<n1;j++){
				int n2;
				cin>>n2;
				g[n2-1][i]=1;
			}
		}

		for(i=0;i<r.size();i++){
			memset(v,0,sizeof(v));
			if(!bfs(r[i]))break;
		}
		if(i==r.size())
		printf("Case #%d: No\n",cas+1);
		else printf("Case #%d: Yes\n",cas+1);
    }
    return 0;
}