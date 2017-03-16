#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string square_of(string s)
{	
	int n=s.size();
	string q;
	for (int i=0; i<n; i++)
	{
		int temp = 0;
		for (int j=0; j<=i; j++)
			temp += (s[j]-'0')*(s[i-j]-'0');
		q += (temp+'0');
	}
	for (int i=n; i<2*n-1; i++)
		q += q[2*n-2-i];
	return q;
}

bool leq(string s, string end)		// return true if s <= end
{	// presumption:  s[0]!='0', end[0]!='0'
	int n=s.size(), m=end.size();
	if (n!=m)	return (n<m);	// different length
	for (int i=0; i<n; i++)
		if (s[i]!=end[i])
			return (s[i]<end[i]);
	return true;		// equal case
}

bool geq(string s, string start)		// return true if s >= start
{	// presumption:  s[0]!='0', start[0]!='0'
	int n=s.size(), m=start.size();
	if (n!=m)	return (n>m);
	for (int i=0; i<n; i++)
		if (s[i]!=start[i])
			return (s[i]>start[i]);
	return true;		// equal case
}

// start: string with length 2n-1
// count: #{FS numbers} whose squares strictly < start
bool enum_comb(int &count, string &start, string &seg, int *N, int k, int n1, bool strict)
{	// to place seg[k]; already has n1 '1'
	int n=start.size()/2+1;
	if (k==n/2-1)		// place done; check (1 seg () seg 1)^2 and start
	{
		string temp("1");
		temp += seg;
		if (n%2==1)		temp += '0';
		for (int i=seg.size()-1; i>=0; i--)
			temp += seg[i];
		temp += '1';
		if (strict)
		{
			if (geq(square_of(temp),start))
				return true;
			else	count++;
		} else
		{
			if (!leq(square_of(temp),start))
				return true;
			else	count++;
		}
		if (n%2==1)
		{
			temp[n/2] = '1';
			if (strict)
			{
				if (geq(square_of(temp),start))
					return true;
				else	count++;
			}else
			{
				if (!leq(square_of(temp),start))
					return true;
				else	count++;
			}
		}
		return false;
	}
	// to place
	seg[k]='0';
	if (enum_comb(count,start,seg,N,k+1,n1,strict))
		return true;
	if (n1<3)	// can place '1' at seg[k]
	{
		seg[k]='1';
		if (enum_comb(count,start,seg,N,k+1,n1+1,strict))
			return true;
	}
	return false;
}



