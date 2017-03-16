#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>

// Use a set to keep the blocks sorted and for quick lookup
// of the next biggest (using upper_bound).
typedef std::set<double> Blocks;

void War(Blocks    naomisBlocks,
         Blocks    kensBlocks,
         unsigned* points)
{
    // Regular War. Naomi chooses smallest block.
    // Ken chooses block bigger than Naomi's.
    while (!naomisBlocks.empty()) {
        Blocks::iterator n_iter = naomisBlocks.begin();
        Blocks::iterator k_iter = kensBlocks.upper_bound(*n_iter);
        if (k_iter == kensBlocks.end()) {
            // Choose smallest. There's nothing larger than Naomi's block.
            k_iter = kensBlocks.begin();
        }
        if (*n_iter > *k_iter) {
            ++*points;
        }
        // Remove the blocks.
        naomisBlocks.erase(n_iter);
        kensBlocks.erase(k_iter);
    }
}
void DeceitfulWar(Blocks    naomisBlocks,
                  Blocks    kensBlocks,
                  unsigned* points)
{
    // Deceitful War. Get Ken to waste his biggest blocks first.
    // Tell Ken a weight slightly less than his biggest block. 
    // Really use Naomi's smallest block.
    while (!naomisBlocks.empty()) {
        Blocks::iterator n_iter               = naomisBlocks.begin();
        Blocks::reverse_iterator k_large_iter = kensBlocks.rbegin();
        Blocks::iterator k_small_iter         = kensBlocks.begin();
        if (*n_iter > *k_small_iter) {
            // Naomi gets a point without cheating...
            ++*points;
            kensBlocks.erase(k_small_iter);
        } else {
            // No points, but we force Ken to use his largest block.
            kensBlocks.erase(--k_large_iter.base());
        }
        naomisBlocks.erase(n_iter);
    }
}


int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cout << "Missing file containing input\n";
        return -1;
    }

    std::ifstream istr(argv[1]);

    // Read in the number of test cases.
    unsigned T;
    istr >> T;

    for (unsigned i = 1; i <= T; ++ i) {
        unsigned N;
        istr >> N;

        Blocks naomis_blocks;
        Blocks kens_blocks;
        for (unsigned j = 0; j < N; ++j) {
            double  weight;
            istr >> weight;
            naomis_blocks.insert(weight);
        }
        for (unsigned j = 0; j < N; ++j) {
            double  weight;
            istr >> weight;
            kens_blocks.insert(weight);
        }

        unsigned deceitful_war_points = 0;
        unsigned war_points = 0;

        War(naomis_blocks, kens_blocks, &war_points);
        DeceitfulWar(naomis_blocks, kens_blocks, &deceitful_war_points);

        std::cout << "Case #" << i << ": "
                  << deceitful_war_points << ' ' << war_points << '\n';
    }

    return 0;
}
