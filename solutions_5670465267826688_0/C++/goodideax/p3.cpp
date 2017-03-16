#include <iostream>
#include <string>
using namespace std;
char map[4][4]={{'1','i','j','k'},
		{'i','0','k','J'},
		{'j','K','0','i'},
		{'k','j','I','0'}};
void translate(char x,int &a, int &neg)
{
	switch(x)
	{
		case '1': a=0,neg=1;break;
		case '0': a=0,neg=-1;break;
		case 'i': a=1;neg=1;break;
		case 'I': a=1;neg=-1;break;
		case 'j': a=2;neg=1;break;
		case 'J': a=2;neg=-1;break;
		case 'k': a=3;neg=1; break;
		case 'K': a=3;neg=-1;break;
		default: ;//cerr<<"error!"<<endl;
	}
	return;
}
char mul(char a,char b)
{
	int aneg,bneg;
	int anum,bnum;
	translate(a,anum,aneg);
	translate(b,bnum,bneg);
	//cerr<<anum<<' '<<bnum<<endl;
	char ans = map[anum][bnum];
	int ansnum,ansneg;
	translate(ans,ansnum,ansneg);
	ansneg = ansneg*aneg*bneg;
	//cerr<<ansnum<<' '<<ansneg<<endl;
	if(ansnum==0)
		return ansneg>0?'1':'0';
	if(ansnum==1)
		return ansneg>0?'i':'I';
	if(ansnum==2)
		return ansneg>0?'j':'J';
	if(ansnum==3)
		return ansneg>0?'k':'K';
}
int main()
{
	int n;
	string str,tmp,ans,back_ans;
	cin>>n;
	long long X;
	long long L;
	int i,j;
	long long first, last;
	char total,back_total;
	for(int t=0;t<n;t++)
	{
		cin>>L>>X;
		cin>>tmp;
		if(X>12) X=12+X%12;
		str = "";
		for(i=0;i<X;i++)
			str+=tmp;
		//cerr<<str<<endl;
		ans.reserve(X*L);
		back_ans.reserve(X*L);

		ans[0] = str[0];
		for(i=1;i<X*L;i++){
			ans[i] = mul(ans[i-1],str[i]);
			//cerr<<ans[i]<<endl;
		}
		total = ans[X*L-1];
		//cerr<<ans<<endl;
		if(total!='0')
		{
			cout<<"Case #"<<t+1<<": NO"<<endl;
			continue;
		}

		back_ans[X*L-1] = str[X*L-1];
		for(i=X*L-2;i>=0;i--)
			back_ans[i] = mul(str[i],back_ans[i+1]);
		back_total = back_ans[0];
		//for(i=0;i<X*L;i++) cout<<back_ans[i]<<'p'<<endl;
		//cerr<<back_ans<<endl;
		for(i=0;i<X*L;i++)
			if(ans[i]=='i') break;
		first = i;

		for(i=X*L-1;i>=0;i--)
			if(back_ans[i]=='k') break;
		last = i;
		if(first+1<last)
			cout<<"Case #"<<t+1<<": YES"<<endl;
		else
			cout<<"Case #"<<t+1<<": NO"<<endl;

	}
	return 0;
}
