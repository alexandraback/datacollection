#include "std.h"
#define DBGLEVEL 1
#define WANT_PROF 0
#include "debug.h"
#include <string.h>

char buf[1024];
char ans[1024];
int N;

int main() {
    int T;
    cin >> T; cin.getline(buf, sizeof buf);
    FOR(tt, T)
    {
	int N;
	cin >> N;

	VI seen(10, 0);
	int nSeen = 0;
	int n = N;

	if (N == 0) 
	{
	    strcpy(ans, "INSOMNIA");
	    goto fin; 
	}

	for(int i = 0; ; i++, n += N)
	{
	    int r = n;
	    while (r > 0)
	    {
		int d = r % 10;
		if (!seen[d])
		{
		    seen[d] = 1;
		    nSeen++;
		    if (nSeen == 10)
		    {
			goto found;
		    }
		}
		r /= 10;
	    }
	}
    found: 
	sprintf(ans, "%d", n);

    fin:
	cout << "Case #"<<(tt+1)<<": ";
	cout << ans;
	cout << endl;
    }
    return 0;
}
