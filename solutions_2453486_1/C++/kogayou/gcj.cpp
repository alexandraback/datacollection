#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int casenum,T;
int flag;
bool over;
void check(char a, char b, char c, char d)
{
	if (a=='.'||b=='.'||c=='.'||d=='.')
	{
		over=0;
		return;
	}
	if (a!='O'&&b!='O'&&c!='O'&&d!='O')	flag=1;
	if (a!='X'&&b!='X'&&c!='X'&&d!='X')	flag=2;

}
int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);
	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		string s[4];
		for (int i=0;i<4;i++)
			cin>>s[i];
		flag=0;
		over=1;
		for (int i=0;i<4;i++)
		{
			check(s[0][i],s[1][i],s[2][i],s[3][i]);
			check(s[i][0],s[i][1],s[i][2],s[i][3]);
		}
		check(s[0][0],s[1][1],s[2][2],s[3][3]);
		check(s[0][3],s[1][2],s[2][1],s[3][0]);
		if (flag==1)	cout<<"X won"<<endl;
		else if (flag==2)	cout<<"O won"<<endl;
		else if (over)	cout<<"Draw"<<endl;
		else	cout<<"Game has not completed"<<endl;
	}
	return 0;
}
