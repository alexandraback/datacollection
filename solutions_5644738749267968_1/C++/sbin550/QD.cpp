#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char ** argv){
    int numberOfTest;
    int numberOfBlocks;

    vector <double> naomi;
    vector <double> ken;

    vector <double> naomi2;
    vector <double> ken2;

    double dTemp;

    int dWar;
    int war;

    int count, count2, count3;

    ifstream inFile;
    ofstream outFile;

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    inFile >> numberOfTest;

    outFile.setf(ios::fixed, ios::floatfield);

    for(int count = 0 ; numberOfTest > count ; count++){
	inFile >> numberOfBlocks;

	naomi.clear();
	ken.clear();

	for(count2  = 0 ; numberOfBlocks > count2 ; count2++){
	    inFile >> dTemp;
	    naomi.push_back(dTemp);
	}

	for(count2  = 0 ; numberOfBlocks > count2 ; count2++){
	    inFile >> dTemp;
	    ken.push_back(dTemp);
	}

	sort(naomi.begin(), naomi.end());
	sort(ken.begin(), ken.end());

	dWar = 0;

	naomi2	= naomi;
	ken2	= ken;

	while(naomi2.size() > dWar){
	    if(naomi2[dWar] < ken2[dWar]){
		naomi2.erase(naomi2.begin());
		ken2.erase(ken2.end()-1);
		dWar = 0;
	    }else{
		dWar++;
	    }
	}
	/*
	while((naomi.size() > dWar) && (ken[0] > naomi[dWar])){
	    dWar++;
	}
	dWar	= naomi.size() - dWar;
	*/

	count3	= naomi.size()-1;
	for(count2 = ken.size()-1; (0 <= count2) && (0<= count3) ; count2--){
	    while(0 <= count3){
		if(ken[count2] < naomi[count3]){
		    count3--;
		}else{
		    break;
		}
	    }
	    if(0 <= count3){
		naomi.erase(naomi.begin() + count3);
		count3--;
	    }
	}
	war = naomi.size();


	outFile << "Case #" << count+1 << ": ";
	outFile << dWar << " " << war << endl;

    }

    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}



