#include <iostream>
#include <memory.h>
#include <vector>
#include <cstdio>
using namespace std;
const int M = 1000000007;
vector<string> a;
int n;
char ss[200];
int w[200];
int cou[200];
typedef vector<string>::iterator P;
void solve(){
    long long ans = 1;
    for (int i = 0; i < a.size(); i++){
        string s = a[i];
        int j = 1;
        while (j < s.length()){
            if ( s[j] == s[j-1]){
                s.erase(j,1);
            } else j++;
        }   
        a[i] = s;
    } 
    P p;
    for (int i = 'a'; i <= 'z'; i++){
        int k = 0;
        p = a.begin();
        while (p != a.end()){
            string s = *p;
           if (s.length() == 1 && s[0] == (char)i){
               k++;
               w[i] = 1;
               p = a.erase(p);
           }else p++; 
           if (p == a.end()) break;
        } 
        for(int e = 2; e <= k; e++) ans = (ans *e) % M;
    }
    for (int i = 'a'; i <= 'z'; i++){
        char c = (char)i;
        int k = 0;
        int r = 0;
        for (p = a.begin(); p!=a.end(); p++){
            string s = *p;
            int flag = 0;
            for (int e = 0; e < s.length(); e++)
            {
                flag = 1;
                if (s[e] == c) k++;
            }
            if (flag) r++;
        }
        if (k > 2||(k == 2 && r == 1)) {printf("0\n");return;}
        cou[i] = k;
    }

/*    printf("r%d\n",ans);
    for (int i = 0; i < a.size(); i++){
        cout << a[i] <<endl;
    }
    */
    for (int i = 'a'; i <= 'z'; i++){
        if (cou[i] ==1 && w[i]){
            char c = (char) i;
            for (p = a.begin(); p != a.end(); p++)
                if ((*p).find(c) != (*p).npos) break;
            string s = *p;
            if (s[0] != (char)i && s[s.length()-1] != (char)i){printf("0\n");return;}
            w[i] = 0; 
        }
        if (cou[i] == 2){
            P p1,p2;
            char c = (char)i;
            for (p1 = a.begin(); p1 != a.end(); p1++)
                if ((*p1).find(c) != (*p1).npos) break;
            for (p2 = p1+1; p2 != a.end(); p2++)
                if ((*p2).find(c) != (*p2).npos) break;
            if (p1 == a.end() || p2 == a.end()) {printf("0\n");return;} 
            string s = *p1;
            if (s[0] != (char)i && s[s.length()-1] != (char)i){printf("0\n");return;}
            s = *p2;
            if (s[0] != (char)i && s[s.length()-1] != (char)i){printf("0\n");return;}
            if (s[0] == (char)i){
                p = p2;
                p2 = p1;p1=p;
            }
            if ((*p1)[0] != c || (*p2)[(*p2).length()-1] != c) {printf("0\n");return;};
            s = *p2 + *p1;
            *p1 = s;
            a.erase(p2);
            w[i] = 0;
            if (s[0] == s[s.length()-1]) {printf("0\n");return;} 
        }
    }
    int k =0;
    for (int i = 'a'; i <= 'z'; i++){
        if (w[i]) k++;
    }
   k += a.size(); 
    for (int e = 1; e <= k;e++) ans = (ans * e) % M; 
   printf("%lld\n",ans);
}
int main(){
    int t;

    cin >> t;
    for (int i = 1; i <= t; i++){
        printf("Case #%d: ",i);
        memset(w,0,sizeof(w));
        memset(cou,0,sizeof(cou));
        a.clear();
        cin >> n;
        for (int k = 0; k < n; k++){
            string s;
            cin >> s;
            a.push_back(s);
        }
            solve();
    }
    return 0;
}
