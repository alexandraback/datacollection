#include <iostream>
#include <stack>
#include <fstream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <string>
#include <cstring>
using namespace std;
typedef pair<int, int> pie;
#define L first
#define R second
#define MP make_pair
#define PB push_back

int chk(int X){
    if(X == 1)
        return true;
    if(X % 2 == 1)
        return false;
    return chk(X / 2);
}

long long get(long long P, long long Q){
    if(P >= Q/2)
        return 1;
    return get(P * 2, Q) + 1;
}

main()
{
    ios_base::sync_with_stdio(false);
    long long T;
    ifstream cin("A-small-attempt1.in");
    ofstream cout("ot.txt");
    cin>>T;
    long long counter = 1;
    while(T--){
        long long P = 0, Q = 0, gc, pos;
        string s;
        cin>>s;
        for(long long i=0;i<s.size();i++)
            if(s[i] == '/')
                pos = i;
        for(long long i=0;i<pos;i++){
            P *= 10;
            P += s[i] - '0';
        }
        for(long long i=pos + 1;i<s.size();i++){
            Q *= 10;
            Q += s[i] - '0';
        }
        gc = __gcd(P, Q);
        P /= gc, Q /= gc;
        cout<<"Case #"<<counter<<": ";
        counter++;
        if(!chk(Q))
            cout<<"impossible"<<endl;
        else
            cout<<get(P, Q)<<endl;
    }
}
