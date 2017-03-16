// Jai Mata Di
#include <iostream>
#include <sstream>
using namespace std;
long long gcd(long long a, long long b) { if (b==0) return a; return gcd(b, a % b); }
bool isqPowerOf2(long long q){
//	cout<<"q="<<q<<endl;
	if(q == 1 || q == 0)
		return true;
	if(q%2 == 0)
		return isqPowerOf2(q/2);
	else
		return false;
}
void getReducedForm(long long* p,long long* q){
	long long g = gcd(*p,*q);
	*p = (long long)(*p/g);
	*q = (long long)(*q/g);
}
class ElfSolver{
public:
	long long p,q;
	void input(){
		string ip;
		cin>>ip;
		size_t found = ip.find("/");
		//cout<<"found at"<<found<<endl;
		//cout<<"first ="<<ip.substr(0,found);
		string first = ip.substr(0,found);
		//cout<<"second ="<<ip.substr(found+1);
		string second = ip.substr(found+1);

		istringstream convertFirst(first);
		if ( !(convertFirst >> p) )
		    p = 0;

		istringstream convertSecond(second);
		if ( !(convertSecond >> q) )
		    q = 0;
		//cout<<p<<q<<endl;
	}
	void printAnswer(long long p,long long q){
		long long l = -100;
		if(p > q){
			l = -1;
		}
		else{
			l = getAns(p,q);
		}
		if(l == -1)
			cout<<"impossible"<<endl;
		else
			cout<<l<<endl;
	}
	long long getAns(long long p,long long q){
			getReducedForm(&p,&q);
			if(isqPowerOf2(q) == false){
				return -1;
			}
			else
			{
				getNoOfLevels(p,q);
			}
	}
	long long getNoOfLevels(long long p,long long q){
		long long halfq= q/2;
		if(p-halfq >=0){
			return 1;
		}
		else{
			return 1+getNoOfLevels(p,halfq);
		}
	}
};
int main() {
	int noOfTestCases;
	cin>>noOfTestCases;
	for(int testCaseNo = 1;testCaseNo <= noOfTestCases;testCaseNo++){
	ElfSolver e;
	e.input();
/*	if(isqPowerOf2(e.q)){
		cout<<"YES SSSSS"<<endl;
	}else{
		cout<<"NOOOO "<<endl;
	}
cout<<"ANS=";*/
	cout<<"Case #"<<testCaseNo<<": ";
	e.printAnswer(e.p,e.q);
	}
	return 0;
}

