#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int sign(int x){
    if(x > 0){
        return 1;
    } else if(x < 0){
        return -1;
    }
    return 0;
}

map<pair<int, int>, int> consMap(){
    auto ret = map<pair<int, int>, int>();
    vector<int> elems {1, 'i', 'j', 'k'};
    for(int i = 0; i < elems.size(); ++i){
        for(int j = 0; j < elems.size(); ++j){
            if(elems[i] == 1){
                ret[make_pair(elems[i], elems[j])] = elems[j];
            } else if(elems[j] == 1){
                ret[make_pair(elems[i], elems[j])] = elems[i];
            } else if(elems[i] == elems[j]){
                ret[make_pair(elems[i], elems[j])] = -1;
            }
        }
    }
    ret[make_pair('i','j')] = 'k';
    ret[make_pair('i','k')] = -1 * 'j';
    ret[make_pair('j','i')] = -1 * 'k';
    ret[make_pair('j','k')] = 'i';
    ret[make_pair('k','i')] = 'j';
    ret[make_pair('k','j')] = -1 * 'i';
    return ret;
}

auto calc = consMap();

int multiply(int x, int y){
    //cout << x << ' ' << y << " multi " << calc[make_pair(abs(x), abs(y))] << endl;
    return sign(x) * sign(y) * calc[make_pair(abs(x), abs(y))];
}

vector<int> accumFor(string str){
    int v = 1;
    auto vec = vector<int>();
    for(int i = 0; i < str.size(); ++i){
        v = multiply(v, str[i]);
        vec.push_back(v);
    }
    return vec;
}

vector<int> accumBack(string str){
    int v = 1;
    auto vec = vector<int>();
    for(int i = str.size()-1; i >= 0; --i){
        v = multiply(str[i], v);
        vec.push_back(v);
    }
    return vec;
}

long minIPos(string str, long rep){
    int n = 1;
    auto vec = accumFor(str);
    for(long i = 0; i <= min(rep, 4L); ++i){
        for(int j = 0; j < vec.size(); ++j){
            int x = multiply(n, vec[j]);
            if(x == 'i'){
                return i * str.size() + j;
            }
        }
        n = multiply(n, vec[vec.size()-1]);
    }
    return 10000000000000001L;
}

long maxKPos(string str, long rep){
    int n = 1;
    auto vec = accumBack(str);
    for(long i = 0; i <= min(rep, 4L); ++i){
        for(int j = 0; j < vec.size(); ++j){
            int x = multiply(vec[j], n);
            if(x == 'k'){
                return (rep-i) * str.size() - j - 1;
            }
        }
        n = multiply(vec[0], n);
    }
    return -1;
}

bool simpleCheck(string xs, long rep){
    int v = 1;
    for(auto it = xs.begin(); it != xs.end(); ++it){
        v = sign(v) * calc[make_pair(abs(v), *it)];
    }
    if(v == -1){
        return rep%2 == 1;
    } else if(v == 1){
        return false;
    } else {
        return rep%4 == 2;
    }
}

void printAns(int n, bool result){
    cout << "Case #" << n << ": ";
    if(result){
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
}

bool solve(string str, int rep){
    long i = minIPos(str, rep);
    long k = maxKPos(str, rep);
    if(i < k){
        return true;
    } else {
        return false;
    }
}

int main(){
    int t;
    cin >> t;
    int x;
    long l;
    string str;
    for(int i = 0; i < t; ++i){
        cin >> x >> l;
        cin >> str;
        if(!simpleCheck(str, l)){
            printAns(i+1, false);
        } else if(solve(str, l)){
            printAns(i+1, true);
        } else {
            printAns(i+1, false);
        }
    }
}
