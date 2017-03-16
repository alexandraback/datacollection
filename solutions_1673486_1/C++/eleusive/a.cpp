#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAX 100000

int a,b;
double prob[MAX];

double probwrong(int bound) {
    double correct=1;
    for(int i=0;i<bound;i++) correct*=prob[i];
    return 1-correct;
}

double solve1() {
    double pwrong=probwrong(a);
    //one was wrong
    double val1=(pwrong)*(2*b+2-a);
    //all were right
    double val2=(1-pwrong)*(b+1-a);
    return val1+val2;
}

double solve2() {
    double ret=1000000000.0;
    for(int i=0;i<a;i++) {
        double pwrong=probwrong(i);
        //one was wrong
        double val1=(pwrong)*(a-i+2*b+2-i);
        //all were right
        double val2=(1-pwrong)*(a-i+b+1-i);
        double val=val1+val2;
        ret=min(ret,val);
    }
    return ret;
}

double solve3() {
    return 2+b;
}

void solve() {
    cin>>a>>b;
    for(int i=0;i<a;i++) cin>>prob[i];
    double val1=solve1();
    double val2=solve2();
    double val3=solve3();
    double ans=min(val1,min(val2,val3));
    cout.setf(ios::fixed);
    cout<<setprecision(6)<<ans<<endl;
}

int main() {
    int cases;
    cin>>cases;
    for(int i=1;i<=cases;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
