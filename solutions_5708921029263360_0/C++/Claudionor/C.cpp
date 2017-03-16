#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	int j;
	int p;
	int s;
	int k;
	vector<vector<int>>comb;
	vector<vector<int>> jp;
	vector<vector<int>> js;
	vector<vector<int>> ps; 
	int cont=1;
	cin>>t;
	while(t--){
		cout<<"Case #"<<cont<<": ";
		cont++;
		comb.clear();
		cin>>j>>p>>s>>k;
		jp=vector<vector<int>>(j,vector<int>(p,0));
		js=vector<vector<int>>(j,vector<int>(s,0));
		ps=vector<vector<int>>(p,vector<int>(s,0));
		for(int i=0;i<s;i++){
			for(int n=0;n<p;n++){
				for(int l=0;l<j;l++){
					if(jp[l][n]<k && js[l][i]<k && ps[n][i]<k){
						jp[l][n]++;
						js[l][i]++;
						ps[n][i]++;
						comb.push_back(vector<int>());
						comb.back().push_back(l+1);
						comb.back().push_back(n+1);
						comb.back().push_back(i+1);
					}
				}
			}
		}
		cout<<comb.size()<<"\n";
		for(int i=0;i<comb.size();i++)
			cout<<comb[i][0]<<" "<<comb[i][1]<<" "<<comb[i][2]<<"\n";
	}
	return 0;
}