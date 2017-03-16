#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


bool is_valid(vector<int>& seat, vector<int>& bf, int beg, int end){
    for(int i=beg; i < end; ++i){
        int left = i - 1;
        int right = i + 1;
        if(left < beg) left = end - 1;
        if(right >= end) right = beg;
        if(bf[seat[i]] != seat[left] && bf[seat[i]] != seat[right]) return false;
    }
    return true;
}


int main()
{
    int T, N;
    scanf("%d", &T);
    for(int tcase = 1; tcase <= T; ++tcase){
        scanf("%d", &N);
        vector<int> bf(N, 0);
        for(int i=0; i < N; ++i){
            scanf("%d", &bf[i]);
            bf[i] -= 1;
        }
        fprintf(stderr, "%d %d\n", tcase, N);
        int ans = 0;
        //set<vector<int> > duple;
        vector<int> seat;
        for(int i=0; i < N; ++i) seat.push_back(i);
        do{
            for(int i=0; i < N; ++i){
                for(int j=i + 2; j <= N; ++j){
                    if(is_valid(seat, bf, i, j)){
                        ans = max(ans, (j - i));
                    }
                }
            }
        }while(next_permutation(seat.begin(), seat.end()));
        printf("Case #%d: %d\n", tcase, ans);
    }

    return 0;
}
