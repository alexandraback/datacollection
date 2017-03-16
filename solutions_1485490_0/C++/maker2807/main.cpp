#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>


using namespace std;

struct item {
    int type;
    unsigned long long int amount;
};

vector <item> reverse(vector <item> v) {
    vector <item> ret;
    while (!v.empty()) {
        item t = v.back();
        v.pop_back();
        ret.push_back(t);

    }
    return ret;
}

int main()
{
    int T;

    cin >> T;

    for (int k=1; k<=T; k++) {
        int N,M;
        cin >> N >> M;
        unsigned long long int a[200][200] = {{0}};
        vector <item> boxes(N);
        for (int i=0; i<N; i++) {
            cin >> boxes[i].amount >> boxes[i].type;
        }

        vector <item> toys(M);
        for (int i=0; i<M; i++) {
            cin >> toys[i].amount >> toys[i].type;
        }

        ///LONG LONG

        //boxes = reverse(boxes);
        //toys = reverse (toys);

        for (int i=1; i<=M; i++) {
            for (int j=1; j<=N; j++) {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
                if (toys[i-1].type == boxes[j-1].type) {
                    long long int m = min(boxes[j-1].amount,toys[i-1].amount);
                    a[i][j]+= m;
                    boxes[j-1].amount -= m;
                    toys[i-1].amount -= m;
                }
                //printf("%6ld",a[i][j]);
            }
            //cout << endl;
        }

        cout << "Case #" << k <<": ";
        cout << a[M][N] << endl;
        //cout << ans << endl;
    }
    return 0;
}
