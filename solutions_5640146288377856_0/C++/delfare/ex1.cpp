#include <stdio.h>
#include <vector>

bool containsNFree(const std::vector<bool>& tab, int N)
{
    int count = 0;
    for(int i = tab.size()-1; i >= 0; i--)
    {
	if(tab[i])
	    count = 0;
	else count++;
	if(count == N)
	    return true;
    }
    return false;
}

int minWithHit(std::vector<bool>& tab, int W, int hitPos)
{
    if(W == 1)
	return 0;
    int countLeft = 0, countRight = 0;
    for(int i = hitPos-1; i >= 0 && tab[i] == false; i--)
	countLeft++;
    for(int i = hitPos+1; i < tab.size() && tab[i] == false; i++)
	countRight++;
    if(countLeft+countRight+1 == W || countLeft == 0 || countRight == 0)
	return W-1;
    return W;
}

int minTryReq(std::vector<bool>& tab, int W)
{
    int minVal = tab.size();
    for(int i = tab.size()-1; i >= 0; i--)
    {
	if(!tab[i])
	{
	    tab[i] = true;
	    if(!containsNFree(tab, W))
	    	minVal = std::min(minVal, minWithHit(tab, W, i)+1);
	    else minVal = std::min(minVal, minTryReq(tab, W)+1);
	    tab[i] = false;
	}
    }
    return minVal;
}

int minTry(int C, int W)
{
   std::vector<bool> tab(C);
   for(int i = 0; i < C; i++)
	tab[i] = false;
   return minTryReq(tab, W);
}

int main()
{
    int num;
    scanf("%d\n", &num);
    for(int i = 0; i < num; i++)
    {
	int R, C, W;
	scanf("%d %d %d", &R, &C, &W);
	printf("Case #%d: %d\n", i+1, minTry(C,W)*R);
    }
    return 0;
}
