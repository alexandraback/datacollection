/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MIN(a,b) ((a)<(b)?(a):(b))

int A[505];
map<int,int> V;
map<int,vector<int> > M;

bool mark(int a,int p){
	map<int,vector<int> >::iterator it;
	do{
		it = M.find(a);
		bool ok=false;
		for (int i=0; i<int((it->second).SL); i++) {
			if( V[(it->second)[i]] == 0 ){
				V[(it->second)[i]] = p;
				a-=(it->second)[i];
				ok=true;
				break;
			}
		}
		if(!ok) return false;
	}while(a>0);
	return true;
}

int main(){
	int T,N;
	cin>>T;
	for (int kases=1; kases<=T; kases++) {
		cin>>N;
		M.clear();
		V.clear();
		for (int i=0;i<N;i++) {
			cin>>A[i];
			V[A[i]] = 0;
			map<int,vector<int> > m;
			map<int,vector<int> >::iterator it;
			for(it = M.begin();it != M.end(); it++){
				m[it->first + A[i]].PB(A[i]);
			}
			m[A[i]].PB(A[i]);
			for (it = m.begin(); it!= m.end(); it++) {
				vector<int> vv = (it->second);
				map<int,vector<int> >::iterator it2 = M.find(it->first);
				if( it2 != M.end() ){
					for (int j=0; j<int(vv.SL); j++) {
						(it2->second).PB(vv[j]);
					}
				}
				else{
					M[it->first] = vector<int>();
					it2 = M.find(it->first);
					for (int j=0; j<int(vv.SL); j++) {
						(it2->second).PB(vv[j]);
					}
				}
			}
		}
		/*for (map<int,vector<int> >::iterator it = M.begin(); it != M.end(); it++) {
			cout<<it->first<<endl;
		}*/
		bool ok=false;
		for (map<int,vector<int> >::iterator it = M.begin() ; it != M.end(); it++) {
			for(map<int,int>::iterator it2 = V.begin(); it2 != V.end(); it2++) it2->second = 0;
			mark(it->first,1);
			if(mark(it->first,2)){
				ok=true; break;
			}
		}
		cout<<"Case #"<<kases<<":";
		if(!ok) cout<<" Impossible"<<endl;
		else{
			cout<<endl;
			bool first_space = true;
			for(map<int,int>::iterator it2 = V.begin();it2 != V.end() ; it2++){
				if((it2->second) == 1) {
					if(first_space){ cout<<it2->first; first_space = false;}
					else{cout<<" "<<it2->first;}
				}
			}cout<<endl;
			first_space = true;
			for(map<int,int>::iterator it2 = V.begin();it2 != V.end() ; it2++){
				if((it2->second) == 2){
					if(first_space){ cout<<it2->first; first_space = false;}
					else{cout<<" "<<it2->first;}
				}
			}cout<<endl;
		}
	}
}