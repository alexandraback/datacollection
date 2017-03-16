#include <iostream>
#include <algorithm>
#include <vector>
struct foo
{
    int j, p, s;
};

int mycount(std::vector<std::pair<int, int> > & v, std::pair<int, int> & val)
{
    int counter = 0;
    for (std::pair<int, int> p : v)
    {
        if ((p.first == val.first) && (p.second == val.second))
            ++counter;
    }
    return counter;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int J, P, S, K;
        std::cin >> J >> P >> S >> K;

        std::vector<std::pair<int, int> > JP;
        std::vector<std::pair<int, int> > JS;
        std::vector<std::pair<int, int> > PS;

        std::vector<foo> result;

        for (int j = 1; j <= J; ++j)
        {
            for (int p = 1; p <= P; ++p)
            {
                for (int s = 1; s <= S; ++s)
                {
                    std::pair<int, int> jp(j, p);
                    if (mycount(JP, jp) == K)
                        continue;
                    std::pair<int, int> js(j, s);
                    if (mycount(JS, js) == K)
                        continue;
                    std::pair<int, int> ps(p, s);
                    if (mycount(PS, ps) == K)
                        continue;
                    JP.push_back(jp);
                    JS.push_back(js);
                    PS.push_back(ps);
                    foo f;
                    f.j = j;
                    f.p = p;
                    f.s = s;
                    result.push_back(f);
                }
            }
        }

        std::cout << "Case #" << t << ": " << result.size() << std::endl;
        for (foo f : result)
            std::cout << f.j << " " << f.p << " " << f.s << std::endl;


    }
    return 0;
}
