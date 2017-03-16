#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define MP(x,y) make_pair(x,y)

bool static comparedesc(const long &stud1, const long &stud2){
    return stud1 > stud2;
}

int get2Pow(int x){
    int num = 1;
    while(x>0){
        num = num *2;
        x--;
    }
    return num;
}

int main(){
    int t ;
    cin >> t;
    for(int _t=1; _t<=t; _t++){
        printf("Case #%d: ", _t);
        int N;
        cin >> N;
        std::vector<std::vector<string> > s(N);
        string temps;
        for(int i=0; i<N; i++){
            cin >> temps;
            s[i].push_back(temps);
            cin >> temps;
            s[i].push_back(temps);
        }
        int maxN = get2Pow(N) - 1;
        int ans = 0;
        while(maxN >= 0){
            set<string> rs[2], fs[2];
            int fkc = 0;
            for(int i=0; i<N; i++){
                if( maxN & (1<<i) ){
                    rs[0].insert(s[i][0]);
                    rs[1].insert(s[i][1]);
                }else{
                    fs[0].insert(s[i][0]);
                    fs[1].insert(s[i][1]);
                    fkc++;
                }
            }
            bool poss = true;
            for(auto word : fs[0]){
                if(rs[0].count(word) == 0){
                    poss = false;
                    break;
                }
            }
            for(auto word : fs[1]){
                if(rs[1].count(word) == 0){
                    poss = false;
                    break;
                }
            }
            if(poss)
                ans = max(ans, fkc);
            maxN--;
        }
        cout << ans << endl;
    }
    return 0;
}