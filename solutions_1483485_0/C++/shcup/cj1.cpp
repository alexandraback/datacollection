#include "iostream"
#include "string"

using namespace std;


int main()
{
	//freopen("in.txt","r",stdin);
	freopen("1.out", "w", stdout);
	
	int t,i,j,id = 1;
	string map("yhesocvxduiglbkrztnwjpfmaq"); 
	string google;
	cin >>t;
	getchar();
	while(t--)
	{
		getline(cin,google);
		
		for(i = 0; i < google.size(); i++)
		{
			if(google[i] == ' ')
				continue;
			google[i] = map[google[i] - 'a'];
		}
		
		cout <<"Case #" << id++ <<": " << google << endl;
	}
	getline(cin,google);
	return 1;
}




/*
int main()
{
	string google,english;
	string map(26,'@');
	
	int i,j;
	for(i = 0;i < 3 ; i++)
	{
		getline(cin,google);
		getline(cin,english);
		
		for(j = 0;j < google.size(); j++)
		{
			if(google[j] == ' ')
				continue; 
			map[google[j] - 'a'] = english[j];
			if(map[google[j] - 'a'] != english[j] && map[google[j] - 'a'] != '@')
				cout << "     777777777777777777  ";
		}
	}
	
	for(i = 0;i < 26 ; i++)
		cout << map[i] << ",";
	
	getline(cin,google);
	
} 
/*
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities
de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up


y,h,e,s,o,c,v,x,d,u,i,g,l,b,k,r,@,t,n,w,j,p,f,m,a,@,
*/
