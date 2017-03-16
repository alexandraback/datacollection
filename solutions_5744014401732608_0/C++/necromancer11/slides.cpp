#include<bits/stdc++.h>
using namespace std;

int t,m,n;
int a[100][100];
int check()
{
    int temp = 1;

    for(int i=1;i<n;i++){
        if(temp>=m)
            return 1;
        temp*=2;
    }

    return 0;
}

void create()
{
    int temp = 1;

    for(int i=n-2;i>=0 && temp<=m;i--){
        for(int j=i+1;j<n;j++){
                a[i][j] = 1;
        }
        temp*=2;
    }

    for(int i=0;i<n-1;i++){
        if(((n-1-i-1)!= 0) && (m&(1<<i)))
            a[0][n-1-i-1] = 1;
    }
}

int main()
{
    ifstream in ("B-small-attempt2.in");
    ofstream out ("smallslide.txt");

    in>>t;

    for(int ts=1;ts<=t;ts++){

        memset(a,0,sizeof a);
        in>>n>>m;
        out<<"Case #"<<ts<<": ";
        if(check()){
            out<<"POSSIBLE"<<endl;
            create();

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
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
