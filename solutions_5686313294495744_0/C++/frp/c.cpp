#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

int test() {
    int n;
    cin >> n;
    vector<pair<string, string>> topics(n);
    for (auto& topic: topics)
        cin >> topic.first >> topic.second;

    int min_legit = 2000000;
    for (int code = 0; code < (1 << topics.size()); code++) {
        //cout << code << endl;
        set<string> vocab1, vocab2;
        int legit = 0;
        for (int i = 0; i < topics.size(); i++)
            if (code & (1 << i)) {
                legit++;
                vocab1.insert(topics[i].first);
                vocab2.insert(topics[i].second);
            }
        //cout << vocab1.size() << " " << vocab2.size() << endl;
        bool broken = false;
        for (int i = 0; i < topics.size(); i++)
            if ((code & (1<< i)) == 0) {
                if (vocab1.find(topics[i].first) == vocab1.end() || vocab2.find(topics[i].second) == vocab2.end()) {
                    //cout << "Code: " << code << endl;
                    broken = true;
                    break;
                }
            }

        if (!broken)
            min_legit = min(legit, min_legit);
    }

    // set<string> vocab1, vocab2;
    // int legit_topics = 0;
    // // both words new
    // for (auto& topic: topics)
    //     if (vocab1.find(topic.first) == vocab1.end() && vocab2.find(topic.second) == vocab2.end()) {
    //         legit_topics++;
    //         vocab1.insert(topic.first);
    //         vocab2.insert(topic.second);
    //     }
    //
    // // first word new
    // for (auto& topic: topics)
    //     if (vocab1.find(topic.first) == vocab1.end() && vocab2.find(topic.second) != vocab2.end()) {
    //         legit_topics++;
    //         vocab1.insert(topic.first);
    //     }
    //
    // // second word new
    // for (auto& topic: topics)
    //     if (vocab1.find(topic.first) != vocab1.end() && vocab2.find(topic.second) == vocab2.end()) {
    //         legit_topics++;
    //         vocab2.insert(topic.second);
    //     }

    return topics.size() - min_legit;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        cout << "Case #" << i + 1 << ": " << test() << endl;
}
