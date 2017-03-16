#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

using namespace std;

string convertInt(long long number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

bool isPalindromes(string s){
	int i;
	for (i=0;i< ceil((double)s.size()/2);i++){
		if (s[i] != s[s.size()-1-i]){
			return false;
		}
	}
	return true;
}

int main(){
//	long  long A = pow((long double)10,14);
//	cout << A;
	int T;
	cin >> T;
	int i;
	long long j;
	for (i=1;i<=T;i++){
		long long A, B;
		cin >> A >> B;
		long long a = ceil(sqrt((long double)A)), b = floor(sqrt((long double)B));
		long long count = 0;
		string n;
		for (j=a;j<=b;j++){
			n = convertInt(j);
			//cout << n;
			if (isPalindromes(n) && isPalindromes(convertInt(j*j))){
				count++;
			}
		}
		cout <<"Case #"<<i<<": "<<count <<endl;
	}

	return 0;
}