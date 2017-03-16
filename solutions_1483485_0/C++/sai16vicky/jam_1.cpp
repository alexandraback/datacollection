#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<string>
#include<algorithm>
#include<map>	
using namespace std;
string res="yhesocvxduiglbkrztnwjpfmaq";
string alpha="abcdefghijklmnopqrstuvwxyz";
int main()
{
	int t;
	scanf("%d\n",&t);
//	getchar();
	for(int tt=1;tt<=t;tt++)
	{
			char str[110];
			gets(str);


			int  len=strlen(str);
			string ans;

			for(int i=0;i<len;i++)
			{
				int chk=1;
				for(int j=0;j<26;j++)
				if(str[i]==alpha[j])
				{
					ans+=res[j];
					chk=0;
					break;
				}	
				if(chk)ans+=' ';
			}
			printf("Case #%d: ",tt);
			cout<<ans<<"\n";
			
	}		
	return 0;
}
