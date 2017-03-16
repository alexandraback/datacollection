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
int A[1010],B[1010];
int U1[1010],U2[1010];
int T,N;

int main()
{

    int cur,cl,res;

    ifstream cin("B-large.in");
    ofstream cout("output.txt");

    cin>>T;


    for(int ts=1;ts<=T;ts++){
        cin>>N;

        for(int i=1;i<=N;i++)cin>>A[i]>>B[i];

        cur=cl=res=0;
        memset(U1,0,sizeof(U1));
        memset(U2,0,sizeof(U2));

        while(cl<N){

            int idx=0;
            for(int i=1;i<=N;i++)if(B[i]<=cur&&(!U2[i]))idx=i;

            if(idx){
                if(U1[idx]){U2[idx]=1;cur++;}
                else{
                    U1[idx]=U2[idx]=1; cur+=2;
                }
                res++; cl++;
            }
            else{
                idx=0; B[idx]=-inf;
                for(int i=1;i<=N;i++)
                    if(A[i]<=cur&&(!U1[i])){
                        if(B[i]>B[idx])idx=i;
                    }
                if(idx){
                    U1[idx]=1; cur++; res++;
                }
                else break;
            }

        }

        cout<<"Case #"<<ts<<": ";
        if(cl==N)cout<<res<<endl;
        else cout<<"Too Bad"<<endl;

    }

    cout.close(); cin.close();


    return 0;
}
