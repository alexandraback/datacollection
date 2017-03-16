#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	int i1, i2, i3, i4, i, i8;
	int t, no, d[10], n[10], w[10], e[10], s[10], del_d[10], del_p[10], del_s[10];
	cin >> t;
	ll attacks;
	map<int, int> segment;

	for(int k=1; k<=t; ++k)
	{
		segment.clear();
		attacks = 0;
		cin >> no;
		for(i=0; i<no; ++i){
			cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> del_d[i] >> del_p[i] >> del_s[i];
		}
		for(int time=0; time<= 676060; ++time)
		{
			for(i=0; i<no; ++i){
				if(d[i] == time){
					for(i8=1; i8<=n[i]; ++i8){
						bool success = false;
						for(i2=w[i]; i2<=e[i]; ++i2){
							if(segment[i2] < s[i]){
								success = true;
								segment[i] = s[i];
							}
						}
						if(success){
							++attacks;
						}
						e[i] += del_p[i];
						w[i] += del_p[i];
						s[i] += del_s[i];
					}
				}
				d[i] += del_d[i];


			} // attacker end
		} // time end

		cout << "Case #" << k << ": " << attacks << endl;
	}

	return 0;
} 