#include "The_Last_Word.h"
#include <iostream>
#include<string>
#include <algorithm>
#include<fstream>
#include <vector>
#include<cstdio>
#include<math.h>
#include<utility>
#include<queue>
#include<iomanip>



using namespace std;

string push_front(string s, char in){
	string fin = "";
	fin += in;
	for (int i = 0; i < s.size(); i++)
	{
		fin += s[i];
	}
	return fin;
}

	FILE *stream;
int main(){
	//freopen_s(&stream,"C:\\Users\\Sherif\\Desktop\\output.txt", "w", stdout);
	int T; cin >> T;
	for (int k = 0; k < T; k++)
	{
		string s;
		cin >> s;
		string ans;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i]>=ans[0]){
				ans = push_front(ans, s[i]);
			}
			else{
				ans += s[i];
			}
		}
		cout << "Case #" << k + 1 << ": " << ans << endl;
	}
	
	
}