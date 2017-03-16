#include<string>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N 1000010

using namespace std;

long long vals[N];
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
		int n,i,j,len,run;
		long long ans,t1;
		scanf("%s %d",name,&n);

		for (len=0;name[len]!=0;++len);

		run=0;
		for (i=0;i<len;++i) {
			if(iscons(name[i])) {
				++run;
				if (run>=n) {
					run=n;
					t1=i-n+2;
					vals[i]=t1;
				} else {
					vals[i]=i>0?vals[i-1]:0;
				}
			} else {
				run=0;
					vals[i]=i>0?vals[i-1]:0;
			}
		}


		ans=0;
		for(i=0;i<len;++i)
		{
//		printf("%d %c %lld\n",i,name[i],vals[i]);
		ans+=vals[i];
		}
		printf("Case #%d: %lld\n",ti,ans);
	}
	return 0;
}
