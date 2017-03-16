#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int n, op, ed, aa[105], naa, cas, md;
const int MOD = 1e9 + 7;
long long jc[105];
vector<string> data;
string t;

bool ised(string a, char c){
    return a[0]==c && a[a.length()-1]!=c;
}

bool isaa(string a, char c){
    for (int i=0;i<a.length();++i) if (a[i]!=c) return false;
    return true;
}

bool isop(string a, char c){
    return a[0]!=c && a[a.length()-1]==c;
}

bool isbad(string a, char c){
    if (a[0]==c && a[a.length()-1]==c && !isaa(a, c)) return true;
    int flag = 0;
    while (flag<a.length() && a[flag]!=c) ++flag;
    if (flag >= a.length()) return false;
    while (flag<a.length() && a[flag]==c) ++flag;
    if (flag >= a.length()) return false;
    for (int i=flag;i<a.length();++i) if (a[i]==c) return true;
    return false;
}

bool ismd(string a, char c){
    int l=0, r=a.length()-1;
    while (l<a.length() && a[l]==c) ++l;
    while (r>=0 && a[r]==c) --r;
    if (r<l) return false;
    for (int i=l;i<=r;++i){
        if (a[i] == c) return true;
    }
    return false;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    jc[0] = jc[1] = 1;
    for (int i=2;i<=101;++i){
        jc[i] = jc[i-1]*i;
        jc[i] %= MOD;
    }
    cin>>T;
    while (T--){
        cin>>n;
        data.clear();
        long long ans = 1;
        for (int i=0;i<n;++i){
            cin>>t;
            data.push_back(t);
        }
        cout<<"Case #"<<++cas<<": ";
        bool noans = false;
        for (char c='a';c<='z';++c){
            op = -1;
            ed = -1;
            md = 0;
            naa = 0;
            for (int i=0;i<n;++i){
                if (isop(data[i], c)){
                    if (op!=-1){
                        //puts("1");
                        noans = true;
                        break;
                    }
                    op = i;
                }
                if (ised(data[i], c)){
                    if (ed!=-1){
                        //puts("2");
                        noans = true;
                        break;
                    }
                    ed = i;
                }
                if (isbad(data[i], c)){
                    //puts("3");
                    noans = true;
                    break;
                }
                if (ismd(data[i], c)){
                    md++;
                    //cout<<"HERE"<<data[i]<<endl;
                    if (md>1){
                        //puts("4");
                        noans = true;
                        break;
                    }
                }
                if (isaa(data[i], c)){
                    aa[naa++] = i;
                }
            }
            if (noans) break;
            bool liu = false;
            if (md && (op!=-1 || naa!=0 || ed!=-1)){
                //printf("%c : md = %d, op = %d, naa=%d, ed=%d\n", c, md, op, naa, ed);
                noans = true;break;
            }
            int dflag = 100000;
            if (op!=-1 && ed!=-1){
                data[op] += data[ed];
                data.erase(data.begin() + ed);
                dflag = ed;
                n--;
            }
            else{
                if (md==0 && (op==-1 && ed==-1)) liu = true;
            }
            for (int i=naa-1;i>=0;--i){
                if (liu && i==naa-1) continue;
                if (aa[i] > dflag) data.erase(data.begin() + aa[i] - 1);
                else data.erase(data.begin() + aa[i]);
                n--;
            }
            //printf("naa = %d\n", naa);
            ans *= jc[naa];
            ans %= MOD;
        }
        //printf("N = %d\n", n);
        //for (int i=0;i<n;++i) cout<<data[i]<<endl;
        ans *= jc[n];
        ans %= MOD;
        if (noans){
            cout<<0<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}
