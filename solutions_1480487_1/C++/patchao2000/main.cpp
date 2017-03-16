#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main (int argc, char * const argv[]) 
{
	freopen("input2012_2B_1.txt", "rt", stdin);
	freopen("output2012_2B_1.txt", "wt", stdout);
    
    int T; 
	cin >> T;
	
    for(int i = 0; i < T; i++) 
    {
        int N;
        cin >> N;
        int S[200], X = 0;
        for (int j = 0; j < N; j++)
        {
            cin >> S[j];
            X += S[j];
        }
        
        int noneed = 0;
        int noneedx = 0;
        
        cout << "Case #" << i+1 << ": ";
        for (int j = 0; j < N; j++)
        {
            if ((double)S[j] >= (double)X * 2 / (double)N)
            {
                noneed ++;
                noneedx += S[j];
            }
        }
            
        //int realn = (N > 2 ? N - noneed : N);
        for (int j = 0; j < N; j++)
        {
            double r = 0.0;
            if ((double)S[j] < (double)X * 2 / (double)N)
                r = ((double)(2 * X-noneedx) / (double)(N - noneed) - (double)S[j]) / (double)X;
            printf("%.6f", r * 100.0);
            if (j != N-1)
                cout << " ";
        }
        
        cout << endl;
    }
    
	return 0;
}