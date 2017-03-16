#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>

#define epsilon 0.000000001

using namespace std;

int T;
vector<double> results;

int main(){
    cin>>T;
    for(int t=1;t<=T;t++){
        double C,F,X;
        cin>>C>>F>>X;
        double curTime=0.0;
        double cookieRate = 2.0;
        while(true){
            //when doing nothing:
            double remainingTimeDoNothing = X/cookieRate;
            //when Buying more:
            double remainingTimeBuyMore=C/cookieRate;
            remainingTimeBuyMore+=X/(cookieRate+F);
            if(remainingTimeBuyMore>remainingTimeDoNothing){
                curTime+=remainingTimeDoNothing;
                break;
            }
            //buy one more:
            curTime+=C/cookieRate;
            cookieRate+=F;
        }
        results.push_back(curTime);
    }
    fixed(cout);
    cout.precision(7);
    int t=0;
    for(double result : results){
        t++;
        cout<<"Case #"<<t<<": "<<result<<endl;
    }
    return 0;
}