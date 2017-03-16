#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define FN "gcj1c_a"

bool iscons(char c)
{
	return c != 'a' && c != 'e' && c != 'u' && c != 'o' && c != 'i';
}

int main()
{
	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int t;
	in >> t;
	for(int i = 0; i < t; i++)
	{
		out << "Case #" << (i+1) << ": ";
		 string s;
		 int n;
		 in >> s >> n;
		 ull ans = 0;


		 for(int j = 0; j < s.length(); j++)
		 {
			 int cons = 0;
			 for(int k = j; k < s.length(); k++)
			 {
				 if(iscons(s[k]))
					 cons++;
				 else
					 cons = 0;

				 if(cons == n)
				 {
					 ans += (s.length()-k)*(k+2-n-j); //also, assume that all j in j..k-n use the same basically. sad? sad.
					 j = k-n+1;
					 break;
				 }
			 }
		 }

		 out << ans << "\n";

		 /*ull bad = 0;

		 int cons = 0;
		 int len = 0;

		 for(int j = 0; j < s.length(); j++)
		 {
			 if( iscons(s[j]) )
			 {
				 cons++;
				 if(cons == n && len >= n)
					 bad += len*(len+1)/2-(len+len-n+2)*(n-1)/2;

			 } else {
				 if(cons >= n) {
					 len = n-1;
				 }
				 cons = 0;
			 }

			 len++;
		 }

		 if(len >= n && cons < n)
			 bad += len*(len+1)/2-(len+len-n+2)*(n-1)/2;

		 out << s.length()*(s.length()+1)/2-bad-(s.length()*2-n+2)*(n-1)/2 << "\n";*/
	}

	out.close();
	return 0;
}