#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <valarray>
#include <ctime>
#include <set>
#include <sstream>
#include <stdarg.h>
#include <fstream>

using namespace std;

long long get(int pw) {
    int part1=(pw+1)/2;
    int part2=pw-part1;
    long long res=pow(10.,(double)part1)-1;
    res+=pow(10.,(double)part2);
    return res;
}

long long get2(long long curnum) {
    string s="";
    long long curcopy=curnum;
    while (curcopy>0) {
        int k=curcopy%10;
        char c='0'+k;
        s+=c;
        curcopy/=10;
    }
    long long curx = pow(10.,(double)(s.size()-1));
    long long curres=curnum-curx;
    long long currev=atol(s.c_str());
    int var1=s.size()/2;
    long long res1 = 0;
    long long firstPart1 = currev%((long long)(pow(10.,(double)var1)));
    long long secondPart1 = curnum%((long long)(pow(10.,(double)(s.size()-var1))));
    if (secondPart1 == 0) {
        firstPart1 = curnum/((long long)(pow(10.,(double)(s.size()-var1))));
        firstPart1--;
        string ss="";
        while (firstPart1>0) {
            ss+=('0'+firstPart1%10);
            firstPart1/=10;
        }
        firstPart1=atol(ss.c_str());
        secondPart1 = pow(10.,(double)(s.size()-var1));
        res1=firstPart1 + secondPart1;
    } else {
        res1=firstPart1 + secondPart1;
    }
    int var2=(s.size()-1)/2;
    long long res2 = 0;
    long long firstPart2 = currev%((long long)(pow(10.,(double)var2)));
    long long secondPart2 = curnum%((long long)(pow(10.,(double)(s.size()-var2))));
    if (secondPart2 == 0) {
        firstPart2 = curnum/((long long)(pow(10.,(double)(s.size()-var2))));
        firstPart2--;
        string ss="";
        while (firstPart2>0) {
            ss+=('0'+firstPart2%10);
            firstPart2/=10;
        }
        firstPart2=atol(ss.c_str());
        secondPart2 = pow(10.,(double)(s.size()-var2));
        res2=firstPart2 + secondPart2;
    } else {
        res2=firstPart2 + secondPart2;
    }
    return min(min(curres,res1),res2);
}

void solve(int t) {
    long long x;
    cin>>x;
    if (x<20) {
        printf("Case #%d: ",t);
        cout<<x<<endl;
        return;
    }
    int cnt=1;
    long long tt=10;
    while (tt<=x) {
        tt*=10;
        cnt++;
    }
    if (tt>x) {
        tt/=10;
        cnt--;
    }
    long long now=10;
    for (int k=2;k<=cnt;k++) {
        now+=get(k);
    }
    now+=get2(x);
    printf("Case #%d: ",t);
    cout<<now<<endl;
}

int main() {
    freopen("in.in","r",stdin);    
    freopen("out.out","w",stdout);    
    int T;
    cin>>T;
    for (int i=0;i<T;i++)
        solve(i+1);
    return 0;
}