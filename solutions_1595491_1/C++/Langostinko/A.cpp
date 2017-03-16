#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <set>

using namespace std;

int t,n,s,p;
int a[200],b[200],c[200];

int main(){
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

    cin >> t;
    for (int i=0; i<t; i++){
        int ans = 0;
        cout << "Case #" << i+1 << ": ";
        cin >> n >> s >> p;
        for (int j=0; j<n; j++){
            cin >> a[j];
            if (a[j]%3==0){
                b[j] = a[j]/3;
                c[j] = a[j]/3 + 1;
                if (a[j]==0){
                    b[j] = 0;
                    c[j] = -1;
                }
            } else if (a[j]%3==1){
                b[j] = a[j]/3 + 1;
                c[j] = a[j]/3 + 1;
                if (a[j]==1){
                    b[j] = 1;
                    c[j] = -1;
                }
            } else {
                b[j] = a[j]/3 + 1;
                c[j] = a[j]/3 + 2;
            }

            if (b[j]>=p)
                ans++;
            else if (c[j]>=p && s>0){
                ans++;
                s--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
