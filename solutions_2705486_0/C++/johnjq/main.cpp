#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> words;
bool testa(string& s, int& index, int& error, string& word, int& errc)
{
    int ws = word.size();
    for (int i = 0; i < ws; ++i) {
        if (s[index+i] != word[i]) {
            if ((index+i)-error >= 5) {
                error = index+i;
                ++errc;
            }
            else return 0;
        }
    }
    index += ws;
    return 1;
}

int aux[4010][6];

unsigned solve(string& s, int ss, int index, int error)
{
    if (index == ss) return 0;
    if (index > ss) return -1;

    int id = index-error-1;
    if (id > 4) id = 5;
    if (aux[index][id] != 0)
        return aux[index][id]-2;

    unsigned best = -1;
    for (int counter = 0, counter_max = words.size(); counter < counter_max; ++counter)
    {
        int newindex = index;
        int newerror = error;
        int errc = 0;
        if (testa(s, newindex, newerror, words[counter], errc))
        {
            unsigned v = solve(s, ss, newindex, newerror);
            if (v != -1) best = min(best, v+errc);
            if (best == 0) break;
        }
    }

    aux[index][id] = best+2;
    return best;
}

int run() {
    string str;
    cin >> str;
    memset(aux, 0, sizeof aux);
    int ans = solve(str, str.size(), 0, -42);
    cout<<" "<<ans<<endl;
}

int main()
{
    //Read words from file
    ifstream file("garbled_email_dictionary.txt");
    words.reserve(521196);
    while (!file.eof()) {
        string palavra;
        file >> palavra;
        words.push_back(palavra);
    }
    //Run
    #if 1
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w+", stdout);
    #endif // ONLINE_JUDGE

    int testcases;
	scanf("%d", &testcases);
	for (int testcase = 1; testcase <= testcases; ++testcase)
	{
	    printf("Case #%d:", testcase);
		run();
	}
}
