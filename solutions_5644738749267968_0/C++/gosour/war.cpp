#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int war_score(vector<double> naomi, vector<double> ken){
		int warcount = 0;
		int i,j;
		for(i=0,j=0;i<naomi.size()&&j<ken.size();i++,j++){
			while(naomi[i] > ken[j] && j<ken.size()) {j++;}
			if(j>=ken.size()) break;
			if(naomi[i]<ken[j]){
				warcount++;
			}
		}
		return naomi.size() - warcount;

}
int dwar_score(vector<double> naomi, vector<double> ken){
	int dwar = 0;
	int i,j;
	for(i=0,j=0;i<naomi.size() && j<ken.size();i++){
		if(naomi[i] < ken[j]) continue;
		else{
			j++;
			dwar++;
		}
	}	
	return dwar;
}

int main(){
	int T,c=1;
	int n;
	cin>>T;
	double temp;
	vector<double> naomi;
	vector<double> ken;
	int i,j;

	while(T--){
		cin>>n;
		naomi.clear();
		ken.clear();
		for(i=0;i<n;i++){
			cin>>temp;
			naomi.push_back(temp);
		}
		for(i=0;i<n;i++){
			cin>>temp;
			ken.push_back(temp);
		}
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
			
		cout<<"Case #"<<c++<<": "<<dwar_score(naomi,ken)<<" "<<war_score(naomi,ken)<<endl;
	}	
}
