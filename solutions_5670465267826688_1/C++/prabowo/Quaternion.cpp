#include<bits/stdc++.h>
using namespace std;

int t;
long long l, x;
string s;
int quater[10002];

int kali(int a, int b){
    int absa = abs(a);
    int absb = abs(b);
    int tanda1 = a / absa;
    int tanda2 = b / absb;
    int tanda = tanda1 * tanda2;

    if (absa == 1 || absb == 1) return absa * absb * tanda;
    if (absa == absb) return -1 * tanda;
    if (absa == 2 && absb == 3) return 4 * tanda;
    if (absa == 3 && absb == 4) return 2 * tanda;
    if (absa == 4 && absb == 2) return 3 * tanda;
    if (absa == 4 && absb == 3) return -2 * tanda;
    if (absa == 3 && absb == 2) return -4 * tanda;
    if (absa == 2 && absb == 4) return -3 * tanda;
}

int main(){
    ifstream in;
    ofstream out;

    in.open("C-large.in");
    out.open("Quaternion.txt");

    in >> t;
    for (int tc=1; tc<=t; tc++){
        in >> l >> x;
        in >> s;
        for (int i=0; i<l; i++) quater[i] = s[i] - 'i' + 2;

        int hasil = 1;
        for (int i=0; i<l; i++) hasil = kali(hasil, quater[i]);
        int tmp = hasil;
        for (int i=1; i<(x-1)%4+1; i++) hasil = kali(hasil, tmp);

        bool bisa = false;
        long long one = l * x, two = l * x;
        if (hasil == -1 && l * x >= 3){
            int tmp = 1;
            int tmp2 = 1;
            bool ada1 = false;
            bool ada2 = false;
            for (int i=0; i<min((long long)4, x); i++){
                for (int j=0; j<l; j++) {
                    tmp = kali(tmp, quater[j]);
                    tmp2 = kali(quater[l-j-1], tmp2);
                    if (tmp == 2 && !ada1) ada1 = true, one = l * i + j + 1;
                    if (tmp2 == 4 && !ada2) ada2 = true, two = l * i + j + 1;

                    if (ada1 && ada2) break;
                }
                if (ada1 && ada2) break;
            }

            if (ada1 && ada2 && one + two < l * x) bisa = true;
        }

        if (bisa) out << "Case #" << tc << ": YES" << endl;
        else out << "Case #" << tc << ": NO" << endl;
    }

    return 0;
}
