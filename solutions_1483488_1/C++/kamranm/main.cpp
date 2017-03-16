#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:16777216")
#define inf 1000000000
#define MP make_pair
#define PI acos(-1.0)
#define eps 1e-9
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
map<int,bool> hm;

inline bool bet(int num,int a,int b){
    return (num>a&&num<=b);
}

int main()
{
    int T,A,B,num,ans,mq;

    ifstream cin("C-large.in");
    ofstream cout("outputb.txt");

    cin>>T;

    for(int ts=1;ts<=T;ts++){
        cin>>A>>B;

        mq=1; num=A;
        while(num){num/=10;mq*=10;}
        mq/=10;

        ans=0;

        for(int i=A;i<=B;i++){
            hm.clear();
            for(int q=10,pq=mq;pq>1;q*=10,pq/=10)
                if(bet((i%q)*pq+(i/q),i,B))hm[(i%q)*pq+(i/q)]=true;
            ans+=hm.size();
        }
        cout<<"Case #"<<ts<<": "<<ans<<endl;
    }
    cin.close(); cout.close();
    return 0;
}
