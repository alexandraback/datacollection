#include<iostream>
#include<fstream>
#include<string>

#include<sstream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
int links[10000];
int linksidx;
bool found;

bool findlinks(int map[1000][11], int classidx){
	
	int num = map[classidx][0];
	if(num==0) return false;
	for(int i=1;i<=num;i++){
		int target = map[classidx][i];
		for(int j=0;j<linksidx;j++){
			if(target == links[j]){
				found = true;
				return true;
			}
		}
		links[linksidx]=target;
		linksidx++;
		findlinks(map, target);
	}
	return false;
}

int main(){
	int testcase;
	ifstream infile;
	ofstream outfile;
	infile.open("A-large.in"); //filename//
	outfile.open("result.txt");
	
	infile>>testcase;

	for(int i=0;i<testcase;i++){
		//do something end
		found = false;
		int n;
		infile>>n;
		int cmap[1000][11]; //small
		for(int j=0;j<n;j++){
			infile>>cmap[j][0];
			for(int k=1;k<=cmap[j][0];k++){
				infile>>cmap[j][k];
				cmap[j][k]--;
			}
		}
		
		for(int j=0;j<n;j++){
			linksidx = 0;
				findlinks(cmap, j);
				if(found) break;
		}

		if(found)
			outfile<<"Case #"<<i+1<<": "<<"Yes"<<"\n";
		else
			outfile<<"Case #"<<i+1<<": "<<"No"<<"\n";

	}
	infile.close();
	outfile.close();
	return 0;
}