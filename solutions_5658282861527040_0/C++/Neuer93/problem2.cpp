#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int t,n,m,ans,k;
string a[101];
int b[101];
int d[101][101];
string pattern;

int main(){
    cin>>t;
    for (int ii = 0; ii < t; ++ii){
        cin>>n>>m>>k;
        ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if ((i & j) < k)
                {
                    ++ans;
                }
        int tmp = (m>n)?(m):(n);
        cout<<"Case #"<<ii+1<<": ";
        cout<<ans<<endl;
    }
}

