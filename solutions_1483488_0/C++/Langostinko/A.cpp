#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <set>

using namespace std;

int t,a,b,ans;
char used[3000000];

int main(){
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

    cin >> t;
    for (int i=0; i<t; i++){
        ans = 0;
        cout << "Case #" << i+1 << ": ";
        cin >> a >> b;
        for (int j=a; j<=b; j++){
            int len = 0, cur=j, dec=1, adec=1;
            while (cur){
                len++;
                cur/=10;
                adec*=10;
            }
            for (int k=1; k<len; k++){
                dec*=10;
                adec/=10;
                cur = (j%dec)*adec + j/dec;
                if ((j%dec)>=dec/10 && (cur>=a&&cur<=b&&cur!=j) && !used[cur]){
                    used[cur] = 1;
                    ans++;
                }
            }

            len = 0, cur=j, dec=1, adec=1;
            while (cur){
                len++;
                cur/=10;
                adec*=10;
            }
            for (int k=1; k<len; k++){
                dec*=10;
                adec/=10;
                cur = (j%dec)*adec + j/dec;
                used[cur] = 0;
            }
        }
        cout << ans/2 << endl;
    }

    return 0;
}
