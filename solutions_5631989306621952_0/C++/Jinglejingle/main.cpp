#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

static int testCase, s_length;
static string S, ans;

int main(void)
{
    string fileName;
    
    cin >> fileName;
    
    ifstream fin(fileName);
    ofstream fout("output.txt");
    
    fin >> testCase;
    
    for (int caseN = 0; caseN < testCase; caseN++)
    {
        fin >> S;
        
        s_length = S.length();
        ans += S[0];
        
        for (int i = 1; i < s_length; i++)
        {
            if (ans[0] <= S[i]) ans.insert(0, S.substr(i, 1));
            else ans += S[i];
        }
        
        fout << "Case #" << caseN + 1 << ": " << ans << endl;
        
        ans.clear();
    }
    
    return 0;
}
