#include<string>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 1010

using namespace std;

bool iscons(char a)
{
	if (a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
	return 0;
return 1;
}

bool  string_has_n_cons(string s,int n)
{
	int run=0;
	for(int i=0;i<s.length();++i) {
		if(iscons(s[i])) {
		++run;
		if (run>=n)
		return 1;
		} else {
		run=0;
		}
	}
	return 0;
}
int main()
{
	int ti,tc;
	scanf("%d",&tc);
	for (ti=1;ti<=tc;++ti) {
	
		char name[N];
		int n,ans=0,i,j,len;
		string str;
		scanf("%s %d",name,&n);
		str=name;
		len=str.length();
		for(j=0;j<len;++j) {
			for(i=1;i<=len-j;++i) {
				if(string_has_n_cons(str.substr(j,i),n)) ++ans;
//				cout<<str.substr(j,i)<<"ans is "<<ans<<endl;
			}
		}
		printf("Case #%d: %d\n",ti,ans);
	}
	return 0;
}
