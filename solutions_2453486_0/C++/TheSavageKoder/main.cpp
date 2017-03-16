#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int cse = 1; cse <= T; cse++) {
        string board[4];
        for(int i = 0; i < 4; i++) {
            cin >> board[i];
        }
        bool going = false, ex = false, ow = false;
        int nums[4][4];
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++) {
                if(board[i][j] == '.')
                    nums[i][j] = 0;
                else if(board[i][j] == 'X')
                    nums[i][j] = 2;
                else if(board[i][j] == 'O')
                    nums[i][j] = 3;
                else
                    nums[i][j] = 1;
            }
        int diag1 = 1, diag2 = 1;
        for(int i = 0; i < 4; i++) {
            diag1 *= nums[i][i];
            diag2 *= nums[3-i][i];
            int num1 = 1, num2 = 1;
            for(int j = 0; j < 4; j++) {
                num1 *= nums[i][j];
                num2 *= nums[j][i];
            }

            if(num1 != 0)
                if(num1%2 == 0 && num1%3 != 0)
                    ex = true;
                else if(num1%3 == 0 && num1%2 != 0)
                    ow = true;
            if(num2 != 0)
                if(num2%2 == 0 && num2%3 != 0)
                    ex = true;
                else if(num2%3 == 0 && num2%2 != 0)
                    ow = true;
            if(num2 == 0 || num1 == 0)
                going = true;
        }
        if(diag1 != 0)
            if(diag1%2 == 0 && diag1%3 != 0)
                ex = true;
            else if(diag1%3 == 0 && diag1%2 != 0)
                ow = true;
        if(diag2 != 0)
            if(diag2%2 == 0 && diag2%3 != 0)
                ex = true;
            else if(diag2%3 == 0 && diag2%2 != 0)
                ow = true;
        if(diag1 == 0 || diag2 == 0)
            going = true;

        cout << "Case #" << cse << ": ";
        if(ex) {
            cout << "X won" << endl;
        } else if(ow) {
            cout << "O won" << endl;
        } else if(going)
            cout << "Game has not completed" << endl;
        else
            cout << "Draw" << endl;
    }
    return 0;
}
