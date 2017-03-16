#include <iostream>
#include <string>
using namespace std;

int allmiss(int C, int W)
{
	return C/W;
}
int catched(int C, int W)
{
	int before=allmiss(C,W);//assume last part is HIT
	int uncertainty=1;
	if(C%W==0)uncertainty=0;
	int remained=(W-1);
	return before+uncertainty+remained;
}

int calc()
{
	int R,C,W;
	cin>>R>>C>>W;
	return (R-1)*allmiss(C,W)+catched(C,W);
}

int main()
{
	//cout<<calc();return 0;
	int N;cin>>N;
	for(int i=0;i<N;i++)
		cout<<"Case #"<<(i+1)<<": "<<calc()<<endl;
	return 0;
}