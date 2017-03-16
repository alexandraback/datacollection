#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	
	int T;
	cin >> T;
	for (int t=0; t<T; ++t) {
		cout << "Case #" << t+1 << ": ";
		int turns = 0;
		char last = '0';
		char current;
		current = getc(stdin);
		while (current != '+' && current !='-') current = getc(stdin);
		while (current != '\n') {
			switch(current) {
				case '+':
				    if (last == '-') ++turns;
				    last = '+';
				    break;
				case '-':
				    if (last == '+') ++turns;
				    last = '-';
				    break;
		    }
		    current = getc(stdin);
		}
		if (last == '-') ++turns;
		cout << turns << "\n";
	}
	return 0;
} 
