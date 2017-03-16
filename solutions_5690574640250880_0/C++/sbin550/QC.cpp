#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char ** argv){

    int count;
    int count2;

    int numberOfTest;

    int cR, cC, rM;
    int C, R, M;

    bool flag;

    vector <string> answer;
    string temp;

    ifstream inFile;
    ofstream outFile;

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    inFile >> numberOfTest;

    for(count = 0 ; numberOfTest > count ; count++){
	inFile >> R;
	inFile >> C;
	inFile >> M;

	outFile << "Case #" << count+1 << ":" << endl;

	answer.clear();
	answer.resize(R);

	temp.clear();
	temp.resize(C);
	for(count2 = 0 ; C > count2;  count2++){
	    temp[count2]    = '.';
	}

	for(count2 = 0 ; R > count2;  count2++){
	    answer[count2]  = temp;
	}
	answer[0][0]= 'c';

	rM  = M;
	cR  = R-1;
	cC  = C-1;

	while(0 < rM){
	    if(cR < cC){
		for(count2 = cR ; (0 <= count2) && (0 < rM) ; count2--, rM--){
		    answer[count2][cC]	= '*';
		}
		if((0 == rM) && (0 == count2)){
		    answer[1][cC]	= '.';
		    answer[cR][cC-1]  = '*';
		}
		cC--;
	    }else{
		for(count2 = cC ; (0 <= count2) && (0 < rM) ; count2--, rM--){
		    answer[cR][count2]	= '*';
		}
		if((0 == rM) && (0 == count2)){
		    answer[cR][1]	= '.';
		    answer[cR-1][cC]  = '*';
		}
		cR--;
	    }
	}

	if((1 != R) && (1 != C)){
	    cR  = R-1;
	    cC  = C-1;
	    flag    = false;

	    for(count2 = 1 ; R > count2 ; count2++){
		if((answer[count2][0]) != (answer[count2][1])){
		    flag = true;
		    break;
		}
	    }
	    if(flag){
		outFile << "Impossible" << endl;
		continue;
	    }
	    for(count2 = 1 ; C > count2 ; count2++){
		if((answer[0][count2]) != (answer[1][count2])){
		    flag = true;
		    break;
		}
	    }
	    if(flag){
		outFile << "Impossible" << endl;
		continue;
	    }
	}

	for(count2 = 0 ; R > count2 ; count2++){
	    outFile << answer[count2] << endl;
	}
    }

    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}



