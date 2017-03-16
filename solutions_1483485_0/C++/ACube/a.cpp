#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout

int rev[200];
char s[200], t[200];

void main2 ()
{
	string s;
	getline(cin, s);
	for (int i = 0; i < SIZE(s); i++)
		if (isalpha(s[i]))
			s[i] = rev[s[i]-'a']+'a';
	gout << s << endl;
}

int main ()
{
	freopen("code", "r", stdin);
	scanf("%s", s);
	scanf("%s", t);
	memset(rev, -1, sizeof(rev));
	for (int i = 0; s[i]; i++)
		rev[s[i]-'a'] = t[i]-'a';
	rev['z'-'a'] = 'q'-'a';

	for (int i = 0; i < 26; i++)
		printf("%c-%c\n", i+'a', rev[i]+'a');
	fclose(stdin);

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d\n", &test_num);

	for ( int i = 0; i < test_num; i++ )
		main2();

	return 0;
}
