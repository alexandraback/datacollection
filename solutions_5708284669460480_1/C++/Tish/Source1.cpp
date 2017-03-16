#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

int calc(long long x, int a[],int b,int n)
{
	int i;
	long long res1=0;
	long long res2=0;
	long long minind=-1;
	for (i=0;i<b;++i)
	{
		res1+=(x+a[i]-1)/a[i];
		if (((x/a[i])*a[i])==x)
		{
			if (minind==-1)
				minind=i;
			res2+=1;
		}
	}
	if ((res1+res2)<n)
		return -1;
	if (res1>=n)
		return -2;
	int count=0;
	for (i=0;i<b;++i)
	{
		if (((x/a[i])*a[i])==x)
		{
			count++;
		}
		if (count==(n-res1))
			return i+1;
	}
	return 0;
}



void q1(int num)
{
	int r,c,w;
	cin >> r >> c >>w;
	int res=(r-1)*(c/w)+(c+w-1)/w+w-1;
	cout <<"Case #"<<num <<": " << res << endl;
	return;
	
}

int ok(char str[],int l,int start)
{
	int i;
	for (i=start;i<l;++i)
		if (str[i-start]!=str[i])
			return 0;
	return 1;
}

int none(char str[],int l,int arr1[])
{
	int i;
	for (i=0;i<l;++i)
	{
		if (arr1[str[i]-'A']==0)
			return 1;
	}
	return 0;
}

void q2(int num)
{
	int k,l,s;
	int i;
	char c;
	int arr1[26];
	char str[100];
	cin >> k >> l >>s;
	for (i=0;i<26;++i)
	{
		arr1[i]=0;
	}
	int pl;
	int count=0;
	for (i=0;i<k;++i)
	{
		cin >>c;
		pl=c-'A';
		if (pl<26 && pl>=0)
		{
			count++;
			arr1[pl]++;
		}
	}
	count =0;

	for (i=0;i<l;++i)
	{
		cin >>c;
		str[i]=c;
	}
	for (i=1;i<l;++i)
	{
		if (ok(str,l,i)==1)
			break;
	}
	int bananas;
	cout.precision(7);
	if (s<l)
	{
		cout <<"Case #"<<num <<": " << "0.0" << endl;
		return;
	}
	bananas=(s-l)/i+1;
	double chance=1.0;
	for (i=0;i<l;++i)
	{
		chance=chance*(arr1[(str[i]-'A')]);
		chance=chance/k;
	}
	if (none(str,l,arr1)==1)
	{
		cout <<"Case #"<<num <<": " << "0.0" << endl;
		return;
	}
	double res=bananas-chance*(s-l+1);
	cout <<"Case #"<<num <<": " << res << endl;
	return;
	
}

 
struct Point {
	coord_t x, y;
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};
 
// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
 
	// Sort points lexicographically
	sort(P.begin(), P.end());
 
	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	H.resize(k);
	return H;
}


void copy(vector<Point> P, vector<Point> P3, int j)
{
	P3.clear();

	int i=0;
	while (j!=0)
	{
		if (j%2)
			P3.push_back(P[i]);
		i++;
		j=j/2;
	}
}
int popcnt(int j)
{
	int res=0;
	while (j!=0)
	{
		res+=j%2;
		j=j/2;
	}
	return res;
}
int find(vector<Point> P,  int j,vector<Point> P2)
{
	Point x=P[j];
	int len=P2.size();
	for (int i=0;i<(len-1);++i)
	{
		if ((x.x==P2[i].x)&&(x.y==P2[i].y))
			return 1;
	}
	for (int i=0;i<(len-1);++i)
	{
		if (((x.x-P2[i].x)*(P2[i+1].y-P2[i].y))==((x.y-P2[i].y)*(P2[i+1].x-P2[i].x)))
			return 1;
	}
	return 0;
}
void q3(int num)
{
	int n;
	int i;
	cin >> n;
	int a,b;
	std::vector<Point> P;
	std::vector<Point> P3;
	Point c;

	for (i=0; i<n;++i)
	{
		cin >>a >> b;
		c.x=a;
		c.x=b;
		P.push_back(c);
	}
	cout <<"Case #"<<num <<":" << endl;
	int res;
	int j;
	std::vector<Point> P2=convex_hull(P);
	for (i=0;i<n;++i)
	{
		res=n;
		for (j=1;j<(1<<n);++j)
		{
			copy(P,P3,j);
			P2=convex_hull(P3);
			if (find(P,i,P2)==1)
				if ((n-popcnt(j))<res)
					res=n-popcnt(j);

		}
		cout << res<<endl;
	}

		
		return;
	
}


int main()
{
	int T;
	cin >> T;
	for (int i=0;i<T;++i)
		q2(i+1);
}