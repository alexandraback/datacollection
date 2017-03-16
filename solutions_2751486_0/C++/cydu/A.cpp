#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int test_cases=0;
    cin >> test_cases;
    for(int test_case=1;test_case<=test_cases;test_case++) {
        string str;
        int n;
        int result = 0;
        cin >> str >> n;
        for(int i=0;i<str.length();i++) {
            for(int j=i+n;j<=str.length();j++) {
                int tmp = 0;
                //cout << str.substr(i,j-i) << endl;
                for(int k=i;k<j;k++) {
                    int x=k;
                    if(str[x] == 'a' || str[x] == 'e' || str[x] == 'i' ||
                            str[x] == 'o' || str[x] == 'u') {
                        tmp = 0; 
                    }else {
                        tmp++;
                        if(tmp >= n) {
                            //cout << "plus" << endl;
                            result++;
                            break;
                        }
                    }
                }
            }
        }
        cout << "Case #" << test_case << ": " << result << endl;
    }
    return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 et: */
