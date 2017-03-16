#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
int findmax(string& target)
{
	int max=0;
	for(int i=0;i<target.size()-1;i++)
	{
		bool stop=false;
		for(int j=0;j<=i;j++)
		{
			if(target[j]!=target[target.size()-i+j-1])
			{			
				stop=true;
				break;
			}
		}
		if(!stop)max=i+1;
	}
	return max;
}
bool writable(string& target,string& keyboard)
{
	int chars[26];
	for(int i=0;i<26;i++)
		chars[i]=0;
	for(int i=0;i<keyboard.size();i++)
	{	
		chars[keyboard[i]-'A']=1;
	}
	for(int i=0;i<target.size();i++)
	{
		if(chars[target[i]-'A']==0)
			return false;
	}
	return true;
}
int countSubstring(const string& str, const string& sub)
{
	int sum=0;
    for(int offset=str.find(sub);offset!=string::npos;offset=str.find(sub,offset+1))
	{
		sum++;
	}
	return sum;
}
pair<double,double> countT(string &target,string& keyboard,int size)
{
	vector<string> all;
	all.push_back("");
	for(int i=0;i<size;i++)
	{
		int p;
		p=all.size();
		for(int j=0;j<p;j++)
		{
			for(int k=0;k<keyboard.size();k++)
			{
				string a=all[j];
				a.push_back(keyboard[k]);
				all.push_back(a);
			}
		}
		vector<string> newall;
		for(int j=p;j<all.size();j++)
		{
			newall.push_back(all[j]);
		}
		all=newall;
	}
/*	for(int i=0;i<all.size();i++)
		cout << all[i] << endl;
	cout << endl;
	*/int sum=0;
	for(int i=0;i<all.size();i++)
	{
		sum+=countSubstring(all[i],target);
	}
	return make_pair(sum,all.size());
}
int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		cout << "Case #"<<t<<": ";
		int keyboardSize,targetSize,writtenSize;
		cin >> keyboardSize >> targetSize >> writtenSize;
		string keyboard;
		string target;
		cin >> keyboard >> target;
		if(targetSize>writtenSize || !writable(target,keyboard))
		{		
			cout << "0.0"<<endl;
			continue;
		}
		int a;
		int bananaFactor=target.size()-findmax(target);
		double bananaCount=1+(writtenSize-target.size())/bananaFactor;
		
		pair<double,double> result=countT(target,keyboard,writtenSize);
		/*cout << result.first << " " << result.second << endl;
		cout << bananaCount << endl;*/
		cout << (double)((double)result.second*bananaCount-(double)result.first)/(double)result.second<<endl;		
	}
	return 0;
}
