#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std;

typedef long long LL;

void getNums(string &line, LL &r, LL &t){
    LL num = 0;
    for(int i=0; i<line.size(); i++){
	if(line[i] == ' '){
	    r = num;
	    num = 0;
	}else{
	    num = num*10 + (line[i]-'0');
	}
    }
    t = num;
}

LL compute(LL r, LL t){
    LL result = 0;
    LL paint;
    LL rad = 0;
    while( (paint = 2*r+2*rad+1) <= t){
	result++;
	t -= paint;
	rad += 2;
    }
    return result;
}

int main(int argc, char *argv[]){
    
    ifstream file(argv[1]);
    ofstream output_file("output");
    string line;
    getline(file, line);
    int T = atoi(line.c_str());
    for(int i=1; i<=T; i++){
	getline(file, line);
	LL r, t;
	getNums(line, r, t);
	LL result = compute(r, t);
	output_file << "Case #" << i << ": " << result << endl;
    }
    file.close();
    output_file.close();
    return 0;
}
