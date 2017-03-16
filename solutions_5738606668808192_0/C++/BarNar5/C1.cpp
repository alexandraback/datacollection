#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int t, n, j, x;
vector<int> pot;
vector<vector<int> > v;

void loop(int ln, int mini) {
    if (ln < 4) {
        for (int i = mini; i<15; ++i) {
            pot.push_back(i);
            loop(ln + 1, i+1);
            pot.pop_back();
            if (v.size() >= 50) {
                break;
            }
        }
    } else {
        int k = 21;
        for (int i = 0; i < pot.size(); ++i) {
            if (pot[i]%2==1) {
                k--;
            } else {
                k++;
            }
        }
        if (k%3==0 && k%7==0) {
            v.push_back(pot);
        }
    }
}

int main() {
    int i, j, k;
    scanf("%d", &t);
    for (i = 0; i<t; ++i) {
        scanf("%d %d", &n, &j);
    }
    loop(0, 1);
    printf("Case #1:\n");
    for (i=0; i<50; ++i) {
                    //cout<<i<<" ";
        printf("1");
        k=0;
        for (j=1; j<15; ++j) {
            if (k < 4 && v[i][k]==j) {
                printf("1");
                k++;
            } else {
                printf("0");
            }
        }
        printf("1 3 2 3 2 7 3 3 2 3\n");
    }
    return 0;
}
