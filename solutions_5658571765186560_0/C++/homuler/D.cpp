#include <iostream>

using namespace std;
bool simple_check(int x, int r, int c){
    if(x == 1){
        return true;
    }
    if(c < x && r < x){
        return false;
    }
    if(c < (x+1)/2 || r < (x+1)/2){
        return false;
    }
    return true;
}

bool solve2(int r, int c){
    return (r%2 == 0 || c%2 == 0);
}

bool solve3(int r, int c){
    if(r == 2){
        switch(c){
            case 2: return false;
            case 3: return true;
            case 4: return false;
        }
    }
    if(r ==3){
        return true;
    }
    if(r == 4){
        switch(c){
            case 2: return false;
            case 3: return true;
            case 4: return false;
        }
    }
}

bool solve4(int r, int c){
    if(r == 2){
        return false;
    }
    if(r == 3){
        return true;
    }
    if(r == 4){
        switch(c){
            case 2: return false;
            case 3: return true;
            case 4: return true;
        };
    }
}

bool solve(int x, int r, int c){
    if(!simple_check(x, r, c)){
        return false;
    }
    switch(x){
        case 2: return solve2(r, c);
        case 3: return solve3(r, c);
        case 4: return solve4(r, c);
    }
}

int main(){
    int t;
    cin >> t;
    int x, r, c;
    for(int i = 0; i < t; ++i){
        cin >> x >> r >> c;
        if(solve(x, r, c)){
            cout << "Case #" << (i+1) << ": GABRIEL" << endl;
        } else {
            cout << "Case #" << (i+1) << ": RICHARD" << endl;
        }
    }
}
