#include <iostream>
#include <fstream>
using namespace std;

const int MAXD=1001;

ifstream fin("pan.in");
ofstream fout("pan.out");
int T;
int pans[MAXD];


int cut(int pile, int floor)
{
    return (pile-1)/floor;
}

int main()
{
    fin>>T;
    for(int curcase = 0; curcase<T; curcase++)
    {
        int D;
        int maxP = 0;
        int minCost = 1001; 
        fin>>D;
        for(int i=0;i<D;i++)
        {
            fin>>pans[i];
            if(pans[i]>maxP) 
            {
                maxP = pans[i];
            }
        }
        for(int floor = maxP; floor>0; floor--)
        {
            int totalCost = 0;
            for(int i=0;i<D;i++)
            {
                int cost;
                cost = cut(pans[i], floor);
                totalCost+=cost;
            }
            totalCost+=floor;
            if(totalCost<minCost)
            {
                minCost = totalCost;
            }
        }
        fout<<"Case #"<<curcase+1<<": "<<minCost<<'\n';
    }
}
