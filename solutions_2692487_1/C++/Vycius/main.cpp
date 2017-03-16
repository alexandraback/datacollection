#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> motes;

int getAnswer(int a, int index);
int countSteps(int now, int need, int m);
int stepping(int a, int steps);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
        int a, n;
        scanf("%d%d", &a, &n);
        motes.clear();
        motes.resize(n);
        for(int j = 0; j < n; ++j)
            scanf("%d", &motes[j]);


        sort(motes.begin(), motes.end());

        printf("Case #%d: %d\n", i+1, getAnswer(a, 0));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

int stepping(int a, int steps){
    for(int i = 0; i < steps; ++i)
        a = 2*a - 1;

    return a;
}

int getAnswer(int a, int index){
   // cout << a << " " << index << endl;
    if(index == motes.size())
        return 0;
    if(a > motes[index])
        return getAnswer(a + motes[index], index + 1);

    int steps = countSteps(a, motes[index], motes.size() - index);

    if(steps < motes.size() - index)
            return min((int) motes.size() - index, steps + getAnswer(stepping(a, steps) + motes[index], index + 1));

    return motes.size() - index;
}


int countSteps(int now, int need, int m){
    int steps = 0;
for(int i = 0; steps < m && now <= need; ++i){
    now = 2*now - 1;
    ++steps;
}

return steps;
}
