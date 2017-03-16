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

struct SCOPE
{
	vector<LL> as;
	vector<LL> As;
	vector<LL> bs;
	vector<LL> Bs;
	LL L[100][100];
	void run(int Case)
	{
		memset(L,-1,sizeof(L));
		int N,M;
		cin >> N >> M;
		LL last=-1;
		FOR(i,0,N){
			LL a, A;
			cin >> a >> A;
			if (A!=last){
			as.push_back(a);
			As.push_back(A);
			last=a;
			}
			else
			{
				as.back()+=a;
			}
		}
		last=-1;
		FOR(i,0,M){
			LL a, A;
			cin >> a >> A;
			if (A!=last){
			bs.push_back(a);
			Bs.push_back(A);
			last=a;
			}
			else
			{
				bs.back()+=a;
			}
		}

		cout << "Case #" << Case << ": " << len(0,0) << endl;
	}

	LL len(int i, int j){
		if (i >= as.size() || j >= bs.size()){
			return 0;
		}

		if (L[i][j]>=0){
			return L[i][j];
		}

		LL m=len(i+1,j+1);
		m=max(m,len(i,j+1));
		m=max(m,len(i+1,j));
		LL a=as[i];
		LL A=As[i];
		LL b=bs[j];
		LL B=Bs[j];
		LL aA=0;
		FOR(ii,i,as.size()){
			if(As[ii]==As[i]){
				aA+=as[ii];
			}
			LL bA=0;
			FOR(jj,j,bs.size()){
				if(Bs[jj]==As[i]){
					bA+=bs[jj];
				}
				m=max(m,min(aA,bA)+len(ii+1,jj+1));
			}
		}
		LL bB=0;
		FOR(jj,j,bs.size()){
			if(Bs[jj]==Bs[j]){
				bB+=bs[jj];
			}
			LL aB=0;
			FOR(ii,i,as.size()){
				if(As[ii]==Bs[j]){
					aB+=as[ii];
				}
				m=max(m,min(bB,aB)+len(ii+1,jj+1));
			}
		}
		return L[i][j]=m;
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
