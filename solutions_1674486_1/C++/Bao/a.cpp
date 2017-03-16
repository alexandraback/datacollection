#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <fcntl.h>
#include <unistd.h>

using namespace std;


int main(int argc, const char **argv)
{

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int classes ;
        cin >> classes;
        int array[classes][classes];
        for(int i = 0 ; i < classes; i++)
        {
            for(int j =  0; j < classes; j ++)
                array[i][j] = 0;
        }
        int inh;
        for(int i = 0 ; i < classes; i++) {
            cin >> inh;
            for(int j = 0; j < inh; j ++)
            {
                int x ;
                cin >> x;
                array[i][x-1] = 1;

            }
        }
        for(int i = 0; i <  classes; i ++)
        {
            for(int j = 0; j < classes; j ++)
            {
                //printf("%d ", array[i][j]);
            }
            //printf("\n");
        }

        int found = 0;
        for(int a = 2; a < classes ; a++) {
            for(int i = 0 ; i < classes; i++)
            {
                for(int j =  0; j < classes; j ++)
                {
                    if(array[i][j] == (a-1)) {
                        for(int k=0; k <classes; k++)
                        {
                            if(array[j][k] == 1) {
                                if(array[i][k] > 0)
                                {
                                    found = 1;
                                    break;
                                } else
                                {
                                    array[i][k] = a;
                                }
                            }
                        }
                    }

                    if(found) break;
                }
                if(found) break;
            }
            if(found) break;
        }
        if(found)
        {
            printf("Case #%d: Yes\n", cas + 1);
        } else
        {
            printf("Case #%d: No\n", cas+ 1);
        }
    }
    return 0;
}
