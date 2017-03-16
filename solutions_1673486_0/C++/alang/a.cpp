
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;
vector<double> est;
double p[100001];

int main() {
        int N;
        cin>>N;
        int count=1;
        while(N--)
        {

            int A,B;
            cin>>A>>B;
            for(int i=0;i<A;i++)
            	cin>>p[i];
            
            est.clear();
            est.push_back(B+A+1);
            double prob=1;
            for(int m=A-1;m>=0;m--)
            {
            	int n=A-m;
            	prob=prob*p[n-1];
            	double estv=prob*(B+m-n+1)+(1-prob)*(2*B+2+m-n);
            	est.push_back(estv);
            }
            est.push_back(B+2);
            sort(est.begin(),est.end());

            cout<<"Case #"<<count++<<": ";
            printf("%.6f\n",est.front());
         }



        return 0;
}

