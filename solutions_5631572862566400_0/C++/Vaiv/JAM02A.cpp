#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	fstream fil;
	fil.open("C:\\Users\\vaibhav\\Desktop\\JAM3Aout.txt");
	int T, s=1;
	cin>>T;
	while(T)
	{
		int N;
		cin>>N;
		int arr[N+10];
		for(int i=1;i<=N;i++)
		{
			cin>>arr[i];
		}
		bool flag=true;
		int count=0,maxCount=0;
		
		for(int i=1;i<=N;i++)
		{
			//int tmp=arr[i];
			int tmp=i;
			//count++;
			vector<int> arr1;
			while(flag)
			{
				int prev=tmp;
				tmp=arr[tmp];
					
				if(prev==arr[tmp]&& i>=2)
				{
					tmp=arr[i-1];
					//count++;
				}
				else if(prev==arr[tmp]&& tmp<N)
				{
					tmp=tmp+1;
					
					//count++;
				}
				else if(prev==arr[tmp])
				{
					count++;
				}
				for(int j=0;j<arr1.size();j++)
				{
					if(arr1[j]==tmp)
					{
						flag=false;
					}
				}
				if(flag)
				{
					arr1.push_back(tmp);
					cout<<tmp<<" ";
					count++;
				}
				
			}
			cout<<endl;
			if(count>maxCount)
			maxCount=count;
			flag=true;
			count=0;
		}
		cout<<"Case #"<<s<<": "<<maxCount<<endl;
		fil<<"Case #"<<s<<": "<<maxCount<<"\n";	
		s++;
		T--;
	}
	fil.close();
}
