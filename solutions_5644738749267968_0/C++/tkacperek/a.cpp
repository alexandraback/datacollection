#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void showme(vector<float> &myvector) {
    for (vector<float>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void deceitful(vector<float> naomi, vector<float> ken, int &pts) {
    int j,N=naomi.size();
    pts=0;
    for (int j=0; j<N; j++) {
        if (naomi.front() < ken.front()) {
            ken.pop_back();
        }
        else {
            ken.erase(ken.begin());
            pts++;
        }
        naomi.erase(naomi.begin());
    }
}

void war(vector<float> &naomi, vector<float> &ken, int &pts) {
    pts=0;
    vector<float>::iterator it;
    int N=naomi.size();
    float nch;
    for (int i=0; i<N; i++) {
        nch = naomi.front();
        naomi.erase(naomi.begin());
        if (nch > ken.back()) {
            ken.erase(ken.begin());
            pts++;
        } else {
            it=ken.begin();
            while (*it < nch)
                it++;
            ken.erase(it);
        }
    }
}

int main() {
    int i,j,k,T,N,pts;
    float a;
    vector<float> naomi,ken;
    cin >> T;
    for (i=0; i<T; i++) {
        cout << "Case #" << i+1 << ": ";
        naomi.clear();
        ken.clear();
        cin >> N;
        for (j=0; j<N; j++) {
            cin >> a;
            naomi.push_back(a);
        }
        for (j=0; j<N; j++) {
            cin >> a;
            ken.push_back(a);
        }
        sort(naomi.begin(),naomi.end());
        sort(ken.begin(),ken.end());
        //showme(naomi);
        //showme(ken);
        deceitful(naomi,ken,pts);
        cout << pts << " ";
        war(naomi,ken,pts);
        cout << pts << "\n";
    }
    return 0;
}