#include <iostream>
#include <string>
#include <array>

using namespace std;

string num2binstr(int num) {
	string binstr = "";
	while(num>0) {
		if (num%2==1) binstr.insert(0,"1");
		else          binstr.insert(0,"0");
		num /= 2;
	}
	return binstr;
}

int main(int argc, char* argv[]) {
	
	int T;
	cin >> T;
	for (int t=0; t<T; ++t) {
		cout << "Case #" << t+1 << ": ";
		
		int N, J;
		cin >> N >> J;
		
		int block = 3; // binary 11
		
		
		
		int j=0;
		while( j<J ) {
			
			string sblock = num2binstr(block);
			int blocklength = sblock.size();
			
			array<long long, 9> divisor;
		    for (int i=2; i<=10; ++i) divisor[i-2] = stoll(sblock, NULL, i);
		
			string coinfront = sblock;
			
			int tail = N - blocklength;
			
			while ((tail > blocklength) &&  //do not complete perfectly to avoid repetition
			       (j < J)) { 
				
				string coin = coinfront;
				coin.append(tail-blocklength, '0');
				coin.append(sblock);
				cout << '\n' << coin;
				for (int i=2; i<=10; ++i) cout << ' ' << divisor[i-2];
				
				++j;
				coinfront.append(sblock);
				tail -= blocklength;
			}
			
			block += 2;
		}
		
		cout << "\n";
	}
	return 0;
} 
