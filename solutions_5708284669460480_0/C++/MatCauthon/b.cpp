#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int longest_suffix(string s)
{
	std::vector<int> v(s.size(),0);;
	v[0] = -1;
	v[1] = 0;
	for (int pos = 2,i=0; pos < s.size();)
	{
		if (s[pos-1]==s[i])
		{
			i++;
			v[pos] = i;
			pos++;
		}
		else if (i>0) i = v[i];
		else 
		{
			v[pos] = 0;
			pos++;
		}
	}
	return v[v.size()-1];
}

int max_repeat(string s, int space)
{
	int overlap = longest_suffix(s + "a");
	//cout << "overlap is " << overlap << endl;
	int max = 0;

	int repeat_space = space - s.size();
	max = 1 + (repeat_space/(s.size()-overlap));
	return max;
}

double target_prob(string keyboard, string target)
{
	double prob=1;
	std::map<char, int> count;
	for (int i = 0; i < keyboard.size(); ++i)
	{
		if (count.find(keyboard[i]) != count.end())
			count[keyboard[i]]++;
		else count[keyboard[i]] = 1;
	}

	for (int i = 0; i < target.size(); ++i)
	{
		if (count.find(target[i]) != count.end())
			prob = prob * ( count[target[i]] / (keyboard.size()*1.0) );
		else
		{
			prob = 0;
			break;
		}
	}
	return prob;
}

int main()
{
        int t;
        cin >> t;
        for (int j=1;j<=t;j++)
        {
        	double ans;
        	int k,l,s;
        	cin >> k >> l >> s;
        	string keyboard,target;
        	cin >> keyboard >> target;

        	int max = max_repeat(target,s);
        	double prob = target_prob(keyboard,target);
        	int possible_places = s - (target.size()-1);
      //  	cout << max << "  " << possible_places << " " << prob << " is the case\n";
        	if (prob == 0) max = 0;
        	ans = (double)max - (possible_places * prob);
            cout << "Case #" << j;
            printf(": %lf\n",ans);
        }

        return 0;
}