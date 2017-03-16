#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
int main()
{
	string a = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string b = "our language is impossible to understand";
	map < char , char > nm;
	for(int i =0 ; i < a.size(); ++i)
		nm[a[i]] = b[i];
	a = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	b = "there are twenty six factorial possibilities";
	for(int i =0 ; i < a.size(); ++i)
		nm[a[i]] = b[i];
	a = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	b = "so it is okay if you want to just give up";
	for(int i =0 ; i < a.size(); ++i)
		nm[a[i]] = b[i];
	nm['z'] = 'q';
	set < char > x , y;
	for(int i = 0 ; i < 26; ++i)
		x.insert( (char)( 'a' + i ) ) , y.insert( (char)( 'a' + i ) );
	x.insert( ' ' );
	y.insert( ' ' );
	y = x;
	map < char , char >::iterator it;
	for( it = nm.begin() ; it != nm.end(); it++)
	{
		//cerr << (*it).first << " " << (*it).second << "\n";
		x.erase( x.find((*it).first) );
		y.erase( y.find((*it).second) );
	}
	nm[*(x.begin())] = *(y.begin());
	int T ;
	cin >> T;
	getline( cin , a );
	for(int i = 1; i <= T; ++i)
	{
		getline( cin , a );
		cout << "Case #"<<i<<": ";
		for(int j = 0; j < a.size(); ++j)
			cout <<nm[a[j]];
		cout << "\n";
	}
	return 0;
}
