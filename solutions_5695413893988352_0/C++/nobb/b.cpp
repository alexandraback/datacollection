#include <fstream>
#include <string>
using namespace std;

int main()
{
	//ifstream infile("B-sample");
	ifstream infile("B-small-attempt1.in");
    ofstream outfile("B-output");
    int t;
    infile >> t;
    for (int ca = 1; ca <= t; ++ca)
    {
        outfile << "Case #" << ca << ": ";
        string s1, s2;
        infile >> s1;
        infile >> s2;
        int len = s1.length();
        //equal
        int i = 0;
        unsigned long long x1 = 0, x2 = 0, delta = 1000000000000000000;
        string ans1, ans2;
        for (i = 0; i < len; ++i)
        {
        	if (s1[i] == '?' && s2[i] == '?')
        	{
        		string s1p, s2p;

        		s1p = s1; s2p = s2;
	        	s1p[i] = '0'; s2p[i] = '1';
	        	unsigned long long tmp1, tmp2, tmpd;
	        	for (int j = i+1; j < len; ++j)
	        	{
	        		if (s1p[j] == '?') s1p[j] = '9';
        			if (s2p[j] == '?') s2p[j] = '0';
	        	}
	        	tmp1 = stoull(s1p, NULL, 10);
	        	tmp2 = stoull(s2p, NULL, 10);
	        	tmpd = (tmp1 > tmp2)? (tmp1 - tmp2): (tmp2 - tmp1);
	        	if (tmpd < delta || (tmpd == delta && tmp1 <= x1 && tmp2 <= x2))
	        	{
	        		x1 = tmp1; x2 = tmp2; delta = tmpd;
	        		ans1 = s1p; ans2 = s2p;
	        	}

	        	s1p = s1; s2p = s2;
	        	s1p[i] = '1'; s2p[i] = '0';
	        	for (int j = i+1; j < len; ++j)
	        	{
	        		if (s1p[j] == '?') s1p[j] = '0'; 
	        		if (s2p[j] == '?') s2p[j] = '9';
	        	}
	        	tmp1 = stoull(s1p, NULL, 10);
	        	tmp2 = stoull(s2p, NULL, 10);
	        	tmpd = (tmp1 > tmp2)? (tmp1 - tmp2): (tmp2 - tmp1);
	        	if (tmpd < delta || (tmpd == delta && tmp1 <= x1 && tmp2 <= x2))
	        	{
	        		x1 = tmp1; x2 = tmp2; delta = tmpd;
	        		ans1 = s1p; ans2 = s2p;
	        	}

        		s1[i] = '0'; s2[i] = '0';
        	}
        	else if (s1[i] == '?')
        	{
        		string s1p, s2p;
        		unsigned long long tmp1, tmp2, tmpd;
        		if (s2[i] > '0')
	        	{
	        		s1p = s1; s2p = s2;
		        	s1p[i] = s2[i] - 1;
		        	unsigned long long tmp1, tmp2, tmpd;
		        	for (int j = i+1; j < len; ++j)
		        	{
		        		if (s1p[j] == '?') s1p[j] = '9';
	        			if (s2p[j] == '?') s2p[j] = '0';
		        	}
		        	tmp1 = stoull(s1p, NULL, 10);
		        	tmp2 = stoull(s2p, NULL, 10);
		        	tmpd = (tmp1 > tmp2)? (tmp1 - tmp2): (tmp2 - tmp1);
		        	if (tmpd < delta || (tmpd == delta && tmp1 <= x1 && tmp2 <= x2))
		        	{
		        		x1 = tmp1; x2 = tmp2; delta = tmpd;
		        		ans1 = s1p; ans2 = s2p;
		        	}
		        }
		        if (s2[i] < '9')
		        {
		        	s1p = s1; s2p = s2;
	        		s1p[i] = s2[i] + 1;
		        	for (int j = i+1; j < len; ++j)
		        	{
		        		if (s1p[j] == '?') s1p[j] = '0'; 
		        		if (s2p[j] == '?') s2p[j] = '9';
		        	}
		        	tmp1 = stoull(s1p, NULL, 10);
		        	tmp2 = stoull(s2p, NULL, 10);
		        	tmpd = (tmp1 > tmp2)? (tmp1 - tmp2): (tmp2 - tmp1);
		        	if (tmpd < delta || (tmpd == delta && tmp1 <= x1 && tmp2 <= x2))
		        	{
		        		x1 = tmp1; x2 = tmp2; delta = tmpd;
		        		ans1 = s1p; ans2 = s2p;
		        	}
		        }
        		s1[i] = s2[i];
        	}
        	else if (s2[i] == '?')
        	{
        		string s1p, s2p;
        		unsigned long long tmp1, tmp2, tmpd;
        		if (s1[i] > '0')
	        	{
	        		s1p = s1; s2p = s2;
		        	s2p[i] = s1[i] - 1;
		        	unsigned long long tmp1, tmp2, tmpd;
		        	for (int j = i+1; j < len; ++j)
		        	{
		        		if (s1p[j] == '?') s1p[j] = '0';
	        			if (s2p[j] == '?') s2p[j] = '9';
		        	}
		        	tmp1 = stoull(s1p, NULL, 10);
		        	tmp2 = stoull(s2p, NULL, 10);
		        	tmpd = (tmp1 > tmp2)? (tmp1 - tmp2): (tmp2 - tmp1);
		        	if (tmpd < delta || (tmpd == delta && tmp1 <= x1 && tmp2 <= x2))
		        	{
		        		x1 = tmp1; x2 = tmp2; delta = tmpd;
		        		ans1 = s1p; ans2 = s2p;
		        	}
		        }
		        if (s1[i] < '9')
		        {
		        	s1p = s1; s2p = s2;
	        		s2p[i] = s1[i] + 1;
		        	for (int j = i+1; j < len; ++j)
		        	{
		        		if (s1p[j] == '?') s1p[j] = '9'; 
		        		if (s2p[j] == '?') s2p[j] = '0';
		        	}
		        	tmp1 = stoull(s1p, NULL, 10);
		        	tmp2 = stoull(s2p, NULL, 10);
		        	tmpd = (tmp1 > tmp2)? (tmp1 - tmp2): (tmp2 - tmp1);
		        	if (tmpd < delta || (tmpd == delta && tmp1 <= x1 && tmp2 <= x2))
		        	{
		        		x1 = tmp1; x2 = tmp2; delta = tmpd;
		        		ans1 = s1p; ans2 = s2p;
		        	}
		        }
        		s2[i] = s1[i];
        	}
        	else // no ?
        	{
        		if (s1[i] != s2[i]) break;
        	}
        }
        // s1 > s2
        if (s1[i] > s2[i])
        {
        	while (i < len)
        	{
        		if (s1[i] == '?') s1[i] = '0';
        		if (s2[i] == '?') s2[i] = '9';
        		++i;
        	}
        	unsigned long long tmp1, tmp2, tmpd;
        	tmp1 = stoull(s1, NULL, 10);
        	tmp2 = stoull(s2, NULL, 10);
        	tmpd = (tmp1 > tmp2)? (tmp1 - tmp2): (tmp2 - tmp1);
        	if (tmpd < delta || (tmpd == delta && tmp1 <= x1 && tmp2 <= x2))
        	{
        		x1 = tmp1; x2 = tmp2; delta = tmpd;
        		ans1 = s1; ans2 = s2;
        	}
        }
        // s1 < s2
        else
        {
        	while (i < len)
        	{
        		if (s1[i] == '?') s1[i] = '9';
        		if (s2[i] == '?') s2[i] = '0';
        		++i;
        	}
        	unsigned long long tmp1, tmp2, tmpd;
        	tmp1 = stoull(s1, NULL, 10);
        	tmp2 = stoull(s2, NULL, 10);
        	tmpd = (tmp1 > tmp2)? (tmp1 - tmp2): (tmp2 - tmp1);
        	if (tmpd < delta || (tmpd == delta && tmp1 <= x1 && tmp2 <= x2))
        	{
        		x1 = tmp1; x2 = tmp2; delta = tmpd;
        		ans1 = s1; ans2 = s2;
        	}
        }

        outfile << ans1;
        outfile << " ";
    	outfile << ans2;
    	outfile << endl;

    }
	return 0;
}