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
	ifstream ifs("D-small-attempt1.in");
    ofstream ofs("answer_D_small");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	int X;
    ifs >> X; cout << "X= " << X << endl; 

    int R;
    ifs >> R; cout << "R= " << R << endl; 

    int C;
    ifs >> C; cout << "C= " << C << endl; 

	
	cout << "Case #" <<t+1<<": ";
    ofs << "Case #" <<t+1<<": ";

	if(X==1){cout << "GABRIEL"<<endl;}
	else if(X==2){ if((R*C)%2==0){cout << "GABRIEL"<<endl;}
	               else{cout <<"RICHARD"<<endl;}
	}else if(X==3){ if((R*C)%3 ==0 && R*C>=6){cout <<"GABRIEL"<<endl;}
	                 else{cout<< "RICHARD"<<endl;}
	}else if(X==4){  if((R==4 && C==4)||(R==4 && C==3)||(R==3 && C==4)){cout <<"GABRIEL" <<endl;}
	                  else{cout <<"RICHARD"<<endl;}
	}

if(X==1){ofs << "GABRIEL"<<endl;}
	else if(X==2){ if((R*C)%2==0){ofs << "GABRIEL"<<endl;}
	               else{ofs <<"RICHARD"<<endl;}
	}else if(X==3){ if((R*C)%3 ==0 && R*C>=6){ofs <<"GABRIEL"<<endl;}
	                 else{ofs<< "RICHARD"<<endl;}
	}else if(X==4){  if((R==4 && C==4)||(R==4 && C==3)||(R==3 && C==4)){ofs <<"GABRIEL" <<endl;}
	                  else{ofs <<"RICHARD"<<endl;}
	}

   } // end of test cases

 return 0;
}