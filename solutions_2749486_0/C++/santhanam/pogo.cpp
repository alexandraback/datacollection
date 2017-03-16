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

		int x,y,sign;
		string xdir,ydir;
		scanf("%d %d",&x,&y);
		if (x!=0) {

			if (x<0) sign=-1;
			else sign=1;
			
			x*=sign;
			while(x>0) {
				if (sign==1) {
				xdir+='W';
				xdir+='E';
				} else {
				xdir+='E';
				xdir+='W';
				}
				
				--x;
			}
				
		}	
		if (y!=0) {

			if (y<0) sign=-1;
			else sign=1;
			
			y*=sign;
			while(y>0) {
				if (sign==1) {
				ydir+='S';
				ydir+='N';
				} else {
				ydir+='N';
				ydir+='S';
				}
				
				--y;
			}
				
		}	
	
		cout<<"Case #"<<ti<<": "<<xdir+ydir<<endl;
	}
	return 0;
}
	
