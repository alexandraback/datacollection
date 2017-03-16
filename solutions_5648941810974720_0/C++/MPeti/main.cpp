#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> D = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<vector<int>> L;

int IN[26];
int R[10];

void get(int digit, char u)
{
    R[digit] = IN[u-'A'];
    for (int i = 0; i < 26; i++)
    {
        IN[i] -= R[digit]*L[digit][i];
    }
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    ios::sync_with_stdio(false);
    for (int i = 0; i < 10; i++)
    {
        L.push_back(vector<int>(26));
        for (char c : D[i])
            L[i][c-'A']++;
    }
    int T;
    in >> T;
    for (int t = 1; t <= T; t++)
    {
        for (int i = 0; i < 26; i++)
            IN[i] = 0;
        for (int i = 0; i < 10; i++)
            R[i] = 0;
        string str;
        in >> str;
        for (char c : str)
        {
            IN[c-'A']++;
        }
        get(0, 'Z');
        get(2, 'W');
        get(6, 'X');
        get(7, 'S');
        get(5, 'V');
        get(4, 'F');
        get(3, 'R');
        get(8, 'T');
        get(1, 'O');
        get(9, 'E');
        out << "Case #" << t << ": ";
        for (int i = 0; i < 10; i++)
        {
            for (int c = 0; c < R[i]; c++)
            {
                out << i;
            }
        }
        out << endl;
    }
}
