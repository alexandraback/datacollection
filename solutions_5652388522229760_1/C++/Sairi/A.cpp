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

using namespace std;

int C[10];

long long M;

void CHECK(long long M){
	while(M>0){
		if(C[M%10]==0){C[M%10]=1;}
		M=M/10;
	}
}

int IsFIN(void){

    int ret=1;
	for(int i=0;i<=9;i++){
       ret*=C[i];
	}
	return ret;
}

int main()
{
	ifstream ifs("A-large (7).in");
    ofstream ofs("answer_A_large");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	long long N;
    ifs >> N; cout << "N= " << N << endl; 

	for(int i=0;i<=9;i++){C[i]=0;}

	cout << "Case #" <<t+1<<": ";
    ofs << "Case #" <<t+1<<": "; 

	if(N==0){cout<<"INSOMNIA"<<endl;
	         ofs<<"INSOMNIA"<<endl;
	        }
	else{
		for(int i=1;;i++){
         M=i*N;
            CHECK(M);
			if(IsFIN()==1){break;}
		}
cout<<M<<endl;
		   ofs<<M<<endl;
	}//else fin
          
   } // end of test cases

 return 0;
}