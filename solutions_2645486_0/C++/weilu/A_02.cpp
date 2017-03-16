#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
		ifstream in ("B-small-attempt3.in");
//	ifstream in ("test.in");
	ofstream out ("test.out" );

	int T;
	in >>T;
	for (int ii = 0 ; ii< T ;ii++){
		int E;
		int R;
		int N;
		in >> E >> R >>N;


		vector<int> v;
		int aa;
		v.push_back(0);
		for (int i = 1; i <= N; i++)
		{
			in >> aa;
			v.push_back(aa);
		}
		int e[1000];
		int pre[1000];
		for (int i = 0; i <= E; i++)
		{
			e[i] =0;
			pre[i]= 0;
		}


		for (int i = 1; i <= N; i++)
		{
			if ( R > E)
				e[i] = e[i] + v[i]*E;

			for (int k = R; k <= E; k++)
			{
				int temp = -1;
				// find max
				for (int j = 0;  j <= E ; j++)
				{
					//if ( k  ==  E ){
					//	for (int z = k + j -R; z <= E; z++)
					//	{
					//		temp = max( pre[ z] + v[i]*( j) , temp);
					//	}
					//}
					if (  (k+ j -R) <= E && (k + j -R) >= 0){
		//										printf(" k is %d j is %d R is %d , E is %d pre[%d] is %d  v[%d]*j is %d \n", k , j , R , E ,  k+ j- R, pre[k+ j- R], i , v[i]*j);
						temp = max( pre[ k + j - R] + v[i]*( j) , temp);
					}
				}
				e[k] = temp;

			}
			for (int k = 0; k <= E; k++)
			{
				pre[k] = e[k];
			}
		}
		int ma = -1;
		for (int i = 0; i <= E; i++)
		{
			//			printf( "%d is %d \n" , i , e[i]);
			ma = max( e[i] , ma);
		}
		out<<"Case #"<<ii+1<<": "<<ma<<endl;
	}

}