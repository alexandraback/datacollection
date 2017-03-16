#include <fstream>
#include <cstring>

using namespace std;

int getOperationTimes(char str[], int len);
void reverseStr(char str[], int len);

int main() {
	//set input/output stream
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");

	char str[200];
	int T;
	input >> T;
	for(int i = 1; i <= T; i++) {
		input >> str;
		output << "Case #" << i << ": " << getOperationTimes(str, strlen(str)) << endl;
	}

	return 0;
}

int getOperationTimes(char str[], int len){
	//delete end +
	while(len > 0 && str[len-1] == '+') {
		len--;
	}
	if(len == 0) {
		return 0;
	}
	int count = 0;
	if(str[len-1] == '-' && str[0] == '-') {
		reverseStr(str, len);
		return getOperationTimes(str, len) + 1;
	} else if (str[len-1] == '-' && str[0] == '+') {
		len--;
		reverseStr(str, len);
		return getOperationTimes(str, len) + 1;
	}

	return 0;
}

void reverseStr(char str[], int len) {
	for(int i = 0; i < len; i++){
		if(str[i] == '-') {
			str[i] = '+';
		} else {
			str[i] = '-';
		}
	}
}
