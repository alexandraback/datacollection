#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

signed main() {
	freopen("a.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	for(int t=1;t<=tt;t++){
		cout << "Case #" << t << ": ";
		cerr << t << endl;
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		cerr << t << " " << d << "\n";
		if(d >= 3){
			cout << a*b*c << "\n";
			for(int i=0;i<a;i++) for(int j=0;j<b;j++) for(int k=0;k<c;k++) cout << i+1 << " " << j+1 << " " << k+1 << "\n";
			continue;
		}
		vector<pair<int,pair<int,int> > > v;
		int aa[3][3],bb[3][3],cc[3][3];
		for(int i=0;i<3;i++) for(int j=0;j<3;j++){
			aa[i][j]=0; bb[i][j]=0; cc[i][j]=0;
		}
		set<pair<int,int> > l[3];
		for(int i=0;i<a;i++) l[0].insert({-1,i});
		for(int i=0;i<b;i++) l[1].insert({-1,i});
		for(int i=0;i<c;i++) l[2].insert({-1,i});
		int ct = 0;
		while(1){
			set<pair<int,int> > :: iterator it = l[0].begin();
			int x = it->second;
			l[0].erase(it);
			l[0].insert({ct,x});
			it = l[1].begin();
			int y = it->second;
			l[1].erase(it);
			l[1].insert({ct,y});
			it = l[2].begin();
			int z = it->second;
			l[2].erase(it);
			l[2].insert({ct,z});
			if(aa[x][y] >= d) break;
			if(bb[y][z] >= d) break;
			if(cc[x][z] >= d) break;
			v.push_back({x+1,{y+1,z+1}});
			aa[x][y]+=1;
			bb[y][z]+=1;
			cc[x][z]+=1;
			ct++;
		}
		//cerr << "HERE" << endl;
		cout << v.size() << "\n";
		for(int i=0;i<v.size();i++){
			cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << "\n";
		}
	}
    return 0;
}
