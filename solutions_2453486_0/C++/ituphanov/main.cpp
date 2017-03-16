#include <iostream>
#include <string>

using namespace std;

bool won(char p, string s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] != p && s[i] != 'T') return false;
    return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
    cin >> T;
	for (int sc = 1; sc <= T; sc++) {
        int i, j;
		
        string s[4], st[4];
        for (i = 0; i < 4; i++) {
            cin >> s[i];
            for (j = 0; j < 4; j++)
                st[j] += s[i][j];
        }
        bool x_won = false, o_won = false, full = true;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (s[i][j] == '.') full = false;
            }
        }

        for (i = 0; i < 4; i++) {
            if (won('X', s[i])) x_won = true;
            if (won('O', s[i])) o_won = true;
        }

        for (i = 0; i < 4; i++) {
            if (won('X', st[i])) x_won = true;
            if (won('O', st[i])) o_won = true;
        }

        string t;
        for (i = 0; i < 4; i++)
            t += string(1, s[i][i]);
        if (won('X', t)) x_won = true;
        if (won('O', t)) o_won = true;

        t = "";
        for (i = 0; i < 4; i++)
            t += string(1, s[i][3-i]);
        if (won('X', t)) x_won = true;
        if (won('O', t)) o_won = true;

        cout << "Case #" << sc << ": ";
        if (x_won) cout << "X won";
        else if (o_won) cout << "O won";
        else if (full) cout << "Draw";
        else cout << "Game has not completed";
        cout << endl;
	}

	fclose(stdin);
	fclose(stdout);
}