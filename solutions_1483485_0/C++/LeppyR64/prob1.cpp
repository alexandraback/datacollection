#include <cstdio>
#include <cassert>
#include <iostream>
#include <cstring>
using namespace std;

char M['z'+1];
char S[1000];

string A = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvzq";
string B = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upqz";

int main()
{
	int n = A.size();
	for(int i = 0; i < n; i++)
	{	
		if(M[A[i]] != 0 && B[i] != M[A[i]])
			assert(false);
		M[A[i]] = B[i];
	}
	
	int t;
	scanf("%d", &t);
	cin.getline(S,200);
	for(int z = 1; z <= t; z++)
	{
		cin.getline(S,200);
		n = strlen(S);
		for(int i = 0; i < n; i++)
			if(S[i] >= 'a' && S[i] <= 'z')
				S[i] = M[S[i]];
		printf("Case #%d: %s\n", z, S);
	}
}
