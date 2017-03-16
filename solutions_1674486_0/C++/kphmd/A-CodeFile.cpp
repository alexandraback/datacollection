#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void solve();
void runCase();

#define REP(i,n) for(int i = 0; i < (n); i++)
#define SZ(x) (int)(x.size())

int N;
vector< vector<int> > tab;

set<int> all;
bool check(int x,int times = 0) {
    if(times==0) {
        all.clear();
        //cout << x << "======="<< endl;
    }
    else {
        //cout << x << endl;
        if(all.count(x)) {
            all.clear();
            return true;
        } else {
            all.insert(x);
        }
    }
    REP(i,SZ(tab[x])) {
        if(check(tab[x][i]-1,1)) return true;
    }
    return false;
}

void runCase()
{
    scanf("%d",&N);
    tab = vector< vector<int> >(N);
    REP(i,N) {
        int m;
        scanf("%d",&m);
        tab[i] = vector<int>(m);
        REP(j,m) scanf("%d",&tab[i][j]);
    }

    REP(i,N) {
        if(check(i)) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

void runSample()
{
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
