#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <utility>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;

struct Point
{
    int x,y;
    
    Point(int a =0 , int b = 0)
    {
	x = a;
	y = b;
    }
};



ifstream infile;
ofstream outfile;

ll num[101][101];
ll box[101];
ll toy[101];

int boxt[101], toyt[101];



//ll solve(int n, int m, int N, int M)
//{
//	if(num[n][m]!=-1)
//		return num[n][m];
//
//	if(n==N-1)
//	{
//
//	}
//}

ll min_l(ll a, ll b)
{
	if (a<b)
		return a;
	else
		return b;
}
int main()
{
	string inputfilename = "C-small-attempt0.in";
	string outputfilename = "out.txt";

	infile.open(inputfilename, ios::in);
	outfile.open(outputfilename, ios::out);

	int i,j,k,m,n,M,N,T;

	string line;
	istringstream ss;

	getline(infile,line);
	ss.clear();
	ss.str(line);

	ss>> T;
	
	

	
	

	for(i=1;i<=T;i++)
	{
		getline(infile,line);
		ss.clear();
		ss.str(line);
		

		ss>>N; ss>>M;

		for(k=0;k<N;k++)
			for(j=0;j<M;j++)
				num[k][j] = -1;

		
		
			getline(infile,line);
			ss.clear();
			ss.str(line);

			for(j=0;j<N;j++)
			{
			 ss>> box[j] ;
			
			ss>>boxt[j];
			}
		

		
		
			getline(infile,line);
			ss.clear();
			ss.str(line);
			for(j=0;j<M;j++)
			{
			ss>>toy[j];
			ss>>toyt[j];
			}
		


		int k1,k2,k3;
		ll total = 0, temp= 0;
		ll res = 0;
		ll t1=0,t2=0,t3=0;
		
		if (N==3)
		{
		for(k1=0;k1<=M;k1++)
			for(k2=k1;k2<=M;k2++)
				
				{
					total = 0;
					temp=0;
					
					for(j=0;j<k1;j++)
						if(toyt[j] == boxt[0])
							temp+=toy[j];

					total += min_l(temp, box[0] );

					temp = 0;
					for(j=k1;j<k2;j++)
					{
						
						if(toyt[j] == boxt[1])
							temp += toy[j]; 
					}

					total += min_l(temp, box[1]);

					

					temp = 0;
					for(j=k2;j<M;j++)
						if(toyt[j] == boxt[2])
							temp+=toy[j];

					total += min_l(temp, box[2]);

					if (res < total)
						res = total;
		}






		if (boxt[0] == boxt[1] && boxt[1] == boxt[2])
		{
			box[0] = box[0] + box[1] + box[1];
         	temp=0;

					for(j=0;j<M;j++)
						if(toyt[j] == boxt[0])
							temp+=toy[j];

					res = min_l(temp, box[0]);
		}

		else
			if(    boxt[0] == boxt[1] && boxt[1] != boxt[2]     )
			{
				box[0] = box[0] + box[1];
				box[1] = box[2];
				boxt[1] = boxt[2];
				 for(k1=0;k1<=M;k1++)
					 {
						 total = 0;
						 temp=0;

					for(j=0;j<k1;j++)
						if(toyt[j] == boxt[0])
							temp+=toy[j];

					total += min_l(temp, box[0]);

					temp = 0;
					for(j=k1;j<M;j++)
						if(toyt[j] == boxt[1])
							temp+=toy[j];

					total += min_l(temp, box[1]);

					if (res < total)
						res = total;
				}
			}

			else
				if(    boxt[0] != boxt[1] && boxt[1] == boxt[2]     )
			{
				
				box[1] += box[2];
				
				 for(k1=0;k1<=M;k1++)
					 {
						 total = 0;
						 temp=0;

					for(j=0;j<k1;j++)
						if(toyt[j] == boxt[0])
							temp+=toy[j];

					total += min_l(temp, box[0]);

					temp = 0;
					for(j=k1;j<M;j++)
						if(toyt[j] == boxt[1])
							temp+=toy[j];

					total += min_l(temp, box[1]);

					if (res < total)
						res = total;
				}
			}

				else
					if(    boxt[0] == boxt[2] && boxt[1] != boxt[2]  )
					{
						box[0] += box[2];

						for(j=0;j<M;j++)
						if(toyt[j] == boxt[0])
							temp+=toy[j];

						total = min_l(temp, box[0]);
						if(res < total)
							res = total;


					}




		}

		
		if (N==2)
			 {
				 for(k1=0;k1<=M;k1++)
					 {
						 total = 0;
						 temp=0;

					for(j=0;j<k1;j++)
						if(toyt[j] == boxt[0])
							temp+=toy[j];

					total += min_l(temp, box[0]);

					temp = 0;
					for(j=k1;j<M;j++)
						if(toyt[j] == boxt[1])
							temp+=toy[j];

					total += min_l(temp, box[1]);

					if (res < total)
						res = total;


				 }


				 if(boxt[0]==boxt[1])
				{	 box[0] +=box[1];

					 total = 0;
					temp=0;

					for(j=0;j<M;j++)
						if(toyt[j] == boxt[0])
							temp+=toy[j];

					res = min_l(temp, box[0]);
				 }





			 }
			
		if (N==1)
			{
					total = 0;
					temp=0;

					for(j=0;j<M;j++)
						if(toyt[j] == boxt[0])
							temp+=toy[j];

					res = min_l(temp, box[0]);
			 }






	

		
		
		
		
		outfile<<"Case #"<<i<<":  "<<res<<endl;


	

	}
	



	infile.close();
	outfile.close();

	
	


}
