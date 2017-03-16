#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++)
	{		
		string S;
		cin >> S;//scanf("%s\n",&S);
		unordered_map <char,int> letter;
		vector <int> digit(10,0);
		for(int i=0;i<S.length();i++) letter[S[i]]++;
		digit[0]=letter['Z'];
		letter['E']-=digit[0]; letter['R']-=digit[0];  letter['O']-=digit[0];
		digit[2]=letter['W'];
		letter['T']-=digit[2]; letter['O']-=digit[2];
		digit[8]=letter['G'];
		letter['E']-=digit[8]; letter['I']-=digit[8]; letter['H']-=digit[8]; letter['T']-=digit[8];
		digit[3]=letter['H'];
		letter['T']-=digit[3]; letter['R']-=digit[3]; letter['E']-=2*digit[3];
		digit[4]=letter['R'];
		letter['F']-=digit[4]; letter['O']-=digit[4]; letter['U']-=digit[4];
		digit[5]=letter['F'];
		letter['I']-=digit[5]; letter['V']-=digit[5]; letter['E']-=digit[5];
		digit[6]=letter['X'];
		letter['S']-=digit[6]; letter['I']-=digit[6];
		digit[7]=letter['V'];
		letter['S']-=digit[7]; letter['E']-=2*digit[7]; letter['N']-=digit[7];
		digit[1]=letter['O'];
		letter['N']-=digit[1]; letter['E']-=digit[1];
		digit[9]=letter['I'];
		letter['N']-=2*digit[9]; letter['E']-=digit[9];
		string R="";
		for(int i=0;i<10;i++) for(int j=0;j<digit[i];j++) R+=to_string(i);
		
		cout << "Case #" << t << ": " << R << endl;
		//printf("Case #%d: %s\n",t,R.c_str());
	}
  return 0;
}
