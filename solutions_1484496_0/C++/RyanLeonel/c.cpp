// headers
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std; // program namespace

vector <vector <int> > list; // brute force of sets enumeration

int main(int argc, char *argv[]) // main function
{ 
    bool found;
    int a, b, cnt, i, j, k, n, num, sum, t, temp;
    vector <int> s, s1, s2, s_temp, ss;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> n;
        s.resize(n); s1.resize(n); s_temp.resize(n); num = 1; sum = 0;
        for (i = 0; i < n; i++) { cin >> s[i]; num *= 2; sum += s[i]; }
        list.resize(sum + 1); for (i = 0; i <= sum; i++) list[i].resize(0);
        for (i = 1; i < num; i++) // brute force! to be able to implement C-small quickly
        {
            for (j = 0; j < n; j++) s1[j] = 0;
            temp = i; for (j = 0; j < n; j++) { s1[j] = temp % 2; temp /= 2; }
            temp = 0; for (j = 0; j < n; j++) if (s1[j]) temp += s[j];
            list[temp].resize(list[temp].size() + 1);
            list[temp][list[temp].size() - 1] = i;
        }
        found = false;
        for (i = 1; i <= sum / 2; i++)
        {
            temp = list[i].size();
            if (temp > 1)
            {
                for (j = 0; j < temp; j++)
                {
                    for (k = j + 1; k < temp; k++)
                    {
                        if (!(list[i][j] & list[i][k]))
                        {
                            found = true;
                            a = list[i][j]; b = list[i][k];
                            break;
                        }
                    }
                    if (found) break;
                }
            }
            if (found) break;
        }
        if (found)
        {
            printf("Case #%d:\n", cnt);
            // display a
            temp = a; for (i = 0; i < n; i++) { s_temp[i] = temp % 2; temp /= 2; }
            temp = 0;
            for (i = 0; i < n; i++)
            {
                if (s_temp[i])
                {
                    if (temp) cout << " ";
                    cout << s[i];
                    temp++;
                }
            }
            cout << endl;
            // display b
            temp = b; for (i = 0; i < n; i++) { s_temp[i] = temp % 2; temp /= 2; }
            temp = 0;
            for (i = 0; i < n; i++)
            {
                if (s_temp[i])
                {
                    if (temp) cout << " ";
                    cout << s[i];
                    temp++;
                }
            }
            cout << endl;
        }
        else printf("Impossible\n");
    }
    return 0;
}
