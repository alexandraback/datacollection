#include    <iostream>
#include    <cstdio>
#include    <cstdlib>
#include    <cstring>
#include    <cmath>
#include    <algorithm>
#include    <vector>
#include    <list>
#include    <queue>
#include    <stack>
#include    <map>
#include    <set>
#include    <utility>
#include    <climits>
#include    <cfloat>
#include    <cassert>
#define     read(n)         scanf("%d",&n)
#define     read2(n,m)      scanf("%d%d",&n,&m)
#define     read3(n,m,l)    scanf("%d%d%d",&n,&m,&l)
#define     readull(n)      scanf("%llu",&n)
#define     readll(n)       scanf("%lld",&n)
#define     init(mem)       memset(mem,0,sizeof(mem))
#define     ull             unsigned long long int
#define     ll              long long int
#define     vi              vector<int>
#define     vs              vector<string>
using namespace std;
//std::cout.sync_with_stdio(false);

bool conso(char c){
    return !(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main(){
    int t;
    cin>>t;
    string name;
    int n;
    int mem[1000000];
    for(int ii=1;ii<=t;ii++){
        cin>>name>>n;

        int cnt=0;
        for(int i=0;i<name.length();i++){
            for(int j=i;j<name.length();j++){
                int maxm;
                mem[i]=conso(name[i]);
                maxm=mem[i];
                for(int k=i+1;k<=j;k++){
                    if(conso(name[k])){
                        mem[k]=mem[k-1]+1;
                        maxm=max(maxm,mem[k]);
                    }
                    else{
                        mem[k]=0;
                    }
                }
                if(maxm>=n) cnt++;
            }
        }
        printf("Case #%d: %d\n",ii,cnt);
    }
    return 0;
}
