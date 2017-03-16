#include <utility>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int C=1; C<=cases; C++) {
        int N;
        cin >> N;
        int lines = (2*N)-1;
        vector< pair<int, int> > A;
        for (int i=0; i<N*lines; i++) {
            int num;
            cin >> num;
            bool in = false;
            for (int j=0; j<A.size(); j++) {
                if (A[j].first == num) {
                    in = true;
                    A[j].second++;
                }
            }
            if (!in) {
                pair<int, int> person;
                person.first = num;
                person.second = 1;
                A.push_back(person);
            }
        }
        string ans = "";
        vector<int> answer;
        for (int i=0; i<A.size(); i++) {
            int indiv = A[i].first;
            int times = A[i].second;
            if (times % 2 == 1) {
                answer.push_back(indiv);
            }
        }
        sort(answer.begin(), answer.end());
        for (int i=0; i<answer.size(); i++) {
            ans += to_string(answer[i]) + " ";
        }
        cout << "Case #" << C << ": " << ans << endl;
    }
}
