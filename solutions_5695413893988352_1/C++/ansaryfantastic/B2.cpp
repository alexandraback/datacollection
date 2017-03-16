#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int t;
    cin >> t;
    for (int c = 0; c < t; c++){
        string a, b;
        cin >> a >> b;
        int len = a.length();
        string ans1 = a;
        string ans2 = b;

        for (int i = len-1; i >= 0; i--){
            if (a[i] == '?' && b[i] == '?'){
                bool bigger = false;
                for (int j = 0; j < i; j++){
                    if (a[j] != '?' && b[j] != '?'){
                        if (a[j] > b[j]) bigger = true;
                        break;
                    }
                }

                if (!bigger) ans1[i] = ans2[i] = '0';
                else ans1[i] = ans2[i] = '9';
            }
            else if (a[i] == '?'){
                ans2[i] = b[i];

                bool bigger = false;
                for (int j = 0; j < i; j++){
                    if (a[j] != '?' && b[j] != '?'){
                        if (a[j] >= b[j]) bigger = true;
                        break;
                    }
                }

                if (!bigger) ans1[i] = '9';
                else ans1[i] = '0';
            }
            else if (b[i] == '?'){
                ans1[i] = a[i];

                bool bigger = false;
                for (int j = 0; j < i; j++){
                    if (a[j] != '?' && b[j] != '?'){
                        if (b[j] > a[j]) bigger = true;
                        break;
                    }
                }


                if (bigger) ans2[i] = '9';
                else ans2[i] = '0';
            }
            else{
                ans1[i] = a[i];
                ans2[i] = b[i];
            }
        }

        cout << "Case #" << (c+1) << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}
