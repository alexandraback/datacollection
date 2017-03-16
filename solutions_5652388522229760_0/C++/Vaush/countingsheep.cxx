#include <fstream>
#include <iostream>
using namespace std;
void check(bool A[10], long long int n){
	while(n > 0){
		A[n%10] = true;
		n /= 10;
	}
}
bool val(bool A[10]){
	bool res = true;
	for(int i = 0; i < 10; i++){
		res = res && A[i];
	}
	return res;
}
int main(int argc, char **argv)
{
	ifstream in("input");
	ofstream out("output");
	int times;
	in >> times;
	for(int t = 1; t <= times; t++){
		long long int n;
		in >> n;
		long long int cnt;
		if(n == 0) out << "Case #" << t <<": INSOMNIA" << endl;
		else{
			bool digits[10] = {};
			cnt = 0;
			do{
				cnt += n;
				check(digits, cnt);
			}while(!val(digits));
			out << "Case #" << t << ": " <<  cnt << endl;
		}
		
	}
	return 0;
}

