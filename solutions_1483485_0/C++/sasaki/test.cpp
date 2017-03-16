#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix.hpp>

#include <boost/assign.hpp>

namespace spirit = boost::spirit;
namespace qi = spirit::qi;
namespace karma = spirit::karma;
namespace phoenix = boost::phoenix;

typedef std::vector<std::string> Data;

template <typename Iterator>
struct input : qi::grammar<Iterator, Data()>
{
    input() : input::base_type(data)
    {
        using namespace qi;
        using namespace boost::phoenix;

        data %= omit[int_[ref(T) = _1] >> eol] >> repeat(ref(T))[line];
        line %= +(char_ - eol) >> eol;
    }

    qi::rule<Iterator, Data()> data;
    qi::rule<Iterator, std::string()> line;
    int T;
};

Data parse(std::istream &in) {
    Data d;
    spirit::istream_iterator b(in), e;
    qi::parse(b, e, input<spirit::istream_iterator>(), d);
    return d;
}

class Trans {
    std::map<char, char> _map;
public:
    Trans() {
        using namespace boost::assign;
        insert(_map)
                ('a', 'y')
                ('b', 'h')
                ('c', 'e')
                ('d', 's')
                ('e', 'o')
                ('f', 'c')
                ('g', 'v')
                ('h', 'x')
                ('i', 'd')
                ('j', 'u')
                ('k', 'i')
                ('l', 'g')
                ('m', 'l')
                ('n', 'b')
                ('o', 'k')
                ('p', 'r')
                ('q', 'z')
                ('r', 't')
                ('s', 'n')
                ('t', 'w')
                ('u', 'j')
                ('v', 'p')
                ('w', 'f')
                ('x', 'm')
                ('y', 'a')
                ('z', 'q')
                (' ', ' ');
    }

    char operator()(char c) {
        return _map[c];
    }
};

std::string calculate(std::string block) {
    std::transform(block.begin(), block.end(), block.begin(), Trans());
    return block;
}

Data calculate(const Data &data) {
    Data v;
    for (size_t i = 0; i < data.size(); ++i)
        v.push_back(calculate(data[i]));
    return v;
}

template <typename Iterator>
struct output : karma::grammar<Iterator, Data()>
{
    output() : output::base_type(entry), c(0)
    {
        using namespace karma;
        using namespace boost::phoenix;
        entry = *(lit("Case #") << lit(++ref(c)) << ": " << string << eol);
    }

    karma::rule<Iterator, Data()> entry;
    int c;
};

void generate(std::ostream &out, const Data &data) {
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