// compute #{FS root numbers} with length start.size()/2+1,
// whose squares are strictly < start for strict==true
// otherwise <= start for strict==false
int le_start(string start, int *N, bool strict)
{
	if (start.size()%2==0)		return 0;	// start is of length 2n, so any FS root number of length n+1 has larger square than start
	int n = start.size()/2+1;		// start is of length 2n-1
	if (n==1)
	{
		if (strict)
		{
			if (start[0]>'4')			return 2;
			else if (start[0]>'1')		return 1;
			else		return 0;
		} else
		{
			if (start[0]=='9')		return 3;
			else if (start[0]>='4')	return 2;
			else		return 1;
		}
	}

	int k = n/2;		// n=2k or n=2k+1
	if (start[0]>='5')		return N[n-1];
	if (start[0]=='4')
	{
		if (n%2==0)		// even length
		{
			string seg;
			seg.assign(n-2,'0');
			string temp("2");			
			temp += seg;
			temp += '2';
			if (strict)
			{
				if ( geq(square_of(temp), start) )		return N[n-1]-1;
				else			return N[n-1];
			} else
			{
				if ( leq(square_of(temp), start) )		return N[n-1];
				else		return N[n-1]-1;
			}
		} else		// n=2k+1
		{
			int exc=N[n-1];
			string seg;
			seg.assign(k-1,'0');
			string temp("2");
			temp += seg;
			temp += '0';
			temp += seg;
			temp += '2';
			if (strict)
			{
				if ( geq(square_of(temp), start) )		return N[n-1]-2;		// start <= 2...0...2^2
				else
				{
					temp[k] = '1';
					if ( geq(square_of(temp), start) )		return N[n-1]-1;		// 2...0...2^2 < start <= 2...1...2^2
					else		return N[n-1];
				}
			} else
			{
				if ( !leq(square_of(temp), start) )		return N[n-1]-2;		// start <= 2...0...2^2
				else
				{
					temp[k] = '1';
					if ( !leq(square_of(temp), start) )		return N[n-1]-1;		// 2...0...2^2 < start <= 2...1...2^2
					else		return N[n-1];
				}
			}
		}
	}
	if (start[0]=='3' || start[0]=='2')
	{
		if (n%2==0)		return N[n-1]-1;
		else					return N[n-1]-2;
	}
	int count=0;
	string seg;
	seg.assign(k-1,'0');
	// first check:  1......2......1  and  1..1..2..1..1, if n is odd
	if (n%2==1)
	{
		string temp("1");
		temp += seg;
		temp += '2';
		temp += seg;
		temp += '1';
		if (strict)
		{
			if ( !geq(square_of(temp),start) )		count++;
		} else
		{
			if ( leq(square_of(temp),start) )		count++;
		}
		for (int i=k-1; i>=1; i--)
		{
			temp[i]='1';
			temp[2*k-i]='1';
			if (strict)
			{
				if ( !geq(square_of(temp),start) )		count++;
				else		break;
			} else
			{
				if ( leq(square_of(temp),start) )		count++;
				else		break;
			}
			temp[i]='0';
			temp[2*k-i]='0';
		}
	}
	// then check roots with only '0' and '1' digits
	enum_comb(count, start, seg, N, 0, 0, strict);
	return count;
}


// calculate #{FS root numbers} with fixed length
void compute_FS(int *N)
{
	int i;
	for (i=0; i<50; i++)		N[i]=0;
	N[0] = 3;
	for (i=1; i<50; i++)	// length i+1
	{
		int k=(i+1)/2;
		int comb=1;	// compute:  C(k-1,0)+C(k-1,1)+C(k-1,2)+C(k-1,3)
		if (k-1>=1)	comb += k-1;
		if (k-1>=2)	comb += (k-1)*(k-2)/2;
		if (k-1>=3)	comb += (k-1)*(k-2)*(k-3)/6;
		if (i%2==1)	// even length
			N[i] = 1+comb;
		else
			N[i] = 2+k+2*comb;
	}
}

int count_final(string start, string end, int *N)
{
	int n=start.size()/2+1, m=end.size()/2+1;
	int result=0;
	for (int i=n-1; i<=m-1; i++)		result += N[i];
	result -= le_start(start, N, true);
	result -= (N[m-1]-le_start(end, N, false));
	return result;
}


int main()
{
	int N[50];
	compute_FS(N);		// N[i]: #{FS root numbers} with length i+1
	//for (int i=0; i<50; i++)
	//	cout << N[i] << "  ";

//	cout << le_start("204060402", N);

	ifstream inFile;
	inFile.open("C-large-1.in");
	ofstream outFile;
	outFile.open("C_large_1.out");
	int nCases, i;
	string start, end;	
	inFile >> nCases;
	inFile.ignore(10,'\n');
	for (i=0; i<nCases; i++)
	{
		inFile >> start >> end;	// current [start, end]
		inFile.ignore(10,'\n');
		outFile << "Case #" << i+1 << ": ";
		outFile << count_final(start,end,N) << endl;
	}


	inFile.close();
	outFile.close();

	return 1;
}


	//string s("1002001");
	//cout << square_of(s) << endl;

	//string s("1002562"), q("1002552");
	//if (geq(s,q))	cout << s << " is geq to " << q << endl;
	//else				cout << s << " is less than " << q << endl;