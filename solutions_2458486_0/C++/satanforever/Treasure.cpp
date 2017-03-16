#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <deque>
#include <map>
#include <vector>
#include <complex>
using namespace std;

#define read(c) scanf("%d",&(c))
#define FOR(i,n) for (int i=0;i<(n);i++)
#define FR(i,a,b) for (int i=(a);i<(b);i++)
#define fillzero(d) memset(d,0,sizeof(d))
#define fillmax(d) memset(d,63,sizeof(d))
#define dumps(x) cerr<<(__LINE__)<< ':'<<#x<<" = "<<(x)<<endl
#define dump(x) cerr<<(__LINE__)<< ':'<<#x<<" = "<<(x)<<"	"
#define shit cerr<<"Line:"<<(__LINE__)<<endl;
#define fileread freopen("/Users/satanforever/Documents/input.txt","r",stdin)
#define filereadT freopen("/Users/satanforever/Downloads/D-small-attempt1.in.txt","r",stdin)
#define filewrite freopen("/Users/satanforever/Documents/codeJam/D-small.out.txt","w",stdout)
#define closeread fclose(stdin)
#define closewrite fclose(stdout)
#define MAXINT 0x7fffffff

deque<vector<int> > qChest, qKey;
bool hash[2097153];
int N, nKey;
int pow2[22], T[22], key[22], keyIn[22][42]; 
vector<int> solve(){
    vector<int> elemChest;
    vector<int> elemKey(nKey+1), tmpKey(nKey+1);
    int mask;
    qChest.clear();
    qKey.clear();
    elemChest.clear();
    fillzero(hash);
    elemChest.push_back(0);
    qChest.push_back(elemChest);
    for (int i = 1; i <= nKey; i++)
        elemKey[i] = 0;
    for (int i = 0; i < T[0]; i++)
        elemKey[keyIn[0][i]]++;
    qKey.push_back(elemKey);
    while (!qChest.empty()) {
        elemChest = qChest.front();
        qChest.pop_front();
        elemKey = qKey.front();
        qKey.pop_front();
        int nChest = elemChest.size();
        if (nChest == N+1)
            return elemChest;
        mask = 0;
        for(int i = 0; i < nChest; i++)
            mask |= pow2[elemChest[i]];
        /*
        cout << "mask:" << mask <<endl;
        for (int i = 0; i <= nKey; i++)
            cout << elemKey[i] << " ";
        cout << endl;
        for (int i = 0; i < elemChest.size(); i++)
            cout << elemChest[i] << " ";
        cout << endl;
        */
        for(int i = 1; i <= N; i++)
            if (!(pow2[i] & mask) && elemKey[key[i]]>0) {
                elemChest.push_back(i);
                mask |= pow2[i];
                if (hash[mask]) {
                    elemChest.pop_back();
                    mask ^= pow2[i];
                    continue;
                }
                hash[mask] = true;
                mask ^= pow2[i];
                qChest.push_back(elemChest);
                elemChest.pop_back();
                tmpKey = elemKey;
                tmpKey[key[i]]--;
                for(int j = 0; j < T[i]; j++)
                    tmpKey[keyIn[i][j]]++;
                qKey.push_back(tmpKey);
            }
    }
    elemChest.clear();
    return elemChest;
}
void input(){
    cin >> T[0] >> N;
    nKey = 0;
    for (int j = 0; j < T[0]; j++) {
        cin >> keyIn[0][j];
        nKey =  max(nKey, keyIn[0][j]);
    }
    for (int i = 1; i <= N; i++) {
        cin >> key[i] >> T[i];
        for (int j = 0; j < T[i]; j++) {
            cin >> keyIn[i][j];
            nKey =  max(nKey, keyIn[i][j]);
        }
    }
}
void output(vector<int> ret, int t){
    cout << "Case #" << t << ":";
    int n = ret.size();
    if (n) {
        for(int i = 1; i < n; i++)
            cout << " " << ret[i];
    } else
            cout << " IMPOSSIBLE";
    cout << endl;
}
int main() {
    //filereadT;
    //filewrite;
    int caseT;
    cin >> caseT;
    pow2[0] = 1;
    for (int i = 1; i <= 21 ; i++) 
        pow2[i] = pow2[i-1] * 2;
    for (int i = 1; i <= caseT; i++) {
  	    input();
  	    vector<int> ret = solve();
  	    output(ret, i);
    }
    //closeread;
    //closewrite;
  	return 0;
}
