#define _SECURE_SCL 0

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#ifdef _DEBUG
#define	Assert(E)		do { if (!(E)) {  __asm {int 3}; } } while (false)
#else// _DEBUG
#define	Assert(E)		do { if (!(E)) {  __asm {int 3}; } } while (false)
//#define	Assert(E)		do { if (!(E)) { } } while (false)
#endif//_DEBUG

typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned __int64 QWORD;

//--------------------------------------------------------------------------------------------------
static char map[26];

//--------------------------------------------------------------------------------------------------
void ProcessTask(int in_id)
{
	vector<char> symbols;
	while(1)
	{
		char ch = cin.get();
		if (ch == '\n') break;
		
		Assert((ch == ' ') || ((ch >= 'a') && (ch <= 'z')));
		symbols.push_back(ch);
	}

	symbols.push_back(0);
	for(DWORD i = 0; i < symbols.size(); ++i)
	{
		char ch = symbols[i];
		if (ch == ' ') continue;
		symbols[i] = map[ch - 'a'];
	}

	printf("Case #%d: %s\n", in_id + 1, &symbols[0]);
}

//--------------------------------------------------------------------------------------------------
const char *istr = "ejp mysljylc kd kxveddknmc re jsicpdrysi\
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jv q";

const char *ostr = "our language is impossible to understand\
there are twenty six factorial possibilities\
so it is okay if you want to just give up z";

void MakeMap()
{
	char used[26];

	for(DWORD i = 0; i < 26; ++i)
	{
		map[i] = 0;
		used[i] = 0;
	}

	const char *i = istr;
	const char *o = ostr;
	for(;*i && *o; ++i, ++o)
	{
		if (*i == ' ')
		{
			Assert(*o == ' ');
			continue;
		}

		int m = *i - 'a';
		int r = *o - 'a';
		Assert((m >= 0) && (m < 26));
		Assert((r >= 0) && (r < 26));
		used[r] = 1;
		if (!map[m])
		{
			map[m] = *o;
		}
		else
		{
			Assert(map[m] == *o);
		}
	}

	DWORD pos = -1;
	DWORD rep = -1;
	for(DWORD i = 0; i < 26; ++i)
	{
		if (!map[i])
		{
			Assert(pos == -1);
			pos = i;
		}
		if (!used[i])
		{
			Assert(rep == -1);
			rep = i;
		}
	}

	if (pos == -1) return;
	Assert(rep != -1);
	map[pos] = char(rep + 'a');
}

//--------------------------------------------------------------------------------------------------
int main()
{
	MakeMap();

	int numb;
	cin >> numb;
	cin.get();

	for(int i = 0; i < numb; ++i)
	{
		ProcessTask(i);
	}

	return 0;
}
