#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

enum State { zero = 0, one, two, three, four, five, six, seven, eight, candidate = '.', mine = '*', first_move = 'c'};

std::ostream& show_vector(std::ostream& ostr, int R, int C, const std::vector<State>& vec)
{
    size_t i = 0;
    for (int ir = 0; ir < R; ++ ir)
    {
	for (int ic = 0; ic < C; ++ ic, ++ i)
	{
	    switch (vec[i])
	    {
	    case mine: 
	    case first_move:
		ostr << static_cast<char>(vec[i]);
		break;
	    default:
		ostr << ".";
	    }
	}
	ostr << std::endl;
    }
    return ostr;
}

std::vector<int> get_neighbors(int pos, int R, int C)
{
    int ix = pos / C;
    int iy = pos % C;
    std::vector<int> nb;
    const std::vector<int> increments({-1, 0, 1});
    for (auto& a : increments)
    {
	for (auto& b : increments)
	{
	    if ((a != 0 || b != 0) 
		    && (iy + b < C) && (iy + b >= 0)
		    && (ix + a < R) && (ix + a >= 0))
		nb.push_back((ix + a)*C + (iy + b));
	}
    }
    return nb;
}


bool winning_config_impl(std::vector<State>& b, int R, int C, int nfreeable, std::vector<int> nxt);

bool winning_config_markall(std::vector<State>& b, int R, int C, int nfreeable, int move, std::vector<int> nxt, const std::vector<int>& nb) 
{
    auto bnew = b;
    for (const auto& inb : nb)
    {
	bnew[(size_t)inb] = State::candidate;
	nxt.push_back(inb);
    }
    bnew[(size_t)move] = State::zero;
    nfreeable -= nb.size();

    if (winning_config_impl(bnew, R, C, nfreeable, nxt))
    {
	b = bnew;
	return true;
    }
    return false;
}

bool winning_config_perm(std::vector<State>& b, int R, int C, int nfreeable, std::vector<int> nxt, std::vector<int> nb, int nuncover, bool explorable, bool marked_once)
{
    std::sort(nb.begin(), nb.end());
    assert(nuncover <= nfreeable);
    do 
    {
	auto bnew = b;
	auto nxtnew = nxt;
	for (size_t i = 0; i < (size_t)nuncover; ++ i)
	{
	    bnew[(size_t)nb[i]] = State::candidate;
	    if (explorable)
	    {
		marked_once = true;
		nxtnew.push_back(nb[i]);
	    }
	}
	if (winning_config_impl(bnew, R, C, nfreeable - nuncover, nxtnew))
	{
	    b = bnew;
	    return true;
	}
    } while (std::next_permutation(nb.begin(), nb.end()));
    return false;
}


bool winning_config_impl(std::vector<State>& b, int R, int C, int nfreeable, std::vector<int> nxt)
{
    if (nxt.empty()) return (nfreeable == 0);
    if (nfreeable == 0) return true;

    for (int i = 0, iend = (int)nxt.size(); i < iend; ++ i)
    {
	auto nxt2 = nxt;
	auto bnew = b;
	int move = nxt2[(size_t)i];
	nxt2.erase(nxt2.begin() + i);

	bnew[(size_t)move] = State::candidate;

	std::vector<int> allnb = get_neighbors(move, R, C);
	std::vector<int> nb;
	for(auto& inb : allnb) {
	    if (bnew[(size_t)inb] == State::mine)
		nb.push_back(inb);
	}
	int ncovered = (int)nb.size();
	if (nfreeable >= ncovered)
	{
	    for (auto& inb : nb) { 
		nxt2.push_back(inb);
		bnew[(size_t)inb] = State::candidate;
	    }
	    if (winning_config_impl(bnew, R, C, nfreeable - ncovered, nxt2))
	    {
		b = bnew;
		return true;
	    }
	}
    }

    return false;
}

std::vector<State> winning_config(int R, int C, int M, int init)
{
    int nfreeable = R*C-M;

    std::vector<State> b((size_t)(R*C), M == 0 ? State::candidate : State::mine);
    std::vector<int> nxt(1, init);

    if (nfreeable > 0 && (M == 0 || winning_config_impl(b, R, C, nfreeable - 1, nxt)))
    {
	b[(size_t)init] = State::first_move;
    }
    else
	b.clear();
    return b;
}

std::vector<State> winning_config(int R, int C, int M)
{
    for (int i = 0; i < R*C; ++ i)
    {
	auto b = winning_config(R, C, M, i);
	if (!b.empty())
	{
	    return b;
	}
    }
    return std::vector<State>();
}


void solve_case(int icase, std::ifstream& ifile)
{
    int R, C, M;
    ifile >> R >> C >> M;
    auto vec = winning_config(R, C, M);
    std::cout << "Case #" << icase << ":" << std::endl;
    if (vec.empty()) 
	std::cout << "Impossible\n";
    else show_vector(std::cout, R, C, vec);
}

void all_cases(std::ifstream& ifile)
{
    int ncases;
    ifile >> ncases;
    for (int i = 0; i < ncases; ++ i)
    {
	solve_case(i+1, ifile);
    }
}

int main(int argv, char** argc)
{
    if (argv < 2)
    {
	std::cerr << "Usage: " << std::string(argc[0]) << " inputfile\n";
	return -1;
    }
    std::ifstream infile(argc[1]);
    all_cases(infile);
}
