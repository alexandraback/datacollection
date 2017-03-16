#include<bits/stdc++.h>
using namespace std;

int a[3000];

int main()
{
    ifstream in ("B-large (1).in");
    ofstream out ("largerank.txt");

    int n,t;
    int x;
    in>>t;

    for(int ts=1;ts<=t;ts++){
        in>>n;
        out<<"Case #"<<ts<<": ";
        for(int i=0;i<2600;i++)
            a[i] = 0;

        for(int i=1;i<2*n;i++){
            for(int j=0;j<n;j++){
                in>>x;
                a[x] = a[x]^1;
            }
        }

        for(int i=0;i<2600;i++){
            if(a[i]==1)
                out<<i<<" ";
        }
        out<<endl;
    }

    return 0;
}
