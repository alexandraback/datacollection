#include <cstdio>
#include <stack>

using namespace std;

int main()
{
	int t,T,onum,i;
	char in[1010],out[1010];
	stack<char> st;

	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%s",in);
		onum=0;
		for(i=0;i<=1000;i++)
			out[i]='\0';
		st.push(in[0]);
		for(i=1;in[i];i++)
		{
			if(in[i]>=st.top())
				st.push(in[i]);
			else
				out[onum++]=in[i];
		}

		printf("Case #%d: ",t);
		while(!st.empty())
		{
			printf("%c",st.top());
			st.pop();
		}
		printf("%s\n",out);
	}
	return 0;
}
