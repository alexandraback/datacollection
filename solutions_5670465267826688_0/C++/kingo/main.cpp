#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int multiply(int a, int b){
    int multi = 1;
    if(a < 0){
        multi *= -1;
        a = -a;
    }
    if(b < 0){
        multi *= -1;
        b = -b;
    }
    if(a == 1)
        return multi * b;
    if(b == 1)
        return multi * a;
    if(a == b)
        return -multi;
    if(a == 2 && b == 3)
        return multi * 4;
    if(a == 3 && b == 2)
        return -multi * 4;
    if(a == 3 && b == 4)
        return multi * 2;
    if(a == 4 && b == 3)
        return -multi * 2;
    if(a == 2 && b == 4)
        return -multi * 3;
    if(a == 4 && b == 2)
        return multi * 3;
}

int mulstr(string a){
    if(a.size() == 1)
        return a[0] - 'g';
    int ans = multiply(a[0] - 'g', a[1] - 'g');
    for(int i = 2; i < a.size(); i++)
        ans = multiply(ans, a[i] - 'g');
    return ans;
}

int main(){
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        long long l, x;
        cin >> l >> x;
        string str;
        cin >> str;

        bool possible = false;
        int value = mulstr(str);
        if(value == 1 || x % 4 == 0 || (value != -1 && x % 2 == 1)|| (value == -1 && x % 2 == 0)){
            possible = false;
        }
        else{
            if(x > 30){
                x = x % 8;
                x += 24;
            }
            string newstr = "";
            for(int j = 0; j < x; j++)
                newstr += str;

            for(int j = 1; j <= newstr.size(); j++){
                if(mulstr(newstr.substr(0, j)) == 2){
                    for(int k = 1; k <= newstr.size() - j; k++){
                        if(mulstr(newstr.substr(j, k)) == 3){
                            possible = true;
                            break;
                        }
                    }
                    if(possible)
                        break;
                }
            }
        }

        if(possible)
            cout << "Case #" << i+1 << ": " << "YES" << endl;
        else
            cout << "Case #" << i+1 << ": " << "NO" << endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}



/*int main(int argc, char *argv[]){
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
}*/
