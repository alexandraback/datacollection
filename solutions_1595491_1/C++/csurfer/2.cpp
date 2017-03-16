#include<iostream>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	int total = tc;

	int arr[31][2];
	
	arr[0][0]=0;arr[0][1]=0;
	arr[1][0]=1;arr[1][1]=1;
	arr[2][0]=1;arr[2][1]=2;
	arr[3][0]=1;arr[3][1]=2;
	arr[4][0]=2;arr[4][1]=2;
	arr[5][0]=2;arr[5][1]=3;
	arr[6][0]=2;arr[6][1]=3;
	arr[7][0]=3;arr[7][1]=3;
	arr[8][0]=3;arr[8][1]=4;
	arr[9][0]=3;arr[9][1]=4;

	arr[10][0]=4;arr[10][1]=4;
	arr[11][0]=4;arr[11][1]=5;
	arr[12][0]=4;arr[12][1]=5;
	arr[13][0]=5;arr[13][1]=5;
	arr[14][0]=5;arr[14][1]=6;
	arr[15][0]=5;arr[15][1]=6;
	arr[16][0]=6;arr[16][1]=6;
	arr[17][0]=6;arr[17][1]=7;
	arr[18][0]=6;arr[18][1]=7;
	arr[19][0]=7;arr[19][1]=7;

	arr[20][0]=7;arr[20][1]=8;
	arr[21][0]=7;arr[21][1]=8;
	arr[22][0]=8;arr[22][1]=8;
	arr[23][0]=8;arr[23][1]=9;
	arr[24][0]=8;arr[24][1]=9;
	arr[25][0]=9;arr[25][1]=9;
	arr[26][0]=9;arr[26][1]=10;
	arr[27][0]=9;arr[27][1]=10;
	arr[28][0]=10;arr[28][1]=10;
	arr[29][0]=10;arr[29][1]=11;

	arr[30][0]=10;arr[30][1]=11;

	while(tc--)
	{
		int n,s,p;
		cin>>n>>s>>p;
		int cnt = 0;
		for(int i=0;i<n;i++)
		{
			int num;
			cin>>num;
			
			if(arr[num][0] >= p) cnt++;
			else if(arr[num][1] >= p && s>0)
			{
				cnt++;
				s--;
			}
		}
		cout<<"Case #"<<total-tc<<": "<<cnt<<"\n";
	}
	return 0;
}
