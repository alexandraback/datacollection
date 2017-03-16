#include <iostream>
#include <algorithm>

int T, K, L, S;
double dp[101][101];
std::string keys, target;
int count[26], offset;

double rec(int l, int m){
    if(l-L < 0){return 0.0;}
    
    auto& res = dp[l][m];
    if(res >= 0){return res;}

    res = 1. * (K-count[target[0]-'A']) / K * rec(l-1, 0);

    double x = 1.0;
    for(int i=m;i<L;i++){
        x *= 1. * count[target[i]-'A'] / K;
    }
    x *= (1. + rec(l-offset, L-offset));

    return res += x;
}

int main(){
    std::cin >> T;

    for(int i=1;i<=T;i++){
        std::fill(count, count+26, 0);
        std::fill(&dp[0][0], &dp[0][0]+101*101, -1.0);

        std::cin >> K >> L >> S;

        std::cin >> keys >> target;

        for(const auto& key : keys){++count[key-'A'];}

        bool needNot = false;
        for(int i=0;i<L;i++){
            if(count[target[i]-'A'] == 0){needNot = true; false;}
        }

        if(needNot){
            std::cout << "Case #" << i << ": " << 0 << std::endl;
            continue;
        }
        
        for(offset=1;offset<L;offset++){
            bool flag = true;
            for(int j=0;j<L-offset;j++){
                if(target[offset+j] != target[j]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                break;
            }
        }
        
        std::cout << "Case #" << i << ": " << (S-L) / offset + 1 - rec(S, 0) << std::endl;
    }
}
