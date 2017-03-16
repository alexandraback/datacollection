#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MP(x,y) make_pair(x,y)
#define rl(n) scanf("%ld", &n)
#define rll(n) scanf("%I64d", &n) 
#define M_PII_4 0.785398163397448309616
bool static comparedesc(const long &stud1, const long &stud2){
    return stud1 > stud2;
}

long J, P, S, K;

// int cjp[10][10];
// int cjs[10][10];
// int cps[10][10];
map<pair<int,int>, int> cjp; map<pair<int,int>, int>  cjs; map<pair<int,int>, int>  cps;
set<pair<int, pair<int, int > > > ans;
set<pair<int, pair<int, int > > > :: iterator it;
/*
void trai(int j, int p, int s){
	//cout << j+1 << "," << p+1 << "," << s + 1 << endl;
	//if(ans.count(MP(j, MP(p,s))) > 0) return;
	
	if(s+1<S){ 
		trai(j,p,s+1);
	}
	if(p+1<P){ 
		trai(j,p+1,s);
	}
	if(j+1<J){ 
		trai(j+1,p,s);
	}
}
*/
int main(){
    int t ;
    cin >> t;
    for(int _t=1; _t<=t; _t++){
        printf("Case #%d: ", _t);
        rl(J); rl(P); rl(S); rl(K);
        cjp.clear();
        cjs.clear();
        cps.clear();
        // memset(cjp, 0, sizeof(cjp));
        // memset(cjs, 0, sizeof(cjs));
        // memset(cps, 0, sizeof(cps));
        //trai(0,0,0);
        for(int s=0; s<S; s++){
        	for(int p=0; p<P; p++){
        		for(int j=0; j<J; j++){
        			if(cjp.count(MP(j,p)) && cjp[MP(j,p)] == K) continue;
        			if(cjs.count(MP(j,s)) && cjs[MP(j,s)] == K) continue;
        			if(cps.count(MP(p,s)) && cps[MP(p,s)] == K) continue;
					ans.insert(MP(j, MP(p,s)));
					cjp[MP(j,p)] += 1;
					cjs[MP(j,s)] += 1;
					cps[MP(p,s)] += 1;
        		}
        	}
        }



        cout << ans.size() << endl;
        for(it=ans.begin(); it!=ans.end(); it++){
        	printf("%d %d %d\n", (*it).first+1, (*it).second.first+1, (*it).second.second+1);
        }
        ans.clear();
    }
    return 0;
}