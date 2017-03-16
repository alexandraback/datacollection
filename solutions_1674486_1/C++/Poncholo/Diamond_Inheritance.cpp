#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct clase{
	int ID;
	vector<int>fathers,sons;
};
int main(){

	ifstream in;
	ofstream out;
	in.open("Diamond_Inheritance_in.txt");
	out.open("Diamond_Inheritance_out.txt");
	int T;
	string _T;
	getline(in,_T);
	sscanf(_T.c_str(),"%d",&T);
	for(int caso=1;caso<=T;++caso){
		int N;
		string _N;
		getline(in,_N);
		sscanf(_N.c_str(),"%d",&N);
		vector<clase>obj(N);
		string y;
		for(int i=0;i<N;++i){
			string line;
			getline(in,line);
			int number=0;
			vector<int>resp;
			for(int j=0;j<(int)line.size();++j){
				if(line[j]==' '){
					resp.push_back(number);
					number=0;
				}
				else{
					number=10*number+line[j]-'0';
				}
			}
			resp.push_back(number);
			int node=i;
			for(int j=1;j<resp.size();++j){
				obj[node].fathers.push_back(resp[j]-1);
				obj[resp[j]-1].sons.push_back(node);
			}
		}
		bool OK=false;
		for(int i=0;i<N;++i){
			int visited[2000];
			memset(visited,0,2000*4);
			visited[i]++;
			vector<int>nodo;
			nodo.push_back(i);
			while(nodo.size()>0){
				vector<int>temp;
				for(int j=0;j<nodo.size();++j){
					int actual=nodo[j];
					for(int k=0;k<obj[actual].fathers.size();++k){
						int next=obj[actual].fathers[k];
						visited[next]++;
						if(visited[next]>1){
							OK=true;
							break;
						}
						temp.push_back(next);
					}
					if(OK==true)break;
				}
				if(OK==true)break;
				nodo=temp;
			}
		}
		y="No";
		if(OK==true)y="Yes";
		out<<"Case #"<<caso<<": "<<y<<endl;
	}
	in.close();
	out.close();
	return 0;
}