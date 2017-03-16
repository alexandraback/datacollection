#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/fusion/adapted.hpp>
#include <boost/range/algorithm.hpp>

namespace spirit = boost::spirit;
namespace qi = spirit::qi;
namespace karma = spirit::karma;
namespace phoenix = boost::phoenix;

struct Block {
    int A, B;
};

BOOST_FUSION_ADAPT_STRUCT(
        Block,
        (int, A)
        (int, B)
        )

typedef std::vector<Block> Data;
typedef std::vector<int> Result;

template <typename Iterator>
struct input : qi::grammar<Iterator, Data()>
{
    input() : input::base_type(data)
    {
        using namespace qi;
        using namespace boost::phoenix;

        data %= omit[int_[ref(T) = _1] >> eol] >> repeat(ref(T))[block];
        block %= int_ >> ' ' >> int_ >> eol;
    }

    qi::rule<Iterator, Data()> data;
    qi::rule<Iterator, Block()> block;
    int T, N;
};

Data parse(std::istream &in) {
    Data d;
    spirit::istream_iterator b(in), e;
    qi::parse(b, e, input<spirit::istream_iterator>(), d);
    return d;
}

int digit(int i) {
    int digit = 0;
    for (;;) {
        i /= 10;
        ++digit;
        if (i == 0)
            return digit;
    }
    return 0;
}

int powi(int a, int d) {
    int r = 1;
    for (int i = 0; i < d; ++i)
        r *= a;
    return r;
}

int recycle(int n, int digit) {
    int d = digit - 1;
    return (n % 10) * powi(10, d) + n / 10;
}

int calculate(const Block &b) {
    int A = b.A;
    int B = b.B;
    std::vector<std::pair<int, int> > v;
    for (int i = A; i <= B; ++i) {
        int d = digit(i);
        for (int m = recycle(i, d); m != i;m = recycle(m, d)) {
            if (i < m && m <= B)
                v.push_back(std::make_pair(i, m));
        }
    }
    return v.size();
}

Result calculate(const Data &data) {
    Result v;
    for (size_t i = 0; i < data.size(); ++i)
        v.push_back(calculate(data[i]));
    return v;
}

template <typename Iterator>
struct output : karma::grammar<Iterator, Result()>
{
    output() : output::base_type(entry), c(0)
    {
        using namespace karma;
        using namespace boost::phoenix;
        entry = *(lit("Case #") << lit(++ref(c)) << ": " << auto_ << eol);
    }

    karma::rule<Iterator, Result()> entry;
    int c;
};

void generate(std::ostream &out, const Result &data) {
    spirit::ostream_iterator sink(out);
    karma::generate(sink, output<spirit::ostream_iterator>(), data);
}

void execute(std::istream &in, std::ostream &out) {
    generate(out, calculate(parse(in)));
}

int main() {
    std::cin.unsetf(std::ios::skipws);
    execute(std::cin, std::cout);
}
