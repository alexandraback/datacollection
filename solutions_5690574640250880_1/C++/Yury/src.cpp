
#if !defined(RECURSIVELY_INCLUDED)

#include <cassert>
#include <cstring>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <initializer_list>
#include <type_traits>
#include <vector>
#include <list>
#include <bitset>
#include <queue>
#include <utility>
#include <algorithm>
#include <memory>

#define ASSERT(x)          assert(x)

#define fori(a, b, c)       for(auto a = static_cast<remove_reference<decltype(c)>::type>(b), a ## _e = (c); (a) < (a ## _e) ; (a)++)
#define foriz(a, c)         fori(a, 0, (c))

#define range_impl__(a, b, c, postfix, ...)      fo ## postfix
#define range(...)   range_impl__(__VA_ARGS__, ri, riz, r) (__VA_ARGS__)

#define val            const auto
#define var                  auto
#define valr           const auto&
#define varr                 auto&

using namespace std;


typedef long long               llong;
typedef unsigned long long      ullong;

#define RECURSIVELY_INCLUDED
#include __FILE__
#undef RECURSIVELY_INCLUDED


#if !defined(CODE_GENERATION)

struct input_t {
    uint R, C, M;

    bool    tred;

    void read(istream& in);
};

struct output_t {
    vector<vector<bool>>    field;

    void write(ostream& out) const;
};

struct solver_t {
    const input_t&  in;
    output_t&       out;

    solver_t(const input_t& in, output_t& out) : in(in), out(out) {}

    void solve();
};

ostream& operator<<(ostream& out, const input_t& in) {
    ASSERT(!"Unimpled");
}

void input_t::read(istream& in) {
    in >> R >> C >> M;

    tred = false;
    if(R > C) {
        swap(C, R);
        tred = true;
    }
}

void output_t::write(ostream& out) const {
    if(field.empty()) {
        out << "Impossible\n";
        return;
    }

    val sz = field.at(0).size();
    range(i,field.size()) {
        valr li = field.at(i);
        ASSERT(li.size() == sz);
        range(j,li.size()) {
            if(i == 0 && j == 0) {
                out << 'c';
                continue;
            }
            valr b = li.at(j);
            out << (b?'*':'.');
        }
        out << endl;
    }
}

void solver_t::solve() {
    out.field.resize(in.R, {});
    range(varr li : out.field) {
        li.clear();
        li.resize(in.C, true);
    }

    /*
    auto fill_field = [this]() {
        range(varr li : out.field) range(var b : li) b = true;
    };
    */
    auto cut_rect = [this](uint R, uint C) {
        range(i,R) range(j,C) out.field.at(i).at(j) = false;
    };

    val RE = in.R * in.C - in.M;

    if(RE == 1) {
        out.field.at(0).at(0) = false;
        goto transpo;
    }

    if(in.R == 1) {
        range(j,in.C) {
            out.field.at(0).at(j) = (j >= RE);
        }
        goto transpo;
    }

    if(in.R == 2) {
        if(RE == 2 || (RE % 2) == 1) {
            out.field.clear();
        } else {
            cut_rect(in.R, RE/2);
        }
        goto transpo;
    }

    switch(RE) {
    case 2:
    case 3:
    case 5:
    case 7: {
        out.field.clear();
        return;
    }
    case 4:
    case 9: {
        uint side = 0;
        switch (RE) {
        case 1: side = 1; break;
        case 4: side = 2; break;
        case 9: side = 3; break;
        default: ASSERT(0);
        }
        cut_rect(side,side);
        goto transpo;
    }
    case 6: {
        cut_rect(3,2);
        goto transpo;
    }
    case 8: {
        if(in.R == 3) {
            cut_rect(3,2);
            cut_rect(2,3);
        } else {
            ASSERT(in.R >= 4);
            cut_rect(4,2);
        }
        goto transpo;
    }
    }

    /////

    {
        val lcnt = RE / in.C;
        val lrem = RE % in.C;

        //cerr << lcnt << " " << lrem << endl;

        switch(lcnt) {
        case 0:
        case 1: {
            val extra = in.C*2 - RE;

            //cerr << extra << endl;

            if(extra % 2) {
                cut_rect(3,3);
                cut_rect(2, in.C - ((extra + 3) / 2));
            } else {
                cut_rect(2, in.C - (extra / 2));
            }
        } break;
        case 2: {
            cut_rect(lcnt, in.C);
            cut_rect(lcnt+1, lrem);

            if(lrem == 1) {
                out.field.at(lcnt).at(1) = false;
                out.field.at(lcnt).at(2) = false;
                out.field.at(0).at(in.C-1) = true;
                out.field.at(1).at(in.C-1) = true;
            }
        } break;
        default: {
            cut_rect(lcnt, in.C);
            cut_rect(lcnt+1, lrem);

            if(lrem == 1) {
                out.field.at(lcnt).at(1) = false;
                out.field.at(lcnt-1).at(in.C-1) = true;
            }
        }};
    }

    if(1) {
        uint su = 0;
        range(i,in.R) range(j,in.C) {
            if(out.field.at(i).at(j)) su++;
        }
        ASSERT(su == in.M);
    }

transpo:
    if(!in.tred || out.field.empty()) return;

    decltype(out.field)     fi(in.C);

    range(varr li : fi) li.resize(in.R);

    range(i,in.R) range(j,in.C) {
        fi.at(j).at(i) = out.field.at(i).at(j);
    }
    out.field = move(fi);
}

