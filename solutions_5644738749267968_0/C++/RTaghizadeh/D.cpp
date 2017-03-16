#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream fout;
	fout.open("d:\\ans.txt");
	cout.rdbuf(fout.rdbuf());

	ifstream fin;
	fin.open("d:\\1.in");
	cin.rdbuf(fin.rdbuf());
	int t,te;
	cin>>t;
	int n,i,j,k;
	int a[2000];
	double w[2000];
	for(te=1;te<=t;te++){
		cin>>n;
		for(i=0;i<n;i++){
			a[i]=1;
			cin>>w[i];
		}
		for(i=0;i<n;i++){
			a[n+i]=2;
			cin>>w[n+i];
		}
		for(i=0;i<2*n;i++){
			for(j=i+1;j<2*n;j++){
				if(w[i]>w[j]){
					swap(w[i],w[j]);
					swap(a[i],a[j]);
				}
			}
		}
		cout<<"Case #"<<te<<": ";
		j=2;k=1;
		int x=0;
		int s=0;
		for(i=0;i<2*n;i++){
			if(a[i]==j){
				x++;
			}
			else if(x>0){
				x--;
				s++;
			}
		}
		cout<<s<<" ";
		j=1;k=2;
		x=0;
		s=0;
		for(i=0;i<2*n;i++){
			if(a[i]==j){
				x++;
			}
			else if(x>0){
				x--;
				s++;
			}
		}
		cout<<n-s<<endl;
			
	}
	return 0;
}