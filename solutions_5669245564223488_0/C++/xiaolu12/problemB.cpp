//#define CMD
#ifdef CMD
#include <iostream>
#else
#include <fstream>
#endif

#include <algorithm>  

#define MAXN 11
#define MAXLEN 101

using namespace std;

#ifndef CMD
ifstream cin;
ofstream cout;
#endif

int n;
char strs[MAXN][MAXLEN];

bool check(int que[], int k)
{
	int flag[26] = {0};
	char tempch = 0;
	for(int i=0; i<k; ++i)
	{
		char *str = strs[que[i]];
		int len = strlen(str);
		for(int j=0; j<len; ++j){
			if(j==0 && i==0){
				tempch = str[j];
			}else{
				if(tempch != str[j]){
					flag[tempch-'a'] = true;
					tempch = str[j];
					if(flag[tempch-'a']){
						return false;
					}
				}
			}
		}
	}
	return true;
}

int search(int k)
{
	int count = 0;
	int que[MAXN];
	for(int i=0; i<k; ++i){
		que[i] = i;
	}
	if(check(que, k)){
		count++;
	}
	while (next_permutation(que,que+k))
	{
		if(check(que, k)){
			count++;
		}
	}
	return count;
}

int main()
{
#ifndef CMD
	cin.open("B-small-attempt2.in");
	cout.open("B-small-attempt2.out");
#endif
	int t;
	cin>>t;
	for(int i=1; i<=t; ++i)
	{
		cin>>n;
		for(int j=0; j<n; ++j)
		{
			cin>>strs[j];
		}
		/*
		cout<<"Case #"<<i<<": "<<endl;
		for(int j=0; j<n; ++j)
		{
			cout<<strs[j]<<endl;
		}*/
		int count = search(n);
		cout<<"Case #"<<i<<": "<<count<<endl;
	}
	return 0;
}