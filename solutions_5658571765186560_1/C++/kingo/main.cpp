#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;


int main(int argc, char *argv[]){
    //freopen("d.in", "r", stdin);
    //freopen("d.out", "w", stdout);
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int X, R, C;
        cin >> X >> R >> C;
        bool possible = true;
        if(X > max(R, C) || X > 2 * min(R, C) - 1)
            possible = false;
        if(X == 2)
            possible = true;
        if(X == 4){
            if(R == 2 || C == 2)
                possible = false;
        }
        if(X == 5){
            if(min(R, C) == 3 && max(R, C) == 5)
                possible = false;
        }
        if(X == 6){
            if(R <= 4 && C <= 4)
                possible = false;
        }
        if(X >= 7)
            possible = false;
        if((R * C) % X != 0)
            possible = false;
        if(possible)
            cout << "Case #" << i+1 << ": " << "GABRIEL" << endl;
        else
            cout << "Case #" << i+1 << ": " << "RICHARD" << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
