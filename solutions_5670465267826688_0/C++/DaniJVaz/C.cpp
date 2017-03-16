#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

string mult(const string & a, const string & b);

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int L, X;
		scanf("%d %d", &L, &X);

		char pattern[L+2];
		scanf("%s", pattern);

		// printf("%s %s %s %s %s %s %s %s\n", mult("1","1").c_str(), mult("1","i").c_str(), mult("1","j").c_str(), mult("1","k").c_str(), mult("1","-1").c_str(), mult("1","-i").c_str(), mult("1","-j").c_str(), mult("1","-k").c_str());
		// printf("%s %s %s %s %s %s %s %s\n", mult("i","1").c_str(), mult("i","i").c_str(), mult("i","j").c_str(), mult("i","k").c_str(), mult("i","-1").c_str(), mult("i","-i").c_str(), mult("i","-j").c_str(), mult("i","-k").c_str());
		// printf("%s %s %s %s %s %s %s %s\n", mult("j","1").c_str(), mult("j","i").c_str(), mult("j","j").c_str(), mult("j","k").c_str(), mult("j","-1").c_str(), mult("j","-i").c_str(), mult("j","-j").c_str(), mult("j","-k").c_str());
		// printf("%s %s %s %s %s %s %s %s\n", mult("k","1").c_str(), mult("k","i").c_str(), mult("k","j").c_str(), mult("k","k").c_str(), mult("k","-1").c_str(), mult("k","-i").c_str(), mult("k","-j").c_str(), mult("k","-k").c_str());
		// printf("%s %s %s %s %s %s %s %s\n", mult("-1","1").c_str(), mult("-1","i").c_str(), mult("-1","j").c_str(), mult("-1","k").c_str(), mult("-1","-1").c_str(), mult("-1","-i").c_str(), mult("-1","-j").c_str(), mult("-1","-k").c_str());
		// printf("%s %s %s %s %s %s %s %s\n", mult("-i","1").c_str(), mult("-i","i").c_str(), mult("-i","j").c_str(), mult("-i","k").c_str(), mult("-i","-1").c_str(), mult("-i","-i").c_str(), mult("-i","-j").c_str(), mult("-i","-k").c_str());
		// printf("%s %s %s %s %s %s %s %s\n", mult("-j","1").c_str(), mult("-j","i").c_str(), mult("-j","j").c_str(), mult("-j","k").c_str(), mult("-j","-1").c_str(), mult("-j","-i").c_str(), mult("-j","-j").c_str(), mult("-j","-k").c_str());
		// printf("%s %s %s %s %s %s %s %s\n", mult("-k","1").c_str(), mult("-k","i").c_str(), mult("-k","j").c_str(), mult("-k","k").c_str(), mult("-k","-1").c_str(), mult("-k","-i").c_str(), mult("-k","-j").c_str(), mult("-k","-k").c_str());

		// If the pattern starts more than 4 times in a part, it can be reduces, since each of these numbers to the power of 4 is 1
		// Therefore, we only need around 12 repetitions, but we keep the same modulo 4

		if (X > 12)
			X = 12 + (X%4);

		string fullText = "";
		for (int i=0; i<X; i++)
			fullText += pattern;

		// Now, since multiplication is associative, we can just stop when we find an i, 
		//because stopping at any other point means that the number in between is equal to 1, and so can be transferred to the j-part
		// The same happens for j

		string cur = "1";
		int i = 0;
		for (; i < (int) fullText.size(); i++) {
			if (cur == "i")
				break;
			cur = mult(cur, string() + (fullText[i]));
		}

		cur = "1";
		for (; i < (int) fullText.size(); i++) {
			if (cur == "j")
				break;
			cur = mult(cur, string() + (fullText[i]));
		}

		cur = "1";
		for (; i < (int) fullText.size(); i++) {
			cur = mult(cur, string() + (fullText[i]));
		}

		printf("Case #%d: ", iC);

		if (cur == "k")
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

string mult(const string & a, const string & b) {
	char cA = a[a.size()-1], cB = b[b.size()-1];
	int sgn = (1-2*(a[0] == '-')) * (1-2*(b[0] == '-'));
	char cR;

	if (cA == '1')
		cR = cB;
	else if (cB == '1')
		cR = cA;
	else if (cA == cB) {
		cR = '1';
		sgn *= -1;
	}
	else if (cA == 'i') {
		cR = (cB=='j')?'k':'j';
		sgn *= (1-2*(cB=='k'));
	}
	else if (cA == 'j') {
		cR = (cB=='i')?'k':'i';
		sgn *= (1-2*(cB=='i'));
	}
	else if (cA == 'k') {
		cR = (cB=='j')?'i':'j';
		sgn *= (1-2*(cB=='j'));
	}
	return string((sgn==1)?"":"-") + cR;
}
