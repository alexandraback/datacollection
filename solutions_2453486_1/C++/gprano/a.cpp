#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

char tab[4][4];

char _getchar()
{
    char c = getchar();
    while(c != 'X' && c != '.' && c != 'O' && c != 'T')
    {
	c = getchar();
    }
    return c;
}

int endgame(int x, int o)
{
    if(x == 4)
	return 1;
    else if(o == 4)
	return 2;
    return -1;
}
	    
int main()
{
    int nb_cas;
    scanf("%d", &nb_cas);
    for(int cas = 1; cas <= nb_cas; cas++)
    {
	int result = 0;
	printf("Case #%d: ",cas);
	for(int i = 0; i < 4; i++)
	    for(int j = 0; j < 4; j++)
	    {
		tab[i][j] = _getchar();
		if(tab[i][j] == '.') result = -1;
	    }
	for(int i = 0; i < 4; i++)
	{
	    int x1 = 0; int o1 = 0;
	    int x2 = 0; int o2 = 0;
	    for(int j = 0; j < 4; j++)
	    {
		if(tab[i][j] == 'X') x1++;
		if(tab[i][j] == 'O') o1++;
		if(tab[i][j] == 'T') x1++, o1++;
		if(tab[j][i] == 'X') x2++;
		if(tab[j][i] == 'O') o2++;
		if(tab[j][i] == 'T') x2++, o2++;
	    }
	    result = max(endgame(x1,o1),result);
	    result = max(endgame(x2,o2),result);
	}
	int x1 = 0; int o1 = 0;
	int x2 = 0; int o2 = 0;
	for(int i = 0; i < 4; i++)
	{
	    if(tab[i][i] == 'X') x1++;
	    if(tab[i][i] == 'O') o1++;
	    if(tab[i][i] == 'T') x1++, o1++;
	    if(tab[3-i][i] == 'X') x2++;
	    if(tab[3-i][i] == 'O') o2++;
	    if(tab[3-i][i] == 'T') x2++, o2++;
	}
	result = max(endgame(x1,o1),result);
	result = max(endgame(x2,o2),result);
	switch(result)
	{
	case -1:
	    printf("Game has not completed\n");
	    break;
	case 0:
	    printf("Draw\n");
	    break;
	case 1:
	    printf("X won\n");
	    break;
	case 2:
	    printf("O won\n");
	    break;
	default:
	    break;
	}
    }
    return 0;
}
