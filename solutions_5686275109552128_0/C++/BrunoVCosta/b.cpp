#include<iostream>
#include<vector>
#include<algorithm>
#include <fstream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	ofstream myfile;
	myfile.open ("saida.txt");
	int t;
	cin>>t;
	for (int i= 0;i<t;i++){
		int d,trocas=0;
		vector<int> p;
		cin>>d;
		for(int j=0;j<d;j++){
			int x;
			cin>>x;
			p.push_back(x);
		}
		sort(p.begin(),p.end());
		reverse(p.begin(),p.end());
		vector<int> aux;
		int repetidos=0;
		aux.clear();
		for(int j=0;j<p.size();j++){
			if(p[j]==p[0])
				repetidos++;
			if (aux.size()){
				if(p[j]!=aux[aux.size()-1]){
					aux.push_back(p[j]);
				}
			}else{
				aux.push_back(p[j]);
			}
		}
		if(aux.size()==1 && aux[0]>=aux[0]-aux[0]/2+repetidos){
			trocas++;
			p.push_back(p[0]-p[0]/2);
			p[0] = p[0]/2;
			sort(p.begin(),p.end());
			reverse(p.begin(),p.end());
			
			aux.clear();
			repetidos=0;
			for(int j=0;j<p.size();j++){
				if(p[j]==p[0])
					repetidos++;
				if (aux.size()){
					if(p[j]!=aux[aux.size()-1]){
						aux.push_back(p[j]);
					}
				}else{
					aux.push_back(p[j]);
				}
			}
			
			
		}
		while(aux.size()!=1 && (aux[0]>=(max(aux[0]-aux[0]/2,aux[1])+repetidos))){
			trocas++;
			p.push_back(p[0]-p[0]/2);
			p[0] = p[0]/2;
			sort(p.begin(),p.end());
			reverse(p.begin(),p.end());
			
			aux.clear();
			repetidos=0;
			for(int j=0;j<p.size();j++){
				if(p[j]==p[0])
					repetidos++;
				if (aux.size()){
					if(p[j]!=aux[aux.size()-1]){
						aux.push_back(p[j]);
					}
				}else{
					aux.push_back(p[j]);
				}
			}
		}
		myfile<<"Case #"<<i+1<<": "<<p[0]+trocas<<endl;
	}
	myfile.close();
	return 0;
}
