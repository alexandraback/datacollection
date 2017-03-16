#include <iostream>
#include <set>
using namespace std;

int n;
int m[1010];
int cnt[1010];
set <int> s[1010];

int num;
bool dia;

//set <int> vis;

void solve(int x){
	if(cnt[x] == num){
		dia = true;
		return;
	}
	cnt[x] = num;

	for(set<int>::iterator sii = s[x].begin(); sii != s[x].end(); sii++){
		solve(*sii);
		if(dia) return;
	}
}

void main(){
	//*
	freopen("A-small.in","r",stdin);
	freopen("A-sm.out","w",stdout);
	//*/

	int T;
	cin>>T;
	for(int tc=1;tc<=T;tc++){

		cin>>n;
		for(int i=1;i<=n;i++){
			s[i].clear();
			cin>>m[i];
			for(int j=0;j<m[i];j++){
				int temp;
				cin>>temp;
				s[i].insert(temp);
			}
		}

		for(int i=1;i<=n;i++) cnt[i]=0;

		dia = false;
		for(int i=1;i<=n;i++){
			num = i;
			if(dia) break;
			solve(i);
		}

		cout<<"Case #"<<tc<<": ";
		if(dia) cout<<"Yes"<<endl;
		else cout<<"No\n";
	}
}
/*
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0

*/