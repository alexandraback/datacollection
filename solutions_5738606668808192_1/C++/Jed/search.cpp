/*
 * $File: search.cpp
 * $Date: Sat Apr 09 19:06:19 2016 +0800
 * $Author: jiakai <jia.kai66@gmail.com>
 * $MAKEFLAGS: -lgmpxx -lgmp
 *
 * For codejam 2016 problem C:
 * If the number of 1s in the sequence is a multiple of 6, then we only need to
 * check for primality against representations under base 2, 6 and 8
 */

#include <gmpxx.h>
#include <cstdio>
#include <array>

class Solver {
    class Found {};

    static constexpr int LEN = 32, REQUEST = 500;

    static constexpr int NEED_CHECK = 3, SEARCH_END = LEN - 1;
    using Sequence = std::array<bool, LEN>;

    mpz_class m_chk_power[NEED_CHECK][LEN], m_cur_sum[NEED_CHECK],
              m_sum_backup[LEN][NEED_CHECK];
    Sequence m_cur_hist, m_ans[REQUEST];
    int m_nr_ans = 0;

    void dfs(int pos, int nr_1s);
    void init_chk_power();

    public:
        void solve();
};

void Solver::solve() {
    init_chk_power();
    for (int i = 0; i < NEED_CHECK; ++ i)
        m_cur_sum[i] = m_chk_power[i][0] + m_chk_power[i][LEN - 1];

    m_cur_hist[0] = m_cur_hist[LEN - 1] = 1;
    try {
        dfs(1, 2);
        fprintf(stderr, "only found %d\n", m_nr_ans);
        abort();
    } catch (Found) {
    }

    for (int i = 0; i < REQUEST; ++ i) {
        for (int j = LEN - 1; j >= 0; -- j)
            printf("%d", m_ans[i][j]);
        printf("\n");
    }
}

void Solver::init_chk_power() {
    const int CHK[NEED_CHECK] = {2, 6, 8};
    for (int i = 0; i < NEED_CHECK; ++ i) {
        m_chk_power[i][0] = 1;
        for (int j = 1; j < LEN; ++ j) {
            m_chk_power[i][j] = m_chk_power[i][j - 1];
            m_chk_power[i][j] *= CHK[i];
        }
    }
}

void Solver::dfs(const int pos, const int nr_1s) {
    if (pos == SEARCH_END) {
        // check whether any could be prime
        for (auto &&i: m_cur_sum) {
            if (mpz_probab_prime_p(i.get_mpz_t(), 20))
                return;
        }
        m_ans[m_nr_ans ++] = m_cur_hist;
        if (m_nr_ans == REQUEST)
            throw Found{};
        return;
    }

    if (!nr_1s || nr_1s + SEARCH_END - (pos + 1) >= 6) {
        m_cur_hist[pos] = 0;
        dfs(pos + 1, nr_1s);
    }

    int next_nr_1s = (nr_1s == 5) ? (0) : (nr_1s + 1);

    if (!next_nr_1s || next_nr_1s + SEARCH_END - (pos + 1) >= 6) {
        mpz_class *backup = m_sum_backup[pos];
        for (int i = 0; i < NEED_CHECK; ++ i) {
            backup[i] = m_cur_sum[i];
            m_cur_sum[i] += m_chk_power[i][pos];
        }
        m_cur_hist[pos] = 1;
        dfs(pos + 1, next_nr_1s);
        for (int i = 0; i < NEED_CHECK; ++ i)
            backup[i].swap(m_cur_sum[i]);
    }
}

int main() {
    Solver().solve();
}

// vim: syntax=cpp.doxygen foldmethod=marker foldmarker=f{{{,f}}}

