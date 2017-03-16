#include <bits/stdc++.h>

class Q
{
public:
	int a;
	char b;
	Q(int x,char y)
	{
		a = x;
		b = y;
	}
};

using namespace std;

Q mul(Q,Q);

int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,l,x,j,c;
    bool r;
    cin>>t;
    for(i=0;i<t;i++)
    {
    	cin>>l>>x;
	    string A;
    	cin>>A;
	    Q v(1,'1');
	    string S;
	    for(j=0;j<(x%4);j++)
	    	S += A;
	    for(c=0;c<S.size();c++)
	    {
	    	Q temp(1,S[c]);
	    	v = mul(v,temp);
	    }
    	if(v.a == -1 && v.b == '1')
    		r = true;
    	else
    		r = false;
    	// cout<<r<<endl;
    	if(r)
    	{
    		string F;
    		for(j=0;j<(x%4);j++)
    			F += A;
    		if(x>=4)
    			for(j=0;j<4;j++)
    				F += A;
    		// cout<<F<<endl;
    		int p1 = -1;
    		int p2 = -1;
    		Q n1(1,'1');
    		for(j=0;j<F.size();j++)
    		{
    			Q temp(1,F[j]);
    			n1 = mul(n1,temp);
    			if(n1.a == 1 && n1.b == 'i')
		    	{
					p1 = j;
					break;
		    	} 
    		}
    		Q n2(1,'1');
    		for(j=F.size()-1;j>=0;j--)
    		{
    			Q tep(1,F[j]);
    			n2 = mul(tep,n2);
    			if(n2.a == 1 && n2.b == 'k')
		    	{
					p2 = j;
					break;
		    	} 
    		}
    		r = (p1>-1&&p2>-1)&&p1<(p2 + (x*l-F.size()));
	    }
    	cout<<"Case #"<<i+1<<": ";
    	if(r)
    		cout<<"YES";
    	else
    		cout<<"NO";
    	cout<<endl;
    }
    return 0;
}	


Q mul(Q x, Q y)
{
	int s1 = x.a;
	char c1 = x.b;
	int s2 = y.a;
	char c2 = y.b;
	int s = s1*s2;
	char c = '1';
	if(c1=='1')
		c = c2;
	else if(c2 == '1')
		c = c1;
	else if(c1 == c2)
	{
		s = -s;
		c = '1';
	}
	else if(c1=='i' && c2=='j')
	{
		c = 'k';
	}
	else if(c1=='i' && c2=='k')
	{
		s = -s;
		c = 'j';
	}
	else if(c1=='j' && c2=='k')
	{
		c = 'i';
	}
	else if(c1=='j' && c2=='i')
	{
		s = -s;
		c = 'k';
	}
	else if(c1=='k' && c2=='i')
	{
		c = 'j';
	}
	else if(c1=='k' && c2=='j')
	{
		s = -s;
		c = 'i';
	}
	Q p(s,c);
	return p;
}