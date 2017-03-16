#include<iostream>
#include<string>
using namespace std;

int mx[30][2];

void init()
{
	mx[0][0]=0;        mx[0][1]=0;   ///score , max_normal , max_surp
	mx[1][0]=1;        mx[1][1]=1;
	mx[2][0]=1;        mx[2][1]=2;
	mx[3][0]=1;        mx[3][1]=2;
	mx[4][0]=2;        mx[4][1]=2;
	mx[5][0]=2;        mx[5][1]=3;
	mx[6][0]=2;        mx[6][1]=3;
	mx[7][0]=3;        mx[7][1]=3;
	mx[8][0]=3;        mx[8][1]=4;
	mx[9][0]=3;        mx[9][1]=4;
	mx[10][0]=4;       mx[10][1]=4;

	mx[11][0]=4;       mx[11][1]=5;
	mx[12][0]=4;       mx[12][1]=5;
	mx[13][0]=5;       mx[13][1]=5;
	mx[14][0]=5;       mx[14][1]=6;
	mx[15][0]=5;       mx[15][1]=6;
	mx[16][0]=6;       mx[16][1]=6;
	mx[17][0]=6;       mx[17][1]=7;
	mx[18][0]=6;       mx[18][1]=7;
	mx[19][0]=7;       mx[19][1]=7;
	mx[20][0]=7;       mx[20][1]=8;

	mx[21][0]=7;       mx[21][1]=8;
	mx[22][0]=8;       mx[22][1]=8;
	mx[23][0]=8;       mx[23][1]=9;
	mx[24][0]=8;       mx[24][1]=9;
	mx[25][0]=9;       mx[25][1]=9;
	mx[26][0]=9;       mx[26][1]=10;
	mx[27][0]=9;       mx[27][1]=10;
	mx[28][0]=10;      mx[28][1]=10;
	mx[29][0]=10;      mx[29][1]=11;
	mx[30][0]=10;      mx[30][1]=11;
}

void solve(int tcase)
{
	int numg,nums,score;cin>>numg>>nums>>score;

	int res=0;

	for(int i=0;i<numg;++i)
	{
		int t;cin>>t;

		if(mx[t][0]>=score)++res;
		else if(nums && mx[t][1]>=score){ ++res;--nums; }
	}

	cout<<"Case #"<<tcase<<": "<<res<<endl;
}

int main()
{
//	freopen("C:\\Users\\CHANDAN\\Desktop\\TC_arena\\out.txt","w",stdout);
//	freopen("I:\\Downloads\\B-large.in","r",stdin);

	init();
	int t;cin>>t;
	for(int i=1;i<=t;++i)solve(i);

	return 0;
}