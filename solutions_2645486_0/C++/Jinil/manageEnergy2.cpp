#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef long long LL;

vector<LL> getNums(string &line){
    vector<LL> list;
    LL num = 0;
    for(int i=0; i<line.size(); i++){
	if(line[i] == ' '){
	    list.push_back(num);
	    num = 0;
	}else{
	    num = num*10 + (line[i]-'0');
	}
    }
    list.push_back(num);
    return list;
}

vector<int> getActivities(string &line){
    vector<int> activities;
    int num = 0;
    for(int i=0; i<line.size(); i++){
	if(line[i] == ' '){
	    activities.push_back(num);
	    num = 0;
	}else{
	    num = num*10 + (line[i]-'0');
	}
    }
    activities.push_back(num);
    return activities;
}

void compute(LL maxE, LL curE, LL R, LL N, vector<int> &acts, 
	     int index, LL curAns, LL &ans){

    if(index == acts.size()){
	if(curAns > ans)
	    ans = curAns;
	return;
    }

    for(LL a = 0; a <= curE; a++){
	LL gain = curAns + acts[index] * a;
	LL nextE = (curE - a + R > maxE) ? maxE : curE - a + R;
	compute(maxE, nextE, R, N, acts, index+1, gain, ans);
    }
}

int main(int argc, char *argv[]){
    ifstream file(argv[1]);
    ofstream output_file(argv[2]);
    string line;
    getline(file, line);
    int T = atoi(line.c_str());
    for(int i=1; i<=T; i++){
	getline(file, line);
	vector<LL> list = getNums(line);
	LL E = list[0];
	LL R = list[1];
	LL N = list[2];

	getline(file, line);
	vector<int> acts = getActivities(line);
	LL result = 0;
	compute(E, E, R, N, acts, 0, 0, result);
	output_file << "Case #" << i << ": " << result << endl;
    }
    file.close();
    output_file.close();
    return 0;
}
