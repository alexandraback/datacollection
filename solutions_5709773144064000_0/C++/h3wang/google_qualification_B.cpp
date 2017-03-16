#include <iostream>
#include <iomanip>
using namespace std;
#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("B.in");
ofstream fout("B.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
double tt,X,C,F;
int T;
bool check(int k){
	return X/(2+(double)k*F)<=C/(2+(double)k*F)+X/(2+(double)(k+1)*F);
}
int main(){
	redirect();
	cin>>T;
	for(int i=0;i<T;i++){
		cout<<"Case #"<<i+1<<": ";
		cin>>C>>F>>X;
		tt=0;
		for(int k=0;;k++){
			if(check(k)){
				tt+=X/(2+(double)k*F);
				break;
			}
			else{
				tt+=C/(2+(double)k*F);
			}
		}
		cout<<setprecision(7)<<fixed<<tt<<endl;
	}

	return 0;
}