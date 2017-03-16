// GCJ2013R2B.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

#pragma warning(disable:4996)

using namespace std;

int T;
string s;
int dCount;
char d[16];
unordered_set<string> dict;
int best[4096][6];
int c1[10] = {0,1,2,3,4,5,6,7,8,9};
int c2[15][2] = {{0,5},{0,6},{1,6},
			{0,7},{1,7},{2,7},
			{0,8},{1,8},{2,8},{3,8},{0,9},
				 {1,9},
				 {2,9},
				 {3,9},
				 {4,9}};

void init()
{
	FILE *fp = fopen("C:\\Users\\yuazh\\Downloads\\garbled_email_dictionary.txt", "rb");
	
	dict.clear();
	while (fscanf(fp, "%s", d) == 1)
	{
		string v = string(d);
		dict.insert(v);
	}
	cin >> T;
}


void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		cin >> s;

		cout << "Case #" << ca << ": ";
		int N = s.length();
		memset(best, 0, sizeof(best));
		for (int j=1; j<5; j++)
		{
			best[0][j] = 9999;
		}
		for (int i=1; i<=N; i++)
		{
			for (int j=0; j<5; j++)
			{
				best[i][j] = 9999;
			}
			for (int k=1; k<=10 && k<=i; k++)
			{
				string w = s.substr(i-k, k);
				string ow = s.substr(i-k, k);
				if (dict.end() != dict.find(w))
				{
					for (int j=0; j<5-k; j++)
					{
						best[i][j] = best[i-k][j+k];
					}
					for (int j=0; j<4 && j<k; j++)
					{
						if (best[i][0] > best[i-k][j+1])
						{
							best[i][0] = best[i-k][j+1];
						}
					}
				}
				for (int f=0; f<10; f++)
				{
					if (c1[f] > k-1)
						break;
					int index1 = i-k+c1[f];
					int pos = 4-(k-c1[f]-1);
					if (pos < 0)
						pos = 0;
					for (int y=0;y<26;y++)
					{
						if (y+'a' != s[index1])
						{
							const char* tmpc = ow.c_str();
							char tmp[16];
							strcpy(tmp, tmpc);
							tmp[c1[f]] = 'a'+y;
							w = string(tmp);

							if (dict.end() != dict.find(w))
							{
								for (int j=0; j<5 && j-c1[f]<=0; j++)
								{
									if (best[i-k][j] + 1 < best[i][pos])
									{
										best[i][pos] = best[i-k][j] + 1;
									}
								}
							}
						}
					}
				}
				

				for (int f=0; f<15; f++)
				{
					if (c2[f][1] > k-1)
						break;
					int index1 = i-k+c2[f][0];
					int index2 = i-k+c2[f][1];
					int pos = 4-(k-c2[f][1]-1);
					if (pos < 0)
						pos = 0;
					for (int y=0;y<26;y++)
					{
						if (y+'a' != s[index1])
						{
							for (int z=0; z<26;z++)
							{
								if (z+'a' != s[index2])
								{
									const char* tmpc = ow.c_str();
									char tmp[16];
									strcpy(tmp, tmpc);
									tmp[c2[f][0]] = 'a'+y;
									tmp[c2[f][1]] = 'a'+z;
									w = string(tmp);

									if (dict.end() != dict.find(w))
									{
										for (int j=0; j<5 && j-c2[f][0]<=0; j++)
										{
											if (best[i-k][j] + 2 < best[i][pos])
											{
												best[i][pos] = best[i-k][j] + 2;
											}
										}
									}
								}
							}
						}
					}
				}
			}


			
		}
		
		int ob=9999;
		for (int j=0; j<5; j++)
		{
			if (ob > best[N][j])
			{
				ob = best[N][j];
			}
		}
		cout << ob << endl;
		/*for (int i=0; i<=N; i++)
		{
			for (int j=0; j<5; j++)
			{
				cout << best[i][j] << ' ';

			}
			cout << endl;
		}*/
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\C-small-attempt1.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\C-small-attempt1.out", "w", stdout);
	init();
	work();

	return 0;
}

