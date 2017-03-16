#include <bits/stdc++.h>
using namespace std;

string s1, s2, sn1, sn2, sw1, sw2;
long long liczba1, liczba2, roznica;

void wylicz(string sv1, string sv2, int k)
{
    //cout<<sv1 << sv2<<endl;
if(sv1[k] > sv2[k])
    {
        for (int i = 0; i < sv1.size(); i++)
            if(sv1[i] == '?')
                sv1[i] = '0';
        for (int i = 0; i < sv2.size(); i++)
            if(sv2[i] == '?')
                sv2[i] = '9';
    }
else
    {
        for (int i = 0; i < sv1.size(); i++)
            if(sv1[i] == '?')
                sv1[i] = '9';
        for (int i = 0; i < sv2.size(); i++)
            if(sv2[i] == '?')
                sv2[i] = '0';
    }
   // cout<<sv1<<sv2<<endl;
long long l1, l2, roz;
l1 = l2 = 0;
for (int j = 0; j < sv1.size(); j++) {
    l1*=10;
    l1+=(sv1[j]-'0');
}
for (int j = 0; j < sv2.size(); j++) {
    l2*=10;
    l2+=(sv2[j]-'0');
}
roz = abs(l1 - l2);
if(roz < roznica ||
 (roz == roznica && l1 < liczba1) ||
 (roz == roznica && l1 == liczba1 && l2 < liczba2)) {
    liczba1 = l1;
    liczba2 = l2;
    roznica = roz;
    sw1 = sv1;
    sw2 = sv2;
}

}


int main()
{
    int t;
    cin >> t;
    int t2 = t;
    while( t--) {
        cout << "Case #"<< t2-t<<": ";
        s1.clear();
        s2.clear();
        sn1.clear();
        sn2.clear();
        cin >> s1 >> s2;
        roznica = 2e18;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i] && s1[i] != '?' && s2[i] != '?') {
                wylicz(s1, s2, i);
                break;
            }
            else if(s1[i] == '?' && s2[i] == '?') {
                sn1 = s1;
                sn2 = s2;
                sn1[i] = '0';
                sn2[i] = '1';
                wylicz(sn1, sn2, i);
                sn1[i] = '1';
                sn2[i] = '0';
                wylicz(sn1, sn2, i);
                s1[i] = s2[i] = '0';
            }
            else if(s1[i] == '?' && s2[i] != '?') {
                sn1 = s1;
                sn2 = s2;
                //1
                if(sn2[i] < '9') {
                    sn1[i] = sn2[i] + 1;
                wylicz(sn1, sn2, i);
                }
                //2
                if(s2[i] > '0') {
                    sn1[i] = sn2[i] - 1;
                wylicz(sn1, sn2, i);
                }
                //3
                s1[i] = s2[i];
            }
            else if(s1[i] != '?' && s2[i] == '?') {
                sn1 = s1;
                sn2 = s2;
                //1
                if(sn1[i] < '9') {
                    sn2[i] = sn1[i] + 1;
                wylicz(sn1, sn2, i);
                }
                //2
                if(s1[i] > '0') {
                    sn2[i] = sn1[i] - 1;
                wylicz(sn1, sn2, i);
                }
                //3
                s2[i] = s1[i];
            }
        }
        wylicz(s1, s2, 0);
        cout<<sw1<<" "<<sw2<<endl;
    }
    return 0;
}
