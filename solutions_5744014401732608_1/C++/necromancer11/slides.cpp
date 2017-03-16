#include<bits/stdc++.h>
using namespace std;

long long t,m,n;
long long a[100][100];
long long check()
{
    long long temp = 1;

    for(long long i=1;i<n;i++){
        if(temp>=m)
            return 1;
        temp*=2;
    }

    return 0;
}

void create()
{
    long long temp = 1;

    for(long long i=n-2;i>=0 && temp<=m;i--){
        for(long long j=i+1;j<n;j++){
                a[i][j] = 1;
        }
        temp*=2;
    }

    for(long long i=0;i<n-1;i++){
        if(((n-1-i-1)!= 0) && (m&(1<<i)))
            a[0][n-1-i-1] = 1;
    }
}

int main()
{
    ifstream in ("B-large (2).in");
    ofstream out ("largeslide.txt");

    in>>t;

    for(long long ts=1;ts<=t;ts++){

        memset(a,0,sizeof a);
        in>>n>>m;
        out<<"Case #"<<ts<<": ";
        if(check()){
            out<<"POSSIBLE"<<endl;
            create();

            for(long long i=0;i<n;i++){
                for(long long j=0;j<n;j++)
                    out<<a[i][j];
                out<<endl;
            }
        }
        else{
            out<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
