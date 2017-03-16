#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int length[2], types[2][100];
long long numbers[2][100];
map<long long, long long> best[100][100][2];

long long getBest(int i, int j, int k, long long left){
	if(i==length[0] || j==length[1])
		return 0;
	if(best[i][j][k].find(left)!=best[i][j][k].end())
		return best[i][j][k][left];
	if(types[0][i]!=types[1][j]){
		if(k==0)
			return max(getBest(i+1, j, 0, -1), getBest(i, j+1, 0, left));
		else
			return max(getBest(i+1, j, 1, left), getBest(i, j+1, 0, -1));
	}
	long long avail[2];
	avail[0]=numbers[0][i];
	avail[1]=numbers[1][j];
	if(left!=-1)
		avail[k]=left;
	if(avail[0]>avail[1])
		return getBest(i, j+1, 0, avail[0]-avail[1])+avail[1];
	else if(avail[0]<avail[1])
		return getBest(i+1, j, 1, avail[1]-avail[0])+avail[0];
	else
		return getBest(i+1, j+1, 0, -1)+avail[0];
}

int main(){
	int numCases;
	ifstream fin("g121cc.in");
	ofstream fout("g121cc.out");
	fin>>numCases;
	for(int caseNum=0; caseNum<numCases; caseNum++){
		fin>>length[0]>>length[1];
		for(int n=0; n<2; n++)
			for(int i=0; i<length[n]; i++){
				fin>>numbers[n][i]>>types[n][i];
				types[n][i]--;
			}
		for(int i=0; i<length[0]; i++)
			for(int j=0; j<length[1]; j++)
				for(int k=0; k<2; k++)
					best[i][j][k].clear();
		fout<<"Case #"<<caseNum+1<<": "<<getBest(0, 0, 0, -1)<<endl;
	}
	return 0;
}
