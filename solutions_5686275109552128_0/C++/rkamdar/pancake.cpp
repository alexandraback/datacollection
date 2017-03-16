#include<iostream>

using namespace std;

int D;
int P[1000];
int Answer;
int Pmax;
int arr[1001];

int findnext(int max){
	int temp;
	if(max > 0)	temp = max-1;
	while(arr[temp] == 0){
		temp--;
	}	
	return temp;
}

int main(){
	int T;
	
	cin >> T;
	
	for(int test_case=0; test_case<T; test_case++){
		//init
		Pmax = 0;
		for(int i=0; i<1001; i++){
			arr[i] = 0;
		}
		arr[0] = 1001;
		
		//for input
		cin >> D;
		for(int i=0; i<D; i++){
			cin >> P[i];
			if(P[i] > Pmax)	Pmax = P[i];
			arr[P[i]]++;
		}
		
		Answer = 0;
		int temp=0;
		int upper = 1000;
		
		int count = 1;
		while(count < upper){
			temp = 0;
			for(int i=0; i<D; i++){
				temp = temp + ((P[i]-1)/count);
			}
			temp = temp+count;
			if(temp < upper)	upper = temp;
			count++;
		}
		
		Answer = upper;
		/*
		Answer = Pmax;
		
		//algo
		int nextAns;
		if(Pmax % 2 == 0){
			if(findnext(Pmax) > Pmax/2){
				nextAns = findnext(Pmax);
			} else {
				nextAns = Pmax/2;
			}
			nextAns = nextAns + arr[Pmax];
		} else {
			if(findnext(Pmax) > (Pmax/2)+1){
				nextAns = findnext(Pmax);
			} else {
				nextAns = (Pmax/2) + 1;
			}
			nextAns = nextAns + arr[Pmax];
		}
		
		int addit = 0;
		
		while((nextAns+addit) <= Answer){
			Answer = nextAns+addit;
			//cout << "Answer updated:" << Answer << endl;
			int temp = arr[Pmax];
			//cout << "temp updated:" << temp << endl;
			addit = addit + temp;
			arr[Pmax] = 0;
			if(Pmax % 2 == 0){
				arr[Pmax/2] = arr[Pmax/2] + (2*temp);
				if(findnext(Pmax) > Pmax/2){
					Pmax = findnext(Pmax);
				} else {
					Pmax = Pmax/2;
				}
				//cout << "something updated:" << arr[Pmax/2] << endl;
			} else {
				int val = Pmax/2;
				arr[val] = arr[val] + temp;
				arr[val+1] = arr[val+1] + temp;
				if(findnext(Pmax) > (Pmax/2)+1){
					Pmax = findnext(Pmax);
				} else {
					Pmax = (Pmax/2)+1;
				}
			}
			
			if(Pmax % 2 == 0){
				if(findnext(Pmax) > Pmax/2){
					nextAns = findnext(Pmax);
				} else {
					nextAns = Pmax/2;
				}
				//cout << "nextAns updated:" << nextAns << endl;
				nextAns = nextAns + arr[Pmax];
				//cout << "nextAns updated:" << nextAns << endl;
			} else {
				if(findnext(Pmax) > (Pmax/2)+1){
					nextAns = findnext(Pmax);
				} else {
					nextAns = (Pmax/2) + 1;
				}
				nextAns = nextAns + arr[Pmax];
			}
			//cout << "nextAns updated:" << nextAns << endl;
		}
		*/
		//for output
		cout << "Case #" << test_case+1 << ": " << Answer << endl;
	}
	
	return 0;
}
