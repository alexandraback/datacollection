#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int used[11][11][11];
int cnt[11][11][11];
int used1[11][11][11];
int cnt1[11][11][11];
vector<pair<int,pair<int,int > > > temp;
void solve(int test){
	int j,p,s,K;
	cin>>j>>p>>s>>K;
	memset(used,0,sizeof(used));
	memset(cnt,0,sizeof(cnt));
	int ans = 0;
	int f = 0;
	for(int off = 10;off < 27; off++){
		memset(used1,0,sizeof(used1));
		memset(cnt1,0,sizeof(cnt1));
		int tans = 0;
		int l = off+1;
		vector<pair<int,pair<int,int> > > t;
		t.push_back(temp[off]);
		if(l == 27)
			l= 0;
		while(l!=off){
			t.push_back(temp[l]);
			l++;
			if(l == 27)
				l= 0;
		}	
		/*cout<<endl;
		for(int i = 0;i < t.size(); i++){
			cout<<t[i].X<<" "<<t[i].Y.X<<" "<<t[i].Y.Y<<endl;
		}*/
		for(int i = 0;i < t.size(); i++){
			int x =t[i].X,y=t[i].Y.X, z=t[i].Y.Y;
			if(x > j || y > p || z > s)continue;
			int XX = max(cnt1[x][y][0],max(cnt1[0][y][z],cnt1[x][0][z]));
			//cout<<x<<" "<<x<<" "<<y<<" "<<z<<endl;
			if(XX == K)continue;
			used1[x][y][z] ++;
			tans++;
			cnt1[x][y][0]++;
			cnt1[0][y][z]++;
			cnt1[x][0][z]++;
		}
		if(ans < tans){
			for(int i = 1;i <=j; i++){
				for(int l = 1;l <=p; l++){
					for(int k = 1;k <=s; k++){
						used[i][l][k] = used1[i][l][k];
					}
				}
			}
			ans = tans;
		}
		if(off == 9)break;
		if(off == 26)off = -1;
	}
	/*if(ans < j*p*s){
		cerr<<"TEST "<<test<<endl;
		cerr<<j<<" "<<p<<" "<<s<<" "<<K<<" "<<ans<<endl;
	}*/
	cout<<ans<<endl;
	for(int i = 1;i <=j; i++){
		for(int l = 1;l <=p; l++){
			for(int k = 1;k <=s; k++){
				if(used[i][l][k])
					cout<<i<<" "<<l<<" "<<k<<endl;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	freopen("./input.txt","r",stdin);
	freopen("./output.txt","w",stdout);
	//cerr<<"Error \n";
	int t;
	cin>>t;
	for(int i = 1;i <=3; i++){
		for(int l = 1;l <=3; l++){
			for(int k = 1;k <=3; k++){
				temp.push_back({i,{l,k}});
			}
		}
	}
	for(int i = 1;i <=t; i++){
		cout<<"Case #"<<i<<": ";
		solve(i);
	}
	return 0;
}	