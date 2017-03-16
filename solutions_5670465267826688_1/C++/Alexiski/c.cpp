#include <iostream>
#include <string>
using namespace std;

int prod(int a, int b)
{
	int s = 1;
	if (a<0) {a = -a; s = -s;}
	if (b<0) {b = -b; s = -s;}
	if (a == 1) return b*s;
	if (b == 1) return a*s;
	if (a == b) return (-1)*s;
	if (a == 2)
	{
		if (b==3) return 4*s;
		else return (-3)*s;
	}
	if (a == 3)
	{
		if (b==4) return 2*s;
		else return (-4)*s;
	}
	if (a == 4)
	{
		if (b==2) return 3*s;
		else return (-2)*s;
	}
}

bool test(int l, long long int x, const string &str)
{
	int f1 = 1; 
	for (int i=0; i<l; i++) 
		f1 = prod(f1, str[i]-'g');
	int r = x%4;
	int f2 = 1; 
	for (int i=0; i<r; i++) 
		f2 = prod(f2, f1);
	if (f2 != -1) return false;
	
	int m = 4; if (f1 == -1) m = 2; 
	int xx1 = l*m;
	long long int xx2 = x*l;
	
	int t1 = 1;
	for (int i=0; (i<xx1) && (i<xx2); i++)
	{
		t1 = prod(t1, str[i%l]-'g');
		if (t1 == 2)
		{
			int t2 = 1;
			for (int k=1; (k<=xx1) && (i+k<xx2); k++)
			{
				t2 = prod(t2, str[(i+k)%l]-'g');
				if (t2 == 3)
				{
					return true;
				}
			}
			return false;
		}
	}
	return false;
}

int main()
{
  int T; cin >> T;
  for (int ii = 0; ii<T; ii++)
  {
    int l; long long x; string str; cin >> l >> x >> str;
	
    cout << "Case #" << ii+1 << ": " << (test(l,x,str) ? "YES" : "NO") << endl;
  }
  return 0;
}
