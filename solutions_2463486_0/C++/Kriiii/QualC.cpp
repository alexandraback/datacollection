#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string num = "0123456789";

string sq(string s)
{
	int i,j,d[200];

	reverse(s.begin(),s.end());
	for (i=0;i<200;i++) d[i] = 0;
	for (i=0;i<s.length();i++) for (j=0;j<s.length();j++){
		d[i+j] += (s[i] - '0') * (s[j] - '0');
	}
	for (i=0;i<200;i++){
		if (d[i] > 10){
			d[i+1] += d[i] / 10;
			d[i] %= 10;
		}
	}
	string res = "";
	for (i=199;i>=0;i--) if (d[i]) break;
	for (;i>=0;i--) res.push_back(num[d[i]]);
	if (res == "") res = "0";
	return res;
}

bool ncmp(string a, string b)
{
	if (a.length() != b.length()) return a.length() < b.length();
	return a <= b;
}

vector<string> dic;

void cnt()
{
	int len,i,j,k; string S; long long res = 0;

	for (len=1;len<=51;len++){
		S = "";
		if (len == 1){
			dic.push_back("1");
			dic.push_back("4");
			dic.push_back("9");
			continue;
		}
		S = "1";
		for (i=1;i<len-1;i++) S += '0';
		S += '1';

		dic.push_back(sq(S));
		if (len%2){
			S[len/2] = '1';
			dic.push_back(sq(S));
			S[len/2] = '2';
			dic.push_back(sq(S));
			S[len/2] = '0';
		}

		for (i=1;i<len/2;i++){
			S[i] = S[len-i-1] = '1';
			dic.push_back(sq(S));
			if (len%2){
				S[len/2] = '1';
				dic.push_back(sq(S));
				S[len/2] = '2';
				dic.push_back(sq(S));
				S[len/2] = '0';
			}
			S[i] = S[len-i-1] = '0';
		}

		for (i=1;i<len/2;i++){
			S[i] = S[len-i-1] = '1';
			for (j=i+1;j<len/2;j++){
				S[j] = S[len-j-1] = '1';
				dic.push_back(sq(S));
				if (len%2){
					S[len/2] = '1';
					dic.push_back(sq(S));
					S[len/2] = '0';
				}
				S[j] = S[len-j-1] = '0';
			}
			S[i] = S[len-i-1] = '0';
		}

		for (i=1;i<len/2;i++){
			S[i] = S[len-i-1] = '1';
			for (j=i+1;j<len/2;j++){
				S[j] = S[len-j-1] = '1';
				for (k=j+1;k<len/2;k++){
					S[k] = S[len-k-1] = '1';
					dic.push_back(sq(S));
					if (len%2){
						S[len/2] = '1';
						dic.push_back(sq(S));
						S[len/2] = '0';
					}
					S[k] = S[len-k-1] = '0';
				}
				S[j] = S[len-j-1] = '0';
			}
			S[i] = S[len-i-1] = '0';
		}

		S = "2";
		for (i=1;i<len-1;i++) S += '0';
		S += '2';

		dic.push_back(sq(S));
		if (len%2){
			S[len/2] = '1';
			dic.push_back(sq(S));
			S[len/2] = '0';
		}
	}
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test,Case=1;
	int i,res; string A,B; char T[102];

	cnt();

	scanf ("%d",&Test); while (Test--){
		printf ("Case #%d: ",Case++);
		scanf ("%s",T); A = T;
		scanf ("%s",T); B = T;
		res = 0;
		for (i=0;i<dic.size();i++) if (ncmp(A,dic[i]) && ncmp(dic[i],B)) res++;
		printf ("%d\n",res);
	}

	return 0;
}