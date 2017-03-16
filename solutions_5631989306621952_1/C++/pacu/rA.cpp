#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string s;
string t;

void calc(int i,int j,int k)	//[i,j] -> [k,l]
{
	if(j<i) return;
	char mx = ' ';
	int cnt = 0;
	for(int c=i;c<=j;c++)
	{
		if(s[c]>mx)
			mx = s[c], cnt = 1;
		else if(s[c]==mx)
			cnt++;
	}
	for(int c=k;c<k+cnt;c++)
		t[c] = mx;
	for(int c=i;c<=j;c++)
	{
		if(s[c]==mx)
		{
			calc(i,c-1,k+cnt);
			int cur = k+cnt+c-i;
			for(int d=c+1;d<=j;d++)
				if(s[d]!=mx)
					t[cur++] = s[d];
			break;
		}
	}
}

void test(int num)
{
	t = "";
	cin >> s;
	for(int i=0;i<s.size();i++)
		t += '-';
	calc(0,s.size()-1,0);
	cout << "Case #" << num << ": " << t << '\n';
}

int main()
{
	freopen("testin.txt","r",stdin);
	freopen("testout.txt","w",stdout);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) test(i+1);
}
