#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#include <cmath>
#include <iomanip>
#include <conio.h>
#define _USE_MATH_DEFINES

using namespace std;
long double c,k,f,x,s,res;
void process(){
    s=2; k=0;
    while (true){
        res=k+(x/s);
        if(res<=(k+(c/s)+(x/(s+f)))) break;
        k=k+(c/s);
        s=s+f;
    }
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int test,ntest;
    //ios::sync_with_stdio(false);
    cin>>ntest;
    cout.setf(ios::fixed, ios::floatfield);cout.precision(7);
    for (test=1;(test <= ntest);test++)
    {
        cin>>c>>f>>x;
        if (test>1) cout<<"\n";
        process();
        cout<<"Case #"<<test<<": "<<res;
    }
    fclose(stdin);      fclose(stdout);
    return 0;
}
