#include <iostream>

using namespace std;

int main()
{
    int n;
    string data[100];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> data[i];
    for(int i = 0; i < n; i++){
        string s = data[i];
        string res = "";
        string temp1 = ""; string temp2 = "";
        for(int j = 0; j < s.length(); j++){
            temp1 = res + s.at(j);
            temp2 = ""; temp2 = temp2 + s.at(j) + res;
            if(temp1.compare(temp2) > 0){
                res = temp1;
            }else{
                res = temp2;
            }
        }
        cout << "Case #" << i + 1 << ": " <<res << endl;
    }
    return 0;
}
