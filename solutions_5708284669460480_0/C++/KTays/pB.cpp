#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define EPS 1e-6

int main()
{
	freopen("D:\\B-small-attempt1.in", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);

	int t, k, l, s;
	int alphabet[30], fc[100],a_num;
	double ans;
	string s1, s2;

	cin >> t;
	for (int tt = 1; tt <= t; tt++){
		memset(alphabet, 0, sizeof(alphabet));
		memset(fc,0,sizeof(fc));
		cin >> k >> l >> s;
		cin >> s1;
		for (int i = 0; i < k; i++){
			alphabet[s1[i] - 'A']++;
		}
		cin >> s2;

		bool is_possible = true;
		for (int i = 0; i < l; i++){
			if (alphabet[s2[i] - 'A'] == 0){
				is_possible = false;
				break;
			}
		}
		if (!is_possible){
			cout << "Case #" << tt << ": " << 0.0 << endl;
			continue;
		}

		fc[0] = -1;
		int it;
		for (int i = 1; i < l; i++){
			it = fc[i - 1];
			while (s2[i] != s2[it + 1] && it >= 0)it = fc[it];
			if (s2[i] == s2[it + 1])fc[i] = it + 1;
			else fc[i] = it;
		}

		int ss = l - fc[l - 1] - 1;
		int cnt;
		if (ss == l){
			cnt = s / l;
		}
		else{
			cnt -= (l - ss) - s%ss;
		}

		double  temp=1;
		for(int i=0;i<s2.size();i++){
		    temp*=alphabet[s2[i]-'A'];
		}

		temp*=pow(s1.size(),s-s2.size())+EPS;
		//temp*=s/s2.size();

		double temp2=pow(s1.size(),s);
		ans=(double)temp/(double)temp2*(double)s/(double)s2.size();

		cout << "Case #" << tt << ": " << (double)cnt-ans << endl;
	}
	//system("pause");
	return 0;
}
