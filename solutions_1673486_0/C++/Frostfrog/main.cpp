#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

/*

*/

int main()
{
    freopen("A-small-attempt.in","r",stdin);
    freopen("A-small-attempt..out","w",stdout);
    std::string str;
    unsigned num_case = 0;
    unsigned num_city =0;
    unsigned ext_dir_count = 0;
    unsigned num_road;
    unsigned N,M,A;

    double prob[100000];

    map<string,unsigned> citymap;
    cin >>  num_case;
    if(num_case==0) return 0;
    string s,d;
    unsigned time;
    for(int c =1; c <= num_case ; c++)
    {
        cin>> N>>M;
        prob[0] = 1;
        for(int i=1; i<=N;i++){
            cin >> prob[i];
            if(i)
            prob[i] *= prob[i-1];
        }
        double max = -1;
        int right_typ = M-N+1;
        for(int i=0;i<=N;i++)
        {
            int index = N-i;
            int wrong_typ = right_typ+M+1;
            double now = prob[index] * right_typ  + ( 1 - prob[index] ) *wrong_typ;
            if(now < max || max<0){ max = now;}
          //  printf("r = %d ,%lf,w = %d , %lf\n",right_typ,prob[index],wrong_typ,( 1 - prob[index] ));
            right_typ +=2;
        }
        //enter right away
        int typ = M+2;
        if(typ < max) {max = typ;}


        printf("Case #%u: %.6f",c,max);
        //print output here

        printf("\n",c);

    }

    return 0;
}
