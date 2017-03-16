#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*
struct tribe_t{
    int d, n, w, e, s, dd, dp, ds;
}tribe[20];
*/

struct attack_t{
    int day, w, e, s;
	attack_t(int _d, int _w, int _e, int _s):day(_d), w(_w), e(_e), s(_s){}
	bool operator < (const attack_t &att)const{
	    return day < att.day;
	}    
};
int wall[2048];
int shift = 1024;
vector<attack_t> attack;

void fill(int m[], int st, int ed, int key){
	for(int i = st; i < ed; ++i){
	    if(m[i] < key){
	        m[i] = key;    
  		}
	}
}    
int test(int m[], int st, int ed, int key){
	for(int i = st; i < ed; ++i){
	    if(m[i] < key){
	        return 1;
  		}
	}
	return 0;
}    
int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
	int T, N;
	int d, n, w, e, s, dd, dp, ds;
	cin>>T;
	for(int tt = 1; tt <= T; ++tt){
	    cin>>N;
	    memset(wall, 0, sizeof(wall));
		attack.clear();
	    for(int i = 0; i < N; ++i){
	    	cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
	    	w += shift;
	    	e += shift;
	    	while(n > 0){
	    	    attack.push_back(attack_t(d, w, e, s));
	    	    d += dd;
	    	    w += dp;
	    	    e += dp;
	    	    s += ds;
	    	    --n;
	    	}
     	}
     	sort(attack.begin(), attack.end());
		int ans = 0, p = 0;
		for(int i = 0; i < attack.size(); ++i){
		    if(attack[i].day != attack[p].day){
		        for(int j = p; j < i; ++j)
		        	fill(wall, attack[j].w, attack[j].e, attack[j].s);
      			p = i;
    		}
    		ans += test(wall, attack[i].w, attack[i].e, attack[i].s);
		}    
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}    
	return 0;
//	system("pause");
}    

