#include<bits/stdc++.h>
#include<deque>
using namespace std;
#define fs first
#define sc second
#define p 1000000007
#define pb push_back
#define mp make_pair
typedef long long Int;
typedef pair<Int,Int> pii;
typedef vector<Int> vi;
typedef vector<pii> vii;
int main()
{
Int T;
cin>>T;
for(int k=1;k<=T;k++)
{
	string s;
	cin>>s;
	deque<char> dq;
	dq.push_back(s[0]);
	for(int i=1;i<s.length();i++)
	{
		if(*dq.crbegin()>s[i])
			dq.push_front(s[i]);
		else
			dq.push_back(s[i]);
	}

	deque<char> :: iterator rit;
	cout<<"Case #"<<k<<": ";
	 for (auto rit = dq.crbegin(); rit != dq.crend(); ++rit)
     cout << *rit;
  cout<<endl;

}


	return 0;
}
/*
Case #1: CAB
Case #2: MJA
Case #3: OCDE
Case #4: BBAAA
Case #5: CCCABBBAB
Case #6: CCCBAABAB
Case #7: ZXCASDQWE
*/
