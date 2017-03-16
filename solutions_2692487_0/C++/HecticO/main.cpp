#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int x, int y){
    return x < y;
};

int main()
{

    int t;

    cin >> t;

    for (int j = 0; j < t; ++j){
//        cout << j << endl;
        vector<int> motes;
        int a, n;
        cin >> a >> n;
//        cout << a << " " << n << " " << j << endl;
        for (int i = 0; i < n; ++i){
            int tmp;
            cin >> tmp;
            motes.push_back(tmp);
        };
        if (a == 1){
            cout << "Case #" << j + 1 << ": " << n << endl;
            continue;
        };

        sort(motes.begin(), motes.end(), cmp);
        int mymoves[n + 1];
        mymoves[0] = 0;

        for (int i = 1; i <= n; ++i){
            int count = 0;
            while (motes[i - 1] >= a){
                a = a * 2 - 1;
                count += 1;
            };
            mymoves[i] = mymoves[i - 1] + count;
            a += motes[i - 1];
        };
        int place = n;
        int mycount = 0;
        for (int i = n; i > 0; --i){
            mycount += mymoves[i] - mymoves[i - 1];
            if (mycount >= place - i + 1){
//                cout << mycount << " " << place << " " << i << endl;
                place = i - 1;
                mycount = 0;
            };
        };
/*        for (int i = 0; i < n + 1; ++i){
            cout << mymoves[i] << " ";
        };
        cout << endl;
        cout << place << endl;
*/
        cout << "Case #" << j + 1 << ": " << mymoves[place] + n - place << endl;
    }


    return 0;
}
