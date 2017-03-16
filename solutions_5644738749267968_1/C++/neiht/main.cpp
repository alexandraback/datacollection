#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    double temp;
    int curCase = 1;

    cin >> t;
    while (t--) {
        cin >> n; 
        vector<double> naomi;
        vector<double> ken;

        for (int i = 0; i < n; i++) {
            cin >> temp;
            naomi.push_back(temp);
        } 
        for (int i = 0; i < n; i++) {
            cin >> temp;
            ken.push_back(temp);
        } 

        sort(naomi.begin(), naomi.end(), std::less<double>());
        sort(ken.begin(), ken.end(),std::less<double>());

        //cout << endl;
        //for (int i = 0; i < n; i++) {
        //    cout << naomi[i] << " ";
        //}
        //cout << endl;
        //for (int i = 0; i < n; i++) {
        //    cout << ken[i] << " ";
        //}
        //cout << endl;

        vector<double> newKen;
        vector<double> delayedKen;
        int curIndex = 0;
        for (int i = 0; i < n; i++) {
            while (curIndex < n && ken[curIndex] < naomi[i]) {
                delayedKen.push_back(ken[curIndex]);
                curIndex++;
            }

            if (curIndex < n) {
                newKen.push_back(ken[curIndex]);
                curIndex++;
            }
        }
        for (int i = 0; i < (int) delayedKen.size(); i++) {
            newKen.push_back(delayedKen[i]);
        }

        //for (int i = 0; i < n; i++) {
        //    cout << newKen[i] << " ";
        //}
        //cout << endl;

        vector<double> newNaomi;
        vector<double> delayedNaomi;
        curIndex = 0;
        for (int i = 0; i < n; i++) {
            while (curIndex < n && naomi[curIndex] < ken[i]) {
                delayedNaomi.push_back(naomi[curIndex]);
                curIndex++;
            }

            if (curIndex < n) {
                newNaomi.push_back(naomi[curIndex]);
                curIndex++;
            }
        }
        for (int i = 0; i < (int) delayedNaomi.size(); i++) {
            newNaomi.push_back(delayedNaomi[i]);
        }

        int countNoDeceive = 0;
        int countDeceive = 0;
        for (int i = 0; i < n; i++) {
            if (naomi[i] > newKen[i]) {
                countNoDeceive++;
            }
            if (newNaomi[i] > ken[i]) {
                countDeceive++;
            }
        }

        cout << "Case #" << curCase << ": ";
        cout << countDeceive << " " << countNoDeceive << endl;

        curCase++;
    } 
    return 0;
}
