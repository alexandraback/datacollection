#include <iostream>
#include <algorithm>
using namespace std;

int player;
int numOfOthers;
int others[1000];

int calculate()
{
    if(player==1)
        return numOfOthers;
    int minimum=numOfOthers;
    int current=0;
    sort(others+1, others+numOfOthers+1);
    for(int i=1; i<=numOfOthers; ++i)
    {
        int temp=0;
        if(player>others[i])
        {
            temp=current+numOfOthers-i;
            player+=others[i];
        }
        else
        {
            /*int diff=others[i]-player+1;
            int need=diff/(player-1);
            if(diff%(player-1)) ++need;
            temp=current+need+numOfOthers-i;
            player+=(player-1)*need+others[i];
            current+=need;*/
            while(player<=others[i])
            {
                player+=(player-1);
                ++current;
            }
            player+=others[i];
            temp=current+numOfOthers-i;
        }
        if(minimum>temp) minimum=temp;
    }
    return minimum;
}

int main()
{
    int numOfCases;
    cin>>numOfCases;
    for(int i=1; i<=numOfCases; ++i)
    {
        cin>>player>>numOfOthers;
        for(int j=1; j<=numOfOthers; ++j)
            cin>>others[j];
        cout<<"Case #"<<i<<": "<<calculate()<<endl;
    }
    return 0;
}
