 #include <cstdio>
 #include <string>
 #include <cstdlib>
 #include <iostream>
 using namespace std;
 
 const int maxn = 1010;
 
 string f[maxn];
 
 string getMax(string a, string b)
 {
    if (a > b) return a;
    else        return b;
 }
 
 void work()
 {
    int t;
    cin >> t;
    for (int l = 0; l < t; ++l)
    {
        string s;
        cin >> s;
        
        int n = s.length();
        f[0] = s[0];
        for (int i = 1; i < n; ++i)
        {
                f[i] = getMax(s[i] + f[i - 1] , f[i - 1] + s[i]);
        }
        cout << "Case #" << l + 1 << ": " << f[n - 1] << endl;
        
    }
 }
 
 
 int main()
 {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    work();
    return 0;
 }
