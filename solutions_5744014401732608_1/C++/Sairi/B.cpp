#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

int B;
long long M;

int C[55][55];

long long L;

void PRINT(void);

ofstream ofs("answer_B_large");

int main()
{
	ifstream ifs("B-large (7).in");
    //ofstream ofs("answer");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	
    ifs >> B; cout << "B= " << B << endl; 

    ifs >> M; cout << "M= " << M << endl; 

	for(int i=1;i<=B;i++){
		for(int j=1;j<=B;j++){
             C[i][j]=0;
		}
	}

	for(int i=1;i<=B;i++){
		for(int j=i+1;j<B;j++){
           C[i][j]=1;
		}
	}

	/*for(int i=1;i<=B;i++){
		for(int j=1;j<=B;j++){
          cout<<" " <<C[i][j];
		}
		cout<<endl;
	}*/

	L=1;
	for(int i=1;i<=B-2;i++){
       L*=2;
	}

	cout<<"L= " <<L<<endl;


	cout << "Case #" <<t+1<<": ";
    ofs << "Case #" <<t+1<<": ";

	if(L<M){cout<<"IMPOSSIBLE"<<endl; ofs<<"IMPOSSIBLE"<<endl; }
	else if(L==M){  cout<<"POSSIBLE"<<endl;ofs<<"POSSIBLE"<<endl;
	for(int i=1;i<=B-1;i++){C[i][B]=1; }
	   PRINT();
	}else {
      cout<<"POSSIBLE"<<endl;ofs<<"POSSIBLE"<<endl;
	  C[1][B]=0;
	  long long  H=M;
	  for(int k=2;k<=B-1;k++){
        C[k][B]=H%2;
		H/=2;
	  }
		PRINT();
	}

   } // end of test cases

 return 0;
}

void PRINT(void)
{

	for(int i=1; i<=B;i++){
		for(int j=1;j<=B;j++){
        //cout<<C[i][j]; 
		ofs<<C[i][j];
		}
		//cout<<endl; 
		ofs<<endl;
	}
}