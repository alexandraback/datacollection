#include<iostream>
#include<string>

using namespace std;

int main()
{  
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        int s;
        string num;
        cin >> s >> num;
        int friends = 0, raised = 0;

        for(int i = 0; i < num.size(); ++i) {
            if(i-raised > 0) {
                friends += i-raised;
                raised += i-raised;
            }

            raised += (num[i] - '0');
        }

        cout << "Case #" << t << ": " << friends << endl;
    }
    
    return 0;
}
