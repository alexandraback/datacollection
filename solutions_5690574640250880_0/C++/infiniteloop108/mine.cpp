#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void disp(vector<vector<char> > brd)
{
for(int i=0;i<brd.size();++i)
{
for(int j=0;j<brd[i].size();++j)
cout<<brd[i][j];
cout<<endl;
}
}
void imp()
{
cout<<"Impossible\n";
}
void doit(int tc)
{
int r,c,m;
cin>>r>>c>>m;
cout<<"Case #"<<tc<<":\n";
if(m==r*c-1)
{
vector<vector<char> > brd2(r,vector<char>(c,'*'));
brd2[r-1][c-1]='c';
disp(brd2);
return;
}
vector<vector<char> > brd(r,vector<char>(c,'.'));
if(r==1)
{
brd[0][c-1]='c';
for(int i=0;i<m;++i)brd[0][i]='*';
disp(brd);
return;
}
if(c==1)
{
brd[r-1][0]='c';
for(int i=0;i<m;++i)brd[i][0]='*';
disp(brd);
return;
}
if(r==2)
{
if(m%2==1){imp();return;}
if(m==(c-1)*r){imp();return;}
brd[r-1][c-1]='c';
for(int i=0;i<m/2;++i)
{
brd[0][i]='*';
brd[1][i]='*';
}
disp(brd);
return;
}
if(c==2)
{
if(m%2==1){imp();return;}
if(m==(r-1)*c){imp();return;}
brd[r-1][c-1]='c';
for(int i=0;i<m/2;++i)
{
brd[i][0]='*';
brd[i][1]='*';
}
disp(brd);
return;
}
int sf=2*(r+c)-4;
int n=r*c;
if(m==n-2||m==n-3||m==n-5||m==n-7){imp();return;}
if(m==n-4)
{
vector<vector<char> > brd2(r,vector<char>(c,'*'));
brd2[r-1][c-1]='c';
brd2[r-2][c-1]='.';
brd2[r-2][c-2]='.';
brd2[r-1][c-2]='.';
disp(brd2);
return;
}
if(m==n-6)
{
vector<vector<char> > brd2(r,vector<char>(c,'*'));
brd2[r-1][c-1]='c';
brd2[r-2][c-1]='.';
brd2[r-2][c-2]='.';
brd2[r-1][c-2]='.';
brd2[r-3][c-2]='.';
brd2[r-3][c-1]='.';
disp(brd2);
return;
}
if(m<=n-8)
{
	brd[r-1][c-1]='c';
	if(m<=n-sf)
	{
		int i=0,j=0,d=0;
		while(d<m)
		{
			brd[i][j]='*';
			j++;	
			d++;
			if(j>c-3){j=0;i++;}
		}	
		disp(brd);
		return;
	}
	else
	{
		int i=0,j=0,d=0;
		while(d<n-sf)
		{
			brd[i][j]='*';
			j++;	
			d++;
			if(j>c-3){j=0;i++;}
		}
		d=m-n+sf;
		if((d)%2==1){brd[r-3][c-3]='.';d++;}
		for(i=0;i<r-3;++i)
		{
			if(d==0){disp(brd);return;}
			brd[i][c-2]='*';
			brd[i][c-1]='*';
			d-=2;
		}
		for(i=0;i<c-3;++i)
		{
			if(d==0){disp(brd);return;}
			brd[r-1][i]='*';
			brd[r-2][i]='*';
			d-=2;
		}
		disp(brd);
		return;
	}

}
imp();
return;
}
int main()
{
int t;
cin>>t;
int i=1;
while(t--)
{
doit(i++);
}
return 0;
}
