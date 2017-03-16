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
    while(t--){
        fout<<"Case #"<<T-t<<": ";
        int n;
        fin >> n;
        int ar[n],isBFF[n],lngstCh[n];
        memset(isBFF,0,sizeof(isBFF));
        memset(lngstCh,0,sizeof(lngstCh));
        for(int ctr1=0;ctr1<n;ctr1++){
            int temp;
            fin >> temp;
            ar[ctr1]=temp-1;
            isBFF[temp-1]++;
        }
        queue<int> bfs;
        for(int ctr1=0;ctr1<n;ctr1++)
            if(!isBFF[ctr1])
                bfs.push(ctr1);
        while(!bfs.empty()){
            int next=bfs.front();
            bfs.pop();
            lngstCh[ar[next]]=max(lngstCh[ar[next]],1+lngstCh[next]);
            if(!(--isBFF[ar[next]]))
                bfs.push(ar[next]);
        }
        int rez=0;
        int sum=0;
        for(int ctr1=0;ctr1<n;ctr1++){
            int cur=ar[ctr1];
            for(int ctr2=1;ctr2<n+1;ctr2++){
                if(cur==ctr1){
                    rez=max(rez,ctr2);
                    if(ctr2==2 && ctr1<ar[ctr1]){
                        sum+=lngstCh[ctr1]+lngstCh[ar[ctr1]]+2;
                    }
                    break;
                }
                cur=ar[cur];
            }
        }
        fout << max(rez,sum) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
