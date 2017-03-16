#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(k,a,b) for(auto k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
typedef long long LL;

const LL MODN = 1000000007LL;

int T,N;
vector<string> c1;
vector<string> c2;
bool chb[26];
bool chp[26][3];
bool c2u[100+1];

LL mfact[100+1] = {0};

LL fact(LL a) {
    if(a == 0) return mfact[0] = 1LL;
    if(mfact[a]) return mfact[a];
    return mfact[a] = (fact(a-1) * a) % MODN;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio (false);

    cin >> T;
    FOR(cas,1,T) {
        cin >> N;

        LL sol = 1;

        c1.clear(); c2.clear();
        fill_n(chp[0],26*3,false);

        REP(i,N) {
            string tmp, red;
            cin >> tmp;

            fill_n(chb,26,false);

            chb[ tmp[0]-'a' ] = true;
            chp[ tmp[0]-'a' ][0] = true;
            red.push_back( tmp[0] );
            char last=tmp[0];

            FOR(j,1,(int)tmp.size()-1) {
                if( tmp[j] != last ) {
                    if(chp[ tmp[j]-'a' ][1] || chp[ last-'a' ][2] || chb[ tmp[j]-'a' ]) {
                        sol = 0;
                        break;
                    }
                    chb[ tmp[j]-'a' ] = true;
                    chp[ tmp[j]-'a' ][0] = true;
                    chp[ tmp[j]-'a' ][1] = true;
                    chp[ last-'a' ][2] = true;
                    if (j==(int)tmp.size()-1)
                        red.push_back( tmp[j] );
                    last = tmp[j];
                }
            }

            if(!sol) break;

            if(red.size()==1) c1.push_back(red);
            else c2.push_back(red);
        }


        int diff = 0;
        if(sol) {
            sort(c1.begin(),c1.end());
            sort(c2.begin(),c2.end());

            if(c1.size()) {
                int lidx = 0;
                int idx = 1;

                bool ex = false;
                REP(k,(int)c2.size()) {
                    ex = (c2[k][0]==c1[lidx][0]) || (c2[k][1]==c1[lidx][0]);
                    if(ex) break;
                }
                bool ns1 = chp[c1[lidx][0]-'a'][1] && chp[c1[lidx][0]-'a'][2];
                bool ns2 = !chp[c1[lidx][0]-'a'][1] && !chp[c1[lidx][0]-'a'][2];
                if(ns1 && !ex) sol = 0LL;
                if(ns2 && !ex) ++diff;

                while(idx < c1.size()) {
                    if(c1[idx][0] != c1[lidx][0]) {
                        bool ex = false;
                        REP(k,(int)c2.size()) {
                            ex = (c2[k][0]==c1[idx][0]) || (c2[k][1]==c1[idx][0]);
                            if(ex) break;
                        }
                        bool ns1 = chp[c1[idx][0]-'a'][1] && chp[c1[idx][0]-'a'][2];
                        bool ns2 = !chp[c1[idx][0]-'a'][1] && !chp[c1[idx][0]-'a'][2];
                        if(ns1 && !ex) sol = 0LL;
                        if(ns2 && !ex) ++diff;

                        sol *= fact(idx-lidx);
                        sol %= MODN;
                        lidx = idx;
                    }
                    ++idx;
                }
                sol *= fact(idx-lidx);
                sol %= MODN;
            }
        }

        fill_n(c2u,101,false);
        if(sol) {
            FOR(i,0,(int)c2.size()-1) {
                if(!c2u[i]) {
                    string st=c2[i];
                    c2u[i] = true;
                    FOR(j,0,(int)c2.size()-1) {
                        if(!c2u[j] && st[1]==c2[j][0]) {
                            c2u[j] = true;
                            st[1] = c2[j][1];
                            j = 0;
                        }
                    }
                    ++diff;
                }
            }
        }

        sol *= fact(diff);
        sol %= MODN;
        
        cout << "Case #" << cas << ": " << sol << endl;
    }

    return 0;
}
