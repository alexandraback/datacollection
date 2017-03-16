#include <iostream>

using namespace std;

int recovery, totalenergy;
int executeProgram();
int getGain(int,int);
int remainingEnergy(int,int);
int getTotalGain(int,int,int,int*);
int getBestGain(int,int,int*);
int* getGainChart(int,int*);

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Case #" << i+1 << ": " << executeProgram() << endl;
	}
}

int executeProgram(){
	int n;
	cin >> totalenergy >> recovery >> n;
	int values[n];
	for(int i = 0; i < n; i++){
		cin >> values[i];
	}
	
	//Generate lists
	int* previous = new int[totalenergy+1];
	int* current = new int[totalenergy+1];
	for(int i = 0; i <= totalenergy; i++){
		previous[i] = 0;
		current[i] = 0;
	}
	
	for(int i = n-1; i >= 0; i--){
		current = getGainChart(values[i], previous);
		delete [] previous;
		previous = current;
	}
	int best = current[totalenergy];
	delete [] current;
	return best;
}

int getGain(int value, int hours){
		return value*hours;
}

int remainingEnergy(int energy, int hours){
	int e = energy-hours+recovery;
	return (e > totalenergy ? totalenergy : e);
}

int getTotalGain(int value, int energy, int hours, int* previous){
	int gain = getGain(value, hours);
	int energyleft = remainingEnergy(energy,hours);
	return gain + previous[energyleft];
}

int getBestGain(int value, int energy, int* previous){
	int best = getTotalGain(value, energy, 0, previous);
	for(int i = 1; i <= energy; i++){
		int tmpgain = getTotalGain(value, energy, i, previous);
		if(tmpgain > best)
			best = tmpgain;
	}
	return best;
}

int* getGainChart(int value, int* previous){
	int* chart = new int[totalenergy+1];
	for(int i = 0; i <= totalenergy; i++){
		chart[i] = getBestGain(value, i, previous);
	}
	return chart;
}