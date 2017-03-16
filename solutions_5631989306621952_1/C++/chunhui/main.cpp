#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    int T;
    cin >> T;
    string s;
    deque<char> que;
    for(int i=1; i<=T; i++){
        cin >> s;
        que.clear();
        if(s.size() <= 1)
        {
            cout << "Case #" << i << ": " << s << endl;
            continue;
        }
        for(int j=0; j<s.size(); j++){
            if(que.empty() || s[j] < que.front()){
                que.push_back(s[j]);
            }
            else{
                que.push_front(s[j]);
            }
        }
        cout << "Case #" << i << ": ";
        for(char c: que)
            cout << c;
        cout << endl;
    }
    return 0;
}
