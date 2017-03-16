#include "std.h"
#include "debug.h"

char buf[1024];
char ans[1024];
int N;

int main() {
    int T;
    cin >> T; cin.getline(buf, sizeof buf);
    FOR(tt, T)
    {
	string s;
	cin >> s;
	bool p = s[0] == '+';
	int f = 0;
	bool plus = p;
	for(int i = 1; i < s.size(); i++)
	{
	    p = s[i] == '+';
	    if (p != plus)
	    {
		f++;
		plus = p;
	    }
	}
	if (!plus) f++;
	cout << "Case #"<<(tt+1)<<": ";
	cout << f;
	cout << endl;
    }
    return 0;
}
