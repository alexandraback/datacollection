#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	char A[30][100];
	char abs;
	cin.get(abs);
	//cout<<"TEst\ning";
	bool out=false;
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<101;j++)
		{
			cin.get(abs);
			switch (abs) {
			
			case 'a': A[i][j]='y';break;
			case 'b': A[i][j]='h';break;
			case 'c': A[i][j]='e';break;
                        case 'd': A[i][j]='s';break;
                        case 'e': A[i][j]='o';break;
                        case 'f': A[i][j]='c';break;
                        case 'g': A[i][j]='v';break;
                        case 'h': A[i][j]='x';break;
                        case 'i': A[i][j]='d';break;
                        case 'j': A[i][j]='u';break;
                        case 'k': A[i][j]='i';break;
                        case 'l': A[i][j]='g';break;
                        case 'm': A[i][j]='l';break;
                        case 'n': A[i][j]='b';break;
                        case 'o': A[i][j]='k';break;
                        case 'p': A[i][j]='r';break;
                        case 'q': A[i][j]='z';break;
                        case 'r': A[i][j]='t';break;
                        case 's': A[i][j]='n';break;
                        case 't': A[i][j]='w';break;
                        case 'u': A[i][j]='j';break;
                        case 'v': A[i][j]='p';break;
                        case 'w': A[i][j]='f';break;
                        case 'x': A[i][j]='m';break;
                        case 'y': A[i][j]='a';break;
                        case 'z': A[i][j]='q';break;
                        case ' ': A[i][j]=' ';break;
			case '\n': A[i][j]='\n';out=true;break;
 			}
			if(out)

			break;
		//cout<<"char";
		}
		//cout<<"Out";
		out=false;
	}
	for(int i=0;i<T;i++)
	{
		cout<<"Case #"<<i+1<<": ";
		for(int j=0;j<101;j++)
		{
			cout<<A[i][j];
			if(A[i][j]=='\n')
				break;
		}
	}
	return 0;
}
