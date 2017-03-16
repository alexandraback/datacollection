#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n,s,p;

bool possible(int total, bool cansurprise) {
    for(int a=0;a<=10;a++)
        for(int b=0;b<=10&&a+b<=total;b++) if(max(a,b)-min(a,b)<3)
            for(int c=0;c<=10&&a+b+c<=total;c++) {
                int big=max(a,max(b,c));
                int small=min(a,min(b,c));
                if((big-small>2)||(big-small==2&&!cansurprise)) continue;
                if(big>=p) return true;
            }
    return false;
}

int solve() {
    cin>>n>>s>>p;
    int total;
    int ret=0;
    for(int i=0;i<n;i++) {
        cin>>total;
        if(possible(total,false)) {
            ret++;
        } else if(s&&possible(total,true)) {
            ret++;
            s--;
        }
    }
    return ret;
}

int main() {
    int cases;
    cin>>cases;
    for(int cnum=1;cnum<=cases;cnum++) {
        cout<<"Case #"<<cnum<<": "<<solve()<<endl;
    }
}
