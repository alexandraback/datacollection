#include <iostream>
using namespace std;

int main()
{	
    int n;
	cin >> n;
	cin.get();
	for (int i=0;i<n;++i)
	{
		//read string
		char t='0';
		cout << "Case #" << i+1 << ": ";
		do{ 
		t=cin.get();
			switch (t)
			{
				case 'a': t='y'; break;
				case 'b': t='h'; break;
				case 'c': t='e'; break;
				case 'd': t='s'; break;
				case 'e': t='o'; break;
				case 'f': t='c'; break;
				case 'g': t='v'; break;
				case 'h': t='x'; break;
				case 'i': t='d'; break;
				case 'j': t='u'; break;
				case 'k': t='i'; break;
				case 'l': t='g'; break;
				case 'm': t='l'; break;
				case 'n': t='b'; break;
				case 'o': t='k'; break;
				case 'p': t='r'; break;
				case 'q': t='z'; break;
				case 'r': t='t'; break;
				case 's': t='n'; break;
				case 't': t='w'; break;
				case 'u': t='j'; break;
				case 'v': t='p'; break;
				case 'w': t='f'; break;
				case 'x': t='m'; break;
				case 'y': t='a'; break;
				case 'z': t='q'; break;
				
			}
			cout << t;
		}while (t!='\0'&&t!='\n');
	}

    return 0;
}