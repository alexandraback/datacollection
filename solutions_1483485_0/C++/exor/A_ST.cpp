#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<fstream>

using namespace std;

int main()
{
	int N,si,i,k=1;
	string Ns,s,s1;
	char c;
	fstream fi("out.txt",ios::out);
	stringstream ss;
	getline(cin,Ns);
	ss << Ns;
	ss >> N;
	while(N--){
		s1 = "";
		i=0;
		getline(cin,s);
		si = s.size();
		while(i<si){
			c = s[i];
			if(c=='a')s1+='y';
			else if(c=='b')s1+='h';
			else if(c=='c')s1+='e';
			else if(c=='d')s1+='s';
			else if(c=='e')s1+='o';
			else if(c=='f')s1+='c';
			else if(c=='g')s1+='v';
			else if(c=='h')s1+='x';
			else if(c=='i')s1+='d';
			else if(c=='j')s1+='u';
			else if(c=='k')s1+='i';
			else if(c=='l')s1+='g';
			else if(c=='m')s1+='l';
			else if(c=='n')s1+='b';
			else if(c=='o')s1+='k';
			else if(c=='p')s1+='r';
			else if(c=='q')s1+='z';
			else if(c=='r')s1+='t';
			else if(c=='s')s1+='n';
			else if(c=='t')s1+='w';
			else if(c=='u')s1+='j';
			else if(c=='v')s1+='p';
			else if(c=='w')s1+='f';
			else if(c=='x')s1+='m';
			else if(c=='y')s1+='a';
			else if(c=='z')s1+='q';
			else s1+=c;
			i++;
		}
		cout <<"Case #"<<k<<": " << s1 << endl;
		fi << "Case #"<<k++<<": " << s1 << "\n";
	}
	return 0;
}
