#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <limits>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;
#define pb push_back

#include <fstream>
ifstream fin("input.txt");
ofstream fout("output.txt");
#define MAXN 130000
long long T,N,R;
string S,F;

int molt[4][4]={
{0,1,2,3},
{1,0,3,2},
{2,3,0,1},
{3,2,1,0},
};

int segno[4][4]={
{1,1,1,1},
{1,-1,1,-1},
{1,-1,-1,1},
{1,1,-1,-1},
};

int corrisp[300];
int pre[MAXN],pres[MAXN];

int main()
{
    corrisp['i']=1;
    corrisp['j']=2;
    corrisp['k']=3;
    fin>>T;
    //cerr<<T<<endl;
    for(int t=1;t<=T;++t)
    {
        fin>>N>>R;
        if(R%4==0) R=min(R,12LL);
        else R=min(R,8+R%4);
        fin>>S;
        F="";
        for(int i=0;i<R;++i) F+=S;
        bool trovatoi=false,trovatok=false;
        for(int i=0;i<F.size();++i)
        {
            pre[i]=molt[(i==0 ? 0 : pre[i-1])][corrisp[F[i]]];
            pres[i]=(i==0 ? 1:pres[i-1]) * segno[(i==0 ? 0 : pre[i-1])][corrisp[F[i]]];
            if(pre[i]==1 && pres[i]==1) trovatoi=true;
            if(trovatoi && pre[i]==3 && pres[i]==1) trovatok=true;
        }

        if(trovatoi && trovatok && pre[F.size()-1]==0 && pres[F.size()-1]==-1) fout<<"Case #"<<t<<": YES"<<endl;
        else fout<<"Case #"<<t<<": NO"<<endl;
    }
}
