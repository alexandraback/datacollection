#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class attack 
{
    public:
	int d;
	int w;
	int e;
	int s;
    	attack(int D, int W, int E, int S) {
	    d = D;
	    w = W;
	    e = E;
	    s = S;
	}
};

bool comp(const attack &a, const attack &b) {
    return a.d < b.d;
}

int main()
{
    int T,N,d,n,w,e,s,delta_d,delta_p,delta_s;
    cin >> T;
    for (int c=1; c<=T; c++) {
	cin >> N;
	vector<attack> atk;
	for (int i=0; i<N; i++) {
	    cin >> d >> n >> w >> e >> s >> delta_d >> delta_p >> delta_s;
	    w += 100;
	    e += 100;
	    for (int j=0; j<n; j++) {
		atk.push_back(attack(d+j*delta_d, w+j*delta_p, e+j*delta_p, s+j*delta_s));
	    }
	}
	int a[1000] = {0};
	sort(atk.begin(), atk.end(), comp);
	int sum = 0;
	for (int i=0; i<atk.size();) {
	    int t = atk[i].d;
	    int j;
	    for (j=i; atk[j].d == t && j<atk.size(); j++) {
		for (int k=atk[j].w; k<atk[j].e; k++) {
		    if (a[k] < atk[j].s) {
			sum++;
			break;
		    }
		}
	    }
	    for (j=i; atk[j].d == t && j<atk.size(); j++) {
		for (int k=atk[j].w; k<atk[j].e; k++) {
		    a[k] = max(atk[j].s, a[k]);
		}
	    }
	    i = j;
	}
	cout << "Case #" << c << ": " << sum << endl;
    }
    return 0;
}
