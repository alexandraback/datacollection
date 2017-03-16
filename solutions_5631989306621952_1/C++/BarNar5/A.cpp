#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int t;
string s, w;

int main() {
    int i, j;
    scanf("%d", &t);
    for (i=0; i<t; ++i) {
        cin>>s;
        w=s[0];
        for (j=1; j<s.length(); ++j) {
            if (s[j] >= w[0]) {
                w=s[j]+w;
            } else {
                w=w+s[j];
            }
        }
        printf("Case #%d: ", i+1);
        cout<<w<<endl;
    }
    return 0;
}
