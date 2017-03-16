#include <iostream>  
#include <cstdio>  
#include <fstream> 
#include <map> 
using namespace std;  

int n;
string str[101];

bool judge(string s) {
    bool used[27];
    memset(used, false, sizeof(used));
    for (int i = 0; i < s.size(); i++) {
        if (used[s[i] - 'a'] == false) {
            used[s[i] - 'a'] = true;
            continue;
        }
        if (s[i] != s[i - 1] && used[s[i] - 'a'] == true) {
            return false;
        }
    }
    return true;
}

int main()  
{  
    //ifstream cin("D:\\B-small-attempt0.in");  
    //freopen("D:\\B-small-attempt0","w",stdout); 

    int k;  
    cin >> k;   
    for(int times = 1; times <= k; times++)  
    {  
        int a[101];
        
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> str[i];
            a[i] = i;
        }
        int ans = 0;
        do {
            string s;
            for (int i = 0; i < n; i++) {
                s += str[a[i]];
            }
            if (judge(s)) ans++;
        } while(next_permutation(a, a + n));
        printf("Case #%d: ", times);
        cout << ans << endl;

    }  
}  
