#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

bool findthesequenceRec(vector<int>& typecount, vector<vector<int> >& chestarr, vector<int>& chesttype, vector<int>& result){
	bool finish = true;
	for(int i = 0; i < chesttype.size(); i ++){
		if(chesttype[i] != -1){
			finish = false;
			break;
		}
	}
	cout << endl;
	if(finish){
		return true;
	}
	for(int i = 0; i < chesttype.size(); i ++){
		if(chesttype[i] != -1 && typecount[chesttype[i] - 1] > 0){
			int temp = chesttype[i];
			chesttype[i] = -1;
			typecount[temp - 1] --;
			for(int j = 0; j < chestarr[i].size(); j ++){
				typecount[chestarr[i][j] - 1] ++;
			}
			result.push_back(i + 1);
			if(findthesequenceRec(typecount, chestarr, chesttype, result)){
				return true;
			}
			chesttype[i] = temp;
			typecount[chesttype[i] - 1] ++;
			for(int j = 0; j < chestarr[i].size(); j ++){
				typecount[chestarr[i][j] - 1] --;
			}
			result.pop_back();	
		}
	}
	return false;
}

int main(int argc, const char **argv){
	ifstream input;
	ofstream output;
	input.open(argv[1]);
	output.open(argv[2]);
	if(!input.is_open() || !output.is_open()){
		exit(0);	
	}
	int numcase;
	input >> numcase;
	for(int i = 0; i < numcase; i ++){
		int K, N;
		input >> K >> N;
		vector<int> typecount(200, 0);
		vector<int> row;
		vector<vector<int> > chestarr(N, row);
		vector<int> chesttype(N, 0);
		vector<int> chesttypecount(200, 0);
		for(int j = 0; j < K; j ++){
			int temp;
			input >> temp;
			typecount[temp - 1] ++;
		}
		for(int j = 0; j < N; j ++){
			input >> chesttype[j];
			chesttypecount[chesttype[j] - 1] ++;
			int num;
			input >> num;
			for(int k = 0; k < num; k ++){
				int itemp;
				input >> itemp;
				chestarr[j].push_back(itemp);
			}
		}
		output << "Case #" << i + 1 << ": ";
		bool keyshort = false;
		for(int j = 0; j < 200; j ++){
			if(typecount[j] < chesttypecount[j]){
				keyshort = true;
			}
		}
		vector<int> result;
		if(keyshort){
			output << "IMPOSSIBLE" << endl;
		}
		else if(findthesequenceRec(typecount, chestarr, chesttype, result)){
			for(int j = 0; j < result.size(); j ++){
				output << result[j] << " ";
			}
			output << endl;
		}
		else{
			output << "IMPOSSIBLE" << endl;		
		}
	}
	input.close();
	output.close();
	return 0;
}
