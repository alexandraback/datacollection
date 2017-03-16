#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() 
{
	int t, len, left_index=0, right_index = 0;
	char prev_char ;
	string s;
	vector<char> myVec;
	map<int, char> myMap;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>s;
		len = s.size();
		prev_char = s[0];
		myMap[0] = s[0];
		right_index = left_index = 0;
		for(int j=1; j<len; j++)
		{
			if((s[j] >= (char)myMap[left_index]) )
			{
				//cout<<"S[j] = "<s[j]<<" MyMap[left_index] ="<<myMap[left_index]<<" MyMap[right_index] = "<<myMap[right_index]<<endl;
//				cout<<myMap[left_index]<<endl;
				myMap[--left_index] = (s[j]);
				prev_char = s[j];
			}
			
			else
			{
				myMap[++right_index] = s[j];
				prev_char = s[j];
			}
		}
		
		//std::sort(myVec.begin(), myVec.end());
		cout<<"Case #"<<i+1<<": ";
		for(int j=0; j<len; j++)
		{
			cout<<myMap[left_index++];
		}
		cout<<endl;
//		myVec.clear();
	}
	return 0;
}