#include<bits/stdc++.h>
using namespace std;
int main()
{
	fstream fin,fout;
	fin.open("A-large.in",ios::in);
	fout.open("large-out.txt",ios::out);
	
	int t,q;
	fin>>t;
	for(q=0;q<t;++q)
	{
		fout<<"Case #"<<q+1<<": ";
		
		string S;
		fin>>S;
		
		int i,len=S.length();
		list<char> str;
		str.push_back(S[0]);
		
		for(i=1;i<len;++i)
		{
			if(S[i] >= str.front())
				str.push_front(S[i]);
			else
				str.push_back(S[i]);
		}
		for(;!str.empty();str.pop_front())
			fout<<str.front();
		fout<<"\n";
	}
	
	fout.close();
	fin.close();
	return 0;
}
