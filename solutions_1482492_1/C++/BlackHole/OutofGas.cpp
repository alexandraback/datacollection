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
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
    int T,case_id,N,A,i,j;
    long double D;
    cin >> T;
    cout << fixed << setprecision (7);
    for (case_id=1; case_id<=T; ++case_id) {
        cout << "Case #" << case_id << ":\n";
        cin >> D >> N >> A;
        long double t[N+1],x[N+1],acc[A+1],tNow,xNow,vNow,tNext,xNext,dProj,dt,dtProj;
        for (i=1;i<=N;++i) 
            cin >> t[i] >> x[i];
        t[0]=x[0]=0;
        for (i=1;i<=A;++i) {
            cin >> acc[i];
            tNow=xNow=vNow=0;
            if (x[1]>D) goto output;
            for (j=1;j<=N;++j) {
                tNext=t[j];xNext=x[j];
                if (xNext>D) {
                    tNext=t[j-1]+(tNext-t[j-1])*(D-x[j-1])/(xNext-x[j-1]);
                    xNext=D;
                }
                //cout << "tNext:" << tNext << endl;
                dProj=vNow*(tNext-tNow)+0.5*acc[i]*(tNext-tNow)*(tNext-tNow);
                dtProj=(-vNow+sqrt(vNow*vNow+2*acc[i]*(xNext-xNow)))/acc[i];
                //cout << dProj << " " << dtProj<< endl;
                if (xNow+dProj<xNext) { //tNow+dtProj>tNext
                    //cout << "1\n";
                    vNow=vNow+(tNext-tNow)*acc[i];
                    tNow=tNext;
                    xNow=xNow+dProj;
                } else {
                    //dt=(-vNow+sqrt(vNow*vNow+2*acc[i]*(xNext-xNow)))/acc[i];
                    //cout << "2\n";
                    vNow=vNow+acc[i]*dtProj;
                    tNow=tNext;
                    xNow=xNext;
                }
                //cout << vNow << " " << tNow << " " << xNow << " " << endl;
                if (xNow>=D-0.0000001) goto output;
            }
output:     if (xNow<D) {
                dt=(-vNow+sqrt(vNow*vNow+2*acc[i]*(D-xNow)))/acc[i];
                tNow+=dt;
            }
            cout << tNow << endl;
        }
    }
    return 0;
}
