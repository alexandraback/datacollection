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
	ifstream ifs("D-small-attempt0 (3).in");
    ofstream ofs("answer_D_small");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	int K;
    ifs >> K; cout << "K= " << K << endl; 

    int C;
    ifs >> C; cout << "C= " << C << endl; 

    int S;
    ifs >> S; cout << "S= " << S << endl; 

	cout << "Case #" <<t+1<<": " ;
    ofs << "Case #" <<t+1<<": " ;


	if(S*C<=K-1){cout<<"IMPOSSIBLE"<<endl;
	             ofs<<"IMPOSSIBLE"<<endl;
	             continue;}

	vector<int> V;

	for(int i=1;i<=K;i++){
      V.push_back(i);
	}

	while(int(V.size())%C !=0){
      V.push_back(K);  //ƒxƒNƒgƒ‹‚Ì”‚ðC‚Ì”{”‚Æ‚·‚é
	}

	/*for(int i=0;i<int(V.size());i++){
       cout<<" " << V[i];
	}
	cout<<endl;*/

	vector<long long> ans;

	long long Pos=1;
	for(int j=1;j<=int(V.size())/C;j++){
         Pos=V[(j-1)*C];
		 for(int k=1;k<=C-1;k++){
			 Pos=(Pos-1)*K+V[(j-1)*C+k];
		 }
       ans.push_back(Pos);
	} //for fin

	for(int n=0;n<int(ans.size());n++){
         cout<<" " << ans[n];
		 ofs <<" " << ans[n];
	}
	cout<<endl; ofs<<endl;

   } // end of test cases

 return 0;
}