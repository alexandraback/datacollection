#include <fstream>
#include <cassert>
#include <unordered_set>
#include <iostream>

bool add_childs(int root, int current, std::unordered_set<int>* childs)
{
    std::unordered_set<int>* r = childs + root;
    std::unordered_set<int> curr = childs[current];

    if (root == current)
    {
        for (auto i = curr.begin(); i != curr.end(); ++i)
        {
            if (add_childs(root, *i, childs))
                return true;
        }
    }
    else
    {
        for (auto i = curr.begin(); i != curr.end(); ++i)
        {
            auto j = r->find(*i);
            if (j == r->end())
            {
                r->insert(*i);
                if (add_childs(root, *i, childs))
                    return true;
            }
            else
            {
                std::cout << *i << " is in " << root << std::endl;
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char* argv[])
{
    assert(argc == 3);

    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);

    int tcs;
    in >> tcs;

    for (int tc = 1; tc <= tcs; ++tc)
    {
        std::cout << tc << std::endl;

        int N;
        in >> N;

        std::unordered_set<int> childs[N+1];
        int rc = 0;
        int roots[N];

        for (int i = 1; i <= N; ++i)
        {
            int n;
            in >> n;

            if (n == 0)
            {
                roots[rc] = i;
                ++rc;
            }

            for (int j = 1; j <= n; ++j)
            {
                int p;
                in >> p;

                childs[p].insert(i);
            }
        }

        bool ok = false;
        int r = 0;
        while (r < rc && !ok)
        {

            ok = add_childs(roots[r], roots[r], childs);
            ++r;
        }

        if (ok)
            out << "Case #" << tc << ": Yes" << std::endl;
        else
            out << "Case #" << tc << ": No" << std::endl;
    }
}
