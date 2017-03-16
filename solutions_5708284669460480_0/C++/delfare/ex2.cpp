#include <stdio.h>
#include <vector>

double computeProba(double *probaLetter, int *target, int L, int S)
{
    std::vector<double> probaPosInWord(L);
    for(int i = 0; i < L; i++)
	probaPosInWord[i] = 0;
    double proba = 0;
    for(int i = 0; i < S; i++)
    {
	for(int j = L-1; j > 0; j--)
	    probaPosInWord[j] = probaPosInWord[j-1]*probaLetter[target[j]];
	probaPosInWord[0] = probaLetter[target[0]];
	proba += probaPosInWord[L-1];
    }
    return proba;
}

bool isSuffix(int *tab, int L, int decal)
{
    for(int i = 0; i < L-decal; i++)
	if(tab[i+decal] != tab[i])
	    return false;
    return true;
}

int maxNumber(int *target, int L, int S)
{
    int biggestSuffix = L;
    for(int i = 1; i < L; i++)
	if(isSuffix(target, L, i))
	{
	    biggestSuffix = i;
	    break;
	}
    if(biggestSuffix == L)
	return S/L;
    else if(S < L)
	return 0;
    else return 1+(S-L)/(biggestSuffix);
}

bool isPossible(int *target, double *probaLetter, int L)
{
    for(int i = 0; i < L; i++)
	if(probaLetter[target[i]] < 0.000001)
	   return false;
    return true;
}

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
	int K, L, S;
        scanf("%d %d %d\n", &K, &L, &S);
	double probaLetter[26];
	for(int j = 0; j < 26; j++)
	    probaLetter[j] = 0;
	char str[255];
	scanf("%s\n", str);
	for(int j = 0; j < K; j++)
	    probaLetter[str[j]-'A']++;
	for(int j = 0; j < 26; j++)
	    probaLetter[j] /= K;
	scanf("%s", str);
	int target[255];
	for(int j = 0; j < L; j++)
	    target[j] = str[j]-'A';
	if(!isPossible(target, probaLetter, L))
	    printf("Case #%d: 0.0\n", i+1);
        else printf("Case #%d: %lf\n", i+1, maxNumber(target, L, S) - computeProba(probaLetter, target, L, S));
    }
    return 0;
}
