#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void solve(string cakes)
{
    int count = 0;
    for(int i=1; i<cakes.length(); i++)
    {
        if(cakes[i] != cakes[i-1])
            count++;
    }
    if(cakes[cakes.length()-1] == '-')
        count++;
    cout << count << endl;
}

int main()
{
    int T;
    string cakes;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> cakes;
        cout << "Case #" << i+1 << ": "; 
        solve(cakes);
    }
}

