#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	ifstream myfile;
	ofstream out;
	myfile.open("input.txt");
	out.open("output.txt");
	int T;
	myfile >> T;
	//cout << T << endl;
	for(int i=0; i<T; i++){
		int N;
		myfile >> N;
		cout << "Case #" << i+1 << ": ";
		int*A = new int[N];
		int*B = new int[N];
		int*A1 = new int[N];
		int*B1 = new int[N];
		int stars = 0, g = 0;
		for(int j=0; j<N; j++){
			int a, b;
			myfile >> a >> b;
			A[j] = a;
			B[j] = b;
			A1[j] = 1;
			B1[j] = 1;
			if(b<=stars){
				stars+=2;
				cout << 'B' << j << ' ';
				g++;
				B1[j] = 0;
				A1[j] = 0;
			}
		}
		while(true){
			bool flag = true;
			while(flag){
				flag = false;
				for(int j=0; j<N; j++){
					if(B[j]<=stars && B1[j]){
						stars+=1 + A1[j];
						cout << 'B' << j << ' ';
						g++;
						B1[j] = 0;
						A1[j] = 0;
						flag=true;
					}
				}
			}
			if(stars==2*N){
				cout << g << endl;
				out << "Case #" << i+1 << ": " << g << endl;
				break;
			}
			flag = false;
			for(int z=100; z>0; z--){
				for(int j=0; j<N; j++){
					if(A[j]<=stars && A1[j] && B[j]>=z){
						stars+=1;
						cout << 'A' << j << ' ';
						g++;
						A1[j] = 0;
						flag = true;
						break;
					}
				}
				if(flag){
					break;
				}
			}
			if(!flag){
				cout << endl;
				out << "Case #" << i+1 << ": Too Bad" << endl;
				break;
			}
		}
		delete[]A;
		delete[]B;
		delete[]A1;
		delete[]B1;
	}
	return 0;
}