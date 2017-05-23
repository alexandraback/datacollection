#include<bits/stdc++.h>
using namespace std;

int t;
int d;
int p[1002];

int main(){
    ifstream in;
    ofstream out;

    in.open("B-small-attempt0.in");
    out.open("Infinite House of Pancakes.txt");

    in >> t;
    for (int tc=1; tc<=t; tc++){
        in >> d;
        int maks = 0;
        for (int i=0; i<d; i++) in >> p[i], maks = max(maks, p[i]);

        int mini = 2000000000;
        for (int i=1; i<=maks; i++){
            int tmp = i;
            for (int j=0; j<d; j++){
                if (p[j] > i) tmp += (p[j] - i - 1) / i + 1;
            }
            mini = min(mini, tmp);
        }

        out << "Case #" << tc << ": " << mini << endl;
    }

    out.close();
    in.close();

    return 0;
}
