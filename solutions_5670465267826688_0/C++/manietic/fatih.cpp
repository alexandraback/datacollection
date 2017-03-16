#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int m(int x, int y)
{
	if(x == 1) return y;
	if(y == 1) return x;
	if(x == y) return -1;
	if(x < 0) return -m(-x,y);
	if(y < 0) return -m(x,-y);
	if(x > y) return -m(y,x);
	if(x == 2 and y == 3) return 4;
	if(x == 2 and y == 4) return -3;
	if(x == 3 and y == 4) return 2;
}

int main()
{
	
	freopen("C-small-attempt0.in","r",stdin);
	freopen("c.out","w",stdout);
	
	
	
	int T; scanf("%d",&T);
	
	for(int t = 1; t <= T; t++)
	{
		ll L,X; cin >> L >> X;
		string s; cin >> s;
		
		string result = "YES";
		
		int a[L+1], b[4*L+1], c[4*L+1], ans1 = 0, ans2 = 0; b[0] = 1; c[0] = 1;
		
		for(int i = 1; i <= L; i++)
		{
			
			
			if(s[i-1] == 'i') a[i] = 2;
			else if(s[i-1] == 'j') a[i] = 3;
			else if(s[i-1] == 'k') a[i] = 4;
			
			
		}
		
		for(int i = 1; i <= 4*L; i++)
		b[i] = m(b[i-1], a[(i-1)%L + 1]);
		
		for(int i = 1; i <= 4*L; i++) if(b[i] == 2) {ans1 = i; break;}
		
		if(!ans1) { result = "NO";}// cout << endl << "error 1 error" << endl;}
		
		for(int i = 1; i <= 4*L; i++)
		c[i] = m(a[L - (i - 1)%L], c[i-1]);
		
		for(int i = 1; i <= 4*L; i++) if(c[i] == 4) {ans2 = i; break;}
		
		if(!ans2) { result = "NO";}// cout << endl << "error 2 error" << endl;}
		
		if(ans1 + ans2 + 1 > L*X) { result = "NO"; }//cout << endl << "error 3 error" << endl;}
		
		int total = 1;
		
		for(int i = 1;  i <= (X%4); i++)
		
		total = m(total, b[L]);
		
		if(total != -1) { result = "NO"; }//cout << endl << "error 4 error" << endl;}
		
		printf("Case #%d: ",t);
		
		cout << result << '\n';
		
	}
	
	return 0;
	
	
}
