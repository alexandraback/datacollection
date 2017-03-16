#include <iostream>
#include <string>

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        std::string sc, sj;
        std::string cb, jb;
        long long best = 0;
        std::cin >> sc >> sj;
        for (size_t s = 0 ; s < sc.size() ; ++s)
        {
            char cc1 = sc[s], cc2 = sc[s];
            char jj1 = sj[s], jj2 = sj[s];
            if (sc[s] == '?')
            {
                if (sj[s] == '?')
                {
                    cc1 = '0';
                    cc2 = '1';
                    jj1 = '0';
                    jj2 = '1';
                }
                else
                {
                    cc1 = jj1 - 1;
                    cc2 = jj1 + 1;
                }
            }
            else
            {
                if (sj[s] == '?')
                {
                    jj1 = cc1 - 1;
                    jj2 = cc1 + 1;
                }
            }
            cc1 = std::max(cc1, '0');
            jj1 = std::max(jj1, '0');
            cc2 = std::min(cc2, '9');
            jj2 = std::min(jj2, '9');
            for (char cc = cc1 ; cc <= cc2 ; ++cc)
            {
                for (char jj = jj1 ; jj <= jj2 ; ++jj)
                {
                    std::string c = sc, j = sj;
                    c[s] = cc;
                    j[s] = jj;
                    long long diff = 0;
                    for (size_t i = 0 ; i < c.size() ; ++i)
                    {
                        if (diff == 0)
                        {
                            if (c[i] == '?')
                            {
                                if (j[i] == '?')
                                {
                                    c[i] = '0';
                                    j[i] = '0';
                                }
                                else
                                {
                                    c[i] = j[i];
                                }
                            }
                            else
                            {
                                if (j[i] == '?')
                                {
                                    j[i] = c[i];
                                }
                            }
                        } 
                        else if (diff > 0) 
                        {
                            if (c[i] == '?')
                            {
                                if (j[i] == '?')
                                {
                                    c[i] = '0';
                                    j[i] = '9';
                                }
                                else
                                {
                                    c[i] = '0';
                                }
                            }
                            else
                            {
                                if (j[i] == '?')
                                {
                                    j[i] = '9';
                                }
                            }
                        }
                        else if (diff < 0)
                        {
                            if (c[i] == '?')
                            {
                                if (j[i] == '?')
                                {
                                    c[i] = '9';
                                    j[i] = '0';
                                }
                                else
                                {
                                    c[i] = '9';
                                }
                            }
                            else
                            {
                                if (j[i] == '?')
                                {
                                    j[i] = '0';
                                }
                            }
                        }
                        diff = diff * 10 + c[i] - j[i];
                    }
                    diff = std::abs(diff);
                    if (cb.empty() || diff < best || diff == best && c < cb || diff == best && c == cb && j < jb)
                    {
                        cb = c;
                        jb = j;
                        best = diff;
                    }
                }
            }
        }
		std::cout << "Case #" << t << ": " << cb << " " << jb << "\n";
	}
	return 0;
}

