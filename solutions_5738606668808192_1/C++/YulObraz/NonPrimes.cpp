//============================================================================
// Name        : NonPrimes.cpp
// Author      : Yul Obraz
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<long long int> primes_calc(int maxValue){
	vector<long long int> primes;
	for(int i = 2; i<maxValue; i++){
		bool checked =false;
		for (std::vector<long long int>::iterator it = primes.begin(), end = primes.end(); it != end; ++it){
			if((i%(it[0]))==0){
				checked = true;
				break;
			}
		}
		if(!checked){
			primes.push_back(i);
		}
	}
	//int*arr = new int[primes.size()];
	//std::copy(primes.begin(), primes.end(), arr);
	//return arr;
	return primes;
}
long long int pow(int value, int size)
{
	long long int v=1;
	for(int i=0;i<size-1;i++){
		v*=(long long int )value;
	}
	return v;
}
long long int calc_left_special(int value, int size, long long int check){
	int vv = size>20? 19: 5;
	long long int firstPart = pow(value, vv);
	long long int left = firstPart % check;
	long long int dd= (left *pow(value, size -vv+1)+1) %check;
	return dd;
}
long long int getValue(int* positions, int scale, int length){
	long long int result=0;
	long long int step =1;
	/*cerr<<" GGG* ";
	for(int p=length+1; p>=0; p--)
			cerr<< positions[p];
	cerr<<" GGG" ;*/
	for(int i=0;i<length; i++){
		if(positions[i]==1){
			result +=(long long int)step;
		}
		//cerr<< step
		step *= (long  int)scale;
	}
	//cerr<<" result "<<scale<<" "<<length<<" "<<result<<endl;
	return result;
}
void calc(int length, int results, int primesMax){
	long long int* starts=new long long int[9];
	for(int i=0;i<9;i++){
		starts[i] = pow(i+2, length) +1;
		cerr<< starts[i] <<" starts "<<i+2<<" "<< length <<endl;
	}
	vector<long long int> primes= primes_calc(primesMax);
	int primesCount = (int)primes.size();
	//int left[9][] = new int [primesCount][9]{0};
	long long int** left = new long long int*[9];
	for(int i = 0; i < 9; ++i)
	    left[i] = new long long int[primesCount];

	for(int i=0;i<9;i++){
		//if(length > 20 && i>6){
			for(int j=0;j<primesCount; j++){
				left[i][j] = calc_left_special(i+2, length, primes[j]);
						cerr<< "left"<<i<<","<<j<<"="<<left[i][j]<< " ["<< (starts[i]%primes[j])<<"] "<<starts[i]<<" "<<primes[j] <<endl;
			}
		/*}else{
		for(int j=0;j<primesCount; j++){
			left[i][j] = (starts[i]%primes[j]);
			//cerr<< "left"<<i<<","<<j<<"="<<left[i][j]<<" "<<starts[i]<<" "<<primes[j] <<endl;
		}
		}*/
	}
	int * positions = new int[length];
	for(int i=0; i<length; i++){
		positions[i]=0;
	}
	long int* dividers=new long int[9];
	positions[0]=0;
	positions[length-1]=0;
	int maxpositions=1;
	int availableResults =0;
	int c;
	for(int n=0; n<results*results; n++){
		for(int i=0; i<9; i++){
			dividers[i]=0;
		}
		for(int i=0;i<9;i++){
			long long int value=getValue(positions, i+2, length);
			//cerr <<n<<" zz "<< value<<endl;
			dividers[i]=0;
			for(int j= 0; j< primesCount; j++){
				if(((value +left[i][j])% primes[j])==0){
					dividers[i]=primes[j];
					//cerr<< "found "<< n <<" "<< value <<"+"<<left[i][j]<<" i" <<i<<"j"<<j <<" %"<< primes[j]<<endl;
					break;
				}
			}
			if(dividers[i]==0){
				break;
			}
			if(i==8){//found
				cout<<"1";
				for(int p=length-2; p>0; p--)
						cout<< positions[p];
				cout <<"1";
				for(int p=0; p<9; p++)
						cout<<" " <<dividers[p];
				cout<<endl;
				availableResults++;
				if(availableResults>=results){
					return;
				}
			}
		}
		c=0;
		do{
			c++;
			if(positions[c]==0){
				positions[c]=1;
				if(c>= maxpositions){
					maxpositions = c;
				}
				cerr<<" pos"<<c<<endl;
			}else{
				positions[c]=0;
				cerr<<" pos"<<c<<0;
			}
		}while(positions[c]==0);
	}
	cerr<< "Not enough "<<availableResults;
}

int main(int argc,char *argv[]) {
	freopen(argv[1],"r",stdin);
	freopen(argv[2],"w",stdout);
	int tests;
	cin >> tests;
	for(int i=0; i<tests; i++){
		int Nlength, Jresults;
		cin>>Nlength>> Jresults;
		cout << "Case #"<< (i+1)<<":"<<endl;
		calc(Nlength, Jresults, 10000);
	}
	return 0;
}
