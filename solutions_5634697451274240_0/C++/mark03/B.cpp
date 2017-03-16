#include<bits/stdc++.h>
using namespace std;

int foo()
{
    string S;
    cin >> S;
    int sol = 0;
    for(int i=0; i<S.size()-1; ++i)
        if(S[i] != S[i+1])
            sol++;
    if(S.back() == '-') sol++;
    return sol;
}

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; ++i)
        cout << "Case #" << i+1 << ": " << foo() << "\n";
    return 0;
}
