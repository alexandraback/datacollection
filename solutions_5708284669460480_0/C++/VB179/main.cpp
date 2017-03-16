#include <fstream>
#include <string>
#include <vector>

using namespace std;

double solve(string, string, int);

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int t;
    fin >> t;
    fout.precision(16);
    for (int i = 1; i <= t; i++)
    {
        int k, l, s;
        fin >> k >> l >> s;
        string keys, word;
        fin >> keys >> word;

        fout << "Case #" << i << ": " << solve(keys, word, s) << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

bool canType(string keys, string word)
{
    bool has[26];
    for (int i = 0; i < 26; i++)
        has[i] = false;
    for (int i = 0; i < keys.length(); i++)
        has[keys[i] - 'A'] = true;
    for (int i = 0; i < word.length(); i++)
        if (!has[word[i] - 'A'])
            return false;

    return true;
}

vector<double> countProbs(string keys)
{
    vector<double> probs(26);
    for (int i = 0; i < 26; i++)
        probs[i] = 0;
    for (int i = 0; i < keys.length(); i++)
        probs[keys[i] - 'A']++;
    for (int i = 0; i < 26; i++)
        probs[i] /= keys.length();

    return probs;
}

int countEntries(string str, string patt)
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        bool f = true;
        for (int j = 0; j < patt.length(); j++)
            if (i + j >= str.length() || str[i + j] != patt[j])
            {
                f = false;
                break;
            }
        if (f)
            cnt++;
    }

    return cnt;
}

void dfs(string curr, vector<double> probs, double p, vector<char> letters, int s, double & exp, string word)
{
    if (curr.length() == s)
    {
        exp += p * countEntries(curr, word);
    }
    else
    {
        for (int i = 0; i < letters.size(); i++)
            dfs(curr + letters[i], probs, p * probs[letters[i] - 'A'], letters, s, exp, word);
    }
}

double countExpected(string keys, string word, int s)
{
    int L = word.length();
    vector<double> probs = countProbs(keys);
    bool has[26];
    for (int i = 0; i < 26; i++)
        has[i] = false;
    vector<char> letters;
    for (int i = 0; i < keys.length(); i++)
        if (!has[keys[i] - 'A'])
        {
            has[keys[i] - 'A'] = true;
            letters.push_back(keys[i]);
        }

    double exp = 0;
    dfs("", probs, 1, letters, s, exp, word);

    return exp;
}

vector<int> prefix_function (string s)
{
	int n = s.length();
	vector<int> pi(n);

	for (int i = 1; i < n; i++)
    {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
            j++;
		pi[i] = j;
	}

	return pi;
}

int countMax(string word, int s)
{
    int L = word.length();
    vector<int> pi = prefix_function(word);
    int step = L - pi[L - 1];

    return (s - L) / step + 1;
}

double solve(string keys, string word, int s)
{
    if (!canType(keys, word))
        return 0;
    else
    {
        double expected = countExpected(keys, word, s);
        int maxVal = countMax(word, s);

        return maxVal - expected;
    }
}
