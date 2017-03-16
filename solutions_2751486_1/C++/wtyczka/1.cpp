#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <ctime>
typedef long long LL;
typedef long double LD;
#define REP(i, n) for (LL i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
#define GETLL(a) scanf("%lld", &a);
#define GETLL2(a, b) scanf("%lld%lld", &a, &b);


template<typename T, long long size = 100010>
class Memory {
public:
    Memory() : _allocated(0) {
        fill(&_data[0], &_data[size], T());
    }

    T *alloc() {
        return &_data[_allocated++];
    }

    T *getNew() {
        T *mem = alloc();
        return new (mem) T();
    }

    T &newRef() {
        return *getNew();
    }

    void clean() {
        fill(&_data[0], &_data[_allocated], T());
        _allocated = 0;
    }

private:
    T _data[size];
    long long _allocated;
};


inline bool vowel(char letter)
{
    return (letter == 'a') || (letter == 'e') || (letter == 'i') ||
           (letter == 'o') || (letter == 'u');
}

template<typename T>
inline T sq(T a, T b) { return a * b; }


int main()
{
    ios_base::sync_with_stdio(false);

    LL t;
    cin >> t;

    string st;

    REP(i, t) {

        cin >> st;

        LL n;
        cin >> n;

        vector<int> nums;

        int counter = 0;
        bool vowels = vowel(st[0]);

        REP(j, st.size()) {
            if (vowels == vowel(st[j])) {
                counter++;
            } else {
                nums.push_back(counter);
                counter = 1;
                vowels = !vowels;
            }
        }

        nums.push_back(counter);

#if 0
        REP(j, nums.size()) {
            cout << nums[j] << " ";
        }
        cout << endl;
#endif


        LL result = 0;
        if (n == 0) {
            result = (st.size() * (st.size() - 1)) / 2 + st.size();
        } else {
            counter = 0;
            vowels = vowel(st[0]);
            LL to_date_without = 0;
            REP(j, nums.size()) {
                if (!vowels && nums[j] >= n) {
                    //cout << "pre " << result << " " ;
                    result += ((nums[j] - n + 1) * (nums[j] - n)) / 2 + (nums[j] - n + 1);
                    //cout << "post " << result << " ";
                    result += (1 + to_date_without) * (1 + st.size() - counter - nums[j]);
                    result--;

                    result += (nums[j] - n) * (st.size() - counter - nums[j]);
                    result += (nums[j] - n) * (to_date_without);
                    //cout << "ost " << result << endl;

                    to_date_without = n - 1;
                } else {
                    to_date_without += nums[j];
                }

                vowels = !vowels;
                counter += nums[j];
            }
        }

        cout << "Case #" << i + 1 << ": " << result << endl;
    }
}

