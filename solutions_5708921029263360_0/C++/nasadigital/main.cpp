#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<string,string> ss;

vector<iii> rez;
vector<int> vek(3),vek2(3);
int times[10][10][3];

bool dfs(int cur){

    if(cur!=3){
        int t=0;
        do{
            vek[cur]=(vek[cur]+1)%vek2[cur];
            t++;
            if(dfs(cur+1))
                return true;
        }
        while (t!=vek2[cur]);
        return false;
    }
    if(times[vek[0]][vek[1]][0] || times[vek[1]][vek[2]][1] || times[vek[0]][vek[2]][2])
        return false;
    times[vek[0]][vek[1]][0]=times[vek[1]][vek[2]][1]=times[vek[0]][vek[2]][2]=1;
    return true;
}


int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int t;
    fin >> t;
    int T=t;

    while(t--)
    {
        rez.clear();
        memset(times,0,sizeof(times));
        fout<<"Case #"<<T-t<<": ";
        for(int ctr1=0;ctr1<3;ctr1++)
            fin>>vek2[ctr1],vek[ctr1]=0;
        int k;
        fin>>k;
        rez.push_back({0,{0,0}});
        times[0][0][0]=times[0][0][1]=times[0][0][2]=1;
        while(dfs(0)){
            rez.push_back({vek[0],{vek[1],vek[2]}});
        }
        if(rez.size()==1 && vek2[2]==1)
            k=1;
        else if (rez.size()==1) {
            fout<<k<<"\n";
            for(int ctr1=0;ctr1<k;ctr1++)
                fout<<"1 1 1"<<"\n";
            continue;
        }
        fout<<rez.size()*k<<"\n";
        for(int ctr1=0;ctr1<k;ctr1++)
        for(int ctr2=0;ctr2<rez.size();ctr2++){
            fout<<rez[ctr2].first+1<<" "<<rez[ctr2].second.first+1<<" "<<rez[ctr2].second.second+1<<"\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}
