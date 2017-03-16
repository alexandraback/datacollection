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

int main()
{
	ifstream ifs("A-large (5).in");
    ofstream ofs("answer_A_large");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	int S_max;
    ifs >> S_max; //cout << "S_max= " << S_max<< endl; 

	string str;
    ifs>>str; //cout <<str<<endl;

	vector<int> L;

	string str_num="0123456789";
	for(int i=0;i<=S_max;i++){
		for(int j=0;j<10;j++){
			if(str.substr(i,1)==str_num.substr(j,1)){ for(int k=0;k<j;k++){ L.push_back(i);}   }
		}
	}

/*	for(int i=0;i<int(L.size());i++){
        cout <<L[i]<<" " ;
	}
  cout <<endl;*/

    int C=0;
	int S=0;

	for(int i=0;i<int(L.size());i++){
		if(L[i]-S>0){C+= (L[i]-S); S+=1+(L[i]-S);}
		else{S+=1;}
		//cout <<"S= " <<S <<"  C= " <<C <<endl;
	}
	
	cout << "Case #" <<t+1<<": " << C <<endl;
    ofs << "Case #" <<t+1<<": "<< C  <<endl;

   } // end of test cases

 return 0;
}