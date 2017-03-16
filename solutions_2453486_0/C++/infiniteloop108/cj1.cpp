#include<iostream>
using namespace std;
int result(char arr[4][5])
{
	for(int i=0;i<4;++i)
	{
		int t=0;
		for(int j=0;j<4;++j)
			if(arr[i][j]=='O'||arr[i][j]=='.')t=1;
		if(t==0)return 1;
	}
	
	for(int i=0;i<4;++i)
	{
		int t=0;
		for(int j=0;j<4;++j)
			if(arr[j][i]=='O'||arr[j][i]=='.')t=1;
		if(t==0)return 1;
	}
	
	
	for(int i=0;i<4;++i)
	{
		int t=0;
		for(int j=0;j<4;++j)
			if(arr[i][j]=='X'||arr[i][j]=='.')t=1;
		if(t==0)return 2;
	}
	
	for(int i=0;i<4;++i)
	{
		int t=0;
		for(int j=0;j<4;++j)
			if(arr[j][i]=='X'||arr[j][i]=='.')t=1;
		if(t==0)return 2;
	}
	
	int t;
	
	t=0;
	for(int i=0;i<4;++i)if(arr[i][i]=='O'||arr[i][i]=='.')t=1;
	if(t==0)return 1;
	
	
	t=0;
	for(int i=0;i<4;++i)if(arr[i][3-i]=='O'||arr[i][3-i]=='.')t=1;
	if(t==0)return 1;
	
	
	t=0;
	for(int i=0;i<4;++i)if(arr[i][i]=='X'||arr[i][i]=='.')t=1;
	if(t==0)return 2;
	
	
	t=0;
	for(int i=0;i<4;++i)if(arr[i][3-i]=='X'||arr[i][3-i]=='.')t=1;
	if(t==0)return 2;
	
	t=0;
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
			if(arr[j][i]=='.')return 4;
	}
	
	return 3;
}
int main()
{
	int t;
	cin>>t;
	int cnt=1;
	while(t>0)
	{
		char arr[4][5];
		for(int i=0;i<4;++i)
			cin>>arr[i];
		
		int ans=result(arr);
		cout<<"Case #"<<cnt<<": ";
		if(ans==1)cout<<"X won\n";
		else if(ans==2)cout<<"O won\n";
		else if(ans==3)cout<<"Draw\n";
		else cout<<"Game has not completed\n";
		t--;
		cnt++;
	}
	return 0;
}
