#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//istream& fin = cin;
//ifstream fin ("C-sample.txt");
ifstream fin ("C-small-attempt0.in");
ofstream fout ("C-small-attempt0.out");
//ifstream fin ("C-large.in");
//ofstream fout ("C-large.out");
//ostream& fout = cout;

int d[20];
vector<int> v1,v2;

bool DFS(int i, int opt, int sum1, int sum2){
	if(i>=20){
		return false;
	}
	if(opt==1){
		sum1+=d[i];
	}else if(opt==2){
		sum2+=d[i];
	}
	if(sum1>0 && sum1==sum2){
    if(opt==1){
			cout << d[i] << endl;
			v1.push_back(d[i]);
		}else if(opt==2){
			v2.push_back(d[i]);
		}
		return true;
	}
	if(DFS(i+1,1,sum1,sum2)||DFS(i+1,2,sum1,sum2)||DFS(i+1,0,sum1,sum2)){
		if(opt==1){
			v1.push_back(d[i]);
		}else if(opt==2){
			v2.push_back(d[i]);
		}
		return true;
	}
	return false;
}

int main(){
	int t,n;
	fin >> t;
	for(int i=1; i<=t; i++){
    fout << "Case #" << i << ":" << endl;
		fin >> n;
		
		for(int j=0; j<n; j++){
			fin >> d[j];
		}
		if(DFS(0,1,0,0)||DFS(0,2,0,0)||DFS(0,0,0,0)){
			for(int k=0; k<v1.size(); k++){
				if(k>0){
					fout << ' ';
				}
				fout << v1[k];
			}
			v1.clear();
			fout << endl;
			for(int k=0; k<v2.size(); k++){
				if(k>0){
					fout << ' ';
				}
				fout << v2[k];
			}
			fout << endl;
			v2.clear();
		}
		
	}
	system("pause");
}
