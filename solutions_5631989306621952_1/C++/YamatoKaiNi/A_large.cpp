#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int test = 1; test <= T; test++){
        string word;
        cin >> word;
        string answer;
        answer += word[0];
        for (int i = 1; i < word.size(); i++)
            if (word[i] < answer.front())
                answer = answer + word[i];
            else
                answer = word[i] + answer;
        printf("Case #%d: %s\n", test, answer.c_str());
    }
}
