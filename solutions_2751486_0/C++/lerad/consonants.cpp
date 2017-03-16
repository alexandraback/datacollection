#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Please specify input file" << endl;
        return 1;
    }
    ifstream in(argv[1]);

    int testCases;
    in >> testCases;
    for (int testCase =0; testCase < testCases; testCase++) {
        long result = 0;
        // Read test case
        char name[101];
        long n;
        in >> name;
        in >> n;
        
        // Handle problem:
        int len = strlen(name);
//        cout << "Test: " << name << endl;
//        cout << "N=" << n << endl;
        for (int i=0; i<(len); i++) {
            for(int j=i; j<len; j++) {
                int curr_cons = 0;
//                cout << "Test from " << i << " to " << j << ": ";
                for(int x=i; x<=j; x++) {
                    char c = name[x];
                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
                        curr_cons = 0;
                    else
                        curr_cons++;
                    if (curr_cons >= n) {
                        result += 1;
                        break;
                    }
                }
            }
        }
        


        cout << "Case #" << (testCase+1) << ": " << result << endl;
    } 
    
    return 0;
}
