#include<bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
typedef long long ll;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int n;
string s1,s2,ans1,ans2; 

#define LL long long
#define ULL unsigned long long
#define LD long double

#define Rep(x,y,i) for (int i=x;i<y;i++) //[x,y)
#define RepD(x,y,i) for (int i=x;i>y;i--) //(y,x]
#define Mem(X) memset(X,0,sizeof(X));
#define Pr(X) cout<<" "<<#X<<"="<<X<<" ";
#define PrL(X) cout<<#X<<" = "<<X<<endl;
#define PrLL cout<<endl;
#define IntMod 10000
const double EPS = 1e-10;
struct BigInt
{
private:
	vector<int> A;
	bool Positive;
	int VecNum;

public:
	//Constructors
	inline int GetLength(LL a) {int t=0; while (a>0) {a/=IntMod; t++;} return t;}
	BigInt() { Positive = 1; VecNum = 0; }
	BigInt(const BigInt &a) { A = a.A; VecNum = a.VecNum; Positive = a.Positive; }
	BigInt(string s)
	{
		A.reserve(100);
		if (s == "-0") { A.push_back(0); Positive = 1; VecNum = 1; return; }
		int kk = 3; int kl = 0;
		int l = s.length();
		int j = l - 1;
		if (s[0] == '-') { Positive = 0; kk++; kl++; }
		else Positive = 1;
		while (j>kk)
		{
			int t = 0;
			Rep(0, 4, i) { t *= 10; t += s[j - (3 - i)] - '0'; }
			j -= 4;
			A.push_back(t);
		}
		int t = 0;
		int k = j + 1;
		Rep(kl, k, i) { t *= 10; t += s[i] - '0'; }
		A.push_back(t);
		VecNum = A.size();
	}
	BigInt(const LL &b)
	{
		LL a=b;
		Positive=(a>=0);
		VecNum=GetLength(abs(a));
		A.resize(VecNum);
		Rep(0,VecNum,i)
		{
			A[i]=a%IntMod;
			a/=IntMod;
		}
	}
	//BigInt& operator = (BigInt& a) { VecNum=a.VecNum; Positive=a.Positive; A=a.A; }
	BigInt& operator = (const string s) { BigInt x(s); *this=x; }
	BigInt& operator = (LL s) { BigInt x(s); *this = x; }
	
	//Basic Math Functions
	friend BigInt abs(BigInt a) { a.Positive=1; return a; }
	friend bool isnegative(BigInt &a) { return a.Positive; }
	BigInt& operator - () { Positive = !(Positive); return *this; }
	
	// Ostream and Instream
	friend ostream& operator << (ostream &out, BigInt &a)
	{
		if (a.VecNum==0)
		{
			out<<"0";
			return out;
		}   //Bug Fixed if there is a BigInt constructed by the default constructor
		if (!a.Positive) out << "-";
		out << a.A[a.VecNum - 1];
		RepD(a.VecNum - 2, -1, i)
		{
			if (a.A[i] == 0) { out << "0000"; continue; }
			Rep(0, (int)(4 - log(a.A[i]) / log(10) - EPS), j) out << '0';
			out << a.A[i];
		}
		return out;
	}
	friend istream& operator >> (istream &in, BigInt &a)
	{
		string s;
		in >> s;
		int L = s.length() - 1;int i = 0;bool flag = 0;
		if (s[i] == '-') { i++; flag = 1; }
		while (s[i] == '0' && i < L) i++;
		string b(s.begin() + i, s.end());
		if (flag) b.insert(0, "-");
		a = BigInt(b);
		return in;
	}

	//Bool Operators
	bool operator < (const BigInt &b) const
	{
		if (Positive &&  b.Positive)
		{
			if (VecNum != b.VecNum) return (bool)(VecNum<b.VecNum);
			RepD(VecNum-1, -1, i)
				if (A[i] != b.A[i])
					return (bool)(A[i]<b.A[i]);
			//Bug Fixed that there should be a RepD rather that Rep
			return 0;
		}
		if (!Positive &&  b.Positive) return 1;
		if (Positive && !b.Positive)  return 0;
		BigInt a = b;
		BigInt c = (*this);
		if (!c.Positive && !a.Positive) return !((-c) < (-a));
		return 1;
	}
	bool operator >  (const BigInt &b) const { return !((*this)<b); }
	bool operator == (const BigInt &b) const { return (Positive == b.Positive && A == b.A && VecNum == b.VecNum); }
	bool operator <= (const BigInt &b) const { return (*this == b) || (*this < b); }
	bool operator >= (const BigInt &b) const { return (*this == b) || !(*this < b);}
	bool operator != (const BigInt &b) const { return !(*this == b); }
	
