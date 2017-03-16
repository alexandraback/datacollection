#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
#define mod 1000000007

using namespace std;

int main()
{
    //freopen("B-small-attempt1 (1).in","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,n;
    int te = 1;
    cin >> t;
    while(t--) {
        cin >> n;
        string str[110];
        int arr[110];
        for(int i=0;i<n;i++) cin >> str[i];
        bool fi = 1;
        for(int j=0;j<n;j++) {
            int ma[26];
            for(int i=0;i<26;i++) ma[i] = 0;
            ma[str[j][0]-'a'] = 1;
            int l = str[j].size();
            for(int i=1;i<l;i++) {
                if(str[j][i] != str[j][i-1]) {
                    if(ma[str[j][i]-'a'] == 1) fi = 0;
                    else ma[str[j][i]-'a'] = 1;
                }
            }
            if(fi == 0) break;
        }
        if(fi == 0) {
            int ansi = 0;
            cout << "Case #" << te << ": " << ansi%mod << endl;
            continue;
        }
        long long ax[110];
        int len[110];
        for(int i=0;i<110;i++) ax[i] = 0;
        for(int i=0;i<n;i++) {
            int l = str[i].size();
            len[i] = l;
            for(int j=0;j<l;j++) {
                ax[i] |= (1<<(str[i][j]-'a'));
            }
        }
        for(int i=0;i<n;i++) arr[i] = i;
        long long ansi = 0;
        do {
            bool f = 1;
            long long fff = 0;
            fff |= ax[arr[0]];
            for(int i=1;i<n;i++) {
                if(!(fff&ax[arr[i]] == (1<<(str[arr[i]][0]-'a')) || fff&ax[arr[i]] == 0))  {
                    f = 0;
                    break;
                }
                fff |= ax[arr[i]];
            }
            if(f) {
                for(int i=0;i<n;i++) cout << str[arr[i]];
                cout << endl;
                ansi++;
            }
        }while(next_permutation(arr,arr+n));
        cout << "Case #" << te << ": " << ansi%mod << endl;
        te++;
    }
}
