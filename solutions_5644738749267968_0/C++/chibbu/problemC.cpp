#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int t;
	cin >> t;
	for(int k=1; k<=t; k++){
		int n;
		cin>> n;
		vector<double> nao(n), ken(n);
		for(int i=0; i<n; i++) cin>> nao[i];
		for(int i=0; i<n; i++) cin>> ken[i];
		sort(nao.begin(),nao.end());
		sort(ken.begin(),ken.end());
		int ken_win=0, n_curr=0, k_curr=0;
		while(n_curr<n && k_curr<n){
			if(nao[n_curr]<ken[k_curr]){
				ken_win++;
				n_curr++;
				k_curr++;
			}
			else{
				k_curr++;
			}
		}
//		cout<<"Naomi wins in war: "<< n-ken_win<< endl;
		int ans2=0, n_beg=0, k_beg=0, k_end=n-1;
		while(n_beg<n && k_beg<=k_end){
			if(nao[n_beg]>ken[k_beg]){
				ans2++;
				n_beg++;
				k_beg++;
			}
			else{
				n_beg++;
				k_end--;
			}
		}
		
		cout<<"Case #"<<k<<": "<<ans2<<" "<<n-ken_win<<endl;
	}
	return 0;

}
