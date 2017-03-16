#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	int sp, pos ;
} car ;

class lane
{
	public :
		car c[110] ;
		int top ;
		lane()
		{
			top = 0 ;
		}
		void addcar(car ca)
		{
			c[top++] = ca ;
		}
		bool canadd(car ca, double t)
		{
			int i ;
			for(i=0;i<top;i++)
			{
				if(fabs((c[i].pos+c[i].sp*t)-(ca.pos+ca.sp*t))<5)
				{
					return false ;
				}
			}
			return true ;
		}
		void remove(int id)
		{
			int i ;
			for(i=id;i<top;i++)
			{
				c[i] = c[i+1] ;
			}
			top-- ;
		}
		lane &operator=(const lane &la)
		{
			this->top = la.top ;
			for(int i=0;i<la.top;i++)
			{
				this->c[i] = la.c[i] ;
			}
			
			return *this ;
		}
		double collid(int *id1, int *id2, double ct)
		{
			int i, j ;
			double ret = -1 ;
			
			for(i=0;i<top;i++)
			{
				for(j=0;j<top;j++)
				{
					double t ;
					if(c[i].sp>c[j].sp)
					{
						t = ((double)(c[j].pos-5-c[i].pos))/(c[i].sp-c[j].sp) ;
						if(t>=ct)
						{
							if(ret<0||t<ret)
							{
								*id1 = i ;
								*id2 = j ;
								ret = t ;
							}
						}
					}
				}
			}
			
			return ret ;
		}
} ;

double go(lane a, lane b, double pt, int pmid, int pl)
{
	double ret = -1 ;
	double ta, tb ;
	int cida[2], cidb[2] ;

	ta = a.collid(cida,cida+1,pt) ;
	tb = b.collid(cidb,cidb+1,pt) ;

	//fprintf(stderr,"%lf %lf\n",ta,tb) ;
	
	if(ta<0&&tb<0)
	{
		return -1 ;
	}
	else if((ta>=0&&ta<tb)||tb<0)
	{
		//deal at
		lane na, nb ;
		na = a ;
		nb = b ;
		ret = ta ;
		if((!(pl==0&&ta==pt&&pmid==cida[0]))&&nb.canadd(na.c[cida[0]],ta)==true)
		{
			nb.addcar(na.c[cida[0]]) ;
			na.remove(cida[0]) ;
			double tmp = go(na,nb,ta,nb.top-1,1) ;
			if(tmp>ret||tmp<0)
			{
				ret = tmp ;
			}
		}
		na = a ;
		nb = b ;
		if((!(pl==0&&ta==pt&&pmid==cida[1]))&&nb.canadd(na.c[cida[1]],ta)==true)
		{
			nb.addcar(na.c[cida[1]]) ;
			na.remove(cida[1]) ;
			double tmp = go(na,nb,ta,nb.top-1,1) ;
			if(tmp>ret||tmp<0)
			{
				ret = tmp ;
			}
		}
	}
	else
	{
		//deal bt
		lane na, nb ;
		na = a ;
		nb = b ;
		ret = tb ;
		if((!(pl==1&&tb==pt&&pmid==cidb[0]))&&na.canadd(nb.c[cidb[0]],tb)==true)
		{
			na.addcar(nb.c[cidb[0]]) ;
			nb.remove(cidb[0]) ;
			double tmp = go(na,nb,tb,na.top-1,0) ;
			if(tmp>ret||tmp<0)
			{
				ret = tmp ;
			}
		}
		na = a ;
		nb = b ;
		if((!(pl==1&&tb==pt&&pmid==cidb[1]))&&na.canadd(nb.c[cidb[1]],tb)==true)
		{
			na.addcar(nb.c[cidb[1]]) ;
			nb.remove(cidb[1]) ;
			double tmp = go(na,nb,tb,na.top-1,0) ;
			if(tmp>ret||tmp<0)
			{
				ret = tmp ;
			}
		}
	}
	
	return ret ;
}

int main(void)
{
	int t, c ;

	scanf("%d",&t) ;
	for(c=1;c<=t;c++)
	{
		char str[5] ;
		int i ;
		int n ;
		lane a, b ;
		double maxt = -10 ;
		
		scanf("%d",&n) ;
		for(i=0;i<n;i++)
		{
			car c ;
			scanf("%s%d%d",str,&c.sp,&c.pos) ;
			if(str[0]=='L')
			{
				a.addcar(c) ;
			}
			else
			{
				b.addcar(c) ;
			}
		}
		
		maxt = go(a,b,0,-1,-1) ;
		
		printf("Case #%d: ",c) ;
		if(maxt<0)
		{
			printf("Possible\n") ;
		}
		else
		{
			printf("%lf\n",maxt) ;
		}
	}
	
	return 0 ;
}
