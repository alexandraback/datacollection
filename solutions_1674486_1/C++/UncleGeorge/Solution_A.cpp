#include <iostream>
#include <iomanip>

using namespace std;

//#define _DEB_

const int maxN = 1000;
int a[maxN][maxN];
int color[maxN];
int N;

bool DFS_visit(int v, int c)
{
   color[v] = c;
   for(int u=0; u<N; u++)
      if(a[v][u])
         if(color[u]==c || DFS_visit(u,c))
            return true;

   return false;
}

bool DFS()
{
   memset(color,0,sizeof(color));
   for(int v=0; v<N; v++)
      if(DFS_visit(v,v+1))
         return true;

   return false;
}

int main()
{
	//cout << "Hello!!!" << endl;
	//return 0;
	int T;

	cin >> T;
	for(int t=1; t<=T; t++)
	{
	        #ifdef _DEB_ 
	           cout << "Test " << t << endl;
	        #endif

	        memset(a,0,sizeof(a));

		/************************************
		*	Input Data
		*************************************/
	        cin >> N;
                #ifdef _DEB_ 
                   cout << "N = " << N << endl;
                #endif
		for(int i=0; i<N; i++)
		{
		   int M;
		   cin >> M;
		   for(int j=0; j<M; j++)
		   {
		      int v;
		      cin >> v;
		      a[i][v-1] = 1;
		   }
	        }
                #ifdef _DEB_ 
                   for(int i=0; i<N; i++)
                   {
                      for (int j=0; j<N; j++)
                      {
                         cout << a[i][j] << ' ';
                      }
                      cout << endl;
                   }
                #endif
		/************************************
		*	Solve the Problem
		*************************************/

		/************************************
		*	Output Results
		*************************************/
		if(DFS())
                   cout << "Case #" << t << ": " << "Yes" << endl;
                else
                   cout << "Case #" << t << ": " << "No" << endl;
                //cout << "Case #" << t << ": " << fixed << setprecision(10) << res << endl;
		//cout << "Case #" << t << ": " << res << endl;
	}

	return 0;
}
