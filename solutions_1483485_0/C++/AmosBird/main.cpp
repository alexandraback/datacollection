#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
string a[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string b[3] = {"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};
char m[256];

int main()
{
    int t;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<a[i].length();j++)
        {
            m[a[i][j]] = b[i][j];
        }
    }
    m['z'] = 'q';
    m['q'] = 'z';
    m[' '] = ' ';
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
	cin>>t;
	cin.ignore();
	string s;
	for (int i=0;i<t;i++)
	{
		getline(cin,s);
		cout<<"Case #"<<i+1<<": ";
		for (int j=0;j<s.length();j++)
		{
			putchar(m[s[j]]);
		}
		putchar('\n');
	}

	return 0;
}
