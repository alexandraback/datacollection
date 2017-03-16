#include<iostream>
using namespace std;
int licz[256];
int ans[10];
int go(char let,string word)
{
	int tmp=licz[(int)let];
	for(size_t i=0;i<word.size();i++)
		licz[(int)word[i]]-=tmp;
	return tmp;
}
void test()
{
	for(int i=0;i<256;i++)licz[i]=0;
	string in;
	cin >> in;
	for(size_t i=0;i<in.size();i++)
	{
		licz[(int)in[i]]++;
	}
	ans[0]=go('Z',"ZERO");
	ans[4]=go('U',"FOUR");
	ans[2]=go('W',"TWO");
	ans[5]=go('F',"FIVE");
	ans[6]=go('X',"SIX");
	ans[7]=go('S',"SEVEN");
	ans[8]=go('G',"EIGHT");
	ans[3]=go('H',"THREE");
	ans[1]=go('O',"ONE");
	ans[9]=go('I',"NINE");
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int k=0;k<t;k++)
	{
		test();
		cout << "Case #"<<k+1<<": ";
		for(int i=0;i<10;i++)
			for(int j=0;j<ans[i];j++)
				cout << i;
		cout << "\n";
	}
}
