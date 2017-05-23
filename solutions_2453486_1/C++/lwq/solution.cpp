#include<stdio.h>
FILE *fin,*fout;
char b[4][4];
int main()
{
	fin=fopen("a.in","r");
	fout=fopen("a.out","w");
	int tc,test;
	int c;
	char t,u;
	bool v;
	int a,s;
	fscanf(fin,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		c=0;
		for(a=0;a<4;a++) for(s=0;s<4;s++)
		{
			fscanf(fin," %c",&b[a][s]);
			if( b[a][s]=='.' ) c++;
		}
		v=false;
		if( v==false )
		{
			for(a=0;a<4;a++)
			{
				v=true;
				t='T';
				for(s=0;s<4;s++)
				{
					u=b[a][s];
					if( u=='.' ) v=false;
					if( u!='T' )
					{
						if( t!='T' && t!=u ) v=false;
						t=u;
					}
				}
				if( v==true ) break;
			}
		}
		if( v==false )
		{
			for(a=0;a<4;a++)
			{
				v=true;
				t='T';
				for(s=0;s<4;s++)
				{
					u=b[s][a];
					if( u=='.' ) v=false;
					if( u!='T' )
					{
						if( t!='T' && t!=u ) v=false;
						t=u;
					}
				}
				if( v==true ) break;
			}
		}
		if( v==false )
		{
			v=true;
			t='T';
			for(a=0;a<4;a++)
			{
				u=b[a][a];
				if( u=='.' ) v=false;
				if( u!='T' )
				{
					if( t!='T' && t!=u ) v=false;
					t=u;
				}
			}
		}
		if( v==false )
		{
			v=true;
			t='T';
			for(a=0;a<4;a++)
			{
				u=b[a][4-1-a];
				if( u=='.' ) v=false;
				if( u!='T' )
				{
					if( t!='T' && t!=u ) v=false;
					t=u;
				}
			}
		}
		fprintf(fout,"Case #%d: ",test);
		if( v==true )
		{
			fprintf(fout,"%c won",t);
		}
		else if( c==0 )
		{
			fprintf(fout,"Draw");
		}
		else
		{
			fprintf(fout,"Game has not completed");
		}
		fprintf(fout,"\n");
	}
}