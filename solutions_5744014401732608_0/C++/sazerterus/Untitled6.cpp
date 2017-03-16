#include <bits/stdc++.h>

using namespace std;
int tempo[55][55];
int main(){
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);


    int t;
    cin >> t;
    int index=1;
    while(t--){
        long long int b,m;
        cin >> b >> m;
        long long int q=m;
        long long int temp=1ll << (b-2);
        if(temp<m){
            cout << "Case #" << index++ << ": IMPOSSIBLE" << endl;
           // cout << b << " " << m << endl;
            continue;
        }

            for(int i=0;i<55;++i)
                for(int j=0;j<55;++j)
                    tempo[i][j]=0;
            for(int i=1;i<b;++i){
                for(int j=i+1;j<b;++j)
                    tempo[i][j]=1;
                }
            vector<int> V;
            for(int i=b-3;i>=0;--i){
                if(m & (1ll << i)){
                    V.push_back(i+2);
                    m-=(1ll << i);
                }
            }
            if(m>0){
                for(int i=1;i<b;++i)
                    tempo[i][b]=1;
            }
            else
            for(int i=0;i<V.size();++i){
                tempo[V[i]][b]=1;
            }

             cout << "Case #" << index++ << ": POSSIBLE" << endl;
           // cout << b << " " << q << endl;
             for(int i=1;i<=b;++i)
                tempo[i][i]=0;
            for(int i=1;i<=b;++i){
            for(int j=1;j<=b;++j)
                cout << tempo[i][j];
                cout << endl;
                }



    }

    return 0;
}
