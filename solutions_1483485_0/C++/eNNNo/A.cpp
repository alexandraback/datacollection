#include <iostream>
#include <string>
using namespace std;
const char trans[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q',};
unsigned int T;
string in[31];
string out;
int main() {
	freopen ("out.txt","w",stdout);
	scanf("%d\n",&T);
	unsigned int i,j;
	for (i = 0; i < T; i++)
		getline (cin,in[i],'\n');
	for (i = 0; i< T; i++) {
		unsigned int len = in[i].length();
		out = "";
		for (j =0; j < len; j++) {
			char ch = in[i].at(j);
			if (ch != ' ')
				out += trans[ch - 'a'];
			else
				out += ' ';
		}
		printf("Case #%d: %s\n",i+1,out.c_str ());
	}
}