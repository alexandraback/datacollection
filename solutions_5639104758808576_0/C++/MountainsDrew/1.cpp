#include <fstream> 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
char c;
int n;
int invitati, inpiedi, aggiunti;


ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	fin>>N;
	for (int i=0; i<N; i++) {
		fin>>M;
		invitati=0;
		inpiedi=0;
		aggiunti=0;
		for (int j=0; j<=M; j++) {
			fin>>c;
			aggiunti =0;
			n= (int)c-48;
			//cout<<n;
			if (inpiedi<j){
				aggiunti = j-inpiedi;
				invitati+=aggiunti;
			}
			inpiedi+=n+aggiunti;
		}
		//cout<<"\n";
		fout<<"Case #"<<i+1<<": "<<invitati<<"\n";
	}
	return 0;
}
