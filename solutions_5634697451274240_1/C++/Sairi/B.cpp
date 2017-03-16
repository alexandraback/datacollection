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

int C[102];

int main()
{
	ifstream ifs("B-large (6).in");
    ofstream ofs("answer_B_large");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	string str;
    ifs >> str; cout << str << endl; 

	int N;
	N=int(str.size());

	for(int i=0;i<N;i++){
		if(str.substr(i,1)=="+"){C[i]=1;}
		else{C[i]=-1;}
	}

	/*for(int i=0;i<N;i++){
	cout<<C[i];
	}
	cout<<endl;*/

	int ans=0;

	for(int i=N-1;i>=0;i--){
		if(C[i]==-1){ ans++;
		for(int j=i;j>=0;j--){
              C[j]=-C[j];
		  }
		}//if fin

	} // for fin

	cout << "Case #" <<t+1<<": " <<ans <<endl;
    ofs << "Case #" <<t+1<<": "<<ans  <<endl;

   } // end of test cases

 return 0;
}