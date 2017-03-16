#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    string S;
    cin >> T;
    for (int i = 1; i <= T; i ++)
    {
        cout << "Case #" << i << ": ";
        cin >> S;
        string newS;
        for (int j = 0; j < S.size(); j ++)
        {
            if (newS + S[j] < S[j] + newS)
                newS = S[j] + newS;
            else
                newS = newS + S[j];
        }
        cout << newS << endl;
    }
    return 0;
}
