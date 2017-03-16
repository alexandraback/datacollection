#include <iostream>
#define PB push_back
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int P[10];
string w;
string wzorzec;
string keyboard;

int res, esp, ile;

void Pref( vector<int> &P, string &S )
{
	unsigned int t = 0, i, n = S.size();
	P.resize(n+1, 0);
	 
	for( i = 2; i < n; i++ )
	{
		while (t > 0 && S[t + 1] != S[i]) t = P[t];
		if( S[t+1] == S[i] ) t++;
		P[i] = t;
	}
}
 
void KMP( string &T, string &W )
{
	string S = "#" + W + "#" + T;
	vector<int> P;
	Pref(P, S);
	 
	unsigned int i, ws = W.size();

	int tmp = 0; 
	for( i = ws + 2; i < S.size(); i++ )
	{
		if( P[i] == ws ) {
			tmp ++;
			res ++;
		}
	}
	esp = max(esp, tmp);
}

void rec(const string& input, string output, int s) {
	if(output.length() == s) {
		ile ++;
          KMP(output, wzorzec);
      } else {
       for(int i=0; i<input.length(); ++i){
            rec(input, output + input[i], s);
       }
  }
}

int main () {
	int te, K, L, S;
	scanf("%d\n", &te);
	for(int i = 1; i <= te; ++i) {
		//printf("asd\n");
		scanf ("%d %d %d\n", &K, &L, &S);
		cin >> keyboard;
		cin >> wzorzec;
		res = 0;
		ile = 0;
		esp = 0;
		rec(keyboard, "", S);
		//printf("%d %d %d\n", res, ile, esp);
		double wyn = (double)res / (double)ile;
		printf("Case #%d: %.6lf\n", i, double(esp)- wyn);
	}
}