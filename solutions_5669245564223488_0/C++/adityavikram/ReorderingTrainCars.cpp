#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <time.h>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define PII pair<int,int>
#define MP make_pair
#define X first
#define Y second
//#define LL long long

const long long MOD = 1000000007LL;

bool aleq(string& s){
    int i,sz= s.size();
    for (i=0; i<sz; i++) {
        if (s[i]!=s[0]) {
            return false;
        }
    }
    return true;
    
}

long long fact(long long acc,int n){
    long long ans = acc;
    for (int i=1; i<=n; i++) {
        ans = (ans*i)%MOD;
    }
    return ans;
    
}

string compress(string &str){
    string ret = "";
    ret += str[0];
    for (int i = 1; i<str.size(); i++) {
        if (str[i]!=str[i-1]) {
            ret+=str[i];
        }
    }
    return ret;
    
}

int main()
{
    int T;
    cin>>T;
    int arr[50];
    for (int i=1; i<=T; i++) {
        memset(arr,0,sizeof(arr));
        int j,N,k,p,ex;
        cin>>N;
        long long ans = 1;
        vector<string> vs;
        string str;
        int sz;
        bool poss = true;
        for (j=0; j<N; j++) {
            cin>>str;
            if (aleq(str)) {
                arr[str[0]-'a']++;
            }
            else{
                vs.push_back(compress(str));
            }
        }
        for (j=0; j<26; j++) {
            if (arr[j]>0) {
                ans = fact(ans,arr[j]);
                string tstr = "";
                tstr += 'a'+j;
                vs.push_back(tstr);
            }
        }
        sz = vs.size();
        
        for (j=0; j<sz; j++) {
            set<char> sc = set<char>();
            for (k=1; k<(vs[j].size()-1); k++) {
                sc.insert(vs[j][k]);
            }
            for (p=0; p<sz; p++) {
                if (p!=j) {
                    for (k=0; k<vs[p].size(); k++) {
                        if(sc.count(vs[p][k])!=0){
                            poss = false;
                            ans = 0;
                            break;
                        }
                    }
                }
                if (!poss) {
                    break;
                }
            }
            if (!poss) {
                break;
            }
        }
        if (poss) {
            //vector<string> vn;
            sort(vs.begin(),vs.end());
            sz = vs.size();
            vector<bool> used(sz,false);
            int cm = 0,ind;
            ex = sz;
            for (j=0;j<sz; j++) {
                cm = 0;
                ind = -1;
                if (!used[j]) {
                    for (k=0; k<sz; k++) {
                        if ((j!=k)&&!used[k]) {
                            if (vs[j].back()==vs[k][0]) {
                                cm++;
                                ind = k;
                            }
                        }
                    }
                }
                if (cm>1) {
                    poss = false;
                    ans = 0;
                    break;
                }
                else if(cm == 1){
                    ex--;
                    used[j] = true;
                }
                
            }
        }
        if (poss) {
            ans = fact(ans,ex);
        }
        
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}