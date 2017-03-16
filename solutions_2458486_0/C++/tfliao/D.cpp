#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 200

int T, nCase = 1 ;
int K, N ;
int keys[MAX], need[MAX], final[MAX];
int MXK ;

struct Chest
{
	int key;
	int nin;
	int in[MAX] ;
    bool hasSelf ;
};
Chest c[MAX] ;

int inSub1() { int v; cin >> v ; MXK = max(MXK, v); return v-1; }

void input()
{
    cin >> K >> N;
    memset(keys, 0, sizeof keys);
    memset(need, 0, sizeof need);
    memset(final, 0, sizeof final);
    MXK = 0;
    for ( int i=0;i<K;++i ) {
        int k = inSub1();
        keys[k]++, final[k]++;
    }
    for ( int i=0;i<N;++i ) {
		int k = inSub1();
		c[i].key = k;
        final[k]--;
        need[k]++ ;
		
        c[i].hasSelf = false ;
		cin >> c[i].nin ;
		for ( int j=0;j<c[i].nin;++j ) {
			k = inSub1();
			c[i].in[j] = k;
            final[k]++;
            if ( k == c[i].key ) c[i].hasSelf = true;
		}
	}
}


vector<int> ans ;
bool open[MAX] ;

bool just_open(int x)
{
    return c[x].hasSelf || need[c[x].key]==1;
}

void open_it(int x)
{
    keys[c[x].key]--;
    need[c[x].key]--;
    open[x] = true;
    ans.push_back(x);
    for ( int i=0;i<c[x].nin;++i ) 
        keys[c[x].in[i]]++;
}

void close_it(int x)
{
    for ( int i=0;i<c[x].nin;++i ) 
        keys[c[x].in[i]]--;
    ans.pop_back();
    open[x] = false;
    need[c[x].key]++;
    keys[c[x].key]++;
}

bool solve_r ( int start )
{
    if ( ans.size() == N ) {
		return true;
	}
	for ( int i=start;i<N;++i ) {
        if ( !open[i] && keys[c[i].key] ) {
            if ( just_open(i) ) {
                open_it(i);
                if ( solve_r(0) )
                    return true;
                
                close_it(i);
            } else {
                open_it(i);
                if ( solve_r(0) )
                    return true;   
                close_it(i);
                if ( solve_r(i+1) ) 
                    return true;
                
            }
            return false;
        }
	}
	return false;
}

bool trival_test()
{
    for ( int i=0;i<MXK;++i ) 
        if ( final[i] < 0 ) return true;
    return false;
}

void solve() 
{
	if ( trival_test() ) {
        cout << " IMPOSSIBLE" << endl;
        return;
    }

	ans.clear();
	memset(open, false, sizeof open);
	if ( solve_r(0) ) {
		for ( int i=0;i<ans.size();++i ) {
			cout << " " << ans[i]+1 ;
		} cout << endl;
	} else {
		cout << " IMPOSSIBLE" << endl;
	}
}

int main()
{
	cin >> T ;
	while(T--){
		input();
		cout << "Case #"<<nCase++<<":";
		solve();
	}
	return 0;
}