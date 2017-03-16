#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAXI = 100;

bool notsmallest(int cont, const vector<int>& scores, double perc, int sum)
{
    double finalscore = scores[cont] + sum*perc;
    double psum = perc;
    
    for(int i=0;i<scores.size();++i)
    {
        if(i != cont)
        {
            double minp = max(0.0, (finalscore - scores[i])/sum);
            psum += minp;
            if(psum > 1)
            {
                break;
            }
        }
    }
    
    return (psum > 1);
}

double min_percentage(int cont, const vector<int>& scores)
{
    double low = 0;
    double high = 1;
    
    int sum = accumulate(scores.begin(), scores.end(), 0);
    
    for(int it=0;it<MAXI;++it)
    {
        double mid = (low+high)/2;
        if(notsmallest(cont, scores, mid, sum))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    
    return low;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int lp=1;lp<=t;++lp)
    {
        int n;
        scanf("%d", &n);
        vector<int> scores(n);
        for(int& s : scores)
        {
            scanf("%d", &s);
        }
        
        printf("Case #%d:", lp);
        for(int i=0;i<n;++i)
        {
            printf(" %.5lf", 100*min_percentage(i, scores));
        }
        printf("\n");
        
    }
    
    return 0;
}