int main(int argc, const char* argv[]) {
    ifstream in(argv[1]);

    uint    T;
    in >> T;
    range(t,T) {
        input_t     input;
        input.read(in);

        output_t    output;

        solver_t{input, output}.solve();

        cout << "Case #" << (t+1) << ":\n";
        output.write(cout);
    }

    return 0;
}

#else // !defined(CODE_GENERATION)

int main () {
    vector<string>      lines1, lines2;

    {
        ifstream    in("src.cpp");
        string      s;

        foriz(i, CODE_GEN_BLOCK_START) {
            getline(in,s); assert(in);
            lines1.push_back(move(s));
        }
        fori(i, CODE_GEN_BLOCK_START, CODE_GEN_BLOCK_END-1) {
            getline(in,s); assert(in);
        }
        for(;;) {
            getline(in,s);
            if(in.eof()) break;
            assert(!in.fail());
            lines2.push_back(move(s));
        }
    }

    ofstream     out("src.cpp", ios::out | ios::trunc);
    assert(out);

    for(valr l : lines1) {
        out << l << endl;
    }

    //////////////////////////////////

    vector<vector<uint>>        tri(32);

    tri.at(0) = { 1 };
    tri.at(1) = { 1, 1 };

    fori(i, 2, tri.size()) {
        valr pline = tri.at(i-1);
        varr line = tri.at(i);
        line.push_back(1);
        fori(j, 1, i) {
            line.push_back(pline.at(j-1) + pline.at(j));
        }
        line.push_back(1);
        line.shrink_to_fit();
    }

    out << "const vector<vector<uint>>    bin_tri = {\n";

    for(valr line : tri) {
        out << " {";
        bool first = true;
        for(valr n : line) {
            out << (first?" ":", ") << n;
            first = false;
        }
        out << " },\n";
    }

    out << "};\n";

    //////////////////////////////////

    for(valr l : lines2) {
        out << l << endl;
    }
}

#endif // !defined(CODE_GENERATION)

#else // !defined(RECURSIVELY_INCLUDED)

namespace std {
    namespace helper {
        template <class T>
        size_t calc_hash(const T& t) {
            return hash<T>()(t);
        }

