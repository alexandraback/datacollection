#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	fstream fil;
	fil.open("C:\\Users\\vaibhav\\Desktop\\JAM2Aout.txt");
	int T, s=1;
	cin>>T;
	while(T)
	{
		int N;
		cin>>N;
		int arr[2*N-1][N];
		for(int i=0;i<2*N-1;i++)
		{
			for(int j=0;j<N;j++)
			{
				cin>>arr[i][j];
			}
		}
		vector <int> ans;
		for(int z=0;z<2*N-1;z++)
		{
			
			for(int y=0;y<N;y++)
			{
				int tmp=arr[z][y];
				int count=0;
				for(int i=0;i<2*N-1;i++)
					{
						for(int j=0;j<N;j++)
							{
								if(tmp==arr[i][j])
								count++;
							}
					}
					if(count%2==1)
					{
						bool flag=true;
						for(int k=0;k<ans.size();k++)
						{
							if(tmp==ans[k])
							{
								flag=false;
								break;
							}
						}
						if(flag)
						ans.push_back(tmp);
					}
					
					
			}
			
		}
		sort(ans.begin(),ans.end());
		cout<<"Case #"<<s<<": ";
		fil<<"Case #"<<s<<": ";	
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
			fil<<ans[i]<<" ";
		}
		cout<<endl;
		fil<<"\n";
		s++;
		T--;
	}
	fil.close();
}
