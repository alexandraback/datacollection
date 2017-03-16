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
vi a,b;
int main(int argc, const char **argv)
{

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
		int i,j,k;
		a.clear();b.clear();
		cin>>n;
		for(i=0;i<n;i++)
		{
			int a1,b1;
			cin>>a1>>b1;
			a.push_back(a1);b.push_back(b1);
		}
		//sort(a.begin(),a.end());
		//sort(b.begin(),b.end());

		//if(a[0]>0){cout<<"Case #"<<cas+1<<": Too Bad"<<endl;continue;}

		int res=0,ts=0,va[1010],vb[1010];
		memset(va,0,sizeof(va));
		memset(vb,0,sizeof(vb));
		int tb=0;
		while(1){
			int found=0;
		    for(i=0;i<b.size();i++){
			    if(ts>=b[i] && vb[i]==0){ts+=2-va[i];vb[i]=1;found =1;res++;break;}
		    }
			if(found==0){
				for(i=0;i<a.size();i++){
					if(ts>=a[i] && va[i]==0 && vb[i]==0){ts+=1;va[i]=1;found =1;res++;break;}
				}
			}
			if(found==0){
				for(i=0;i<b.size();i++){
			        if(vb[i]==0){tb=1;break;}
				}
				break;
			}
			int ff=0;
			for(i=0;i<b.size();i++){
			    if(vb[i]==0){ff=1;break;}
			}
			if(ff==0)break;
		}
		if(tb){cout<<"Case #"<<cas+1<<": Too Bad"<<endl;continue;}
		cout<<"Case #"<<cas+1<<": "<<res<<endl;
    }
    return 0;
}