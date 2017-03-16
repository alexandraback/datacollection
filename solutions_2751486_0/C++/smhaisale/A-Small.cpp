#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>

using namespace std;

vector<long int> pos;

bool isConsonant(char c)
{
	if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
	if((c - 'a') < 26 && (c - 'a') >= 0)
	return true;
	
	return false;
}

int check(string str, int n)
{
	int temp = 0;
	int length = str.length();
	for(int i = 0; i < length-n+1; i++)
	{
		temp = 0;
		for(int j = i; j < i+n; j++)
		{
			if(isConsonant(str[j]))
			{
				temp++;
				if(temp == n)
				break;
			}
			else break;
		}
		if(temp == n)
		pos.push_back(i);
	}
}

struct Pair
{
	int a;
	int b;
};

vector<Pair> subs;

int main(void)
{
	freopen("C:/Downloads/A-sm.in", "r", stdin);
	freopen("C:/Downloads/A-sm.out", "w+", stdout);
	
	int T;
	cin>>T;
	int cas = 1;
	while(T--)
	{
		pos.clear();
		subs.clear();
		string str;
		cin>>str;
		int n; 
		cin>>n;
		int length = str.size();
		check(str, n);
		long int res = 0;
		for(int i = 0; i < pos.size(); i++)
		{
			int value = (length - pos[i] - n + 1)*(pos[i] + 1) - 1;
			for(int a = 0; a < pos[i] + 1; a++)
			{
				for(int b = pos[i] + n - 1; b < length; b++)
				{
					Pair p = {a, b};
					int j;
					for(j = 0; j < subs.size(); j++)
					{
						if(subs[j].a == a && subs[j].b == b)
						break;						
					}
					if(j == subs.size())
					subs.push_back(p);
				}
			}
		}
		cout<<"Case #"<<cas++<<": "<<subs.size()<<endl;
	}
	return 0;
}
