#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <string>

#define M 1000000007
#define ULL unsigned long long int

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

bool isvalid(string rs)
{
// is rs valid?
	int k=0;
	while (k<rs.length()-1)
	{
		if (rs[k] == rs[k+1])
		{
			k++;
		}
		else
		{
			for (int l=k+1;l<rs.length();l++)
			{
				if (rs[k] == rs[l])
					return false;
			}
			k++;
		}		
	}
	return true;
}

ULL mres()
{
	int N;
	ein >> N;
	vector <string> s(N);
	vector <string> i(N);
	vector <string> e(N);
	for (int n=0;n<N;n++)
	{
		ein >> s[n];
		
		string a = s[n];
		if (a.length()<2)
		{
			i[n] = "";
			e[n] = a;
			if (a.length()==1)
			{
				e[n] += a;
			}
		}
		else
		{			
			string b;
			char fi = a[0];
			char la = a[a.length()-1];
			while (a.length() > 0)
			{
				if (a[a.length()-1] == la)
				{
					b = a.substr(0,a.length()-1);
					a = b;
				}
				else
					break;
			}
			while (a.length()>0)
			{
				if (a[0] == fi)
				{
					b = a.substr(1,a.length()-1);
					a = b;
				}
				else
					break;
			}
			i[n] = a;
			e[n] = s[n].substr(0,1) + s[n].substr(s[n].length()-1,1);
		}
	}


	/*
	// all permutations
	ULL mres;
	mres = 0;
	if (TestCase == 14)
		{
			int myp[] = {0,1,2,3,4,5,6,7,8,9};
	mres =0;
	do
	{
		string rs = "";
		for (int k=0;k<N;k++)
			rs = rs + s[myp[k]];
		if (isvalid(rs))
		{
			mres++;				
		}
	} while (std::next_permutation(myp,myp+N));
	getchar();
	}
	*/

	for (int n=0;n<N;n++)
	{
		string a;
		string b;
		a = i[n];		
		for (int k=0;k<N;k++)
		{
			if (n!=k)
			{
			b = s[k];
			for (int ka=0;ka<a.length();ka++)
			{
				for (int kb=0;kb<b.length();kb++)
				{
					if (a[ka]==b[kb])
					{
						return 0;
					}
				}
			}
			}
		}
	}

	for (int n=0;n<N;n++)
	{
		string a;
		a = s[n];
		int k =0;
		while (k<a.length()-1)
		{
			if (a[k] == a[k+1])
			{
				k++;
			}
			else
			{
				for (int l=k+1;l<a.length();l++)
				{
					if (a[k] == a[l])
						return 0;
				}
				k++;
			}
		}
	}

	ULL res = 1;

	for (int n=0;n<N;n++)
	{
		if (!e[n].empty())
		{
			if (e[n][0] == e[n][1])
			{
				ULL v =1;
				for (int k=n+1;k<N;k++)
				{
					if (e[k] == e[n])
					{
						v++;
						res = (res * v) % M;
						e[k] = "";
						s[n] += s[k];
						s[k] = "";
					}
				}
				
			

			for (int k=0;k<N;k++)
			{
				if ((k!=n) && (!e[k].empty()))
				{
					if (e[k][1] == e[n][0])
					{
						e[n] = "";
						s[k] = s[k]+s[n];
						s[n] = "";
						break;
					}
				}
			}
			if (!e[n].empty())
			{
				for (int k=0;k<N;k++)
				{
					if ((k!=n) && (!e[k].empty()))
					{
						if (e[k][0] == e[n][1])
						{							
							e[n] = "";
							s[k] = s[n]+s[k];
							s[n]="";
							break;
						}
					}
				}
			}			
			}
		}
	}

	bool red = true;
	while (red)
	{
		red = false;
		for (int n=0;n<N;n++)
		{
			if (!e[n].empty()) {
			for (int k=0;k<N;k++)
			{
				if ((k!=n) && (!e[k].empty())) {
				if (e[n][0] == e[k][1])
				{
					e[k][1] = e[n][1];
					s[k] = s[k]+s[n];
					s[n]="";
					e[n] = "";
					red = true;
					break;
				}}

			}
			}
		}
	}

	int nonempty=0;

	string rs = "";
	for (int n=0;n<N;n++)
	{
		if (!e[n].empty())
		{
			nonempty++;
			rs = rs+ s[n];
			for (int k=0;k<n;k++)
			{
				if (!e[k].empty())
				{
					if ((e[n][0]==e[k][0]) || ((e[n][1] == e[k][1])))
						return 0;
				}
			}
		}
	}	

	if (!isvalid(rs))
		return 0;

	for (ULL a=1;a<=nonempty;a++)
	{
		res = (res*a) % M;
	}
	//printf("%d: %d %d", N, res, mres);
	return res;
}

void start()
{
	printf("%d\n", TestCase);
	
	ULL result;
	result = mres();




	// output result
    fprintf(aus, "Case #%d: %llu\n", TestCase, result); 
}

void main()
{
	int NumTestCases;	
	ein.open("B-large.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
