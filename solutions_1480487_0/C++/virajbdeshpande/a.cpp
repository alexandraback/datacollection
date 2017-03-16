#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

int ncases;
cin >> ncases;
for (int caseno = 0; caseno < ncases; caseno++){

	double N;
	cin >> N;
	double s[(int)N];
	double sum = 0;
	float minsc = 0;
	float maxsc = 0;
	int mindefined = 0;
	for (int Ni = 0; Ni < N; Ni++){
		cin >> s[Ni];
		sum += s[Ni];
		/*if (mindefined == 0){ 
			minsc = s[Ni];
			maxsc = s[Ni];
		} else {
			if (s[Ni] < minsc)
				minsc = s[Ni];
			if (s[Ni] > maxsc)
				maxsc = s[Ni];
		}
		
		if(Ni == 0) mindefined = 1;*/
		
	}
	float avg = sum/N;
	
	float newsum = 0;
	float newN = 0;
	for (int Ni = 0; Ni < N; Ni++){
		if (s[Ni] < 2 * avg){
			newsum += s[Ni];
			newN += 1;
		}
	}
	
	//cout << sum<< newsum<< N<< newN<<endl;
	
	cout << "Case #" << caseno +1 <<": ";
	for(int Ni = 0; Ni < N; Ni++){
		if (s[Ni] > 2 * avg) cout << 0;
		else printf("%.6f", 100.0 * ((sum + newsum)/newN - s[Ni])/sum);
		if(Ni < N - 1) cout << " ";
	}
	 cout << endl;
	
}



}
