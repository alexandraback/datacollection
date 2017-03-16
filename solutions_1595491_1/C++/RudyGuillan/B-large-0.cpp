#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// no whitespaces
const char* original_data = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
const char* original_translation = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
// no mapping from q or z...
// const char* letters = "yhesocvxduiglbkr?tnwjpfma?";
// clue from the statement: z -> q, so q -> z
const char* letters = "yhesocvxduiglbkrztnwjpfmaq";

char* solve(const char* input) {
	/*int size_letters = ('z'-'a') + 1;
	char* letters = (char*) malloc(size_letters * sizeof(char));
	for(int i=0; i<size_letters; i++)
		letters[i] = i + 'A';
	int original_length = strlen(original_data);
	for(int i=0; i<original_length; i++)
		letters[original_data[i] - 'a'] = original_translation[i];
	for(int i=0; i<size_letters; i++)
		cerr << letters[i];
	cerr << endl; */
	int len_input = strlen(input);
	char* output = (char*) malloc((len_input + 1) * sizeof(char));
	output[len_input] = 0; // NULL terminator
	for(int i=0; i<len_input; i++) {
		if(input[i] == ' ')
			output[i] = ' ';
		else
			output[i] = letters[input[i] - 'a'];
	}
	return output;
}

int main() {
	string input_line;
	int n;
	cin >> n;
	getline(cin, input_line); // discard the first line (n)
	for(int i=1; i<=n; i++) {
		getline(cin, input_line);
		cout << "Case #" << i << ": " << solve(input_line.c_str()) << endl;
	}
	return 0;
}