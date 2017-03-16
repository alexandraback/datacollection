#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <math.h>

using namespace std;

int main()
{
    int tests;
    cin >> tests;
    for(int i=1;i<=tests;i++){
        int cc, accCount;
        double D, time, startTime, finishTime;
        double tCo[2100];
        double pCo[2100];
        double acc[250];
        cin >> D >> cc >> accCount;
        for(int j=0;j<cc;j++){
            cin >> tCo[j] >> pCo[j];
        }
        tCo[cc-1]=tCo[cc-2]+(D-pCo[cc-2])*(tCo[cc-1]-tCo[cc-2])/(pCo[cc-1]-pCo[cc-2]);
        pCo[cc-1]=D;
        for(int j=0;j<accCount;j++){
            cin >> acc[j];
        }
        cout << "Case #"<<i<<":"<<endl;
        for(int j=0;j<accCount;j++){
            double accel=acc[j];
            double minTime=10000000;
            for(int k=0;k<cc;k++){
                time=sqrt(2*pCo[k]/accel);
                startTime=max(0.0,tCo[k]-time);
                for (int m=0;m<cc;m++){
                    if(tCo[m]<startTime){
                        continue;
                    }
                    double tst = (tCo[m]-startTime)*(tCo[m]-startTime)*0.5*accel;
                    if(tst>pCo[m]+0.00000001){
                       goto superBreak;
                    }
                }
                finishTime=sqrt(2*D/accel)+startTime;
                if(finishTime<minTime){
                    minTime=finishTime;
                }
                superBreak:
                ;
            }
            cout.precision(10);
            cout << minTime << endl;

        }



    }
    return 0;
}
