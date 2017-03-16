#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int normal_max_score(int x)
{
    if (x>=1)
    return (x+2)/3;
    else return 0;
}
int surprise_max_score(int x)
{
    if(x>=2)
        return (x+4)/3;
    else return normal_max_score(x);
}
void solve_one()
{
    int n_g,S,p;
    scanf("%d%d%d",&n_g,&S,&p);
    vector <int> score;
    int i;
    for (i=0;i<n_g;i++) {
        int sc;
        scanf("%d",&sc);
        score.push_back(sc);
    }
    sort(score.begin(),score.end());
    int count = 0;
    for (i=score.size()-1;i>=0;i--) {
        if (normal_max_score(score[i]) >= p)
        {
            count++;
        }
        else if(surprise_max_score(score[i]) >= p && S > 0) 
        {
            count++;
            S--;
        }
        else break;
    }
    printf("%d\n",count);
}
int main ()
{
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++) {
        printf("Case #%d: ",i);
        solve_one();
    }
    return 0;
}