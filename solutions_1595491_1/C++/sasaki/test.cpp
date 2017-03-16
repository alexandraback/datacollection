#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/fusion/adapted.hpp>
namespace spirit = boost::spirit;
namespace qi = spirit::qi;
namespace karma = spirit::karma;
namespace phoenix = boost::phoenix;

struct Block {
    int S, p;
    std::vector<int> t;
};

BOOST_FUSION_ADAPT_STRUCT(
        Block,
        (int, S)
        (int, p)
        (std::vector<int>, t)
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
        block %= omit[int_[ref(N) = _1] >> ' '] >> int_ >> ' ' >> int_ >> ' ' >> (int_ % ' ') >> eol;
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

int calculate(const Block &block) {
    const std::vector<int> &r = block.t;

    using namespace phoenix::arg_names;

    int c = block.p * 3 - 2;
    int mycount = (int) count_if (r.begin(), r.end(), arg1 >= c);
    int candidates = (int) count_if (r.begin(), r.end(), (arg1 == c - 1 || arg1 == c - 2) && (arg1 >= 2 && arg1 <= 28));
    return mycount + std::min(block.S, candidates);
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
