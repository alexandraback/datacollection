#include <iostream>
#include <cstdio>
using namespace std;

int A,B,K;
int _;
int main(){
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    cin >> _;
    int cas=0;
    while(_--){
        cin >> A >> B >> K;
        int cnt = 0;
        for (int i=0;i<A;i++)
            for (int j=0;j<B;j++)
                if ((i&j)<K){
                    //cout << i << " " << j << " " << (i&j) << endl;
                    cnt++;
                }
        printf("Case #%d: %d\n",++cas,cnt);
    }
}
