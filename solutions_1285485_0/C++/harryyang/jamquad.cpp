#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iterator>
#include<fstream>
using namespace std;

int cases;
int H,W,D;
vector<vector<char>> mat;
double xH,xW;

ifstream ifs;
ofstream ofs;

void InputMat()
{
	mat.resize(H);
	for(int i=0;i<H;i++)
	{
		mat[i].resize(W);
		for(int j=0;j<W;j++)
		{
			char c;
			ifs>>c;
			if(c=='X')
			{
				xH=-(i-0.5);
				xW=j-0.5;
			}
			mat[i][j]=c;
		}
	}
}

int ComputeImages()
{	
	vector<double> ws;
	vector<double> hs;
	ws.push_back(xW);
	hs.push_back(xH);

	int i=1;
	double leftW=xW;
	while(true)
	{
		double newW=leftW;
		if(i%2==1)
		{
			newW-=2*xW;
		}
		else
		{
			newW=newW-2*(W-2)+2*xW;
		}
		if(xW-newW>D)
			break;
		leftW=newW;
		ws.push_back(leftW);
		i++;
	}
	double rightW=xW;
	i=1;
	while(true)
	{
		double newW=rightW;
		if(i%2==1)
		{
			newW=newW+2*(W-2)-2*xW;
		}
		else
		{
			newW=newW+2*xW;
		}
		if(newW-xW>D)
			break;
		rightW=newW;
		ws.push_back(rightW);
		i++;
	}
	sort(ws.begin(),ws.end());
	double upH=xH;
	i=1;
	while(true)
	{
		double newH=upH;
		if(i%2==1)
		{
			newH=newH+2*(-xH);
		}
		else
		{
			newH=newH+2*(H-2)-2*(-xH);
		}
		if(newH-xH>D)
			break;
		upH=newH;
		hs.push_back(upH);
		i++;
	}
	double downH=xH;
	i=1;
	while(true)
	{
		double newH=downH;
		if(i%2==1)
		{
			newH=newH-2*(H-2)+2*(-xH);
		}
		else
		{
			newH=newH+2*xH;
		}
		if(xH-newH>D)
			break;
		downH=newH;
		hs.push_back(downH);
		i++;
	}
	sort(hs.begin(),hs.end());
	vector<double> resW,resH;
	for(int i=0;i<ws.size();i++)
	{
		for(int j=0;j<hs.size();j++)
		{
			double w=ws[i]-xW;
			double h=hs[j]-xH;
			double dist=w*w+h*h;
			if(dist<=D*D && dist>0)
			{
				bool flag=false;
				for(int i=0;i<resW.size();i++)
				{
					if(w*resH[i]==h*resW[i] && ((w*resW[i]>0) || (h*resH[i]>0)))
					{
						flag=true;
						break;
					}
				}
				if(!flag)
				{
					resH.push_back(h);
					resW.push_back(w);
				}
			}
		}
	}
	return resW.size();
}


int main()
{
	ifs.open("D-small-attempt0.in");
	ofs.open("D-small-attempt0.out");
	ifs>>cases;
	int cnt=1;
	while(cases--)
	{
		ifs>>H>>W>>D;
		InputMat();
		int res=ComputeImages();
		ofs<<"Case #"<<cnt<<": "<<res<<endl;
		cnt++;
	}
	ifs.close();
	ofs.close();
}