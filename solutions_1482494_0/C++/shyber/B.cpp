#include <vector>
#include <iostream>
#include <utility>
#include <cstdio>
#include <algorithm>

using namespace std;

struct sort_ld {
    bool operator()(const std::pair< pair<int,int>, int> &left, const std::pair< pair<int,int>, int > &right) {
        return right.first.second < left.first.second;
    }
};

struct sort_d {
    bool operator()(const std::pair < pair<int,int>, int > &left, const std::pair< pair<int,int>, int> &right) {
        return left.second < right.second;
    }
};

int main(){
    int t, n, x, y, stars, found, games;
    vector <pair < pair < int, int > , int> > v;

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        v.clear();
        for(int j = 0; j < n; j++){
            scanf("%d %d", &x, &y);
            v.push_back(make_pair(make_pair(x ,y), 0));
        }

        stars = 0;
        games = 0;
        found = 1;
        while(stars != n*2){
            if(!found) break;

            found = 0;
            sort(v.begin(), v.end(), sort_ld());
            for(int j = 0; j < v.size(); j++){
                if(stars >= v[j].first.second && v[j].second == 0){
                    stars+=2;
                    v[j].second = 2;
                    found = 1;
                    games++;
                    break;
                }
            }
            if(found) continue;

             for(int j = 0; j < v.size(); j++){
                if(stars >= v[j].first.second && v[j].second == 1){
                    stars+=1;
                    v[j].second = 2;
                    found = 1;
                    games++;
                    break;
                }
            }
            if(found) continue;

             for(int j = 0; j < v.size(); j++){
                if(stars >= v[j].first.first && v[j].second == 0){
                    stars+=1;
                    v[j].second = 1;
                    found = 1;
                    games++;
                    break;
                }
            }



        }
        if(stars < n*2){
            printf("Case #%d: Too Bad\n", i+1);
        }else{
            printf("Case #%d: %d\n", i+1, games);
        }

    }

    return 0;
}
