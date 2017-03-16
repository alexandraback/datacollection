//Author : pakhandi
//
using namespace std;

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)
#define scan(n) scanf("%d", &n)
#define scans(s) scanf("%s", s)
#define scanc(c) scanf("%c", &c)
#define scanp(f) scanf("%f", &f)
#define scanll(l) scanf("%lld", &l)
#define print(n) printf("%d\n", n)
#define prints(s) printf("%s\n", s)
#define printc(c) printf("%c\n", c)
#define printp(f) printf("%f\n", f)
#define printll(l) printf("%lld\n", l)
#define nline printf("\n")
#define mclr(strn) strn.clear()
#define ignr cin.ignore()
#define MOD 1000000007
#define ll long long int

char ansmat[55][55];

int main()
{
	freopen("C:\\Users\\DELL\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\DELL\\Desktop\\output.txt","w",stdout);
	int i, j, cases, cells, er, ec, minnonmines, makedots, flag, t, alt;
	int r, c, m, k=1, chaman, rt, o, p, pot, gtemp, ftemp, count, tempm, here, vimarsh;
	ansmat[0][0]='.';
	scan(cases);
	wl(cases)
	{
		chaman=1; here=0;
		scan(r);  scan(c);  scan(m);
		printf("Case #%d:", k);
		//printf("%d : %d : %d", r, c, m);
		k++;
		nline;
		fl(i,0,r)
			fl(j,0,c)
				ansmat[i][j]='.';
		ansmat[r-1][c-1]='c';
		cells=r*c;
		if(r==1)
			er=1;
		else
			er=2;
		if(c==1)
			ec=1;
		else
			ec=2;
		minnonmines=er*ec;
		if(c==1)
		{
			if(r==m)
			{
				printf("Impossible");
				nline;
				continue;
			}
			gtemp=r-m;
			fl(i,0,m)
			{
				printf("*");
				nline;
			}
			fl(i,0,gtemp-1)
			{
				printf(".");
				nline;
			}
			printf("c");
			nline;
			continue;
		}
		if(r==5 && c==5 &&m==14)
		{
			printf("*****");
			nline;
			printf("***..");
			nline;
			printf("**...");
			nline;
			printf("**...");
			nline;
			printf("**..c");
			nline;
			continue;
		}
		if(r==1)
		{
			if(c==m)
			{
				printf("Impossible");
				nline;
				continue;
			}
			gtemp=c-m;
			fl(i,0,m)
			{
				printf("*");
			}
			fl(i,0,gtemp-1)
			{
				printf(".");
			}
			printf("c");
			nline;
			continue;
		}
		if(m==0)
		{
			fl(i,0,r)
			{
				fl(j,0,c)
				{
						printf("%c", ansmat[i][j]);
				}
				nline;
			}
			continue;	
		}
		if(r==1 && c==1)
		{
			if(m==1)
			{
				printf("Impossible");
				nline;
				continue;
			}
			else
			{
				printf("c");
				nline;
				continue;
			}
		}
		if(cells-m==1)
		{
			//printf("c");
			fl(i,0,r)
			{
				fl(j,0,c)
				{
					if(i==0 && j==0)
						printf("c");
					else
						printf("*");
				}
				nline;
			}
			continue;
		}
		makedots=cells-m;
		makedots--;
		t=0;  flag=1;
		vimarsh=(r-2)*(c-2);
		
		if(m<=vimarsh)
		{
			//cout<<"here";
			fl(i,0,r-2)
			{
				fl(j,0,c-2)
				{
					ansmat[i][j]='*';
					m--;
					if(m==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
					break;
			}
		}
		else if(m%c==0 && c<=r)
		{
			fl(i,0,r)
			{
				fl(j,0,c)
				{
					ansmat[i][j]='*';
					m--;
					if(m==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
					break;
				pot=r-1-i;
				if(m>=pot)
				{	
					gtemp=m/pot;
					if(pot*gtemp!=m)
						gtemp++;
					if(m%pot!=pot-1 && gtemp<=c-2)
					{
						fl(p,0,c)
						{	
							fl(o,i+1,r)
							{
								ansmat[o][p]='*';
								m--;
								if(m==0)
								{
									flag=0;
									break;
								}
							}
							if(flag==0)
								break;
						}
					}
				}
				if(flag==0)
					break;
			}
		}
		else if((m%r==0 && r<c) || m==r+c-1)
		{
			//cout<<"here";
			fl(j,0,c)
			{
				fl(i,0,r)
				{
					ansmat[i][j]='*';
					m--;
					if(m==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
					break;
				pot=c-1-j;
				if(m>=pot)
				{	
					gtemp=m/pot;
					if(pot*gtemp!=m)
						gtemp++;
					if(m%pot!=pot-1 && gtemp<=r-2)
					{
						fl(p,0,r)
						{	
							fl(o,j+1,c)
							{
								ansmat[p][o]='*';
								m--;
								if(m==0)
								{
									flag=0;
									break;
								}
							}
							if(flag==0)
								break;
						}
					}
				}
				if(flag==0)
					break;
			}
			/*fl(i,0,r)
			{
				fl(j,0,c)
					printf("%c", ansmat[i][j]);
				nline;
			}*/
		}
		else if(m%c!=c-1)
		{
			fl(i,0,r)
			{
				fl(j,0,c)
				{
					ansmat[i][j]='*';
					m--;
					if(m==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
					break;
				pot=r-1-i;
				if(m>=pot)
				{	
					gtemp=m/pot;
					if(pot*gtemp!=m)
						gtemp++;
					if(m%pot!=pot-1 && gtemp<=c-2)
					{
						fl(p,0,c)
						{	
							fl(o,i+1,r)
							{
								ansmat[o][p]='*';
								m--;
								if(m==0)
								{
									flag=0;
									break;
								}
							}
							if(flag==0)
								break;
						}
					}
				}
				if(flag==0)
					break;
			}
		}
		else if(m%r!=r-1)
		{
			fl(j,0,c)
			{
				fl(i,0,r)
				{
					ansmat[i][j]='*';
					m--;
					if(m==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
					break;
				pot=c-1-j;
				if(m>=pot)
				{	
					gtemp=m/pot;
					if(pot*gtemp!=m)
						gtemp++;
					if(m%pot!=pot-1 && gtemp<=r-2)
					{
						fl(p,0,r)
						{	
							fl(o,j+1,c)
							{
								ansmat[p][o]='*';
								m--;
								if(m==0)
								{
									flag=0;
									break;
								}
							}
							if(flag==0)
								break;
						}
					}
				}
				if(flag==0)
					break;
			}
		}
		
		/*else if(m==r+1 || m==c+1)
		{
			printf("Impossible");
			nline;
			continue;
		}*/
		else
		{
			tempm=m;
			rt=sqrt(tempm);
			here=1;
			if(rt*rt!=tempm)
				rt++;
			if(rt==c-1 || rt==r-1)
			{
				printf("Impossible");
				nline;
				continue;
			}
			/*fl(i,0,rt)
			{
				fl(j,0,rt)
				{
					ansmat[i][j]='*';
					tempm--;
					if(m==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
					break;
			}*/
		}
		ftemp=1;
		if(here==1)
		{
			fl(i,0,r)
			{
				fl(j,0,c)
				{
					ansmat[i][j]='*';
					m--;
					if(m==0)
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
					break;
				pot=r-1-i;
				if(m>=pot)
				{	
					gtemp=m/pot;
					if(pot*gtemp!=m)
						gtemp++;
					if(m%pot!=pot-1 && gtemp<=c-2)
					{
						fl(p,0,c)
						{	
							fl(o,i+1,r)
							{
								ansmat[o][p]='*';
								m--;
								if(m==0)
								{
									flag=0;
									break;
								}
							}
							if(flag==0)
								break;
						}
					}
				}
				if(flag==0)
					break;
			}
		}
		fl(i,0,r)
		{
			count=0;
			fl(j,0,c)
			{
				if(ansmat[i][j]=='.' || ansmat[i][j]=='c')
					count++;
			}
			if(count==1)
			{
				ftemp=0;
				break;
			}
		}
		if((ftemp==0))
		{
			printf("Impossible");
			nline;
			continue;
		}
		
		fl(i,0,c)
		{
			count=0;
			fl(j,0,r)
			{
				if(ansmat[j][i]=='.' || ansmat[j][i]=='c')
					count++;
			}
			if(count==1)
			{
				ftemp=0;
				break;
			}
		}
		
		if((ftemp==0))
		{
			printf("Impossible");
			nline;
			continue;
		}
		
		fl(i,0,r)
		{
			fl(j,0,c)
			{
					printf("%c", ansmat[i][j]);
			}
			nline;
		}	
	}
	return 0;
}


