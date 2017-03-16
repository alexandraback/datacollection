
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin>>t;
	string str[4];
	int str_num[4][4];
	int ca=0;
	while(t--)
	{
		ca++;
		int is_ok=-1;
		int empty_num=0;
		for(int i=0;i<4;i++)
		{
			cin>>str[i];
		}
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
			{
				if (str[i][j]=='X')
					str_num[i][j]=1;
				if (str[i][j]=='O')
					str_num[i][j]=-1;
				if (str[i][j]=='T')
					str_num[i][j]=100;
				if (str[i][j]=='.')
				{
					str_num[i][j]=0;
					empty_num++;
				}
			}
		int sum_r=0;
		int sum_c=0;
		for (int i=0;i<4;i++)
		{
			sum_r=0;
			sum_c=0;
			for (int j=0;j<4;j++)
			{
				sum_r+=str_num[i][j];
				sum_c+=str_num[j][i];
			}
			if (sum_r==4||sum_r==103||sum_c==4||sum_c==103)
				is_ok=0;
			if (sum_r==-4||sum_r==97||sum_c==-4||sum_c==97)
				is_ok=1;
			if (is_ok>=0)
				break;
		}
		sum_r=0;
		sum_c=0;
		for (int i=0;i<4;i++)
		{
			sum_r+=str_num[i][i];
			sum_c+=str_num[i][3-i];
		}
		if (sum_r==4||sum_r==103||sum_c==4||sum_c==103)
			is_ok=0;
		if (sum_r==-4||sum_r==97||sum_c==-4||sum_c==97)
			is_ok=1;
		cout<<"Case #"<<ca<<": ";
		if (is_ok==0)
			cout<<"X won";
		if (is_ok==1)
			cout<<"O won";
		if (is_ok==-1&&empty_num==0)
			cout<<"Draw";
		if (is_ok==-1&&empty_num>0)
			cout<<"Game has not completed";
		cout<<endl;
	}
	return 0;
}
