#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
int n, m[1001];
bool vis[1001][1001];
vector <vector<int> > vi;

void doit(){
	int tv;
	int q[1005],qb,qe,ti,nti;
	vector <int> tvi;
	memset(vis,0,sizeof(vis));
	vi.clear();
	cin>>n;
	for(int i=0;i<n;i++){
		tvi.clear();
		cin>>m[i];
		for(int j=0;j<m[i];j++){
			cin>>tv;
			tvi.push_back(tv-1);
		}
		vi.push_back(tvi);
	}
	for(int i=0;i<n;i++){
		vis[i][i]=true;
		qb=qe=0;
		q[qe++]=i;
		while(qe>qb){
			ti=q[qb++];
			for(int j=0;j<m[ti];j++){
				nti=vi[ti][j];
				if(vis[i][nti]){
					cout<<"Yes"<<endl;
					return;
				}
				else{
					vis[i][nti]=true;
					q[qe++]=nti;
				}
			}
		}
	}
	cout<<"No"<<endl;
    return;
}
int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cout<<"Case #"<<i<<": ";
        doit();
    }
    return 0;
}
