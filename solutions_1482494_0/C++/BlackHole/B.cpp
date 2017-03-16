#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    int T,case_id,N,nummove,finish,mademove,star;

    freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
    cin >> T;
    for (case_id=1;case_id<=T;++case_id) {
        cin >> N;
        int a[N+1],b[N+1],cleared[N+1];
        int longestaway,longestaway_ind;
        nummove=finish=mademove=star=0;
        for (int i=1;i<=N;++i) {
            cin >> a[i] >> b[i];
            cleared[i]=0;
        }
        while (finish==0) {
            mademove=0;
            for (int i=1;i<=N;++i) {
                if (star>=b[i] && cleared[i]<2) {
                    if (cleared[i]==0) {
                        star+=2;
                    } else
                    if (cleared[i]==1) {
                        star+=1;
                    }
                cleared[i]=2;
                ++nummove;
                mademove=1;
                break;
                }
            }
            if (mademove==0) {
                longestaway=-1;longestaway_ind=-1;
                for (int i=1;i<=N;++i) {
                    if (star>=a[i] && cleared[i]==0 && b[i]>longestaway) {
                        longestaway_ind=i;
                        longestaway=b[i];
                    }
                }
                if (longestaway_ind>-1) {
                    cleared[longestaway_ind]=1;
                    star+=1;
                    ++nummove;
                    mademove=1;
                }
            }
            if (mademove==0) {
                finish=2;
                for (int i=1;i<=N;++i) {
                    if (cleared[i]<2) finish=1;
                    break;
                }
            }
        }
        
        if (finish==2) {
            cout << "Case #" << case_id << ": " << nummove << endl;
        } else
        if (finish==1) {
            cout << "Case #" << case_id << ": " << "Too Bad" << endl;
        }
    }
    return 0;
}
