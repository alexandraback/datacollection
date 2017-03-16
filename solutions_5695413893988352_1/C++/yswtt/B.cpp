#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

struct ll
{
	long long dif;
	string s1, s2;
	long long n1, n2;
};

ll f[22][3]; // 0 larger, 1 equal, 2 smaller

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; i <= s1.length(); ++i)
			f[i][0].dif = f[i][1].dif = f[i][2].dif = -1;
		f[0][1].dif = 0;
		f[0][1].s1 = f[0][1].s2 = "";
		f[0][1].n1 = f[0][1].n2 = 0;
		for (int i = 0; i < s1.length(); ++i)
		{
			if (f[i][0].dif != -1)
			{
				f[i+1][0].dif = f[i][0].dif * 10;
				f[i+1][0].s1 = f[i][0].s1;
				f[i+1][0].s2 = f[i][0].s2;
				f[i+1][0].n1 = f[i][0].n1 * 10;
				f[i+1][0].n2 = f[i][0].n2 * 10;
				if (s1[i] == '?')
				{
					f[i+1][0].s1 += "0";
				}
				else
				{
					f[i+1][0].s1 += s1[i];
					f[i+1][0].dif += s1[i] - '0';
					f[i+1][0].n1 += s1[i] - '0';
				}
				if (s2[i] == '?')
				{
					f[i+1][0].s2 += "9";
					f[i+1][0].dif -= 9;
					f[i+1][0].n2 += 9;
				}
				else
				{
					f[i+1][0].s2 += s2[i];
					f[i+1][0].dif -= s2[i] - '0';
					f[i+1][0].n2 += s2[i] - '0';
				}
			}
			
			
			if (f[i][2].dif != -1)
			{
				f[i+1][2].dif = f[i][2].dif * 10;
				f[i+1][2].s1 = f[i][2].s1;
				f[i+1][2].s2 = f[i][2].s2;
				f[i+1][2].n1 = f[i][2].n1 * 10;
				f[i+1][2].n2 = f[i][2].n2 * 10;
				if (s1[i] == '?')
				{
					f[i+1][2].s1 += "9";
					f[i+1][2].dif -= 9;
					f[i+1][2].n1 += 9;
				}
				else
				{
					f[i+1][2].s1 += s1[i];
					f[i+1][2].dif -= s1[i] - '0';
					f[i+1][2].n1 += s1[i] - '0';
				}
				if (s2[i] == '?')
				{
					f[i+1][2].s2 += "0";
				}
				else
				{
					f[i+1][2].s2 += s2[i];
					f[i+1][2].dif += s2[i] - '0';
					f[i+1][2].n2 += s2[i] - '0';
				}
			}
			
			if (f[i][1].dif != -1)
			{
				if ((s1[i] == s2[i]) || (s1[i] == '?') || (s2[i] == '?'))
				{
					f[i+1][1].dif = 0;
					f[i+1][1].s1 = f[i][1].s1;
					f[i+1][1].s2 = f[i][1].s2;
					f[i+1][1].n1 = f[i][1].n1 * 10;
					f[i+1][1].n2 = f[i][1].n2 * 10;
					if ((s1[i] == '?') && (s2[i] == '?'))
					{
						f[i+1][1].s1 += "0";
						f[i+1][1].s2 += "0";
						if ((f[i+1][0].dif == -1) || (f[i+1][0].dif > 1) || ((f[i+1][0].dif == 1) && (f[i+1][1].n1+1 < f[i+1][0].n1)))
						{
							f[i+1][0].dif = 1;
							f[i+1][0].s1 = f[i][1].s1 + "1";
							f[i+1][0].s2 = f[i][1].s2 + "0";
							f[i+1][0].n1 = f[i+1][1].n1 + 1;
							f[i+1][0].n2 = f[i+1][1].n2;
						}
						
						if ((f[i+1][2].dif == -1) || (f[i+1][2].dif > 1) || ((f[i+1][2].dif == 1) && (f[i+1][1].n1 < f[i+1][2].n1)))
						{
							f[i+1][2].dif = 1;
							f[i+1][2].s1 = f[i][1].s1 + "0";
							f[i+1][2].s2 = f[i][1].s2 + "1";
							f[i+1][2].n1 = f[i+1][1].n1;
							f[i+1][2].n2 = f[i+1][1].n2 + 1;
						}
					}
					else if (s1[i] == '?')
					{
						f[i+1][1].s1 += s2[i];
						f[i+1][1].s2 += s2[i];
						f[i+1][1].n1 += s2[i] - '0';
						f[i+1][1].n2 += s2[i] - '0';
						
						if ((s2[i] != '9') && ((f[i+1][0].dif == -1) || (f[i+1][0].dif > 1) || ((f[i+1][0].dif == 1) && (f[i+1][1].n1+1 < f[i+1][0].n1))))
						{
							f[i+1][0].dif = 1;
							f[i+1][0].s1 = f[i][1].s1 + char(s2[i] + 1);
							f[i+1][0].s2 = f[i][1].s2 + s2[i];
							f[i+1][0].n1 = f[i+1][1].n1 + 1;
							f[i+1][0].n2 = f[i+1][1].n2;
						}
						
						if ((s2[i] != '0') && ((f[i+1][2].dif == -1) || (f[i+1][2].dif > 1) || ((f[i+1][2].dif == 1) && (f[i+1][1].n1-1 < f[i+1][2].n1))))
						{
							f[i+1][2].dif = 1;
							f[i+1][2].s1 = f[i][1].s1 + char(s2[i] - 1);
							f[i+1][2].s2 = f[i][1].s2 + s2[i];
							f[i+1][2].n1 = f[i+1][1].n1 - 1;
							f[i+1][2].n2 = f[i+1][1].n2;
						}
					}
					else if (s2[i] == '?')
					{
						f[i+1][1].s1 += s1[i];
						f[i+1][1].s2 += s1[i];
						f[i+1][1].n1 += s1[i] - '0';
						f[i+1][1].n2 += s1[i] - '0';
						
						if ((s1[i] != '0') && ((f[i+1][0].dif == -1) || (f[i+1][0].dif > 1) || ((f[i+1][0].dif == 1) && (f[i+1][1].n1 < f[i+1][0].n1))))
						{
							f[i+1][0].dif = 1;
							f[i+1][0].s1 = f[i][1].s1 + s1[i];
							f[i+1][0].s2 = f[i][1].s2 + char(s1[i] - 1);
							f[i+1][0].n1 = f[i+1][1].n1;
							f[i+1][0].n2 = f[i+1][1].n2 - 1;
						}
						
						if ((s1[i] != '9') && ((f[i+1][2].dif == -1) || (f[i+1][2].dif > 1) || ((f[i+1][2].dif == 1) && (f[i+1][1].n1 < f[i+1][2].n1))))
						{
							f[i+1][2].dif = 1;
							f[i+1][2].s1 = f[i][1].s1 + s1[i];
							f[i+1][2].s2 = f[i][1].s2 + char(s1[i] + 1);
							f[i+1][2].n1 = f[i+1][1].n1;
							f[i+1][2].n2 = f[i+1][1].n2 + 1;
						}
					}
					else
					{
						f[i+1][1].s1 += s1[i];
						f[i+1][1].s2 += s2[i];
						f[i+1][1].n1 += s1[i] - '0';
						f[i+1][1].n2 += s2[i] - '0';
					}
				}
				else if (s1[i] > s2[i])
				{
					f[i+1][1].dif = -1;
					f[i+1][1].s1 = f[i][1].s1 + s1[i];
					f[i+1][1].s2 = f[i][1].s2 + s2[i];
					f[i+1][1].n1 = f[i][1].n1 * 10 + s1[i] - '0';
					f[i+1][1].n2 = f[i][1].n2 * 10 + s2[i] - '0';
					if ((f[i+1][0].dif == -1) || (f[i+1][0].dif > f[i+1][1].n1 - f[i+1][1].n2) || ((f[i+1][0].dif == f[i+1][1].n1 - f[i+1][1].n2) && (f[i+1][1].n1 < f[i+1][0].n1)))
					{
						f[i+1][0].dif = f[i+1][1].n1 - f[i+1][1].n2;
						f[i+1][0].n1 = f[i+1][1].n1;
						f[i+1][0].n2 = f[i+1][1].n2;
						f[i+1][0].s1 = f[i+1][1].s1;
						f[i+1][0].s2 = f[i+1][1].s2;
					}
				}
				else if (s1[i] < s2[i])
				{
					f[i+1][1].dif = -1;
					f[i+1][1].s1 = f[i][1].s1 + s1[i];
					f[i+1][1].s2 = f[i][1].s2 + s2[i];
					f[i+1][1].n1 = f[i][1].n1 * 10 + s1[i] - '0';
					f[i+1][1].n2 = f[i][1].n2 * 10 + s2[i] - '0';
					if ((f[i+1][2].dif == -1) || (f[i+1][2].dif > f[i+1][1].n2 - f[i+1][1].n1) || ((f[i+1][2].dif == f[i+1][1].n2 - f[i+1][1].n1) && (f[i+1][1].n1 < f[i+1][2].n1)))
					{
						f[i+1][2].dif = f[i+1][1].n2 - f[i+1][1].n1;
						f[i+1][2].n1 = f[i+1][1].n1;
						f[i+1][2].n2 = f[i+1][1].n2;
						f[i+1][2].s1 = f[i+1][1].s1;
						f[i+1][2].s2 = f[i+1][1].s2;
					}
				}
			}
		}
		
		cout << "Case #" << t << ": ";
		if (f[s1.length()][1].dif != -1)
			cout << f[s1.length()][1].s1 << " " << f[s1.length()][1].s2 << endl;
		else if (f[s1.length()][0].dif == -1)
			cout << f[s1.length()][2].s1 << " " << f[s1.length()][2].s2 << endl;
		else if (f[s1.length()][2].dif == -1)
			cout << f[s1.length()][0].s1 << " " << f[s1.length()][0].s2 << endl;
		else if (f[s1.length()][0].dif < f[s2.length()][2].dif)
			cout << f[s1.length()][0].s1 << " " << f[s1.length()][0].s2 << endl;
		else if (f[s1.length()][2].dif < f[s2.length()][0].dif)
			cout << f[s1.length()][2].s1 << " " << f[s1.length()][2].s2 << endl;
		else if (f[s1.length()][0].n1 < f[s1.length()][2].n1)
			cout << f[s1.length()][0].s1 << " " << f[s1.length()][0].s2 << endl;
		else if (f[s1.length()][0].n1 > f[s1.length()][2].n1)
			cout << f[s1.length()][2].s1 << " " << f[s1.length()][2].s2 << endl;
		else if (f[s1.length()][0].n2 < f[s1.length()][2].n2)
			cout << f[s1.length()][0].s1 << " " << f[s1.length()][0].s2 << endl;
		else
			cout << f[s1.length()][2].s1 << " " << f[s1.length()][2].s2 << endl;
	}

    return 0;
}
