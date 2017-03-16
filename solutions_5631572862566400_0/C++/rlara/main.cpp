#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
using namespace std;


int a[20];
int b[20];
int mayor;

int posible(vector <int> v, int n){
	/*for(int i=0;i<n;i++)
		cout << v[i] << " ";
	cout << endl;*/
	int cont=1;
	for(int i=1;i<n;i++){
		/*if(i==0){
			if(a[v[i]]==v[i+1] || a[v[i]]==v[n-1]){
				cont++;
			}
			else{
				if(a[v[i]]==v[0] && (a[v[0]]==v[i] || a[v[0]]==v[1]))
					return cont+1;
				else
					return 0;
			}
					
		}*/
		if(i==n-1){
			if(a[v[i]]==v[0] || a[v[i]]==v[i-1]){
				cont++;
			}
			else{
				if(a[v[i]]==v[0] && (a[v[0]]==v[i] || a[v[0]]==v[1]) )
					return cont+1;
				else
					return 0;
			}
		}
		else{
			if(a[v[i]]==v[i+1] || a[v[i]]==v[i-1]){
				cont++;
			}
			else{
				if(a[v[i]]==v[0] && (a[v[0]]==v[i] || a[v[0]]==v[1]))
					return cont+1;
				else
					return 0;
			}
		}
	}
	if(a[v[0]]==v[n-1] || a[v[0]]==v[n-1])
		return cont;
	else
		return 0;
}

void busca(vector <int> v, int n, int cont){
	int r=v.size()-2;
	if(r>1){
		if(a[v[r]]!=v[r-1] && a[v[r]]!=v[r+1]){
			int u=posible(v, cont);
			if(u>mayor){
				mayor=u;
			}
			return;
		}
	}
	
	if(cont<n){
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				b[i]=1;
				v.push_back(i);
				busca(v, n, cont+1);
				v.pop_back();
				b[i]=0;
			}
		}
	}
	else{
		int r=posible(v, n);
		if(r>mayor){
			mayor=r;
		}
	}
}

int main(){
	int t, n, k;
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		mayor=0;
		vector <int> v;
		busca(v, n, 0);
		cout << "Case #" << tt+1 << ": " << mayor << endl;
		
		//cout << endl; 
	}
	return 0;
}
