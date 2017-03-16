#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    int a[1024];    
    int n;
    string s;
    cin >> n;
    deque<char> d;
    for(int i = 1; i <= n; i++) {
        d.clear();
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] >= d[0]) {
                d.push_front(s[j]);
            }
            else {
                d.push_back(s[j]);
            }
        }
        cout << "Case #" << i << ": ";
        for(int j = 0; j < d.size(); j++) {
            cout << d[j];
        }
        cout << endl;
    }
    return 0;
}
