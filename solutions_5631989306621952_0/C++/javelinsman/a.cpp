#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    int T; scanf("%d", &T);
    for(int ti=1;ti<=T;ti++){
        fprintf(stderr, "start %d\n", ti);
        string s; cin >> s;
        int n = s.size();
        deque<char> ans;
        int mc = -1;
        for(char c : s){
            if(mc < c) mc = c;
            if(mc == c){
                ans.push_front(c);
            }
            else ans.push_back(c);
        }
        printf("Case #%d: ", ti);
        for(char c : ans) printf("%c", c);
        printf("\n");
        fprintf(stderr, "end %d\n", ti);
    }
    return 0;
}
