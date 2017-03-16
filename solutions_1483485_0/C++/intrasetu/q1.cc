#include<iostream>
using namespace std;
main()
{
	char mapping[]="yhesocvxduiglbkrztnwjpfmaq";
	int T,j;
	char buffer[105];
	cin>>T;
	cin.getline(buffer,104);
	for(int i=0;i<T;i++)
	{
		cin.getline(buffer,104);
		for(j=0;buffer[j];j++)
		{
			if(buffer[j]!=' ')
			{
				buffer[j]=mapping[buffer[j]-'a'];
			}
		}
		cout<<"Case #"<<i+1<<": "<<buffer<<endl;
	}
	return 0;
}
