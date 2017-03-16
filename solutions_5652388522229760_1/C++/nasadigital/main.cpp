#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

bool check(int * ar){
    for(int ctr1=0;ctr1<10;ctr1++)
        if(!ar[ctr1])
            return true;
    return false;
}

ll findLast(ll st){
    int ar[10]={0};
    ll ctr1;
    for(ctr1=0;check(ar);){
        ctr1+=st;
        ll temp=ctr1;
        while(temp>0)
            ar[temp%10]++,temp/=10;
    }
    return ctr1;
}

int main()
{
    ifstream fin("test.in");
    ofstream fout("sol.out");
    int t,T;
    fin>>t;
    T=t;
    while(t--){
        fout<<"Case #"<<T-t<<": ";
        ll n;
        fin>>n;
        if(n==0){
            fout<<"INSOMNIA\n";
            continue;
        }
        fout<<findLast(n)<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}
