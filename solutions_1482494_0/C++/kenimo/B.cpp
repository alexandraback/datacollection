#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#define FOR(i, b, e) for (typeof(b) i = (b); i != (e); ++i)
#define VAR(a,b) typeof(b) a=b
#define dout cout
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<P, int> Q;
struct SCOPE
{
	void run(int Case)
	{
		cout << "Case #" << Case << ": ";
		int N;
		cin >> N;
		bool done[1001]={0};
		vector<P> h;
		vector<Q> l;
		int A[1001]={0};
		FOR(i,0,N){
			int a, b;
			cin >> a >> b;
			//l.push_back(Q(P(a,-b),i));
			h.push_back(P(b,i));
			A[i]=a;
		}
		sort(l.begin(),l.end());
		sort(h.begin(),h.end());
		int c=0;
		int j=0;
		int ret=0;
		while(1){
			if(j==h.size()){
				break;
			}
			if(c>=h[j].first)
			{
				//cout << "2: " << h[j].second << endl;
				int i=h[j].second;
				if (done[i]){
					c+=1;
				}
				else
				{
					c+=2;
					done[i]=true;
				}
				j++;
				ret++;
				continue;
			}
			
			int k;
			for(k=((int)h.size())-1;k>=0;k--){
				int i=h[k].second;
				if (c>=A[i])
				{
					if (!done[i]){
						//cout << "1: " << h[j].second << endl;
						done[i]=true;
						c++;
						ret++;
						break;
					}
				}
			}

			if (k<0){
				cout << "Too Bad" << endl;
				return;
			}
		}
		cout << ret << endl;
	}
};

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		SCOPE* pSCOPE = new SCOPE();
		pSCOPE->run(t);
		delete pSCOPE;
	}
}
