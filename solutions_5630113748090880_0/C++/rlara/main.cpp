#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<vector> 

using namespace std;

int a[2502];


vector < int > v;

int main(){
	int t, n, k;
	cin >> t;
	int aux;
	for(int tt=0;tt<t;tt++){
		cin >> n;
		cout << "Case #" << tt+1 << ": ";
		for(int i=0;i<2*n-1;i++){ 
			for(int j=0;j<n;j++){
				cin >> aux;
				a[aux]++;
			}
		}
		v.clear();
		for(int i=0;i<=2500;i++){
			if(a[i]%2==1)
				v.push_back(i);
			a[i]=0;
		}
		for(int i=0;i<v.size();i++)
			cout << v[i] << " ";
		cout << endl; 
	}
	return 0;
}
