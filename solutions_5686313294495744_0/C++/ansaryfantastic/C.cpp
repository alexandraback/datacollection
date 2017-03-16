#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int t;
    cin >> t;

    for (int i = 0; i< t; i++){
        cout << "Case #" << (i+1) << ": ";
        int n;
        cin >> n;
        vector<string> one, two;
        for (int i = 0; i < n; i++){
            string s1, s2;
            cin >> s1 >> s2;
            one.push_back(s1);
            two.push_back(s2);
        }

        int fakes = 0;
        for (int i = 0; i < n; i++){
            string s1 = one[i];
            string s2 = two[i];
            bool oneFound = false;
            bool twoFound = false;
            for (int j = 0; j < n; j++){
                if (j == i) continue;
                if (s1 == one[j]) oneFound = true;
                if (s2 == two[j]) twoFound = true;

                if (oneFound && twoFound) break;
            }

            if (oneFound && twoFound) fakes++;
        }
        cout << fakes;

        cout << endl;
    }

}
