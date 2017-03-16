#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;
double power(double b,int n)
{
    double ret = 1;
    for(int i = 0;i < n;i++) ret *= b;
    return ret;
}

int totalDigit(double num)
{
    double ret = 0;
    while(power(10,ret) <= num) ret++;
    return ret-1;
}

bool isPalin(double num)
{
    int totDigit = totalDigit(num);
    for(int j = 0;power(10,j) <= num;j++)
    {
        int dig = int(fmod(num / power(10,j),10));
        int dig2 = int(fmod(num / power(10,totDigit-j),10));
        if(dig != dig2) return false;
    }
    return true;
}

int main()
{
    // pre-generate palinList
    vector<double> palinList;
    double last = 100000000000000;
    for(double i = 1;i <= sqrt(last);i++)
    {
        i = round(i);
        if(totalDigit(i) > 1 && int(fmod(i / power(10,totalDigit(i)),10)) >= 3)
        {
            i += power(10,totalDigit(i))-1;
        }
        else {
            if(isPalin(i)) {// if this is palin
                if(isPalin(i*i)) // square and check palin
                {
                    palinList.push_back(i*i);
                }
            }
        }
    }
    int t,tt;
    scanf("%d",&tt);
    for(t=0;t < tt;t++)
    {
        double a,b;
        scanf("%lf %lf",&a,&b);
        int cnt=0;
        for(int i = 0;i < palinList.size();i++)
        {
            if(a <= palinList[i] && palinList[i] <= b)
            {
                cnt++;
            }
        }

        printf("Case #%d: %d\n",t+1,cnt);
    }
}
