#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
 //   ifstream fin("A-small-attempt0.in");
 //   ofstream fout("A-small-attempt0.out");
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");

    int T; fin >> T;
    string L; int N;
    
    
    for (int t = 1 ; t <= T; t++)
    {  
		fout << "Case #" << t << ": ";
		
		fin >> L >> N;
		long long answer = 0;
		
		int temp = 0; int start = 0;
		for (int i = 0 ; i < L.size() ; i++)
        {
             if (L[i] == 'a' || L[i] == 'e' || L[i] == 'i' || L[i] == 'o' || L[i] == 'u')
                temp = 0;
             else
                 temp++;
             if (temp >= N)
                start = (i+1-N+1);
             
             answer += start;
        }
		
        fout << answer << endl;
    }
}
