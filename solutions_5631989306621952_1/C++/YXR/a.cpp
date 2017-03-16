#include <iostream>
#include <cstdio>
using namespace std;

struct A{
    char c;
    int p;
}a[2000];

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    cin >> T;
    int t = 1;
    for (int t = 1;t<=T;t++){
        string s;
        cin >> s;
        int m = s.size();
        for (int i = 1; i<=m; i++){
            a[i].c = s[i-1];
            a[i].p = i-1;
        }
        for (int i = 1; i <= m; i++){
            for (int j = i+1; j <= m; j++){
                if (a[j].c > a[i].c || (a[j].c == a[i].c && a[j].p > a[i].p)){
                    swap(a[i],a[j]);
                }
            }
        }
        string ansl = "";
        string ansr = "";
        int la = m;
        for (int i = 1; i <= m; i++){
            if (a[i].p < la){
                ansl = ansl + a[i].c;
                for (int j = la -1 ;j > a[i].p;j--)
                    ansr = s[j] + ansr;
                la = a[i].p;
            }
        }
        ansl = ansl + ansr;
        printf("Case #%d: ",t);
        cout << ansl << endl;
    }
}