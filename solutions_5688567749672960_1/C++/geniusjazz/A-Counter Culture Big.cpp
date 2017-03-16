#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#define min(x, y) (((x) < (y)) ? (x) : (y))
 
using namespace std;

long long reverse(long long i) {
    long long n = 0;
    while (i > 0) 
    {
         n = n*10 + (i%10);
         i = i/10;
    }
    return n;
}

int digits (long long i) {
	int digits = 0; 
	while (i != 0) { 
		i /= 10; 
		digits++; 
	}
	return digits;
}
 
int main()
{
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");
    int T;
    fin >> T;

    int ans[14];
	ans[0] = 1;
	ans[1] = 10;
	for (int i = 2 ; i < 15 ; i++) {
		ans[i] = ans[i-1] + pow(10,(i/2))-1 + pow(10,(int)ceil((double)i/2.0));
	        cout << i << " " << ans[i] << endl;
	}
	
    long long N;
    for (int t = 1 ; t <= T; t++)
    {  
	fin >> N;
	int d = digits(N);
	int k = pow(10,(int)ceil((double)d/2.0));

	long long answer = 0;
	for (int i = 0 ; i < 15 ; i++)
		if (N == pow(10, i)) {answer = ans[i]; break;}

	if (answer != 0) {fout << "Case #" << t << ": " << answer << endl; continue;}
	//if (N <= 20) { fout << "Case #" << t << ": " << N << endl; continue;}  
	
	long long mod = N%k;
	if (mod==0) mod = k;
	
	long long r = reverse(N-mod+1);
cout << N << " " <<  d << " " << k << " " << r << endl;
	answer = mod + ans[d-1]+ (r-pow(10,d-1));
if (r == N-mod+1) answer--;
	
       fout << "Case #" << t << ": " << answer << endl;       
    }
}
