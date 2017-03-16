#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	ifstream ifs("A-small-attempt0 (2).in");
    ofstream ofs("A-small-answer");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	long A; 
    ifs >> A;cout <<"A=" << A ;
	int N;
	ifs >>N;  cout <<" N=" << N<<endl;
	vector <long> size;
	for(int i=0;i<N;i++){
       long v;
	   ifs >> v;
	   size.push_back(v);  //cout <<v ;
	}
	sort(size.begin(),size.end());
	for(int i=0;i<N;i++){
     cout << size[i] << " " ;
	}

	long X=A;
   
	int M=size.size();
	long C1=0;
	vector <long> D;
	int I=0;
	while(M>0){ //cout <<"X= " << X <<endl;
		if(X>size[I]){X+=size[I++];M--;}
		else {
			 X += X-1; 
			 D.push_back(C1+M);
			 C1++;
		}
	
		if(C1>102){break;}
	} // while-loop

	long MIN=102;
	int N_D=D.size();
	for(int j=0; j<N_D;j++){
		if(MIN>D[j]){MIN=D[j];}
	}
	if(C1<MIN)MIN=C1;

	cout << "Case #" << t+1 << ": " << MIN<<endl;
    ofs << "Case #" << t+1 << ": " << MIN<<endl;


   } // end of test cases

 return 0;
}