#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream in("in.in");
	ofstream out("out.out");

	int T;
	in >> T;
	
	for(int test = 0; test < T; ++test)
	{
        int A, N;
        int motes [100];
        int extraMotes [100];
        int choppedMotes [100];
        
        in >> A >> N;
        for(int i = 0; i < N; ++i)
            in >> motes[i];
            
        sort(motes, motes+N);
        
        /*for(int i = 0; i < N; ++i)
            cout << motes[i] << " ";
        cout << endl;*/
            
        int currentExtras = 0;
        if(A == 1) {
            out << "Case #" << test+1 << ": " << N << endl;
            continue;
        }
        
        for(int i = 0; i < N; ++i) {
            while(A <= motes[i])
            {
                A = 2*A - 1;
                currentExtras += 1;
            }
            
            A += motes[i];
            extraMotes[i] = currentExtras;
        }
        
/*        for(int i = 0; i < N; ++i)
            cout << extraMotes[i] << " ";
        cout << endl;*/
        
        int minScore = N;
        
        for(int i = 0; i < N; ++i)
        {
            int choppedAtI = extraMotes[i] + N - i - 1;
            minScore = min(minScore, choppedAtI);
        }
        
        out << "Case #" << test+1 << ": " << minScore << endl;
	}
}
