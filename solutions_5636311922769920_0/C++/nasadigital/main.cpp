#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
    ifstream fin("test.in");
    ofstream fout("sol.out");
    int t,T;
    fin>>t;
    T=t;

    while(t--){
        fout<<"Case #"<<T-t<<": ";
        int k,c,s;
        fin>>k>>c>>s;
        vector<ll> rez;
        int cur=0;
        for(int ctr1=0;ctr1<s;ctr1++){
            if(cur==k)
            break;
            ll my=0;
            for(int ctr2=0;ctr2<c;ctr2++){
                my*=k;
                if(cur<k){
                    my+=cur;
                    cur++;
                }
            }
            rez.push_back(my+1);
        }
        if(cur<k)
        {
            fout<<"IMPOSSIBLE\n";
            continue;
        }
        for(int ctr1=0;ctr1<rez.size();ctr1++)
            fout<<rez[ctr1]<<" ";
        fout<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}

