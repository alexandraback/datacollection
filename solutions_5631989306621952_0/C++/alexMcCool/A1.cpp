#include<iostream>
#include<fstream>
#include<list>
#include<string>
#include<sstream>

using namespace std;

int main (void)
{
    ifstream in("Ain.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("Aout.txt");
    cout.rdbuf(out.rdbuf()); 

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
       
        string S;
        cin >> S;

        list<char> O;
        O.push_front(S[0]);

        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] >= O.front())
                O.push_front(S[i]);
            else
                O.push_back(S[i]);
        }

        list<char>::iterator it;
        for (it = O.begin(); it != O.end(); ++it)
            cout << *it;

        cout << endl;
    }
    return 0;
}
