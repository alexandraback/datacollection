#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;

vector<LL> memo;

LL solve(vector<pair<LL, int> >& boxes, size_t bi, vector<pair<LL, int> >& toys, size_t ti, bool fresh){
    if(bi >= boxes.size() || ti >= toys.size()) return 0;
    if(fresh && memo[bi*1000 + ti] >= 0) return memo[bi*1000 + ti];
    LL result = solve(boxes, bi+1, toys, ti, true);
    int box_type = boxes[bi].second;
    LL box_amount = boxes[bi].first;
    LL consume = 0;
    for(size_t i = ti; i < toys.size(); i++){
        int toy_type = toys[i].second;
        LL toy_amount = toys[i].first;
        if(box_type != toy_type) continue;
        if(box_amount < toy_amount){
            consume += box_amount;
            toys[i].first -= box_amount;
            result = max(result, consume + solve(boxes, bi+1, toys, i, false));
            toys[i].first += box_amount;
            break;
        }else{
            consume += toy_amount;
            box_amount -= toy_amount;
            result = max(result, consume + solve(boxes, bi+1, toys, i+1, true));
        }
    }
    if(fresh){
        memo[bi*1000+ti] = result;
    }
    return result;
}

int main(){
    size_t T = 0;
    cin >> T;
    for(size_t t = 1; t <= T; t++){
        int N, M;
        cin >> N >> M;
        vector<pair<LL, int> > boxes;
        vector<pair<LL, int> > toys;
        for(int n = 0; n < N; n++){
            LL num, type;
            cin >> num >> type;
            boxes.push_back(pair<LL,int>(num, type));
        }
        for(int m = 0; m < M; m++){
            LL num, type;
            cin >> num >> type;
            toys.push_back(pair<LL,int>(num, type));
        }
        memo = vector<LL>(1000000, -1);
        LL result = solve(boxes, 0, toys, 0, true);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}

