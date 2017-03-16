#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL alg(LL initial, vector<LL> &v)
{
    sort(v.begin(), v.end());

    vector<LL> possible_answers;

    LL current = initial;
    LL ops = 0;

    bool got_to_end = true;

    for (int i = 0; i < v.size(); i++) {
        if (current <= v[i]) {
            possible_answers.push_back(ops + (v.size() - i));
            if (current == 1) {
                got_to_end = false;
                break;
            }

            while (current <= v[i]) {
                current += (current - 1);
                ops++;
            }
        }

        current += v[i];
    }

    if (got_to_end)
        possible_answers.push_back(ops);

    sort(possible_answers.begin(), possible_answers.end());
    return possible_answers.front();
}

int main()
{
    LL t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        LL a;
        cin >> a;

        LL n;
        cin >> n;
    
        vector<LL> v;
        v.reserve(n);

        while (n--) {
            LL tmp;
            cin >> tmp;
                
            v.push_back(tmp);
        }

        cout << "Case #" << i + 1 << ": " << alg(a, v) << endl; 
    }
}

