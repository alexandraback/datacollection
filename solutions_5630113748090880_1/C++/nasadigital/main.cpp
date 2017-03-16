#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int t;
    fin >> t;
    int T=t;
    int ar[2501];
    while(t--){
        fout<<"Case #"<<T-t<<": ";
        int n;
        fin>>n;
        memset(ar,0,sizeof(ar));
        vector<int> rez;

        int temp;
        for(int ctr1=0;ctr1<2*n-1;ctr1++){
            for(int ctr2=0;ctr2<n;ctr2++){
                fin>>temp;
                ar[temp]++;
            }
        }
        for(int ctr1=1;ctr1<2501;ctr1++)
            if(ar[ctr1]&1)
                rez.push_back(ctr1);
        sort(rez.begin(),rez.end());
        for(int ctr1=0;ctr1<rez.size();ctr1++)
            fout<<rez[ctr1]<<" ";
        fout<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}
