#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

vector <unsigned long long> a,b;

int stoi(string str){
stringstream ss;
ss << str;
int i;
ss >> i ;
return i;
}

long stol(string str){
stringstream ss;
ss << str;
long i;
ss >> i ;
return i;
}

vector<long> v;

int main()
{
	ifstream ifs("B-small-attempt0 (3).in");
	string str;
	ifs >> str;
   int T=stoi(str);
   cout << "T= " << T <<endl;
   ofstream ofs("B-small-answer");

   for(int t=0;t<T;t++){  // test case
	   v.clear();
    ifs >> str; long E=stol(str);
	ifs >> str; long R=stol(str);
    ifs >> str; int N=stoi(str);

	cout << E << " " << R << " " <<N <<endl;

	for(int i=0; i < N ;i++){
      ifs >> str; long M=stol(str);
       v.push_back(M);
	   //cout << M << " ";
	}

	a.clear();
	b.clear();

	for(long i=0;i<=E;i++){
      a.push_back(0); b.push_back(0);
	}

	//cout << a[E] << endl;


	for(int n=0; n<N;n++){ // activities
		for(int j=0;j<=E;j++){ b[j]=0;}
		for(int j=R;j<=E;j++){ b[j]=a[j-R]; }
		for(int j=E-R ; j<=E; j++){if(b[E]<a[j])b[E]=a[j];}  

         for(int j=0;j<=E;j++){ a[j]=0;}

		 /******************/
		 for(int j=R; j<=E; j++){
			 for(int k=0; k<=j;k++){
				 if(a[j-k]<=b[j]+k*v[n]){a[j-k]=b[j]+k*v[n];}
			 }
		}
		 /******************/

		/* cout <<"a: " ;
		 for(int j=0;j <=E; j++){cout << a[j] << " " ;}
		 cout << endl;*/
		 
	} // end of activities loop

	unsigned long long max=0;
	for(int j=0;j<=E;j++){
		if(a[j]>=max){max=a[j];}
	}


	cout << "Case #" << t+1 << ": " << max <<endl;
    ofs << "Case #" << t+1 << ": " << max <<endl;
   } // end of test case

 return 0;
}