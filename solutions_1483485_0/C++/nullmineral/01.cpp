#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	char map[27] = "yhesocvxduiglbkrztnwjpfmaq";
	
	scanf("%d ", &t);
	
	for(int time = 0; time < t; ++time) {
		
		string input;
		
		getline(cin, input);
		
		for(int i = 0; i < input.size(); ++i) {
		
			char from = input[i];
			
			if(from == ' ')
				continue;
			
			input[i] = map[from - 'a'];
		}
		
		cout << "Case #" << (time + 1) << ": " << input << endl;
	}
	
	return 0;
}