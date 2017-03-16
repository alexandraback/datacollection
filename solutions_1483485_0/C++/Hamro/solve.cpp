#include<iostream>
#include<string>

using namespace std;

char w[30];

int main()
{
	w[0] = 'y';
	w[1] = 'h';
	w[2] = 'e';
	w[3] = 's';
	w[4] = 'o';
	w[5] = 'c';
	w[6] = 'v';
	w[7] = 'x';
	w[8] = 'd';
	w[9] = 'u';
	w[10] = 'i';
	w[11] = 'g';
	w[12] = 'l';
	w[13] = 'b';
	w[14] = 'k';
	w[15] = 'r';
	w[16] = 'z';
	w[17] = 't';
	w[18] = 'n';
	w[19] = 'w';
	w[20] = 'j';
	w[21] = 'p';
	w[22] = 'f';
	w[23] = 'm';
	w[24] = 'a';
	w[25] = 'q';
	int t;
	cin >> t;
	int test = 0;
	while(t > -1)
	{
		string s;
		getline(cin , s);
		string ans ="";
		for(int i=0  ; i < s.length() ; i++)
		{
			if(s[i] == ' ')
			{
				ans += s[i] ;
				continue;
			}
			int q = s[i];
			q-=97;
			ans += w[q];
		}
		if(test > 0)
			cout <<  "Case #"<<test<<": " << ans << endl;
		test++;
		t--;
	}
}
