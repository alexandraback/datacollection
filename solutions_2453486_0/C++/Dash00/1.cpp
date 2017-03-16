#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char map[5][5];

int main()
{
	int t,cas = 1;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		for(i=0;i<4;i++)
		{
			scanf("%s",&map[i]);
		}
		bool f1, f2, full;
		f1 = f2 =  false;
		full = true;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(map[i][j] == '.')
					full = false; 
			}	
		}
		int cnt1, cnt2, cnt3;
		for(i=0;i<4;i++)
		{
			cnt1 = cnt2 = cnt3 =0;
			for(j=0;j<4;j++)
			{
				if(map[i][j] == 'X')
					cnt1 ++;
				if(map[i][j] == 'O')
					cnt2 ++;
				if(map[i][j] == 'T')
					cnt3 ++;
			}
			if(cnt1 == 4 || (cnt1 == 3 && cnt3 == 1))
				f1 = true;
			if(cnt2 == 4 || (cnt2 == 3 && cnt3 == 1))
				f2 = true;
			cnt1 = cnt2 = cnt3 =0;
			for(j=0;j<4;j++)
			{
				if(map[j][i] == 'X')
					cnt1 ++;
				if(map[j][i] == 'O')
					cnt2 ++;
				if(map[j][i] == 'T')
					cnt3 ++;
			}
			if(cnt1 == 4 || (cnt1 == 3 && cnt3 == 1))
				f1 = true;
			if(cnt2 == 4 || (cnt2 == 3 && cnt3 == 1))
				f2 = true;
		}
		cnt1 = cnt2 = cnt3 = 0;
		for(i=0;i<4;i++)
		{
			if(map[i][i] == 'X')
				cnt1 ++;
			if(map[i][i] == 'O')
				cnt2 ++;
			if(map[i][i] == 'T')
				cnt3 ++;
		}	
		if(cnt1 == 4 || (cnt1 == 3 && cnt3 == 1))
			f1 = true;
		if(cnt2 == 4 || (cnt2 == 3 && cnt3 == 1))
			f2 = true;
		cnt1 = cnt2 = cnt3 = 0;
		for(i=0;i<4;i++)
		{
			if(map[i][3-i] == 'X')
				cnt1 ++;
			if(map[i][3-i] == 'O')
				cnt2 ++;
			if(map[i][3-i] == 'T')
				cnt3 ++;
		}	
		if(cnt1 == 4 || (cnt1 == 3 && cnt3 == 1))
			f1 = true;
		if(cnt2 == 4 || (cnt2 == 3 && cnt3 == 1))
			f2 = true;
		printf("Case #%d: ",cas++);
		if(f1)
			cout<<"X won"<<endl;
		else if(f2) 
			cout<<"O won"<<endl;
		else if(!f1 && !f2 && full)
			cout<<"Draw"<<endl;
		else
			cout<<"Game has not completed"<<endl;
	}
	return 0;
}
