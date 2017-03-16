#include <iostream>
#include <algorithm>

using namespace std;

constexpr unsigned max_r = 50, max_c = 50;

char data[max_r][max_c];

bool solve(unsigned r, unsigned c, unsigned m){
    // initialize with mines
    for(unsigned i = 0; i < r; i++)
        fill(data[i], data[i] + c, '*');

    unsigned s = r * c - m;

    if(s == 1){
        data[0][0] = 'c';
        return true;
    }
    if(r == 1){
        fill_n(data[0], s, '.');
        data[0][0] = 'c';
        return true;
    }
    if(c == 1){
        for(unsigned i = 0; i < s; i++)
            data[i][0] = '.';
        data[0][0] = 'c';
        return true;
    }
    if(s == 2 || s == 3 || s == 5 || s == 7){ // prime numbers (WRONG COMMENT)
        return false;
    }
    if(r == 2){
        if(s % 2) return false;
        fill_n(data[0], s / 2, '.');
        fill_n(data[1], s / 2, '.');
        data[0][0] = 'c';
        return true;
    }
    if(c == 2){
        if(s % 2) return false;
        for(unsigned i = 0; i < s / 2; i++)
            data[i][0] = data[i][1] = '.';
        data[0][0] = 'c';
        return true;
    }
    if(s % 2 == 0 && s <= 2 * c){
        fill_n(data[0], s / 2, '.');
        fill_n(data[1], s / 2, '.');
        data[0][0] = 'c';
        return true;
    }
    if(s % 2 == 1 && s <= 2 * c + 1){
        fill_n(data[0], (s - 3) / 2, '.');
        fill_n(data[1], (s - 3) / 2, '.');
        fill_n(data[2], 3, '.');
        data[0][0] = 'c';
        return true;
    }
    if(s % c == 1){
        for(unsigned i = 0; i < s / c - 1; i++)
            fill_n(data[i], c, '.');
        fill_n(data[s / c - 1], c - 1, '.');
        data[s / c][0] = data[s / c][1] = '.';
        data[0][0] = 'c';
        return true;
    } else {
        for(unsigned i = 0; i < s / c; i++)
            fill_n(data[i], c, '.');
        fill_n(data[s / c], s % c, '.');
        data[0][0] = 'c';
        return true;
    }
}

int main(){
    unsigned t;
    cin >> t;
    for(unsigned x = 1; x <= t; x++){
        cerr << "Case #" << x << "..." << endl;
        unsigned r, c, m; cin >> r >> c >> m;
        bool b = solve(r, c, m);
        cout << "Case #" << x << ":" << endl;
        if(b){
            for(unsigned i = 0; i < r; i++){
                for(unsigned j = 0; j < c; j++)
                    cout << data[i][j];
                cout << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }
    }
}
