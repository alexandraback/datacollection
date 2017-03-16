/* 
 * File:   main.cpp
 * Author: roman
 *
 * Created on 10 травня 2015, 11:45
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

string generate_combination(const string& keys, int count, int number)
{
    string res;
    res.reserve(count);
    for (int i = 0; i < count; i++)
    {
        res += keys[number % keys.size()];
        number /= keys.size();
    }
    return res;
}

void test(int ti)
{
    int k, l, s;
    cin >> k >> l >> s;
    
    string keys, target;
    cin >> keys >> target;
    
    int combinations = 1;
    for (int i = 0; i < s; i++)
        combinations *= k;
    
    vector<int> counts(s + 1);
    
    for (int i = 0; i < combinations; i++)
    {
        string comb = generate_combination(keys, s, i);
        //cout << comb << endl;
        vector<int> pf = prefix_function(target + "$" + comb);
        int cnt = count(pf.begin(), pf.end(), l);
        counts[cnt]++;
    }
    
    double result = 0;
    
    for (int i = 0; i <= s; i++)
        result += i * double(counts[i]) / combinations;
    
    int max_cnt = 0;
    for (int i = s; i >= 0; i--)
        if (counts[i] != 0)
        {
            max_cnt = i;
            break;
        }
    
    cout << "Case #" << ti << ": " << max_cnt - result << endl;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        test(i+1);
    return 0;
}

