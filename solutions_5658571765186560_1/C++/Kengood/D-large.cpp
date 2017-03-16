#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;


int main()
{	


	int Case, cases = 0;
	scanf("%d" , &Case);

	while (Case--)
	{
		int X,R,C;
		cin >> X >> R >> C;
		
		char ans = 0;
		//printf("Case #%d: %d\n" , ++cases, ans);
		
		//hmm
		if ( X == 1 )
			ans = 1;
		else if ( X == 2 )
		{
			ans = R%2 == 0 || C%2 == 0;
		}
		else if (X == 3)
		{

			/*
			xxx
			xxx
			xxx
			001
			011
			*/

			ans = (R >=2  && C%3 == 0) ||
				  (R%3==0  && C>=2);
		}
		else if (X == 4)
		{
			/*
			   00
			    00


				xxxx
				xxxx
				1222
				1002
			    1100
			*/
			ans = (R%4==0  && C >=3) ||
				  (R >= 3  && C%4 == 0);
		}
		else if (X == 5)
		{
			/*
			 0
			000
			 0

		   11022
		   10002
		   11022
		          33331
		  11222   32201
		  10002   22001
		  11002   20011

			*/
			ans = (C%5 == 0 && R >= 4) ||
				  (R%5==0 && C >= 4) ;
		}
		else if (X == 6)
		{
			/*
             111334
			 100334
             102234
			 102234
			 002244
			 
            111224
			110024
            100224
			003244
			333334

			112244
			110234
			100234
			102234
			003334
			*/
			ans = (C%6 == 0 && R >= 5) ||
				  (R%6==0 && C >= 5) ;
		}
		else
		{
			/*
			000
			0 0  make a damn hole , 88 
			00
			*/
			ans = 0;
		}

		printf("Case #%d: %s\n" , ++cases, ans? "GABRIEL":"RICHARD");
		
	}

	return 0;
}
