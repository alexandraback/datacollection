#include<iostream>
#include<vector>

#define mp make_pair
#define pii pair<unsigned long long int,unsigned long long int>
#define pb push_back
#define ull unsigned long long int;

using namespace std;

int main()
{
	int t;
	cin>>t;
	int dx[] = {-1, 0, -1};
	int dy[] = {-1, -1, 0};
	for(int kase = 1 ; kase <= t ; kase++) {

		unsigned long long int N,M;
		unsigned long long int lcs[102][102];
		for(int i=0;i<101;i++){
			 lcs[i][0] = 0;
			 lcs[0][i] = 0;
		}
		
		vector<pair<unsigned long long int,unsigned long long int> > Nx,Mx;
		vector<pair<unsigned long long int,unsigned long long int> > nx,mx;
		cin>>N>>M;
		unsigned long long int a,b;
		
		for(int i=0;i<N;i++){
			cin>>a>>b;
			Nx.pb(mp(b,a));
		}
		for(int i=0;i<M;i++){
			cin>>a>>b;
			Mx.pb(mp(b,a));
		}
		mx=Mx;nx=Nx;
		for(int i=1;i<Nx.size()+1;i++) {
			for(int j=1; j<Mx.size()+1;j++)	{
				unsigned long long int v = 0;
				for(int k=0;k<3;k++){
				 v = max(v,lcs[i+dx[k]][j+dy[k]]);
				}
				if(v == lcs[i+dx[0]][j+dy[0]]){
					Nx[i-1] = nx[i-1];
					Mx[j-1] = mx[j-1];
				} else if (v == lcs[i+dx[1]][j+dy[1]]){
					Mx[j-1] = mx[j-1];
				}else {
					Nx[i-1] = nx[i-1];
				}
				lcs[i][j] = v;
				if(Nx[i-1].first == Mx[j-1].first) {
					unsigned long long int mini = min(Nx[i-1].second, Mx[j-1].second);
					Nx[i-1].second -= mini;
					Mx[j-1].second -= mini;
					lcs[i][j] += mini;
				}
				
			}
		}
		cout<<"Case #"<<kase<<": ";
		cout<<lcs[Nx.size()][Mx.size()]<<endl;
	}

}
