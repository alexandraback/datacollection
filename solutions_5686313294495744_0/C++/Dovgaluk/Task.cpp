#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <stdlib.h>
#include <time.h>

typedef std::pair<int, int> P;
typedef std::list<P> L;
typedef std::map<std::string, int> M;
typedef std::vector<int> V;

int wa = 0, wb = 0;

int find(L list)
{
    V a(wa), b(wb);
    V ax(wa), bx(wb);
    for (L::iterator l = list.begin() ; l != list.end() ; ++l)
    {
        ++ax[l->first];
        ++bx[l->second];
    }

    for (int i = 0 ; i < std::min(3, std::max(wa, wb)) ; ++i)
    {
        if (list.empty())
            break;
        int v = rand() % list.size();
        L::iterator it = list.begin();
        for ( ; v ; ++it, --v) ;
        ++a[it->first];
        ++b[it->second];
        --ax[it->first];
        --bx[it->second];
        list.erase(it);
    }

    while (!list.empty())
    {
        L::iterator it = list.end();
        if (it == list.end())
        {
            for (L::iterator l = list.begin() ; l != list.end() ; ++l)
            {
                if (a[l->first] == 0 && b[l->second] == 0 && (ax[l->first] == 1 || bx[l->second] == 1))
                {
                    it = l;
                    break;
                }
            }
        }
        if (it == list.end())
        {
            for (L::iterator l = list.begin() ; l != list.end() ; ++l)
            {
                if (a[l->first] == 0 && b[l->second] == 0)
                {
                    it = l;
                    break;
                }
            }
        }
        if (it == list.end())
        {
            for (L::iterator l = list.begin() ; l != list.end() ; ++l)
            {
                if (a[l->first] == 0)
                {
                    it = l;
                    break;
                }
            }
        }
        if (it == list.end())
        {
            for (L::iterator l = list.begin() ; l != list.end() ; ++l)
            {
                if (b[l->second] == 0)
                {
                    it = l;
                    break;
                }
            }
        }
        if (it != list.end())
        {
            ++a[it->first];
            ++b[it->second];
            --ax[it->first];
            --bx[it->second];
            list.erase(it);
        }
        else
        {
            break;
        }
    }

    return (int)list.size();
}

int main()
{
    srand((int)time(NULL));
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        int n;
        std::cin >> n;
        M dictA, dictB;
        L list;
        wa = 0;
        wb = 0;
        for (int i = 0 ; i < n ; ++i)
        {
            std::string a, b;
            std::cin >> a >> b;
            if (dictA.find(a) == dictA.end())
                dictA[a] = wa++;
            if (dictB.find(b) == dictB.end())
                dictB[b] = wb++;
            list.push_back(P(dictA[a], dictB[b]));
        }
        int fake = 0;
        for (int i = 0 ; i < 200 ; ++i)
        {
            int f = find(list);
            if (f > fake)
                fake = f;
        }
		std::cout << "Case #" << t << ": " << fake << "\n";
	}
	return 0;
}

