#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
 
using namespace std;
 
int main()
{
    ifstream fin("B-small-attempt0.in");
    ofstream fout("B-small-attempt0.out");
    int T;
    fin >> T;
     
    string S;
    for (int t = 1 ; t <= T; t++)
    {  
    	fin >> S;
        int answer = 0;
        int i = 0;
        while (i < S.size()) {
            if (S[i] == '-') {
                int j;
                for (j = i+1 ; j < S.size() ; j++) {
                    if (S[j] == '+') {
                        answer++;
                        break;
                    }
                }
                if (j == S.size()) answer++;
                i = j;
            } else {
                int j;
                for (j = i+1 ; j < S.size() ; j++) {
                    if (S[j] == '-') {
                        answer++;
                        break;
                    }
                }
                i = j;
            }
        }
       	fout << "Case #" << t << ": " << answer << endl;
    }
}
