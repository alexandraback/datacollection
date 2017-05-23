#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#define min(x, y) (((x) < (y)) ? (x) : (y))
 
using namespace std;

int reverse(int i) {
    int n = 0;
    int t = i;
    while (i > 0) 
    {
         n = n*10 + (i%10);
         i = i/10;
    }
    //cout << t << " : " << n << endl;
    return n;
}
 
int main()
{
    ifstream fin("A-small-attempt3.in");
    ofstream fout("A-small-attempt3.out");
    int T;
    fin >> T;
     
    int answer[1000002];
    int N;
    for (int i = 1 ; i <= 1000000 ; i++) 
    {
	answer[i] = 0;
    }
    answer[1] = 1;
    for (int i = 1 ; i <= 1000000 ; i++)
   {
        int r = reverse(i);
        if (r > i && r <= 1000000) 
    		if (answer[r] == 0) answer[r] = answer[i]+1;
		else answer[r] = min(answer[r], answer[i]+1);
		
	if (answer[i+1] == 0)
		answer[i+1] = answer[i]+1;
	else 
		answer[i+1] = min(answer[i+1], answer[i]+1);
	//cout << i << " : " << answer[i] << endl;
    }

    for (int t = 1 ; t <= T; t++)
    {  
	fin >> N;

       fout << "Case #" << t << ": " << answer[N] << endl;       
    }
}
