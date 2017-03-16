#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


int main(int argc, char* argv[]){
	int T,nocase;
	int N;

	int i,j,d,num;
	int seen[10];

	cin >> T;  // read t. cin knows that t is an int, so it reads it as such.
	for (nocase = 1; nocase <= T; ++nocase) {
		cin >> N;  // read n and then m.
		
		if(N==0) {
			cout << "Case #" << nocase << ": INSOMNIA" << endl;
		}
		else {
			for(i=0;i<10;i++) seen[i]=0;
			i = 0;
			num = 0;
			while(num!=10){
				i = i + N;
				j = i;
				while(j){
					d = j%10;
					if(seen[d]==0){
						seen[d] = 1;
						num++;
					}
					j = j/10;
				}
			}
			cout << "Case #" << nocase << ": " << i<< endl;
		}
	}

	return 0;
}