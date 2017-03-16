#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<double> load_vec(std::ifstream& ifile, size_t N)
{
    std::vector<double> vec;
    double tmp;
    for (size_t i = 0; i < N; ++ i)
    {
	ifile >> tmp;
	vec.push_back(tmp);
    }
    return vec;
}

size_t play_deceitful_war(std::vector<double>& n, std::vector<double>& k)
{
    std::sort(n.begin(), n.end());
    std::sort(k.begin(), k.end());
    // n rounds
    size_t N = n.size();
    size_t ndx = 0;
    while (ndx < N && n[ndx] < k[N - 1 - ndx]) ++ ndx;
    size_t ndwins = (N - 1) - ndx + 1;
    return ndwins;
}
size_t play_war(std::vector<double>& n, std::vector<double>& k)
{
    std::sort(n.begin(), n.end());
    std::sort(k.begin(), k.end());
    // n rounds
    size_t N = n.size();
    size_t nwins = 0;
    for (size_t ndx = 0; ndx < N; ++ ndx)
    {
	if (n[ndx] > k[ndx])
	    ++ nwins;
    }
    return nwins;
}

std::pair<size_t, size_t> play_war_simple(std::vector<double>& n, std::vector<double>& k)
{
    std::vector<char> id;
    std::sort(n.begin(), n.end());
    std::sort(k.begin(), k.end());
    size_t idx = 0, jdx = 0;
    size_t N = n.size();
    while (idx < N && jdx < N)
    {
	if (n[idx] < k[jdx]) { ++ idx; id.push_back('n'); }
	else { ++ jdx; id.push_back('k'); }
    }
    for (; idx < N; ++ idx) id.push_back('n');
    for (; jdx < N; ++ jdx) id.push_back('k');
    size_t ncount = 0, kcount = 0, nwins = 0, kwins = 0;
    for (auto& ic : id)
    {
	if (ic == 'n') { ++ ncount; 
	    if (kcount > 0) { -- kcount; ++ nwins; }
	} 
	if (ic == 'k') { ++ kcount; 
	    if (ncount > 0) { -- ncount; ++ kwins; }
	}
    }
    return std::make_pair(nwins, N - kwins);
}
void solve_case(int icase, std::ifstream& ifile)
{
    size_t N;
    ifile >> N;
    auto n = load_vec(ifile, N);
    auto k = load_vec(ifile, N);
    //size_t ndwar = play_deceitful_war(n, k);
    //size_t nwar = play_war(n, k);
    auto ndnwar = play_war_simple(n, k);
    size_t ndwar = ndnwar.first;
    size_t nwar = ndnwar.second;
    std::cout << "Case #" << icase << ": " << ndwar << " " << nwar << std::endl;
    assert(ndwar >= nwar);
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
