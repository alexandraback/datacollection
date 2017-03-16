#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	int num;
	string str;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num>>str;
		int invite,current;
		invite = 0;
		current = 0;
		for(int j=0;j<num+1;j++)
		{
			if(current<j){
				invite+=j-current;
				current = j;
			}
			current+=str[j]-'0';
		}
		cout<<"Case #"<<i+1<<": "<<invite<<endl;
	}
	return 0;
}
