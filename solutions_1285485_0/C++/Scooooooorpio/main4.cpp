//#include "LongInt.h"
#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <cassert>
#include <cmath>
#include <QPoint>
using namespace std;
ifstream fin; 
ofstream fout;

void preWork();
void work();

int main(int argc, char *argv[])
{
	//preWork();
	QCoreApplication a(argc, argv);

	//char * inputName="A-large.in";
	//fin.open(inputName);
	//	fin.open ( "A-small-practice.in");
	//fin.open ( "A-large-practice.in");
	fin.open("NO4_input.txt");

	fout.open("output.txt");
	int n;
	fin >>n;
	for (int i=0; i<n; i++)
	{
		fout<<"Case #"<<i+1<<": ";
		work();
		fout<<endl;
	}


	fin.close();

	fout.close();



	//	return a.exec();
}
char cccc[500][500];
int  rrrr[500][500];
bool kkkk[500][500];
char & grid(QPoint p)
{
	int a,b;
	a= p.x();
	b= p.y();
	assert(a>-200 && a<200);
	assert(b>-200 && b<200);
	return cccc[a+250][b+250];
}
char & grid2(QPoint p)
{
	return grid( (p+QPoint(1,1))/2 );
}
int & mirrorImage(QPoint p)
{
	int a, b;
	a= p.x();
	b= p.y();
	assert(a>-200 && a<200);
	assert(b>-200 && b<200);
	return rrrr[a+250][b+250];

}
int ngcd(int a,int b)
{
	while (b!=0)
	{
		int c= a%b;
		a= b;
		b=c;
	}
	return a;
}
void simplifyAngle(QPoint & a)
{
	int t = abs(ngcd(a.x(), a.y() ) );
	if (t==0) return;
	a.rx()/= t;
	a.ry()/= t;
}
bool & result(QPoint p)
{
	simplifyAngle(p);
	int a, b;
	a= p.x();
	b= p.y();
	assert(a>-200 && a<200);
	assert(b>-200 && b<200);
	return kkkk[a+250][b+250];
}
void preWork()
{


}
int DDD;
bool angleBetween(QPoint a0, QPoint a1, QPoint a2)
{
	
	if (a1.x()== a2.x())
	{
		int t= abs( ngcd(a0.x(),a1.x()));
		int z = a1.x()/t;
		int z1 = a0.x()/t;
		a0*=z;
		a1*= z1;
		a2*= z1;
		if (a1.y()> a2.y()) swap(a1,a2);
		if (a1.y()<= a0.y() && a0.y()<= a2.y()) return true;
		else return false;
	}
	else
	{
		assert(a1.y()== a2.y());
		int t= abs( ngcd(a0.y(),a1.y()));
		int z = a1.y()/t;
		int z1 = a0.y()/t;
		a0*=z;
		a1*= z1;
		a2*= z1;
		if (a1.x()> a2.x()) swap(a1,a2);
		if (a1.x()<= a0.x() && a0.x()<= a2.x()) return true;
		else return false;
	}
	assert(false);
}

bool check(QPoint start, QPoint dir)
{
	simplifyAngle(dir);
	if (dir==QPoint(-1,-2))
	{
		cout<<1;
	}
	QPoint now = start;

	QPoint currentGrid;
	currentGrid = now;
	while(true)
	{
//////////////approach one grid
		bool crossV, crossH;


		QPoint d1,d2,d3;
		QPoint g1,g2,g3;
		g1 = currentGrid;
		g2= g1; 
		g3= g2;
		int y0,y1;
		int x0,x1;
		if (dir.y()>0)
		{
			y1 = currentGrid.y()- now.y()+1;
			y0=y1-2;
			g1.ry()+=2;
			g2.ry()+=2;
		}
		else
		{
			y1 = currentGrid.y()- now.y()-1;
			y0=y1+2;
			g1.ry()-=2;
			g2.ry()-=2;
		}
		if (dir.x()>0)
		{
			x1 = currentGrid.x()- now.x()+1;
			x0=x1-2;
			g3.rx()+=2;
			g2.rx()+=2;

		}
		else
		{
			x1 = currentGrid.x()- now.x()-1;
			x0=x1+2;
			g3.rx()-=2;
			g2.rx()-=2;
		}
		d1 = QPoint(x0,y1);
		d2= QPoint(x1,y1);
		d3= QPoint(x1,y0);
		y1+=now.y();
		x1+=now.x();
		if (angleBetween(dir,d1,d2))
		{
			crossV = true;
		}
		else
		{
			crossV = false;
		}
		if (angleBetween(dir,d3,d2))
		{
			crossH = true;
		}
		else
		{
			crossH = false;
		}

		if (dir.y() ==0)
		{
			crossV = false;
			crossH = true;
		}
		if (dir.x() ==0)
		{
			crossH = false;
			crossV = true;
		}

begin:
		if (crossV &&!crossH)
		{
			if (grid2(g1) !='#')
			{
				currentGrid = g1;
			}
			else
			{
				now.ry() = 2*y1- now.y();
				dir.ry()*=-1;
			}
		}
		else if  (crossH &&!crossV)
		{
			if (grid2(g3) !='#')
			{
				currentGrid = g3;
			}
			else
			{
				now.rx() = 2*x1- now.x();
				dir.rx()*=-1;
			}
		}
		else
		{
			if (grid2(g2) !='#')
			{
				currentGrid = g2;
			}
			else if (grid2(g3) !='#' && grid2(g1)=='#')
			{
				currentGrid = g3;
				now.ry() = 2*y1- now.y();
				dir.ry()*=-1;
			}
			else if (grid2(g3) =='#' && grid2(g1)!='#')
			{
				currentGrid = g1;
				now.rx() = 2*x1- now.x();
				dir.rx()*=-1;
			}
			else if (grid2(g3) =='#' && grid2(g1)=='#')
			{
				now.ry() = 2*y1- now.y();
				now.rx() = 2*x1- now.x();
				dir *=-1;
			}
			else
			{
				return false;
			}
		}

//////////////////////////
	
		QPoint p = currentGrid - now;		
		int vDis = p.x()*p.x() + p.y() *p.y() ;

		if (   vDis > 4* DDD*DDD) break;

		if (currentGrid == start)
		{
			simplifyAngle(p);
			if (p == dir) return true;
		}
	}

	return false;
}
void work()
{
	memset(cccc,'.',sizeof(cccc));
	memset(rrrr,1,sizeof(rrrr));
	memset(kkkk,false,sizeof(kkkk));
	result(QPoint(0,0) )= true;
	int H,W;
	QPoint me;
	fin>>H>>W>>DDD;
	for (int i=0; i<H; i++)
	{
		for (int j=0; j<W; j++)
		{
			fin>>grid(QPoint(i,j));
			if (grid(QPoint(i,j)) =='X')
			{
				me = QPoint(i,j);
			}
		}
	}
	int count=0;
	for (int i=-DDD; i<=DDD; i++)
	{
		for (int j=-DDD; j<=DDD; j++)
		{
			if (result(QPoint(i,j))) continue;
			QPoint z = me*2 -QPoint(1,1);

			if (check(z,QPoint(i,j)))
			{
				count++;
			}
			result(QPoint(i,j)) =true;
		}
	}
	fout<<count;
}


