#include <iostream>
#include <fstream>
using namespace std;


bool findNextLevel(int *stars, int* level1, int* level2, int numOfLevels){
	int i=0;
	bool found=false;
	while((i<numOfLevels)&&(!found)){
		if ((level2[i]<=*stars)&&(level2[i]!=-1)){
			//solve this level
			if (level1[i]==-1) { *stars+=1; level2[i]=-1; }
			else { *stars+=2; level2[i]=level1[i]=-1;}
			found=true;
		}
		i++;
	}
	if (found) return true;
	i=0;
	found=false;
	int max=-1, pos=-1;
	while((i<numOfLevels)){
		if ((level1[i]<=*stars)&&(level1[i]!=-1)){
			
			if (level2[i]-level1[i]>max) { max=level2[i]-level1[i]; pos=i; }
			
		}
		i++;
	}
	if (max==-1) return false;

	*stars+=1; level1[pos]=-1;
	return true;
}


int main(int argc, char* argv[]){
	int numOfCases;
	int *level1, *level2;
	int numOfLevels, numOfStars;
	
	ofstream output;
	ifstream input;
	
	input.open(argv[1]);
	if (!input){
		cout << "Cannot open file "<<argv[1]<<endl;
		return -1;
	}
	cout << "File "<< argv[1] <<" opened for reading" <<endl;

	output.open(argv[2]);
	if (!output){
		cout << "Cannot open file "<<argv[2]<<endl;
		return -1;
	}
	cout << "File "<< argv[2] <<" opened for writing" <<endl;
	

	input>>numOfCases;


	int i=0;
	while(i<numOfCases){
		input>>numOfLevels;
		level1=new int[numOfLevels];
		level2 = new int[numOfLevels];
		int j=0;
		while(j<numOfLevels){
			input>>level1[j];
			input>>level2[j];
			j++;
		}
		numOfStars=0;
		output<<"Case #"<<i+1<<": ";

		bool end = false;
		int k=0;
		while(!end){
			k++;
			if (!findNextLevel(&numOfStars,level1, level2, numOfLevels)) { output<<"Too Bad"<<endl; end=true; }
			if (numOfStars == numOfLevels*2) { output<<k<<endl; end = true; }
		}
		i++;
		delete level1; delete level2;
	}



	cout<<"Work finished"<<endl;
	input.close();
	output.close();

	return 0;


}