#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fi;
    ofstream fo;
    fi.open("A-small-attempt0.in");
    //fi.open("A-large.in");
    fo.open("Ares.out");

    int tn, m, n, l;
    long long ans, a1,a2;
    char ch;
    long* ar = new long[1000000];
    fi >> tn;
    string vowels = "aeiou";
    string st;
    for (int ti = 0; ti < tn; ti++){
        l = -1;
        ans = 0;
        fi >> st >> n;
        m = st.length();
        for (int i = 0; i < m; i++){
            if (vowels.find(st[i])!=string::npos){
                ar[i] = 0;
            } else if (i == 0){
                ar[i] = 1;
            } else {
                ar[i] = ar[i-1]+1;
            }
            if (ar[i] >= n){
                if ((l == -1) || (i == 0) || (ar[i-1]<n))
                    a1 = i-l-n+1;
                else
                    a1 = 1;
                a2 = m-i;
                ans = ans + a1*a2;
                //cout << a1 << ' ' << a2 << endl;
                //cout << l << endl;
                l = i-n+1;
            }
        }/*
        m = 0;
        while (1){
            if (ch == ' ')
                break;
            cout << ch;
            if (vowels.find(ch)!=string::npos){
                ar[m] = 0;
            } else if (m == 0){
                ar[m] = 1;
            } else {
                ar[m] = ar[m-1]+1;
            }
            m++;
            cin >> ch;
        }
        cin >> n;
        for (int i = 0; i < m; i++){
            if (ar[i] >= n){
                if ((l == -1) || (i == 0) || (ar[i-1]==0))
                    a1 = i-l-n+1;
                else
                    a1 = 1;
                a2 = m-i;
                ans = ans + a1*a2;
                l = i;
            }
        }*/
        fo << "Case #" << ti+1 << ": " << ans << endl;

    }


    fi.close();
    fo.close();
    return 0;
}
