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
#include"cv.h"
#include"highgui.h"


//#define DEBUG

#ifdef DEBUG
#define ifs cin
#define ofs cout
#endif

using namespace std;
using namespace cv;

int main()
{
#ifndef DEBUG
	ifstream ifs("A-small-attempt0 (4).in");
	ofstream ofs("A-small-attempt0 (4).out");
#endif

	int testCases;
	ifs>>testCases;
	int cnt=1;
	while(cnt<=testCases)
	{
		int N;
		ifs>>N;
		Mat mat(N,N,CV_64FC1);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				mat.at<double>(i,j)=0;
			}
		}
		for(int i=0;i<N;i++)
		{
			int Mi;
			ifs>>Mi;
			for(int j=0;j<Mi;j++)
			{
				int temp;
				ifs>>temp;
				mat.at<double>(i,temp-1)=1;
			}
		}
		Mat count(N,N,CV_64FC1),power(N,N,CV_64FC1);
		mat.copyTo(count);
		mat.copyTo(power);
		bool flag=false;
		for(int i=0;i<N-2;i++)
		{
			power=power*mat;
			count=count+power;
			for(int j=0;j<N;j++)
			{
				for(int k=0;k<N;k++)
				{
					if(count.at<double>(j,k)>1)
					{
						flag=true;
						break;
					}
				}
				if(flag)break;
			}
			if(flag)break;
		}
		ofs<<"Case #"<<cnt<<": ";
		if(flag)
			ofs<<"Yes";
		else
			ofs<<"No";
		ofs<<endl;
		cnt++;
	}


#ifndef DEBUG
		ifs.close();
		ofs.close();
#endif

}