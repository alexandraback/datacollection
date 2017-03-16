#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
#include<set>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
class Fraction
{
public:
	int n,d;//numerator and denominator
	Fraction(int nn, int dd):n(nn),d(dd){reduce();}
	Fraction(){n=1;d=1;}
	void reduce()
	{
		int b=gcd(abs(n),abs(d)); n/=b; d/=b;
	}
	Fraction operator*(const Fraction &b)
	{
		Fraction x;
		x.n = n*b.n;
		x.d = d*b.d;
		x.reduce();
		return x;
	}
	Fraction operator+(const Fraction &b)
	{
		Fraction x;
		x.d = d*b.d;
		x.n = n*b.d + d*b.n;
		x.reduce();
		return x;
	}
	bool operator==(const Fraction &b)
	{
		return (n==b.n && d==b.d);
	}

	bool operator<(const Fraction &b) const
	{
		//work only if numbers are positive
		return n*b.d < d*b.n;
	}

	friend ostream& operator<<(ostream &output, const Fraction &b)
	{
		output<<b.n<<'/'<<b.d<<endl;
		return output;
	}
};

int main(int argc, char *argv[])
{
//readin file
	string file;
	if(argc!=2){cerr<<"0,1 or 2!"<<endl;exit(1);}
	switch(atoi(argv[1]))
	{
		case 0: file="test"; break;
		case 1: file="D-small"; break;
		case 2: file="D-large"; break;
		default: cerr<<"choose the correct file, 0(test),1(small),2(large)"<<endl;exit(1); break;
	}
	string ifilename=file+".in"; string ofilename=file+".out";
	ifstream input(ifilename.c_str());ofstream output(ofilename.c_str());

//read in number of events
	int T;
	input>>T;
	int H,W,D;

//main loop start
	for(int t=0;t<T;t++)
	{
		int r=0;
		input>>H>>W>>D;
		char A[H][W];
		double Xi,Xj;
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				input>>A[i][j];
				if(A[i][j]=='X'){Xi=i-0.5;Xj=j-0.5;}
//				cout<<A[i][j];
			}
//			cout<<endl;
		}

		vector<Fraction> dir;
		int DH = (D+1)/(H-2)+4;
		int DW = (D+1)/(W-2)+4;
		for(int n=-DH;n<=DH;n++)
			for(int m=-DW;m<=DW;m++)
			{
				if(n==0 && m==0)continue;
				if(n==0 && (m>1 || m<-1))continue;
				if(m==0 && (n>1 || n<-1))continue;
				int x = n*(H-2);
				int y = m*(W-2);
				double xx,yy;
				if(n%2==0)xx=x+Xi;
				else xx = x+(H-2)-Xi;
				if(m%2==0)yy=y+Xj;
				else yy = y+(W-2)-Xj;
//				cout<<n<<' '<<m<<' '<<sqrt((xx-Xi)*(xx-Xi)+(yy-Xj)*(yy-Xj))<<endl;
				
				if(((xx-Xi)*(xx-Xi)+(yy-Xj)*(yy-Xj)) <= D*D)
				{
					Fraction f(int((xx-Xi)*2),int((yy-Xj)*2));
					bool exist=false;
					for(int i=0;i<dir.size();i++)
					{
						if(dir[i] == f){exist=true;break;}
					}
					if(!exist){
						dir.push_back(f);
						r++;
					}
				}
			}

		output<<"Case #"<<t+1<<": "<<r<<endl;
		cout<<"case : "<<t+1<<": "<<r<<endl;
	}

	input.close();
	output.close();
	return 0;
}
