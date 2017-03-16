#include <iostream>
#include <fstream>

#define LIM_N 1001

using namespace std;

double nweights[LIM_N];
double kweights[LIM_N];

double nweights2[LIM_N];
double kweights2[LIM_N];


// Using insertion sort. :/
void insert(double val, double arr[], int len) {
	int i = len;
	double temp;
	arr[len] = val;
	while(i > 0 && arr[i - 1] > arr[i]) {
		temp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = temp;
		i--;
	}
}


// Waste some time to delete. (N < 10)
void remove(int index, double arr[], int len) {
	for(int i = index; i < len - 1; i++) arr[i] = arr[i + 1];
}

void printArr(double arr[], int len) {
	for(int i = 0; i < len; cout << arr[i++] << " ");
	cout << endl;
}

int getCeilIndex(double val, double sortedArr[], int len) {
	if(sortedArr[len - 1] <= val) return len - 1;
	for(int i = len - 2; i >= 0; i--) 
		if(sortedArr[i] < val) return i + 1;
	
	return 0;
}

class Ken {
	int getBestChoice(double nChoice) {
		int ceil = getCeilIndex(nChoice, weights, length);
		if(weights[ceil] < nChoice) return 0;
		return ceil;
	}
	
public:
	double *weights;
	int length;

	Ken(double *weights, int length): weights(weights), length(length) {
	}
	
	int play(double nChoice) {
		return getBestChoice(nChoice);
	}
};

class Naomi {
	double *weights;
	int length;
	Ken *ken;
	
public:
	Naomi(double *weights, int length, Ken *ken): weights(weights), length(length), ken(ken) {
	}
	
	bool playWar() {
		int kChoice = ken->play(weights[0]);
		bool result = ken->weights[kChoice] < weights[0];
	
		remove(0, weights, length);
		remove(kChoice, ken->weights, ken->length);
		length--; ken->length--;
		
		return result;
	}

	int getWarScore() {
		int score = 0;
		while(length) if (playWar()) score++;
		return score;
	}
	
	int getDWarScore() {
		int winnables = 0;
		for(int last = length - 1; last >= 0 && weights[last] > ken->weights[last]; last--) winnables++;
		while(winnables < length) {
			// Lose a point
			remove(0, weights, length);
			remove(ken->length - 1, ken->weights, ken->length);
			length--; ken->length--;
			
			winnables = 0;	
			for(int last = length - 1; last >= 0 && weights[last] > ken->weights[last]; last--) winnables++;
		}
		
		return winnables;
	}
	
	void printWeights() {
		cout << "Naomi: ";
		printArr(weights, length);
		cout << "Ken: ";
		printArr(ken->weights, ken->length);
	}
};


int main() {
	ifstream cin;
	ofstream cout;
	cin.open("D-large.in");
	cout.open("D-large.out");

	int testCases, n;
	cin >> testCases;
	for(int tcase = 1; tcase <= testCases; tcase++) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> nweights[i];
			insert(nweights[i], nweights, i);
		}
		for(int i = 0; i < n; i++) {
			cin >> kweights[i];
			insert(kweights[i], kweights, i);
		}
		
		for(int i = 0; i < n; i++) {
			nweights2[i] = nweights[i];
			kweights2[i] = kweights[i];
		}

		Ken ken(kweights, n), kenD(kweights2, n);
		Naomi naomi(nweights, n, &ken), naomiD(nweights2, n, &kenD);
		
		cout << "Case #" << tcase << ": ";
//		naomiD.printWeights();
			cout << naomiD.getDWarScore() <<  " ";
			cout << naomi.getWarScore();
		cout << endl;

	}
	
	cin.close();
	cout.close();
	return 0;
}