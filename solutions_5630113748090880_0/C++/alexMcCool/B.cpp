#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

int max_index(string & S, int r1, int r2)
{
    char max_char = S[r1];
    int max_ind = r1;

    for (int i = r1+1; i < r2; i++)
    {
        if (S[i] > max_char)
        {
            max_char = S[i];
            max_ind = i;
        }
    }

    return max_ind;
}

struct s_range
{
    int r1;
    int r2;
};

int main (void)
{
    ifstream in("Bin.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("Bout.txt");
    cout.rdbuf(out.rdbuf()); 

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ":";
       
        vector<bool> mults(2501, false);

        int N;
        cin >> N;

        for (int i = 0; i < N * (2*N-1); i++)
        {
            int n;
            cin >> n;
            mults[n] = !mults[n];
        }

        for (int i = 1; i < mults.size(); i++)
        {
            if (mults[i])
                cout << " " << i;
        }      

        cout << endl;
    }
    return 0;
}
