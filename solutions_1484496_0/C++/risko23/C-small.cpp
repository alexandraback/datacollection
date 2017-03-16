#include <sstream>
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

#define FOR(i,a) for (int (i)=0;(i)<(a);++(i))
#define FORR(i,a,b) for (int (i)=(a);(i)<(b);++(i))
#define sz(a) int((a).size()) 
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end() 


main(){
	ofstream fout ("C-small-attempt0.out");
	ifstream fin ("C-small-attempt0.in");
	int T;
	fin>>T;
	FOR(num,T){
		vector<int> a;
		int N;
		fin>>N;
		FOR(i,N){
			int tmp;
			fin>>tmp;
			a.push_back(tmp);
		}
		int out=0;
		vector< vector<int> > outset (2,vector<int>(0));
		vector<int> outputs(2000001,0);
		vector<int> first(2000001,0);
		bool ok=false;
		for(int i=0;i< (1<<N);i++){
			int sum=0;
			FOR(j,N){
				if ((i & 1 << j) != 0){
					sum+=a[j];
				}
			}
			outputs[sum]++;
			if (outputs[sum]==2){
				FOR(j,N){
					if ((i & 1 << j) != 0){
						outset[0].push_back(a[j]);
					}
				}
				FOR(j,N){
					if ((first[sum] & 1 << j) != 0){
						outset[1].push_back(a[j]);
					}
				}
				ok=true;
				break;
			}
			else first[sum]=i;
		}
		fout<<"Case #"<<num+1<<":"<<endl;
		if (ok==false) fout << "Impossible"<<endl; 
		else{
			FOR(i,2){
				FOR(j,outset[i].size()){
					fout<<outset[i][j];
					if(j!=outset[i].size()-1)
					fout<<" ";
					else fout<<endl;
				}
			}
		}
	}
	fout.close();
}
