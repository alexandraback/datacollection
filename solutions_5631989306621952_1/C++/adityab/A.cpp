#include <iostream>
#include <string>

using namespace std;

void solve(string word)
{
    string ans(1,word[0]);
    for(int i=1; i<word.length(); i++)
    {
        //cout << word[i] << (int) word[i] << endl;
        if((int)word[i] >= (int)ans[0])
        {
            ans.insert(0,1,word[i]);
        }
        else
        {
            ans.push_back(word[i]);
        }
    }
    cout << ans << endl;
}

int main()
{
    //solve
    int T;
    cin >>T;
    string word;
    for(int i=0; i<T; i++)
    {
        cin >> word;
        cout << "Case #" << i+1 << ": ";
        solve(word);
    }
}

