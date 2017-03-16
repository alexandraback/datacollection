#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
using namespace std;

int main(int p_Argc, char  **p_Argv)
{
    int T, D;

	fstream input("B-large.in");
	ofstream output("enfin4.txt");


//    int Tmin[251002]={0};
//    for (int l=1;l<251002;l++){
//            Tmin[l] = ceil( l/floor(sqrt(l)) -1 ) + floor(sqrt(l)) ;
//            output << "Case " << l << " " << floor(sqrt(l)) << " " << ceil( l/floor(sqrt(l)) -1 ) + floor(sqrt(l)) << endl;
//    }

    input >> T;

    for (int p=0;p<T;p++)
    {

        int tmp=0;
        int maxPi = 0;
        int ans =0;

        input >> D;
        int Diner[D];
        for (int u=0;u<D;u++)
        {
            input >> tmp;
            Diner[u]=tmp;
            maxPi = max( maxPi,tmp);
        }

        ans = maxPi;

        for (int h=1;h<maxPi;h++)
        {
            int Ah = 0;
            for (int u=0;u<D;u++)
            {
                Ah += ceil(Diner[u]/(double)h)-1;
            }
            ans = min(ans,Ah+h);
        }

        output << "Case #" << p+1 << ": " << ans << endl;
    }




    return 0;

}





