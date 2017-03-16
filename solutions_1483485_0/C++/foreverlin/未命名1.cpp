#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<numeric>
#include<cctype>
using namespace std;
char num[256];

int main(){
	num[0]='y';
	num[1]='h';
	num[2]='e';
	num[3]='s';
	num[4]='o';
	num[5]='c';
	num[6]='v';
	num[7]='x';
	num[8]='d';
	num[9]='u';
	num[10]='i';
	num[11]='g';
	num[12]='l';
	num[13]='b';
	num[14]='k';
	num[15]='r';
	num[16]='z';
	num[17]='t';
	num[18]='n';
	num[19]='w';
	num[20]='j';
	num[21]='p';
	num[22]='f';
	num[23]='m';
	num[24]='a';
	num[25]='q';
	int T;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	string s1,s2;
	getline(cin,s1);
	for(int ca=1;ca<=T;ca++){
		getline(cin,s1);
		string s2="";
		for(int i=0;i<s1.length();i++){
			if(islower(s1[i]))s2+=num[s1[i]-'a'];
			else s2+=s1[i];
			}
		cout<<"Case #"<<ca<<": "<<s2<<endl;
		}
	}
/*int main(){
	string s[2][3],bf,s1,s2;
	
	memset(num,-1,sizeof(num));
	for(int i=0;i<3;i++){
		getline(cin,s[0][i]);
		s1=s[0][i];
		getline(cin,s[1][i]);
		s2=s[1][i];
		int len=s[0][i].length();
		for(int j=0;j<len;j++)if(islower(s1[j])){
			if(num[s1[j]-'a']==-1)num[s1[j]-'a']=s2[j];
			else if(num[s1[j]-'a']!=s2[j]){
				cout<<"bad!"<<endl;
				cout<<s1[j]<<" "<<s2[j]<<" num="<<num[s1[j]-'a']<<endl;
				}
			}
		}
	for(int i=0;i<26;i++)cout<<"num["<<i<<"]="<<num[i]<<";"<<endl;
	while(1);
    return 0;
    }*/
/*
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities
de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up
*/
