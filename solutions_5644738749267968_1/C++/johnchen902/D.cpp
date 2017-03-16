#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

constexpr unsigned max_r = 50, max_c = 50;

vector<double> vec1, vec2;

unsigned solve1(){
    auto i = vec1.begin();
    auto j = vec2.rbegin();
    while(i != vec1.end() && vec1.back() < *j)
        ++i, ++j;
    auto k = vec2.begin();
    while(true){
        i = find_if(i, vec1.end(), bind(greater<double>(), placeholders::_1, *k));
        if(i == vec1.end())
            break;
        ++i;
        ++k;
    }
    return k - vec2.begin();
}

unsigned solve2(){
    auto i = vec1.begin(), j = vec2.begin();
    while(true){
        j = find_if(j, vec2.end(), bind(greater<double>(), placeholders::_1, *i));
        if(j == vec2.end())
            break;
        ++i;
        ++j;
    }
    return vec1.end() - i;
}

int main(){
    unsigned t;
    cin >> t;
    for(unsigned x = 1; x <= t; x++){
        unsigned n; cin >> n;
        copy_n(istream_iterator<double>(cin), n, back_inserter(vec1));
        copy_n(istream_iterator<double>(cin), n, back_inserter(vec2));
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        cout << "Case #" << x << ": " << solve1() << " " << solve2() << endl;
        vec1.clear();
        vec2.clear();
    }
}
