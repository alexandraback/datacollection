#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string, map<string, string> >mp;

string mul(string& a, string& b) {
    return mp[a][b];
}

string mul(string& a, char& b) {
    string t = "";
    t += b;
    return mul(a, t); 
}
string mul(char& a, string& b) {
    string t = "";
    t += a;
    return mul(t, b); 
}


int main() {
    mp["1"]["1"] = "1";
    mp["1"]["i"] = "i";
    mp["1"]["j"] = "j";
    mp["1"]["k"] = "k";
    mp["1"]["-1"] = "-1";
    
    mp["1"]["-1"] = "-1";
    mp["1"]["-i"] = "-i";
    mp["1"]["-j"] = "-j";
    mp["1"]["-k"] = "-k";
    mp["1"]["1"] = "1";
    
    mp["i"]["-1"] = "-i";
    mp["i"]["-i"] = "1";
    mp["i"]["-j"] = "-k";
    mp["i"]["-k"] = "j";
    mp["i"]["1"] = "i";
    
    mp["j"]["-1"] = "-j";
    mp["j"]["-i"] = "k";
    mp["j"]["-j"] = "1";
    mp["j"]["-k"] = "-i";
    mp["j"]["1"] = "j";
    
    mp["k"]["-1"] = "-k";
    mp["k"]["-i"] = "-j";
    mp["k"]["-j"] = "i";
    mp["k"]["-k"] = "1";
    mp["k"]["1"] = "k";

    mp["-i"]["-1"] = "i";
    mp["-i"]["-i"] = "-1";
    mp["-i"]["-j"] = "k";
    mp["-i"]["-k"] = "-j";
    mp["-i"]["1"] = "-i";
    
    mp["-j"]["-1"] = "j";
    mp["-j"]["-i"] = "-k";
    mp["-j"]["-j"] = "-1";
    mp["-j"]["-k"] = "i";
    mp["-j"]["1"] = "-j";
    
    mp["-k"]["-1"] = "k";
    mp["-k"]["-i"] = "j";
    mp["-k"]["-j"] = "-i";
    mp["-k"]["-k"] = "-1";
    mp["-k"]["1"] = "-k";
    
    
    mp["-1"]["-1"] = "1";
    mp["-1"]["-i"] = "i";
    mp["-1"]["-j"] = "j";
    mp["-1"]["-k"] = "k";
    mp["-1"]["1"] = "1";

    mp["i"]["1"] = "i";
    mp["i"]["i"] = "-1";
    mp["i"]["j"] = "k";
    mp["i"]["k"] = "-j";
    mp["i"]["-1"] = "-i";
    
    mp["j"]["1"] = "j";
    mp["j"]["i"] = "-k";
    mp["j"]["j"] = "-1";
    mp["j"]["k"] = "i";
    mp["j"]["-1"] = "-j";
    
    mp["k"]["1"] = "k";
    mp["k"]["i"] = "j";
    mp["k"]["j"] = "-i";
    mp["k"]["k"] = "-1";
    mp["k"]["-1"] = "-k";

    mp["-i"]["1"] = "-i";
    mp["-i"]["i"] = "1";
    mp["-i"]["j"] = "-k";
    mp["-i"]["k"] = "j";
    mp["-i"]["-1"] = "i";
    
    mp["-j"]["1"] = "-j";
    mp["-j"]["i"] = "k";
    mp["-j"]["j"] = "1";
    mp["-j"]["k"] = "-i";
    mp["-j"]["-1"] = "j";
    
    mp["-k"]["1"] = "-k";
    mp["-k"]["i"] = "-j";
    mp["-k"]["j"] = "i";
    mp["-k"]["k"] = "1";
    mp["-k"]["-1"] = "k";
    
    
    mp["-1"]["1"] = "-1";
    mp["-1"]["i"] = "-i";
    mp["-1"]["j"] = "-j";
    mp["-1"]["k"] = "-k";
    mp["-1"]["-1"] = "1";
    

    int T;
    long long L, X;
    string S;
    string ss;

    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        printf("Case #%d: ", kase);
        cin >> L >> X >> ss;
        string all;
        int i_ok = -1;
        int k_ok = -1;
        string cur = "1";
        S = "";
        if (X <= 8) {
            for (int i = 0; i < X; i++) S += ss;
            cur = "1";
            for (int i = 0; i < S.length(); i++) {
                cur = mul(cur, S[i]);
//                printf("i = %d, cur = %s\n", i, cur.c_str());
                if (cur == "i" && i_ok == -1) {
                    i_ok = i;
                    break;
                }
            }
            cur = "1";
            for (int i = S.length() - 1; i >= 0; i--) {
                cur = mul(S[i], cur);
//                printf("i = %d, cur = %s\n", i, cur.c_str());
                if (cur == "k" && k_ok == -1) {
                    k_ok = i;
                    break;
                }
            }

//            printf("%d, %d\n", i_ok, k_ok);
            if (i_ok == -1 || k_ok == -1 || i_ok >= k_ok) {
                printf("NO\n");
                continue;
            }
            else {
                string mid = "1";
                for (int i = i_ok + 1; i < k_ok; i++) {
                    mid = mul(mid, S[i]);
                }
                if (mid == "j") {
                    printf("YES\n");
                }
                else printf("NO\n");
                continue;
            }
        }
        else {
            all = "1";
            for (int i = 0; i < L; i++) all = mul(all, ss[i]);
            for (int i = 0; i < 4; i++) S += ss;
            cur = "1";
            for (int i = 0; i < S.length(); i++) {
                cur = mul(cur, S[i]);
                if (cur == "i" && i_ok == -1) {
                    i_ok = i;
                    break;
                }
            }
            cur = "1";
            for (int i = S.length() - 1; i >= 0; i--) {
                cur = mul(S[i], cur);
                if (cur == "k" && k_ok == -1) {
                    k_ok = i;
                    break;
                }
            }
            if (i_ok == -1 || k_ok == -1) {
                printf("NO\n");
                continue;
            }
            else {
                string mid = "1";
                for (int i = i_ok + 1; i < S.length(); i++) {
                    mid = mul(mid, S[i]);
                }
                for (int i = 0; i < (X-8)%4; i++) {
                    mid = mul(mid, all);
                }
                for (int i = 0; i < k_ok; i++) {
                    mid = mul(mid, S[i]);
                }
                if (mid == "j") {
                    printf("YES\n");
                }
                else printf("NO\n");
                continue;
            }
        }
    }

    
    return 0;
}