	bool operator <  (const string b) const { BigInt x(b); return (*this) < x; }
	bool operator == (const string b) const { BigInt x(b); return x==(*this) < x; }
	
	bool operator <  (const LL& b) const { BigInt x(b); return *this < x; }
	bool operator == (const LL& b) const { BigInt x(b); return *this == x; }
	//Function of Plus and Minus
	BigInt operator - (const BigInt &b) const
	{
		BigInt x=*this;
		BigInt y=b;
		
		if (!x.Positive &&  y.Positive) return -(-x + y);
		if ( x.Positive && !y.Positive) return x + y;
		if (!x.Positive && !y.Positive) return (-y) - (-x);
		if (x<y) return  -(y - x);
		
		int L = max(x.VecNum, y.VecNum);
		y.A.resize(L);
		x.A.resize(L);
		Rep(0, L, i)
		{
			x.A[i] -= y.A[i];
			if (x.A[i]<0) { x.A[i] += IntMod; x.A[i + 1]--; }
		}
		while (x.A[L - 1] == 0 && ((L-1)!=0) ) { x.VecNum--; x.A.pop_back(); L--; }
		return x;
	}
	BigInt operator + (const BigInt &b) const
	{
		BigInt x=*this;
		BigInt y=b;
		
		if (!x.Positive &&  y.Positive) return y - (-x);
		if (!x.Positive && !y.Positive) return -(-x + (-y));
		if ( x.Positive && !y.Positive)  return x - (-y);
		int L = max(x.VecNum, y.VecNum);
		x.A.resize(L + 1);
		y.A.resize(L + 1);
		for (int i = 0; i<L; i++) x.A[i] += y.A[i];
		for (int i = 0; i<L; i++)
		{ x.A[i + 1] += x.A[i] / IntMod; x.A[i] %= IntMod; }
		x.VecNum = L;
		if (x.A[L]) x.VecNum++;
		else x.A.erase(x.A.begin() + L);
		return x;
	}
	BigInt operator - (const LL &b) const { BigInt y(b); return *this - y; }
	BigInt operator + (const LL &b) const { BigInt y(b); return *this + y; }
	BigInt operator - (const string b) const { BigInt y(b); return *this - y; }
	BigInt operator + (const string b) const { BigInt y(b); return *this + y; }
	BigInt operator += (const BigInt& b) { *this=*this+b; return *this; }
	BigInt operator += (const LL& b)     { *this=*this+b; return *this; }
	BigInt operator -= (const BigInt& b) { *this=*this-b; return *this; }
	BigInt operator -= (const LL& b)     { *this=*this-b; return *this; }
	
	
	//Function of Multiply and Division
	BigInt operator * (const BigInt& b) const
	{
		BigInt x=*this;
		BigInt y=b;
		BigInt ans;
		if ((x.Positive && y.Positive) || (!x.Positive && !y.Positive)) ans.Positive=1;
		else ans.Positive=0;
		int m=x.VecNum,n=y.VecNum;
		int L=m+n+1;
		ans.VecNum=L;
		ans.A.resize(L+3);
		Rep(0,m,i)
			Rep(0,n,j)
			{
				int pos=i+j;
				LL t=x.A[i]*y.A[j];
				int post=0;
				while (t>0)
				{
					ans.A[pos+post]+=t%IntMod;
					t/=IntMod;
					post++;
				}
			}
		Rep(0,L,i) { ans.A[i + 1] += ans.A[i] / IntMod; ans.A[i] %= IntMod; }
		while (ans.A[L - 1] == 0 && ((L-1)!=0) ) { ans.VecNum--; ans.A.pop_back(); L--; }
		return ans;
	}
	BigInt operator * (const LL &b) const    { BigInt x(b); return (*this) * x; }
	BigInt operator * (const string b) const { BigInt x(b); return (*this) * x; }
	BigInt operator *= (const BigInt& b){ *this = *this * b; return *this; }
	BigInt operator *= (const LL &b)    { *this = *this * b; return *this; }
	BigInt operator *= (const string b) { *this = *this * b; return *this; }
	
