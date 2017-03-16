#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


int main ()
{
	ifstream cin;
	cin.open("C-small-attempt0.in");
	ofstream cout;
	cout.open("recycled.out");

	int T,temp;
	char buffer[2000];
	int A,B;
	string temp_str,n_str;
	vector <int> tried;

	cin>>T;

	for (int t=1; t<=T; t++)
	{
		int count=0;
		cin>>A>>B;

		for (int n=A; n<=B; n++)
		{
			tried.clear();
			itoa(n,buffer,10);
			n_str=(buffer);

			for (int i=1; i<n_str.size(); i++)
			{
				temp_str="";
				temp_str=n_str.substr(n_str.size()-i,i);
				temp_str+=n_str.substr(0,n_str.size()-i);
				temp=atoi(temp_str.c_str());
				
				bool found=false;
				for (int j=0; j<tried.size(); j++)
					if (tried[j]==temp)
						found=true;
				if (!found)
					tried.push_back(temp);
				
				if (!found && temp>=A && temp<=B && n<temp){
					count++;
				}
			}
		}

		cout<<"Case #"<<t<<": "<<count<<endl;
	}

	return 0;
}