// ============================================================================
//
//       Filename:  D-treasure.cpp
//
//    Description:  Problem D - Treasure
//                  Depth-first search / Backtrack
//
//        Version:  1.0
//        Created:  13/Apr/2013 09:02:37
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;


int T, K, N, chave, qtd_keys_inside; // K -> tipos de chave, N -> qtd de chests
int abre_com[400]; // abre_com[i] -> tipo de chave que abe a chest i
bool foi_aberta[400];
multiset<int> keys_disponiveis, keys_inside[400];
vector<int> visitas; // Ordem usada para abrir as chests
vector<int>::iterator it; // Ordem usada para abrir as chests


bool abre(int n)
{
    foi_aberta[n] = true;
    visitas.push_back(n);

    // Se já abriu todas as chests, então o problema foi resolvido
    if ((int)visitas.size() == N)
        return true;

    // Remove chave usada agora da lista de disponíveis
    keys_disponiveis.erase(keys_disponiveis.find(abre_com[n]));

    // Adiciona chaves encontradas na chest às disponíveis
    keys_disponiveis.insert(keys_inside[n].begin(), keys_inside[n].end());

    for (int i = 0; i < N; i++)
        if (!foi_aberta[i])
            if (keys_disponiveis.count(abre_com[i]))
            {
                if (abre(i))
                    return true;
            }

    // Se chegou até aqui é porque o caminho não deu certo. Backtrack
    visitas.pop_back();
    foi_aberta[n] = false;
    keys_disponiveis.insert(abre_com[n]);

    return false;
}


int main()
{
    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        memset(foi_aberta, 0, sizeof(foi_aberta));

        scanf("%d %d", &K, &N);

        for (int i = 0; i < K; i++)
        {
            scanf("%d", &chave);
            keys_disponiveis.insert(chave);
        }

        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &abre_com[i], &qtd_keys_inside);
        
            for (int j = 0; j < qtd_keys_inside; j++)
            {
                scanf("%d", &chave);
                keys_inside[i].insert(chave);
            }
        }

        printf("Case #%d:", caso);
        bool possivel = false;
        for (int i = 0; i < N && !possivel; i++)
            if (keys_disponiveis.count(abre_com[i]))
            {
                if ((possivel = abre(i)))
                {
                    for (it = visitas.begin(); it != visitas.end(); it++)
                        printf(" %d", *it+1);
                    putchar('\n');
                }
            }

        if (!possivel)
            puts(" IMPOSSIBLE");

        visitas.clear();
        keys_disponiveis.clear();
    }

    return 0;
}

