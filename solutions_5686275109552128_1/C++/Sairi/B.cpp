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

int ROU(int L, int K)
{
     double dL,dK;
	 dL=double(L);
	 dK=double(K);
	 
	 double R;
	 R=dL/dK;

	 if(double(R-int(R))>0.0){return int(R)+1;}
	 else{return int(R);}
}

int main()
{
	ifstream ifs("B-large (4).in");
    ofstream ofs("answer_B_large");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	int D;
    ifs >> D; cout << "D= " << D << endl;

	vector<int> P;

	int tmp;

	for(int i=0;i<D;i++){
       ifs >> tmp; P.push_back(tmp);
	}

/*	for(int i=0;i<int(P.size());i++){
   cout <<P[i] <<" " ;
	}
	cout <<endl;*/


    int N_max=0;

	for(int i=0;i<D;i++){
		if(P[i]>N_max){N_max=P[i];}
	}
//	cout<<"N_max= " <<N_max<<endl;

	int TIME=0;
	int MIN_TIME=9999;

	for(int N=1;N<=N_max;N++){

	vector<int> M; vector<int> Q;

		M.clear(); Q.clear();

		for(int i=0;i<D;i++){
            M.push_back(ROU(P[i],N)-1);      
			Q.push_back(ROU(P[i], M[i]+1));
			//cout<<"i= " <<i << "  M= " <<M[i] <<" Q= " <<Q[i]<<endl;
		}
        int sum_M=0.0;

		for(int i=0;i<D;i++){
           sum_M+=M[i];
		}

		int Q_max=0;
		for(int i=0;i<D;i++){
			if(Q[i]>Q_max){Q_max=Q[i];}
		}

       TIME=sum_M+Q_max; 
	   if(MIN_TIME>TIME){MIN_TIME=TIME;}
	}//N-loop fin



	cout << "Case #" <<t+1<<": " << MIN_TIME<<endl;
    ofs << "Case #" <<t+1<<": " << MIN_TIME <<endl;

   } // end of test cases

 return 0;
}