// RCC_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int findCount (const vector<int>& num) {
    int answer = 0;
    if (num.empty()) {
        return 0;
    }

    int m = 0;
    for (int i = num.size() / 2 - 1; i >= 0; --i) {
        m *= 10;
        m += num[i];
    }
    if (m > 1)
       ++m;
    answer += m;
    m = 0;
    for (int i = num.size() / 2; i < num.size(); ++i) {
        m *= 10;
        m += num[i];
    }
    answer += m - 1;
    if (m == 0) {
        bool b = true;
        vector <int> newNum(num);
        for (int i = newNum.size() - 1; i >= 0; --i) {
            if (newNum[i] && b) {
                --newNum[i];
                b = false;
            }
            if (newNum[i] == 0 && b) {
                newNum[i] = 9;
            }
        }
        if (newNum[0] == 0) {
            return 0;
        }
        return findCount(newNum) + 1;
    }
    return answer;
}

int main(int argc, char* argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        long long n;
        cin >> n;
        long long tmp = n;
        int count = 0;
        vector <int> num;
        while (tmp) {
            num.push_back(tmp % 10);
            tmp /= 10;
            ++count;
        }
        for (int i = 0; i < num.size() / 2; ++i) 
        {
            swap(num[i], num[num.size() - 1 - i]);
        }
        int answer = 0;
        int pow = 0;
        for (int i = 0; i < count; ++i) {
            answer += findCount(vector<int>(pow, 9)) + 1;
            ++pow;
        }
        answer += findCount(num);
        cout << "Case #" << t + 1 << ": " << answer << endl;
    }
	return 0;
}

