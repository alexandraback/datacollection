#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int nCase;
    scanf("%d", &nCase);
    for (int iCase = 1; iCase <= nCase; ++iCase) {
	unsigned n;
	scanf("%u", &n);

	vector<unsigned> s;
	s.reserve(n);
	unsigned S = 0;
	for (unsigned i = 0; i < n; ++i) {
	    unsigned si;
	    scanf("%u", &si);
	    s.push_back(si);
	    S += si;
	}

	printf("Case #%u:", iCase);
	for (unsigned i = 0; i < n; ++i) {
	    unsigned si = s[i];
	    double head = 0.0, tail = 1.0;
	    while (head + 1e-8 < tail) {
		double m = (head + tail) / 2;
		double r = 0.0;
		for (unsigned j = 0; j < n; ++j) {
		    if (j == i) {
			continue;
		    }
		    if (si+S*m > s[j]) {
			r += (si+S*m - s[j]) / S;
		    }
		}
		if (m + r > 1) {
		    tail = m;
		} else {
		    head = m;
		}
	    }
	    printf(" %.8lf", (100*head));
	}
	printf("\n");
    }
    return 0;
}

