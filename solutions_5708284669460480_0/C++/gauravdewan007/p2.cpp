#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char w[202];
char target[202];
double p[26]; //prob table of alphabet
double ans=0.0;
int m = 0; //largest length suffix of string that is also a prefix of it - for target
double e = 0;
int k,l,s;
char b[200];

int match(const char *s, const char *p, int overlap)
{
        int c = 0, l = strlen(p);
 
        while (*s != '\0') {
                if (strncmp(s++, p, l)) continue;
                if (!overlap) s += l - 1;
                c++;
        }
        return c;
}

double prob(char* b)
{
	int k = strlen(b);
	double h = 1.0;
	int i;
	for(i=0;i<k;i++)
		h *= p[b[i]-'A'];
	return h;
	
}
void compute(int r)
{
	if(r == s)
	{	//b is full
		//kmp or naive?
		//find occurence of target in it
		b[r] = 0;
		int h = match(b,target,1);
		m = max(m,h);
		double pr = prob(b);
		e += h*pr;
		return;
	}
	int i;
	for(i=0;i<26;i++)
	if(p[i])
	{
		b[r] = (char)(i+'A');
		compute(r+1);
	}
}

int main()
{
	int t,i,j,ka;
	cin>>t;
	for(ka=1;ka<=t;ka++)
	{
		
		ans = 0.0;m=0;e=0.0;
		memset(p,0,sizeof(p));
		cin>>k>>l>>s;
		cin.getline(w,200);
		cin.getline(w,200);
		for(i=0;i<k;i++)
			p[w[i]-'A'] += 1.0/k;
		
		cin.getline(target,200);
		compute(0);
		ans = m-e;		
		
		
		printf("Case #%d: %0.7lf\n",ka,ans);
	}
	return 0;
}
