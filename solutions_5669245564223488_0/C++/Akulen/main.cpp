#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int MAX_CHAINES = 100;
const int MOD = 1000*1000*1000+7;

int nbTests;
int nbChaines;
string chaine;
char curChaine[MAX_CHAINES+1];
char dominos[MAX_CHAINES][2];
int kind[26];
int gauche[26], droite[26];
bool verbotten[26];

long long int pgcd(long long int a, long long int b)
{
	if(b == 0)
		return a;
	return pgcd(b, a%b);
}

void computeAnswer()
{
	for(int iTest = 1; iTest <= nbTests; ++iTest)
	{
		printf("Case #%d: ", iTest);
		scanf("%d", &nbChaines);
		long long int total = 1;
		int nbDominos = nbChaines;
		for(int i = 0; i < 26; ++i)
			kind[i] = 0,
			gauche[i] = 0,
			droite[i] = 0,
			verbotten[i] = false;
		for(int iChaine = 0; iChaine < nbChaines; ++iChaine)
		{
			scanf(" %s", curChaine);
			chaine = curChaine;
			dominos[iChaine][0] = chaine[0];
			dominos[iChaine][1] = chaine[chaine.size()-1];
			int deb = 0, fin = chaine.size()-1;
			while(deb < fin && (chaine[deb] == chaine[deb+1] || chaine[fin-1] == chaine[fin]))
			{
				if(chaine[deb] == chaine[deb+1])
					++deb;
				if(chaine[fin-1] == chaine[fin])
					--fin;
			}
			for(int i = deb+1; i < fin; ++i)
			{
				if(verbotten[chaine[i] - 'a'] && chaine[i-1] != chaine[i])
					total = 0;
				verbotten[chaine[i] - 'a'] = true;
			}
			if(deb < fin-1 && dominos[iChaine][0] == dominos[iChaine][1])
				total = 0;
		}
		for(int iDomino = 0; iDomino < nbChaines; ++iDomino)
			if(verbotten[dominos[iDomino][0]-'a'] || verbotten[dominos[iDomino][1]-'a'])
				total = 0;
		for(int iDomino = 0; iDomino < nbChaines; ++iDomino)
			if(dominos[iDomino][0] == dominos[iDomino][1])
			{
				--nbDominos;
				++kind[dominos[iDomino][0]-'a'];
			}
		for(int iDomino = 0; iDomino < nbChaines; ++iDomino)
		{
			if(dominos[iDomino][0] != dominos[iDomino][1])
			{
				++gauche[dominos[iDomino][0]-'a'];
				++droite[dominos[iDomino][1]-'a'];
			}
		}
		for(int i = 0; i < 26; ++i)
			if(gauche[i] > 1 || droite[i] > 1)
				total = 0;
		for(int iDomino = 0; iDomino < nbChaines; ++iDomino)
		{
			if(dominos[iDomino][0] != dominos[iDomino][1])
			{
				if(gauche[dominos[iDomino][0]-'a'] == 1 && droite[dominos[iDomino][0]-'a'] == 1)
				{
					--nbDominos;
				}
			}
		}
		for(int i = 2; i <= nbDominos; ++i)
			total = (total * i) % MOD;
		if(!nbDominos)
			total = 0;
		for(int i = 0; i < 26; ++i)
		{
			if(kind[i])
			{
				if(!gauche[i] && !droite[i])
					++nbDominos,
					total = (total * nbDominos) % MOD;
				for(int j = 2; j <= kind[i]; ++j)
					total = (total * j) % MOD;
			}
		}
		printf("%lld\n", total);
	}
}

void displayAnswer()
{

}

void readInput()
{
	/*
	freopen("test.in", "r", stdin);
	/*/
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	//*/
	scanf("%d", &nbTests);
}

int main()
{
	readInput();
	computeAnswer();
	displayAnswer();
	return 0;
}
