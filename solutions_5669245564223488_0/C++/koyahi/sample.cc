#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
//typedef pair<int, int> P;
typedef long long ll;
int T;
int N;
const int MAX_N = 12;
bool used[MAX_N];
int jun[MAX_N];
bool appear[26];
vector<string> trains;
vector<string> Tr;

int dfs(int n) {
    if (n == N) {
        char pre = 'A';
        memset(appear, false, sizeof(appear));
        for (int i = 0; i < N; i++) {
            string s = Tr[jun[i]];
            for (int j = 0; j < s.size(); j++) {
                char current = s[j];
                if (pre == 'A' || pre != current) {  //新しい文字
                    if (appear[current-'a']) return 0;
                    appear[current-'a'] = true;
                    pre = current;
                }
            }
        }
        return 1;
    }
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            used[i] = true;
            jun[n] = i;
            ret += dfs(n+1);
            used[i] = false;
        }
    }
    return ret;
}


int main(int argc, const char * argv[])
{
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        trains.clear();  //全ての要素を消す
        Tr.clear();  //全ての要素を消す
        scanf("%d", &N);
        char temp;
        scanf("%c", &temp);  //\nを除く
        int num_same = 0;
        bool impossible = false;
        for (int i = 0; i < N; i++) {
            string s = "";
            char pre = 'A';
            memset(appear, false, sizeof(appear));
            while (true) {
                char c;
                scanf("%c", &c);
                if (c == ' ' || c == '\n') {
                    break;
                } else {
                    if (pre == 'A') {
                        appear[c-'a'] = true;
                        pre = c;
                        s += c;
                    } else {
                        if (pre != c) {  //短く
                            if (appear[c-'a']) {
                                impossible = true;
                                break;
                            }
                            appear[c-'a'] = true;
                            s += c;
                            pre = c;
                        }
                    }
                }
            }
            if (impossible) break;
            trains.push_back(s);
        }
        if (impossible) {
            printf("Case #%d: %d\n", t+1, 0);
        } else {
            memset(appear, false, sizeof(appear));
            for (int j = 0; j < N; j++) {
                string str = trains[j];
                if (str.size() == 1) {
                    if (appear[str[0]-'a']) {
                        num_same++;
                    } else {
                        appear[str[0]-'a'] = true;
                        Tr.push_back(str);
                    }
                } else {
                    Tr.push_back(str);
                }
            }
            memset(used, false, sizeof(used));
            N = (int)Tr.size();
            int ret = dfs(0);
            ret <<= num_same;
            printf("Case #%d: %d\n", t+1, ret);
            
        }
        
//        }
//            bool same = true;
//            for (int j = 0; j < s.size()-1; j++) {
//                if (s[j] != s[j+1]) {
//                    same = false;
//                    break;
//                }
//            }
////            if (same && s.size() > 1) {
////                num_same++;
////            } else {  //異なる文字が含まれる
////                
////                char pre = 'A';
////                string ss = "";
////                for (int j = 0; j < s.size(); j++) {
////                    char current = s[j];
////                    if (pre == 'A' || pre != current) {  //新しい文字
////                        if (appear[current-'a']) {
////                            impossible = true;  //同じトレインに同じ文字がバラバラに出現
////                            break;
////                        }
////                        appear[current-'a'] = true;
////                        pre = current;
////                    }
////                }
////                if (impossible) break;
////                trains.push_back(s);
////            }
//        }
//        if (impossible) {
//            printf("Case #%d: %d\n", t+1, 0);
//        } else {
//            memset(used, false, sizeof(used));
//            N = (int)trains.size();
//            int ret = dfs(0);
//            ret <<= num_same;
//            printf("Case #%d: %d\n", t+1, ret);
//        }
//        
        
    }
    return 0;
}