	BigInt operator / (const BigInt& b) const
	{
		
	}
	
	//Function of Remainder
	BigInt operator % (const BigInt& b) const
	{
		
	}
	
	//Function of BITS
};
bool fff=0;
void check(string p1,string p2) {
//	cout<<p1<<' '<<p2<<endl;
	if (!fff) {
		fff=1;
		ans1=p1,ans2=p2;
		return;
	}	
	BigInt ppp=abs(BigInt(p1)-BigInt(p2));
	BigInt pp2=abs(BigInt(ans1)-BigInt(ans2));
	if (ppp<pp2) {
		fff=1;
		ans1=p1,ans2=p2;
		return;
	} else if (ppp==pp2&&BigInt(p1)<BigInt(ans1)){
		fff=1;
		ans1=p1,ans2=p2;
		return;
	} else if (ppp==pp2&&BigInt(p1)==BigInt(ans1)&&BigInt(p2)<BigInt(ans2) ) {
		fff=1;
		ans1=p1,ans2=p2;
		return;
	}
}
void fi(string &s,int i,int j,int p) {
	Fork(k,i,j) if (s[k]=='?')s[k]=p;
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("Bbb.out","w",stdout);
	int T;
	cin>>T;
	For(kcase,T)
	{
		fff=0;
		bool f=0;
		cin>>s1>>s2;
		n=s1.length();
		string p1=s1,p2=s2;
		for(int i=0;i<n;i++) {
			char p='0';
			if (s1[i]=='?'&&s2[i]=='?') {
				s1[i]=s2[i]='0';
				p1=s1,p2=s2;
				p1[i]='1'; 
				fi(p1,i+1,n-1,'0');
				fi(p2,i+1,n-1,'9');
				check(p1,p2);
				p1=s1,p2=s2;
				p1[i]='0'; p2[i]='1';				
				fi(p1,i+1,n-1,'9');
				fi(p2,i+1,n-1,'0');
				check(p1,p2);
			}	
			else if (s1[i]=='?'||s2[i]=='?')
			{
				if (s1[i]=='?') {
					p1=s1,p2=s2;
					if (s2[i]!='0') {
						p1[i]=p2[i]-1;
						fi(p1,i+1,n-1,'9');
						fi(p2,i+1,n-1,'0');
						check(p1,p2);
					}
					p1=s1,p2=s2;
					if (s2[i]!='9') {
						p1[i]=p2[i]+1;
						fi(p1,i+1,n-1,'0');
						fi(p2,i+1,n-1,'9');
						check(p1,p2);
					}
					
				}
				else {
					p1=s1,p2=s2;
					if (s1[i]!='0') {
						p2[i]=p1[i]-1;
						fi(p2,i+1,n-1,'9');
						fi(p1,i+1,n-1,'0');
						check(p1,p2);
					}
					p1=s1,p2=s2;
					if (s1[i]!='9') {
						p2[i]=p1[i]+1;
						fi(p2,i+1,n-1,'0');
						fi(p1,i+1,n-1,'9');
						check(p1,p2);
					}
					
					
				}
				p=s1[i]=='?' ?s2[i]:s1[i];
				s1[i]=s2[i]=p;
			}
			else if (s1[i]==s2[i]) continue;
			else if (s1[i]!=s2[i]) {
				f=1;
				if (s1[i]<s2[i]) {
					fi(s1,i+1,n-1,'9');
					fi(s2,i+1,n-1,'0');
					check(s1,s2);
				}
				else {
					fi(s1,i+1,n-1,'0');
					fi(s2,i+1,n-1,'9');
					check(s1,s2);
					
				}break;
			}
		}		
		if (!f) check(s1,s2);
			
		printf("Case #%d: ",kcase);
		cout<<ans1<<' '<<ans2;
		cout<<endl;
	}
	
	return 0;
}

