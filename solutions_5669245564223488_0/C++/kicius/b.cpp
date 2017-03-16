
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <numeric>
#include <array>
#include <map>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <thread>
#include <sstream>
#include <atomic>

using namespace std;

const long long Mod =1000000007;

long long silnia(int i) {
    if(i<=0) return 1;
    return (silnia(i-1)*i)%Mod;
}

int main () {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
        int zabron[26];
        int jeden[26];
        int B[26];
        int E[26];
        for (int i=0; i<26; i++) {
            zabron[i]=jeden[i]=0;
            B[i]=E[i]=-1;
        }


        vector<char> pociagi[100];
        int N;
        scanf("%d", &N);
        for (int n=0; n<N; n++) {
            char buf[1000];
            scanf("%s", buf);
            pociagi[n].push_back((*buf)-'a');
            for (char* s=buf+1; *s; s++) {
                if (pociagi[n].back()!=(*s)-'a') pociagi[n].push_back((*s)-'a');
            }
        }
        bool zle=false;
        for (int n=0; n<N; n++) {
            if (pociagi[n].size()==1) {
                jeden[pociagi[n].front()]++;
                continue;
            }

            if (B[pociagi[n].front()]!=-1) zle=true;
            B[pociagi[n].front()]=n;
            if (E[pociagi[n].back()]!=-1) zle=true;
            E[pociagi[n].back()]=n;

            if (pociagi[n].size()>2) {
                for (int i=1; i<pociagi[n].size()-1; i++) {
                    zabron[pociagi[n][i]]++;
                }
            }
        }

        int mark[26];
        for (int c=0; c<26; c++) mark[c]=0;

        for (int c=0; c<26; c++) {
            if (B[c]==-1 && E[c]!=-1) {
                for (int act=c; E[act]!=-1; act=pociagi[E[act]].front()) {
                    mark[act]=1;
                }
            }
        }

        for (int c=0; c<26; c++) {
            if ((zabron[c] && (jeden[c] || (B[c]!=-1) || (E[c]!=-1)) ) || zabron[c]>1) zle=true;
            if (mark[c]==0 && (B[c]!=-1) && (E[c]!=-1)) zle=true;
        }




        if (zle) {
            printf("Case #%d: 0\n", t);
        }
        else {
            long long res=1;
            int ileP=0;
            for (int c=0; c<26; c++) {
                res=(res*silnia(jeden[c]))%Mod;
                if (jeden[c] && (B[c]==-1) && (E[c]==-1)) ileP++;
                if ((B[c]!=-1) && (E[c]==-1)) ileP++;
            }
            res=(res*silnia(ileP))%Mod;
            printf("Case #%d: %lld\n", t, res);
        }
	}
	return 0;
}

