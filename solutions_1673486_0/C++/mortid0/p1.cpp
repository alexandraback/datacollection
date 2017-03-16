#include <iostream>

using namespace std;

int main()
{
	int total_num;
	cin>>total_num;
	int a, b;
	int i, case_num;
	for (case_num = 0; case_num < total_num; case_num++)
	{
		cin>>a>>b;
		double p[a];
//		cout<<a<<" "<<b<<endl;
		for (i = 0; i < a; i++)
		{
			cin>>p[i];
//			cout<<p[i]<< " ";
		}
		double ans = 0.0;
		double keep_typing, hit_enter, backspace, backspace2, backspace3;
		if (1==a)
		{
			keep_typing = p[0]*(b)+(1.0-p[0])*(2*b+1);
			hit_enter = b+2;
			backspace = b+2;
			ans = (hit_enter < keep_typing) ? hit_enter:keep_typing; 
		}
		else if (2==a)
		{
			keep_typing = p[0]*p[1]*(b-1)+(1-p[0]*p[1])*2*b;
			hit_enter = b+2;
			backspace = (b+1)*(p[0])+(b+1+b+1)*(1-p[0]);
			backspace2 = b+3;
			double m1 = (keep_typing<hit_enter)?keep_typing:hit_enter;
			double m2 = (backspace<backspace2)?backspace:backspace2;
			ans = (m1<m2)?m1:m2;
		}
		else if (3==a)
		{
			keep_typing = p[0]*p[1]*p[2]*(b-2)+(1-p[0]*p[1]*p[2])*(2*b-1);
			hit_enter = b+2;
			backspace = b*(p[0]*p[1])+(1-p[0]*p[1])*(b+b+1);
			backspace2 = (2+b)*(p[0])+(1-p[0])*(2+b+b+1);
			backspace3 = b+4;
			double m1 = (keep_typing<hit_enter)?keep_typing:hit_enter;
			double m2 = (backspace<backspace2)?backspace:backspace2;
			ans = (m1<m2)?m1:m2;
			ans = (ans<backspace3)?ans:backspace3;
		}
		cout<<"Case #"<<(case_num+1) <<": "<<ans<<endl;
	}
	return 0;
}
