#include <bits/stdc++.h>

using namespace std;
map <int, int> mp;
vector <int> v;
int main()
{
    int t, cases = 1, n, temp;
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        mp.clear();
        v.clear();
        scanf("%d", &n);
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &temp);
                mp[temp]++;
            }
        }
        for(map<int, int>::iterator it=mp.begin();it!=mp.end();it++){
            if((it->second)%2)v.push_back(it->first);
        }
        sort(v.begin(), v.end());
        printf("Case #%d:", cases++);
        for(int i=0;i<v.size();i++){
            printf(" %d", v[i]);
        }
        cout<<"\n";
    }
    return 0;
}
