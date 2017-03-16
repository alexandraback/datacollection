#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#define TASKNAME "A"
int n;
int kq;
string s[111];
vector<int> dem[111];
int read(){
    cin>>n;
    for (int i=0;i<n;i++) cin>>s[i];
    return 0;
}
int process(){
    for (int i=0;i<n;i++) dem[i].clear();
    string pattern;
    pattern.clear();
    for (int i=0;i<s[0].length();i++){
        if (pattern.empty() || pattern[pattern.length()-1]!=s[0][i]) {
            pattern.push_back(s[0][i]);
            dem[0].push_back(1);
        } else dem[0].back()++;
    }
    for (int i=1;i<n;i++){
        int k=0;
        string tam;
        tam.clear();
        for (int j=0;j<s[i].length();j++){
            if (tam.empty() || tam[tam.length()-1]!=s[i][j]) {
                tam.push_back(s[i][j]);
                dem[i].push_back(1);
            } else dem[i].back()++;
        }
        if (tam!=pattern) {
            cout<<"Fegla Won";
            return 0;
        }
    }
    //
    kq=0;
    int k=dem[0].size();
    for (int j=0;j<k;j++){
        vector<int> tam;
        tam.clear();
        for (int i=0;i<n;i++){
            tam.push_back(dem[i][j]);
        }
        sort(tam.begin(),tam.end());
        int mid=tam[(tam.size()+1)/2-1];
        for (int i=0;i<n;i++){
            kq+=abs(mid-dem[i][j]);
        }
    }
    cout<<kq;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen(TASKNAME".inp","r",stdin);
    freopen(TASKNAME".out","w",stdout);
    #endif // ONLINE_JUDGE
    int sotest;
    scanf("%d",&sotest);
    // sotest=1;
    for (int test=1;test<=sotest;test++){
        printf("Case #%d: ",test);
        read();
        process();
        printf("\n");
    }

    return 0;
}
