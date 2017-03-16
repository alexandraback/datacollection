#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void flip(char * stack, int num){
    for(int i=0;i<num;i++){
        stack[i]=stack[i]=='+'?'-':'+';
    }
}

void doThings(string stacks, int numCase){
    int stackLen = stacks.length();
    char * stack = new char[stackLen+1];
    strcpy(stack, stacks.c_str());
    
    int indexDone = stackLen;
    int numFlips = 0;
    
    for(int i=indexDone-1;i>=0 && stack[i]=='+';i--){
        indexDone--;
    }
    
    while(indexDone > 0){
        flip(stack, indexDone);
        numFlips++;
        
        for(int i=indexDone-1;i>=0 && stack[i]=='+';i--){
            indexDone--;
        }
    }
    
    cout << "Case #" << numCase << ": " << numFlips << endl;
}

int main() {
	int T;

	cin >> T;

	int sum = 0;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;

		doThings(s, i+1);
	}

	return 0;
}