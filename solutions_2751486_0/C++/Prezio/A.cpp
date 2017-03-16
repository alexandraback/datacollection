#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
string word;

bool vowel(char a)
{
	 return (a=='a'||a=='e'||a=='i'||a=='o'||a=='u');
}

int main()
{
	cin>>N;
	int k=1;
	while(k<=N)
	{
		int n;
		cin>>word>>n;
		int result=0;
		int last_good=0;		

		for(int i=0; i<word.size(); i++)
		{
			//if(!vowel(word[i]))
			//	sum_cons++;
			int j=i+n;
			if(j>word.size())
				break;
			
			bool good=true;
			for(int w=i; w<j; w++)
			{
				if(vowel(word[w]))
				{
					good=false;
					break;
				}
				//cout<<word[w];
			}
			//cout<<"\n";
			if(good)
			{
				result+=(i-last_good+1)*(word.size()-j+1);
				last_good=i+1;
				//result+=((i+1)*(word.size()-j+1)-1);
				//result-=sum_sub;
				//if(j==word.size()&&sum_sub!=0)
				//	result++;
				//result+=(word.size()-n);
				//sum_sub++;
			}
		}
		//if(result!=0)
		//	result++;
		cout<<"Case #"<<k<<": "<<result<<"\n";
		k++;
	}
	return 0;
}
