#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		char S[1010]; scanf ("%s",S);
		string s = "";
		for (int i=0;S[i];i++){
			string a = S[i] + s, b = s + S[i];
			if (a < b) s = b;
			else s = a;
		}
		printf ("Case #%d: %s\n",Case,s.c_str());
	}

	return 0;
}