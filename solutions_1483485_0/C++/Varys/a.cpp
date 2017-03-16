#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

const char a[]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
const char b[]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
const char c[]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
char a2[]="our language is impossible to understand";
char b2[]="there are twenty six factorial possibilities";
char c2[]="so it is okay if you want to just give up";
char gumap[26];
int main(){
	freopen("A-small-practice.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	char* ptr;
	string str,str2;
	int i=0;
	int index=0;
	int sum=0,sum2=0;
	int count=0;
	int T=0;
	int clen=strlen(a);
	gumap['q'-'a']='z';
	
	for(i=0;i<clen;i++)
		if(a[i]>=97 && a[i]<=122)
	    	gumap[a[i]-'a']=a2[i];
	clen=strlen(b);
	for(i=0;i<clen;i++)
		if(b[i]>=97 && b[i]<=122)
	    	gumap[b[i]-'a']=b2[i];
	clen=strlen(c);
	for(i=0;i<clen;i++)
		if(c[i]>=97 && c[i]<=122)
	    	gumap[c[i]-'a']=c2[i];
	for(int j=0;j<26;j++)
		{
			if(gumap[j]<97 || gumap[j]>122)
			{
				/*if(j != 'q'-'a')*/
					index=j;
				count++;
			}
			else
				sum+=gumap[j];
			sum2+=('a'+j);
		}
	gumap[index]=sum2-sum;
	scanf("%d",&T);
	getline(cin,str);
	for(i=1;i<=T;i++)
	{
		getline(cin,str);
		str2.clear();
		// scanf("%s",str);
		for(int j=0;j<str.length();j++)
			if(str[j]>=97 && str[j]<=122)
				str2.push_back(gumap[str[j]-'a']);
			else if(str[j]==32)
				str2.push_back(32);
			else
				cout<<"error."<<endl;
		
		printf("Case #%d: ", i);
		for(int j=0;j<str.length();j++)
			printf("%c",str2[j]);
		printf("\n");
		// cout<<str2<<endl;
	}
	return 0;
}






















