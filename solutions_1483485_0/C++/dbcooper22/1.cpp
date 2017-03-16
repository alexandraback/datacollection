#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int change(string T)
{
    int ans = 0;
    for(int i = 0; i < T.length(); i++)
    {
        ans *= 10;
        int temp = T[i] - '0';
        ans += temp;
    }
    return ans;
}

int main()
{
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    string S = "yhesocvxduiglbkrztnwjpfmaq", s;
    string T;
    getline(cin, T);
    for(int ts = 1; ts <= change(T); ts++)
    {
        getline(cin,s);
        cout << "Case #" << ts << ": ";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ') cout << ' ';
            else cout << S[s[i]-'a'];
        }
        cout << endl;
    }
    return 0;
}
