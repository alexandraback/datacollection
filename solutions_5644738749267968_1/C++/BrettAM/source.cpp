#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void readInput();
int deceit();
int war();
bool descendSort(float i, float j) { return i > j; }
//vars
ifstream inFile;
ofstream outFile;
float* naomi;
float* ken;
int numBlocks;

int main(int argc, char const *argv[]){
	if(argc != 2){
		cout<<"Error in Input"<<endl;
		return 0;
	}
	inFile.open(argv[1]);
	outFile.open("output.txt", ios::trunc | ios::out);
	if(!(inFile.is_open() && outFile.is_open()) ){
		cout << "can't open files"<<endl;
		return 0;
	}

	int N;
	inFile >> N;
	cout << "Running through " << N << " Iterations" << endl;

	for(int count=0; count<N; count++){
		readInput();

		sort(naomi,	naomi + numBlocks, descendSort);
		sort(ken,	ken + numBlocks,   descendSort);

		outFile << "Case #" << count+1 << ": ";
		outFile << deceit() << " ";
		outFile << war() << "\n";

		cout << ".";
		delete[] naomi;
		delete[] ken;
	}

	cout << "\n";
	inFile.close();
	outFile.close();
	return 0;
}

void readInput(){
	inFile >> numBlocks;
	naomi = new float[numBlocks];
	ken = new float[numBlocks];
	for (int i = 0; i < numBlocks; ++i) inFile >> naomi[i];
	for (int i = 0; i < numBlocks; ++i) inFile >> ken[i];
}

int deceit(){
	int nbot = numBlocks-1;
	int kbot = numBlocks-1;

	while(nbot>=0){
		if(naomi[nbot] > ken[kbot]){ //cheap win
			nbot--;
			kbot--;
		} else { //optimal loss
			nbot--;
		}
	}

	return numBlocks-kbot-1;
}

int war(){
	int nwin = 0, kwin = 0;
	for (int i = 0; i < numBlocks; ++i){
		if(naomi[i] > ken[kwin]) nwin++;
		else kwin++;
	}
	return nwin;
}
