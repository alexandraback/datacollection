#include<bits/stdc++.h>
using namespace std;

int main() {

    ifstream file("A-large.in");
    ofstream file2("A-large.out");
    int test;
    file>>test;
    for (int t=1; t<=test; t++) {

        int s, ans=0, tot=0;
        char arr[10000];
        file>>s>>arr;

        tot += arr[0] - '0';

        for (int i=1; i<=s; i++) {
            //cout<<ans<<endl;
            if (arr[i] == '0') continue;
            else {
                if (i > tot) {
                    ans += (i-tot);
                    tot += (i-tot);
                }
                tot += arr[i] - '0';
            }
        }

        file2<<"Case #"<<t<<": "<<ans<<endl;

    }
    return 0;
}