        template <int N, class T, class... Ts>
        struct enumerate {
            template <class... TTs>
            static size_t hash(const tuple<TTs...>& t) {
                return calc_hash(get<N>(t)) + 9901 * enumerate<N+1, Ts...>::hash(t);
            }
        };
        template <int N, class T>
        struct enumerate<N, T> {
            template <class... TTs>
            static size_t hash(const tuple<TTs...>& t) {
                return calc_hash(get<N>(t));
            }
        };
    } // namespace helper

    template <class T, class U>
    struct hash<pair<T, U>> {
        size_t operator()(const pair<T, U>& p) const {
            return hash<tuple<T, U>>()(make_tuple(p.first, p.second));
        }
    };

    template <class... Ts>
    struct hash<tuple<Ts...>> {
        size_t operator()(const tuple<Ts...>& t) const {
            return helper::enumerate<0, Ts...>::hash(t);
        }
    };

    namespace helper {
        template<class T>
        true_type try_to_hash(T* t, decltype(hash<T>()(T())) sz = 0);
        false_type try_to_hash(...);
    } // namespace helper

    template <class T>
    struct is_hashable : decltype(helper::try_to_hash((T*)nullptr)) {};
} // namespace std

namespace {
    template <class T>
    struct union_find_impl {
    private:
        typedef  unordered_map<T, pair<T, uint>>        data_type;

    public:
        void add(const T& t) {
            val pp = data_.insert(make_pair(t, make_pair(t, 0)));
            ASSERT(pp.second);
        }

        T find(const T& t) const {
            return find_leader(t).first;
        }

        T join(const T& t1, const T& t2) {
            varr l1 = find_leader(t1);
            varr l2 = find_leader(t2);

            if(l1.second < l2.second) {
                l1.first = l2.first;
            } else {
                l2.first = l1.first;
                if(l1.second == l2.second) {
                    l1.second++;
                }
            }

            return l1.first;
        }

    private:

        typename data_type::mapped_type& find_leader(const T& t) const {
            val it1 = data_.find(t);
            ASSERT(it1 != data_.end());
            if(it1->second.first == t) return it1->second;

            val it2 = data_.find(it1->second.first);
            ASSERT(it2 != data_.end());
            if(it2->second.first == it1->second.first) return it2->second;

            vector<typename data_type::iterator>     rs;
            rs.push_back(it1);
            rs.push_back(it2);

            for(;;) {
                val it = data_.find(rs.back()->second.first);
                ASSERT(it != data_.end());

                if(it == rs.back()) break;

                rs.push_back(it);
            }

            val itl = rs.back();   rs.pop_back();
            for(val it : rs) {
                it->second.first = itl->first;
            }

            return itl->second;
        }

        mutable data_type data_;
    };

    template <class T>
    struct union_find
        : enable_if<is_hashable<T>::value, union_find_impl<T>>::type
    {
        static_assert(is_copy_constructible<T>::value &&
            is_copy_assignable<T>::value, "T must be `trivial'");
        //static_assert(is_trivial<T>::value, "T must be trivial");
        //static_assert(is_trivially_copyable<T>::value, "T must be trivially copyable");
        static_assert(is_hashable<T>::value, "T must be hashable");     // doen't work for pairs/tuples :'(
    };

    /////////////////

    uint gcd(uint a, uint b) {
        if(a < b) {
            swap(a, b);
        }

        while(b > 0) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    template <class... Ts>
    uint gcd(const uint& a, const uint& b, const Ts&... ts) {
        return gcd(gcd(a, b), ts...);
    }

    template <class T, class U>
    ostream& operator<< (ostream& out, const pair<T, U>& p) {
        return out << "pair(" << p.first << ", " << p.second << ")";
    }

    template <class T>
    void dump(const T& v) {
        for(valr i : v ){
            cerr << " " << i;
        }
        cerr << endl;
    }
} // namespace

// Everything between CODE_GEN_BLOCK_{START,END} macroes
// will be overwritten by the code generator!!
const int CODE_GEN_BLOCK_START = __LINE__;
const int CODE_GEN_BLOCK_END = __LINE__;
#endif // !defined(RECURSIVELY_INCLUDED)

