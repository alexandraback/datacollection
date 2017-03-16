#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("D.in");
ofstream fout("D.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}

int T,N;
double tmp;
vector<double> v[2],o[2];
void removeken(int k){
	swap(v[1][k],v[1][v[1].size()-1]);
	v[1].pop_back();
	sort(v[1].begin(),v[1].end(),greater<double>());
}
int main(){
	redirect();
	cin>>T;
	for(int k=0;k<T;k++){
		cout<<"Case #"<<k+1<<": ";
		o[0].clear();
		o[1].clear();
		cin>>N;
		for(int i=0;i<2;i++){
			for(int j=0;j<N;j++){
				cin>>tmp;
				o[i].push_back(tmp);
			}
			sort(o[i].begin(),o[i].end(),greater<double>());
		}
		v[0]=o[0];
		v[1]=o[1];
		int index,nami=0;
		while(v[1].size()){
			bool larger=true;
			for(int i=0;i<v[0].size();i++){
				if(v[0][i]<v[1][i]){
					larger=false;
					break;
			    }
			}
			if(larger){
				nami=v[0].size();
				break;
			}
			index=-1;
			double smallest=v[0][v[0].size()-1];
			for(int i=0;i<v[1].size();i++){
				if(v[1][i]>smallest){
					index=i;
					break;
		        }
			}
			if(index!=-1){
				removeken(index);
				v[0].pop_back();
			}
		}
		cout<<nami<<" ";
		v[0]=o[0];
		v[1]=o[1];
		nami=0;
		for(int i=v[0].size()-1;i>=0;i--){
			index=-1;
			for(int j=v[1].size()-1;j>=0;j--){
				if(v[1][j]>v[0][i]){
					index=j;
					break;
				}
			}
			if(index!=-1)
			 removeken(index);
			else
			  break;
		}
		nami+=v[1].size();
		cout<<nami<<endl;
	}
	return 0;
}