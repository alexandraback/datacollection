#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string input[16][2];
int check[16];
int n;

int mmax = -1;

void cal(int num){
	if(num == n){
		int res = 0;
		for(int i=0;i<n;i++){
			if(check[i] == 1)
				continue;
			res++;
			int a,b;
			int a_c,b_c;
			a_c = b_c = 0;

			for(int j=0;j<2*n;j++){
				if(check[j/2] == 0)
					continue;
				if(input[i][0].compare(input[j/2][j%2]) == 0){
					a=j/2;
					a_c++;					
				}
			}
			for(int j=0;j<2*n;j++){
				if(check[j/2] == 0)
					continue;
				if(input[i][1].compare(input[j/2][j%2]) == 0){
					b=j/2;
					b_c++;					
				}
			}
			if(a_c * b_c == 0)
				return;
			if(b_c == 1 && a_c == 1 && a == b)
				return;
		}
		if(res > mmax)
			mmax = res;
		return;
	}
	if(check[num] == 1)
		cal(num+1);
	else{
		check[num] = 1;
		cal(num+1);
		check[num] = 0;
		cal(num+1);
	}
}

int main()
{
	int t,T;
	//ifstream fin("input.txt");
	ifstream fin("C-small-attempt1.in");
	ofstream fout("output.txt");
	
	fin>>T;

	for(t=0;t<T;t++){
		fin>>n;
		for(int i=0;i<n;i++){
			fin>> input[i][0] >> input[i][1];
		}
		mmax = -1;
		cal(0);

		fout<<"Case #"<<t+1<<": "<<mmax<<endl;
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);