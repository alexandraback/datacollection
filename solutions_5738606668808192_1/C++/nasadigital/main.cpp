#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<int> primes;

void erasten(){
    int ar[100001];
    memset(ar,0,sizeof(ar));

    for(int ctr1=2;ctr1<317;ctr1++){
        if(!ar[ctr1])
        for(int ctr2=2*ctr1;ctr2<100001;ctr2+=ctr1)
            ar[ctr2]=1;
    }
    for(int ctr1=3;ctr1<100001;ctr1++)
        if(!ar[ctr1])
            primes.push_back(ctr1);

}

int getRandBit(){
    return rand()>(RAND_MAX/2);
}

ll getNum(int n){
    ll num=1;
    for(int ctr1=0;ctr1<n-2;ctr1++)
        num<<=1,num|=getRandBit();
    num<<=1;
    num|=1;
    return num;
}

int findDivisor(ll num,int base,int n){
    for(int ctr1=0;ctr1<primes.size();ctr1++){
        int rem=0;
        ll curBit=1LL<<(n-1);
        while(curBit>0){
            rem*=base;
            rem+=((num&curBit) > 0);
            rem%=primes[ctr1];
            curBit>>=1;
        }
        if(!rem){
            return primes[ctr1];
        }
    }
    return 0;
}

int main()
{
    srand(time(0));
    rand();
    erasten();
    ifstream fin("test.in");
    ofstream fout("sol.out");
    int t,T;
    fin>>t;
    T=t;
    while(t--){
        fout<<"Case #"<<T-t<<":\n";
        int n,j;
        fin>>n>>j;
        set<ll> done;
        while(j){

            ll cur=getNum(n);
            if(done.count(cur))
            continue;
            done.insert(cur);

            vector<int> rez;
            for(int ctr1=2;ctr1<=10;ctr1++){
                rez.push_back(findDivisor(cur,ctr1,n));
                if(!rez[rez.size()-1])
                {
                    rez.resize(0);
                    break;
                }
            }

            if(rez.size()==9)
            {
                j--;
                ll curBit=1LL<<(n-1);
                while(curBit>0){
                    fout<<((cur&curBit) > 0);
                    curBit>>=1;
                }
                fout<<" ";
                for(int ctr1=0;ctr1<rez.size()-1;ctr1++)
                    fout<<rez[ctr1]<<" ";

                fout<<rez[rez.size()-1];
                if(j)
                    fout<<"\n";
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}

