#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

int abs(int val){
    return val < 0 ? val * -1 : val;
}

string getStr2(int num){
    if (num == 0) return "00";
    else if (num < 10) return "0" + SSTR(num);
    else return SSTR(num);
}

string getStr3(int num){
    if (num == 0) return "000";
    else if (num < 10) return "00" + SSTR(num);
    else if (num < 100) return "0" + SSTR(num);
    else return SSTR(num);
}

string ans(string c, string jam){
    int min = 9999999999;
    string ans = "";
    int l = c.length();
    if (l == 1){
        if (c[0] == '?' && jam[0] == '?') return "0 0";
        else if (c[0] == '?') return jam + " " + jam;
        else {
            return c + " " + c;
        }
    }
    else if (l == 2){
        for (int i = 0; i <= 9; i++){
            for (int j = 0; j <= 9; j++){
                for (int k = 0; k <= 9; k++){
                    for (int l =0; l <= 9; l++){
                        int num1 = 0;
                        int num2 = 0;

                        if (c[0] == '?') num1 = i;
                        else num1 = c[0] - '0';

                        if (c[1] == '?') num1 = num1 * 10 + j;
                        else num1 = num1 * 10 + (c[1] - '0');

                        if (jam[0] == '?') num2 = k;
                        else num2 = jam[0] - '0';

                        if (jam[1] == '?') num2 = num2 * 10 + l;
                        else num2 = num2*10 + (jam[1] - '0');


                        int diff = abs(num1 - num2);
                        if (diff < min){
                            min = diff;
                            ans = getStr2(num1) + " " + getStr2(num2);
                        }
                    }
                }
            }
        }
        return ans;
    }
    else{
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                for (int k = 0; k < 10; k++){
                    for (int l = 0; l < 10; l++){
                        for (int m = 0; m < 10; m++){
                            for (int n = 0; n < 10; n++){
                                int num1 = 0;
                                int num2 = 0;

                                if (c[0] == '?') num1 = i;
                                else num1 = c[0] - '0';

                                if (c[1] == '?') num1 = num1*10 + j;
                                else num1 = num1*10 + (c[1] - '0');

                                if (c[2] == '?') num1 = num1*10 + k;
                                else num1 = num1*10 + (c[2] -'0');

                                if (jam[0] == '?') num2 = l;
                                else num2 = jam[0] - '0';

                                if (jam[1] == '?') num2 = num2*10 + m;
                                else num2 = num2*10 + (jam[1] - '0');

                                if (jam[2] == '?') num2 = num2*10 + n;
                                else num2 = num2*10 + (jam[2] - '0');

                                int diff = abs(num1 - num2);
                                if (diff < min){
                                    min = diff;
                                    ans = getStr3(num1) + " " + getStr3(num2);
                                }

                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
}

int main(){
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");

    int t;
    cin >> t;
    for (int i =0; i < t; i++){
        string a, b;
        cin >> a >> b;
        cout << "Case #" << (i+1) << ": " << ans(a, b) << endl;
    }

    return 0;
}
