#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct game{
    int num;
    int one;
    int two;
};

bool sort_func2(const game& left, const game& right) {
    return left.two < right.two;
}

int act2(vector<game>& ratings, vector<game>& hist, int stars) {
    for(int i=0; i < ratings.size(); i++) {
        if( ratings[i].two <= stars && hist[ ratings[i].num ].two == 0 ) {
            hist[ ratings[i].num ].two = 1;
            if( hist[ ratings[i].num ].one == 0 ) {
                return 2;
            } else {
                return 1;
            }
        } else if( ratings[i].two > stars ){
            return 0;
        }
    }
}

int act1(vector<game>& ratings, vector<game>& hist, int stars) {
    int i;
    for(i=ratings.size()-1; i >= 0; i--) {
        if( ratings[i].one <= stars && hist[ ratings[i].num ].one == 0 && hist[ ratings[i].num ].two == 0 ) {
            hist[ ratings[i].num ].one = 1;
            return 1;
        }
    }
    return 0;
}

void doCase(vector<game>& ratings) {
    vector<game> hist;
    hist.resize(ratings.size());
    int stars = 0;
    int two_completed = 0;
    int result = 0;

    sort(ratings.begin(), ratings.end(), sort_func2);

    for(int i=0; i < ratings.size(); i++) {
        hist[i].one = hist[i].two = 0;
    }

    while(two_completed < ratings.size()) {
        int res = act2(ratings, hist, stars);
        stars += res;
        switch( res ){
            case 0:
                res = act1(ratings, hist, stars);
                if(res == 0) {
                    printf("Too Bad\n");
                    return;
                } else {
                    stars += 1;
                }
                break;
            case 1:
            case 2:
                two_completed++;
                break;
        }
    }
    //for(int i=0; i < hist.size(); i++) {
    //    printf("ratings one: %d two: %d\n", ratings[i].one, ratings[i].two);
    //    printf("hist    one: %d two: %d\n", hist[i].one, hist[i].two);
    //}

    for(int i=0; i < hist.size(); i++) {
        if( hist[i].one ){
            result++;
        }
        if( hist[i].two ){
            result++;
        } else {
            fprintf(stderr, "err: two should be completed\n");
            exit(1);
        }
    }
    printf("%d\n", result);
}

int main() {
    int T; scanf("%d\n", &T);
    for(int i=0; i < T; i++) {
        int N; scanf("%d\n", &N);
        vector<game> stars;
        stars.resize(N);
        for(int j=0; j < N; j++) {
            scanf("%d %d\n", &stars[j].one, &stars[j].two);
            stars[j].num = j;
        }
        printf("Case #%d: ", i+1);
        doCase(stars);
    }
    return 0;
}
