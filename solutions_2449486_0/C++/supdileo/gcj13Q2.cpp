#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int maxn=110;
typedef vector<int> vint;
int Lwn[maxn][maxn];


int main(){
	ifstream cin("B-small-attempt3.in");
	ofstream cout("Bsmall.out");
	int ncase;
	cin>>ncase;
	vint height;
	for(int icase=1;icase<=ncase;icase++){
		int N,M;
		cin>>N>>M;
		bool fail=0;
		height.clear();
		for(int i=0;i<N;i++)for(int j=0;j<M;j++){
			cin>>Lwn[i][j];
			height.push_back(Lwn[i][j]);
		}

		sort(height.begin(),height.end());
		vint::iterator end=unique(height.begin(),height.end());
		height.erase(end,height.end());
		
		
		vint x;
		vint y;
		int min,secmin;
		vint xmow,ymow;
		for(int t=0;t<height.size()-1;t++){
			xmow.clear();ymow.clear();
			x.assign(N,0);y.assign(M,0);

			min = height[t];secmin=height[t+1];
			for(int i=0;i<N;i++)for(int j=0;j<M;j++){
				if(Lwn[i][j]==min){
					x[i]++;
					y[j]++;
				}
			}
			for(int i=0;i<N;i++)if(M==x[i])xmow.push_back(i);
			for(int i=0;i<M;i++)if(N==y[i])ymow.push_back(i);
			if(xmow.empty() && ymow.empty()){
				fail=1;
				break;
			}
			for(int i=0;i<xmow.size();i++)for(int j=0;j<M;j++){
				Lwn[xmow[i]][j]=secmin;
			}
			for(int j=0;j<ymow.size();j++)for(int i=0;i<N;i++){
				Lwn[i][ymow[j]]=secmin;
			}
			for(int i=0;i<N;i++)for(int j=0;j<M;j++){
				if(Lwn[i][j]==min){
					fail=1;
					break;
				}
			}
		}
		cout<<"Case #"<<icase<<": ";
		if(fail)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;

	}
	return 0;
}
