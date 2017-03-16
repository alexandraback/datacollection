#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> choices;

vector<string> generate_choices(string keyboard, ll length) {
    vector<string> result;
    if (length == 0) {
        result.push_back("");
        return result;
    }
    vector<string> suffixes = generate_choices(keyboard, length-1);
    for (ll i = 0; i < keyboard.length(); i++) {
        string s;
        s += keyboard[i];
        for (ll j = 0; j < suffixes.size(); j++) {
            string t = s + suffixes[j];
            result.push_back(t);
        }
    }
    return result;
}

int main()
{
    ll T; cin >> T;
    for (ll I = 1; I <= T; I++) {
        ll k, l, s; cin >> k >> l >> s;
        string keyboard, target;
        cin >> keyboard >> target;
        double result = 0;
        choices = generate_choices(keyboard, s);
        // we got choices
        // now for each choice we calculate how many times
        // target is in the chosen word
        ll maxcount = 0;
        ll totcount = 0;
        ll numchoices = 0;
        for (string s : choices) {
            ll poscount = 0;
            size_t pos = s.find(target, 0);
            while (pos != string::npos) {
                poscount++;
                pos = s.find(target, pos+1);
            }
            maxcount = max(maxcount, poscount);
            totcount += poscount;
            numchoices++;
        }
        // maxcount is number of expected bananas
        result = maxcount - ((double)totcount/(double)numchoices);

        cout << "Case #" << I << ": " << setprecision(10) << result << endl;
    }
    return 0;
}

