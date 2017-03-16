#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	float p,pr,ch;
	int i=0,j,t,b,a;
	vector<float> out;
	vector<float>::iterator it;
	cin>>t;
	while(i++<t)
	{
		cin>>a>>b;
		p=(float)1;
		ch=0;
		out.clear();
		for(j=0;j<a;j++)
		{
			cin>>pr;
			p*=pr;
			ch=p*(2*(a-j-1)+(b-a+1)) + (1-p)*(2*(a-j-1)+(b-a+1)+(b+1));
			out.push_back(ch);
		}
		ch=p*((float)(b-a+1)) + (1-p)*((float)(2*b+2-a));
		ch=(float)(b+2);
		out.push_back(ch);
		it=min_element(out.begin(),out.end());
		printf("Case #%d: %.6f\n",i,*it);
		//cout<<"Case #"<<i<<": "<<(float)ch<<"\n";
	}
	return 0;
}