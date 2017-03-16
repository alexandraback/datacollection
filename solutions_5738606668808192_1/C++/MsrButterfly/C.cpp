#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using byte = uint8_t;
using dual_byte = uint16_t;

const byte byte_all_one = std::numeric_limits<byte>::max();
const size_t bits_per_byte = std::numeric_limits<byte>::digits;

class large_int;

inline large_int abs(const large_int &n);

class divide_by_zero {
public:
    divide_by_zero() {}
};

class out_of_range {
public:
    out_of_range() {}
};

template <class T>
struct div_t_2 {
    T quot;
    T rem;
};

inline div_t_2<int> div(const int &a, const int &b);
inline div_t_2<long> div(const long &a, const long &b);
inline div_t_2<long long> div(const long long &a, const long long &b);
inline div_t_2<large_int> div(const large_int &a, const large_int &b);

class large_int {
    using self_type = large_int;
public:
    large_int();
    large_int(const self_type &another);
    large_int(self_type &&another);
    template <class T, class C = typename std::enable_if<std::is_integral<T>::value>::type>
    large_int(const T &num);
public:
    template <class T, class C = typename std::enable_if<std::is_integral<T>::value>::type>
    bool representable() const;
    template <class T, class C = typename std::enable_if<std::is_integral<T>::value>::type>
    T get() const;
    size_t bit_size() const;
public:
    self_type operator~() const;
    self_type operator+() const;
    self_type operator-() const;
    self_type operator++(int);
    self_type operator--(int);
    self_type &operator=(const self_type &another);
    self_type &operator=(self_type &&another);
    self_type &operator++();
    self_type &operator--();
    self_type &operator<<=(const size_t &shift);
    self_type &operator>>=(const size_t &shift);
    self_type &operator&=(const self_type &another);
    self_type &operator|=(const self_type &another);
    self_type &operator^=(const self_type &another);
    self_type &operator+=(const self_type &another);
    self_type &operator-=(const self_type &another);
    self_type &operator*=(const self_type &another);
    self_type &operator/=(const self_type &another);
    self_type &operator%=(const self_type &another);
    friend bool operator==(const self_type &a, const self_type &b);
    friend bool operator!=(const self_type &a, const self_type &b);
    friend bool operator<(const self_type &a, const self_type &b);
    friend bool operator>(const self_type &a, const self_type &b);
    friend bool operator<=(const self_type &a, const self_type &b);
    friend bool operator>=(const self_type &a, const self_type &b);
    friend self_type operator<<(const self_type &value, const size_t &shift);
    friend self_type operator>>(const self_type &value, const size_t &shift);
    friend self_type operator&(const self_type &a, const self_type &b);
    friend self_type operator|(const self_type &a, const self_type &b);
    friend self_type operator^(const self_type &a, const self_type &b);
    friend self_type operator+(const self_type &a, const self_type &b);
    friend self_type operator-(const self_type &a, const self_type &b);
    friend self_type operator*(const self_type &a, const self_type &b);
    friend self_type operator/(const self_type &a, const self_type &b);
    friend self_type operator%(const self_type &a, const self_type &b);
    friend div_t_2<self_type> div(const self_type &a, const self_type &b);
    explicit operator bool() const;
public:
    friend self_type abs(const self_type &n);
    template <class Char>
    friend std::basic_ostream<Char> &operator<<(std::basic_ostream<Char> &os, const self_type &n);
    template <unsigned int Ary, class Char, class C>
    friend std::basic_ostream<Char> &output(std::basic_ostream<Char> &os, const self_type &n);
private:
    bool signed_;
    std::vector<byte> num_;
};

inline large_int abs(const large_int &n) {
    auto m = n;
    m.signed_ = false;
    return m;
}

inline div_t_2<int> div(const int &a, const int &b) {
    auto r = std::div(a, b);
    return {r.quot, r.rem};
}

inline div_t_2<long> div(const long &a, const long &b) {
    auto r = std::ldiv(a, b);
    return {r.quot, r.rem};
}

inline div_t_2<long long> div(const long long &a, const long long &b) {
    auto r = std::lldiv(a, b);
    return {r.quot, r.rem};
}

inline div_t_2<large_int> div(const large_int &a, const large_int &b){
    auto d = a / b;
    return {d, a - b * d};
}

template <unsigned int Ary>
class digit {
public:
    using self_type = digit;
    using value_type = uint8_t;
public:
    digit();
    template <class T, class C = typename
        std::enable_if<std::is_unsigned<T>::value>::type>
        digit(const T& n);
public:
    const value_type &get() const;
    const value_type &carry() const;
    const value_type &borrow() const;
    self_type &operator=(const self_type &another);
    self_type &operator++();
    self_type &operator--();
    self_type operator++(int);
    self_type operator--(int);
    self_type &operator+=(const self_type &another);
    self_type &operator-=(const self_type &another);
    self_type &operator*=(const self_type &another);
    self_type &operator/=(const self_type &another);
    friend self_type operator+(const self_type &a, const self_type &b) { return self_type(a) += b; }
    friend self_type operator-(const self_type &a, const self_type &b) { return self_type(a) -= b; }
    friend self_type operator*(const self_type &a, const self_type &b) { return self_type(a) *= b; }
    friend self_type operator/(const self_type &a, const self_type &b) { return self_type(a) /= b; }
    template <class Char>
    friend std::basic_ostream<Char> &operator<<(std::basic_ostream<Char> &os, const self_type &n) {
        os << static_cast<unsigned int>(n.n_);
        return os;
    }
private:
    value_type carry_;
    value_type borrow_;
    value_type n_;
};

template <unsigned int Ary>
digit<Ary>::digit()
    : digit(0u) {}

template <unsigned int Ary>
template <class T, class C>
digit<Ary>::digit(const T &n)
    : carry_(0), borrow_(0), n_((n < Ary) ? static_cast<value_type>(n) : 0) {}

template <unsigned int Ary>
const typename digit<Ary>::value_type &digit<Ary>::get() const {
    return n_;
}

template <unsigned int Ary>
const typename digit<Ary>::value_type &digit<Ary>::carry() const {
    return carry_;
}

template <unsigned int Ary>
const typename digit<Ary>::value_type &digit<Ary>::borrow() const {
    return borrow_;
}

template <unsigned int Ary>
digit<Ary> &digit<Ary>::operator=(const self_type &another) {
    carry_ = another.carry_;
    borrow_ = another.borrow_;
    n_ = another.n_;
    return *this;
}

template <unsigned int Ary>
digit<Ary> &digit<Ary>::operator+=(const self_type &another) {
    carry_ = 0;
    borrow_ = 0;
    n_ += another.n_;
    if (n_ >= Ary) {
        n_ -= Ary;
        carry_ = 1;
    }
    return *this;
}

template <unsigned int Ary>
digit<Ary> &digit<Ary>::operator++() {
    return operator+=(1u);
}

template <unsigned int Ary>
digit<Ary> digit<Ary>::operator++(int) {
    auto a = *this;
    operator+=(1u);
    return a;
}

template <unsigned int Ary>
digit<Ary> &digit<Ary>::operator-=(const self_type &another) {
    carry_ = 0;
    borrow_ = 0;
    if (n_ < another.n_) {
        n_ += Ary;
        borrow_ = 1;
    }
    n_ -= another.n_;
    return *this;
}

template <unsigned int Ary>
digit<Ary> &digit<Ary>::operator--() {
    return operator-=(1u);
}

template <unsigned int Ary>
digit<Ary> digit<Ary>::operator--(int) {
    auto a = *this;
    operator-=(1u);
    return a;
}

template <unsigned int Ary>
digit<Ary> &digit<Ary>::operator*=(const self_type &another) {
    carry_ = 0;
    borrow_ = 0;
    n_ *= another.n_;
    carry_ = n_ / Ary;
    n_ -= carry_ * Ary;
    return *this;
}

template <unsigned int Ary>
digit<Ary> &digit<Ary>::operator/=(const self_type &another) {
    carry_ = 0;
    borrow_ = 0;
    n_ /= another.n_;
    return *this;
}

large_int::large_int()
    : signed_(false), num_(0, 1) {}

large_int::large_int(const self_type &another)
    : signed_(another.signed_), num_(another.num_) {}

large_int::large_int(self_type &&another)
    : signed_(std::move(another.signed_)), num_(std::move(another.num_)) {}

template <class T, class C>
large_int::large_int(const T &num)
    : signed_(std::is_signed<T>::value && num < 0) {
    uintmax_t n;
    n = signed_ ? -(intmax_t)num : num;
    while (n > 0) {
        num_.push_back(static_cast<byte>(n));
        n >>= bits_per_byte;
    }
    if (num_.size() == 0) {
        num_.push_back(0);
    }
}

template <class T, class C>
bool large_int::representable() const {
    return *this >= std::numeric_limits<T>::min() && *this <= std::numeric_limits<T>::max();
}

template <class T, class C>
T large_int::get() const {
    if (!representable<T>()) {
        throw out_of_range();
    }
    union {
        T value = 0;
        byte bytes[sizeof(T)];
    } ret;
    if (is_little_endian()) {
        memcpy(&ret, num_.data(), num_.size());
    } else if (is_big_endian()) {
        // std::rbegin() is first introduced in C++14.
        auto it = ret.bytes + sizeof(T) - 1;
#if defined(_MSC_VER) && _SECURE_SCL == 1
        // Tricking the Secure SCL.
        // reverse_iterator<byte *> is supported by the implementation,
        // but not the specification (raw pointer).
        // https://msdn.microsoft.com/en-us/library/aa985928.aspx
        auto dest = stdext::make_unchecked_array_iterator(it);
#else
        auto dest = it;
#endif
        std::copy(num_.begin(), num_.end(), dest);
    }
    if (signed_) {
        ret.value = -(intmax_t)ret.value;
        // ok: with T = int8_t, *this = -128
        // -(-128) = (~0x80) + 1 = 0x7F + 1 = 0x80 = -128
        // http://stackoverflow.com/questions/17469804/what-is-128-for-signed-single-byte-char-in-c
    }
    return ret.value;
}

template <size_t N>
struct bit_size {
    static const size_t value = bit_size<(N >> 1)>::value + 1;
};

template <>
struct bit_size<0> {
    static const size_t value = 0;
};

template <class T>
size_t dynamic_bit_size(T num) {
    size_t count = 0;
    while (num) {
        ++count;
        num >>= 1;
    }
    return count;
}

size_t large_int::bit_size() const {
    return (num_.size() - 1) * bits_per_byte + dynamic_bit_size(num_.back());
}

large_int large_int::operator~() const {
    auto n = *this;
    size_t i;
    for (i = 0; i < n.num_.size() - 1; ++i) {
        n.num_[i] ^= byte_all_one;
    }
    byte h = n.num_[i];
    byte u;
    for (u = 0; h; h >>= 1) {
        u <<= 1;
        ++u;
    }
    n.num_[i] ^= u;
    decltype(num_)::reverse_iterator p;
    for (p = n.num_.rbegin(); p != n.num_.rend() && *p == 0; ++p);
    if (p == n.num_.rend()) {
        n.signed_ = false;
        n.num_ = {0};
    } else {
        n.num_.resize(n.num_.rend() - p);
    }
    return std::move(n);
}

large_int large_int::operator+() const {
    return *this;
}

large_int large_int::operator-() const {
    auto n = *this;
    if (n) {
        n.signed_ = !n.signed_;
    }
    return std::move(n);
}

large_int large_int::operator++(int) {
    auto n = *this;
    ++*this;
    *this += 1;
    return std::move(n);
}

large_int large_int::operator--(int) {
    auto n = *this;
    *this -= 1;
    return std::move(n);
}

large_int &large_int::operator++() {
    return *this += 1;
}

large_int &large_int::operator--() {
    return *this += 1;
}

large_int &large_int::operator=(const self_type &another) {
    signed_ = another.signed_;
    num_ = another.num_;
    return *this;
}
large_int &large_int::operator=(self_type &&another) {
    signed_ = std::move(another.signed_);
    num_ = std::move(another.num_);
    return *this;
}

large_int &large_int::operator<<=(const size_t &another) {
    auto div = std::lldiv(another, bits_per_byte);
    decltype(num_) c(static_cast<size_t>(div.quot) + num_.size());
    std::copy(begin(num_), end(num_), begin(c) + static_cast<size_t>(div.quot));
    num_ = std::move(c);
    if (div.rem > 0) {
        dual_byte d = 0;
        for (auto &i : num_) {
            d = (static_cast<dual_byte>(i) << div.rem) + d;
            i = static_cast<byte>(d);
            d >>= bits_per_byte;
        }
        if (d) {
            num_.push_back(static_cast<byte>(d));
        }
    }
    return *this;
}

large_int &large_int::operator>>=(const size_t &another) {
    auto div = std::lldiv(another, bits_per_byte);
    if (num_.size() - div.quot <= 0) {
        return (*this = 0);
    }
    decltype(num_) c(num_.size() - static_cast<size_t>(div.quot));
    std::copy(begin(num_) + static_cast<size_t>(div.quot), end(num_), begin(c));
    num_ = std::move(c);
    if (div.rem > 0) {
        dual_byte d = 0;
        for (auto i = num_.size(); i > 0; i--) {
            auto j = i - 1;
            d = ((static_cast<dual_byte>(num_[j]) << bits_per_byte) >> div.rem) + d;
            num_[j] = static_cast<byte>(d >> bits_per_byte);
            d <<= bits_per_byte;
        }
        if (*num_.rbegin() == 0) {
            if (num_.size() > 1) {
                num_.pop_back();
            } else {
                signed_ = false;
            }
        }

    }
    return *this;
}

large_int &large_int::operator&=(const large_int &another) {
    auto size = std::min(num_.size(), another.num_.size());
    if (num_.size() > size) {
        num_.resize(size);
    }
    for (size_t i = 0; i < size; ++i) {
        num_[i] &= another.num_[i];
    }
    decltype(num_)::reverse_iterator p;
    for (p = num_.rbegin(); p != num_.rend() && *p == 0; ++p);
    if (p == num_.rend()) {
        signed_ = false;
        num_ = {0};
    } else {
        num_.resize(num_.rend() - p);
    }
    return *this;
}

large_int &large_int::operator|=(const large_int &another) {
    auto size = std::min(num_.size(), another.num_.size());
    for (size_t i = 0; i < size; ++i) {
        num_[i] |= another.num_[i];
    }
    decltype(num_)::reverse_iterator p;
    for (p = num_.rbegin(); p != num_.rend() && *p == 0; ++p);
    if (p == num_.rend()) {
        signed_ = false;
        num_ = {0};
    } else {
        num_.resize(num_.rend() - p);
    }
    return *this;
}

large_int &large_int::operator^=(const large_int &another) {
    auto size = std::min(num_.size(), another.num_.size());
    auto another_size = another.num_.size();
    if (num_.size() < another_size) {
        num_.resize(another_size);
    }
    for (size_t i = 0; i < size; ++i) {
        num_[i] ^= i < another_size ? another.num_[i] : 0;
    }
    decltype(num_)::reverse_iterator p;
    for (p = num_.rbegin(); p != num_.rend() && *p == 0; ++p);
    if (p == num_.rend()) {
        signed_ = false;
        num_ = {0};
    } else {
        num_.resize(num_.rend() - p);
    }
    return *this;
}

large_int &large_int::operator+=(const self_type &another) {
    auto &a = num_;
    auto &b = another.num_;
    if (signed_ ^ another.signed_ && another) {
        return *this -= -another;
    }
    size_t max_size = std::max(a.size(), b.size());
    if (a.size() < max_size) {
        a.resize(max_size);
    }
    dual_byte c = 0;
    for (size_t i = 0; i < max_size; ++i) {
        dual_byte ub = 0;
        if (i < b.size()) {
            ub = b[i];
        } else if (!c) {
            break;
        }
        c = static_cast<dual_byte>(a[i]) + ub + c;
        a[i] = static_cast<byte>(c);
        c >>= bits_per_byte;
    }
    if (c) {
        a.push_back(static_cast<byte>(c));
    }
    return *this;
}

large_int &large_int::operator-=(const self_type &another) {
    auto &a = num_;
    auto &b = another.num_;
    if (signed_ ^ another.signed_ && another) {
        return *this += -another;
    }
    auto a_size = a.size();
    size_t max_size = std::max(a_size, b.size());
    if (a_size < max_size) {
        a.resize(max_size);
        std::fill(a.begin() + a_size, a.end(), 0);
    }
    dual_byte c = 0;
    for (size_t i = 0; i < max_size; ++i) {
        c ^= byte_all_one;
        c++;
        c &= byte_all_one;
        dual_byte ub = 0;
        if (i < b.size()) {
            ub = b[i];
        } else if (!c) {
            break;
        }
        c = static_cast<dual_byte>(a[i]) - ub - c;
        a[i] = static_cast<byte>(c);
        c >>= bits_per_byte;
    }
    if (c) {
        for (auto &i : a) {
            i ^= byte_all_one;
        }
        auto signed__ = signed_;
        signed_ = false;
        operator++();
        signed_ = !signed__;
    }
    decltype(num_)::reverse_iterator p;
    for (p = num_.rbegin(); p != num_.rend() && *p == 0; ++p);
    if (p == num_.rend()) {
        signed_ = false;
        num_ = {0};
    } else {
        num_.resize(num_.rend() - p);
    }
    return *this;
}

large_int &large_int::operator*=(const self_type &another) {
    auto a = num_;
    auto &b = another.num_;
    signed_ = signed_ ^ another.signed_;
    num_ = decltype(num_)(a.size() + b.size());
    decltype(num_) part(a.size() + b.size());
    for (size_t i = 0; i < b.size(); ++i) {
        std::fill(part.begin(), part.end(), 0);
        dual_byte c = 0;
        for (size_t j = 0; j < a.size(); ++j) {
            c = static_cast<dual_byte>(a[j]) * static_cast<dual_byte>(b[i]) + c;
            part[i + j] = static_cast<byte>(c);
            c >>= bits_per_byte;
        }
        if (c) {
            part[i + a.size()] = static_cast<byte>(c);
        }
        c = 0;
        for (size_t j = 0; j < num_.size(); ++j) {
            c = static_cast<dual_byte>(num_[j]) + part[j] + c;
            num_[j] = static_cast<byte>(c);
            c >>= bits_per_byte;
        }
    }
    decltype(num_)::reverse_iterator p;
    for (p = num_.rbegin(); p != num_.rend() && *p == 0; ++p);
    if (p == num_.rend()) {
        signed_ = false;
        num_ = {0};
    } else {
        num_.resize(num_.rend() - p);
    }
    return *this;
}

large_int &large_int::operator/=(const self_type &another) {
    if (!another) {
        throw divide_by_zero();
    }
    if (!*this) {
        return *this;
    }
    auto a = *this;
    auto b = another;
    const size_t a_bits = a.bit_size();
    const size_t b_bits = b.bit_size();
    if (a_bits < b_bits) {
        *this = 0;
        return *this;
    }
    std::fill(num_.begin(), num_.end(), 0);
    b <<= a_bits - b_bits;
    for (size_t i = a_bits - b_bits + 1; i > 0; --i, b >>= 1) {
        size_t vi = (i - 1) / bits_per_byte;
        size_t ei = (i - 1) % bits_per_byte;
        if (a >= b) {
            num_[vi] |= 1 << ei;
            a -= b;
        } else {
            num_[vi] &= ~(1 << ei);
        }
    }
    decltype(num_)::reverse_iterator p;
    for (p = num_.rbegin(); p != num_.rend() && *p == 0; ++p);
    if (p == num_.rend()) {
        signed_ = false;
        num_ = {0};
    } else {
        num_.resize(num_.rend() - p);
    }
    signed_ = signed_ ^ another.signed_;
    if (num_.size() == 1 && *num_.rbegin() == 0) {
        signed_ = false;
    }
    return *this;
}

large_int &large_int::operator%=(const self_type &another) {
    auto d = div(*this, another);
    *this = d.rem;
    return *this;
}

bool operator==(const large_int &a, const large_int &b) {
    return !(a != b);
}

bool operator!=(const large_int &a, const large_int &b) {
    if ((a.signed_ ^ b.signed_) || a.num_.size() != b.num_.size()) {
        return true;
    }
    for (size_t i = 0; i < a.num_.size(); ++i) {
        if (a.num_[i] != b.num_[i]) {
            return true;
        }
    }
    return false;
}

bool operator<(const large_int &a, const large_int &b) {
    if (a.signed_ ^ b.signed_) {
        return a.signed_;
    }
    auto &signed_ = a.signed_;
    if (a.num_.size() != b.num_.size()) {
        return (a.num_.size() < b.num_.size()) ^ signed_;
    }
    for (auto i = a.num_.size(); i > 0; i--) {
        auto j = i - 1;
        if (a.num_[j] != b.num_[j]) {
            return (a.num_[j] < b.num_[j]) ^ signed_;
        }
    }
    return false;
}

bool operator>(const large_int &a, const large_int &b) {
    if (a.signed_ ^ b.signed_) {
        return b.signed_;
    }
    auto &signed_ = a.signed_;
    if (a.num_.size() != b.num_.size()) {
        return (a.num_.size() > b.num_.size()) ^ signed_;
    }
    for (auto i = a.num_.size(); i > 0; i--) {
        auto j = i - 1;
        if (a.num_[j] != b.num_[j]) {
            return (a.num_[j] > b.num_[j]) ^ signed_;
        }
    }
    return false;
}

bool operator<=(const large_int &a, const large_int &b) {
    return !(a > b);
}

bool operator>=(const large_int &a, const large_int &b) {
    return !(a < b);
}

large_int operator<<(const large_int &a, const size_t &b) {
    auto c = a;
    return std::move(c <<= b);
}

large_int operator>>(const large_int &a, const size_t &b) {
    auto c = a;
    return std::move(c >>= b);
}

large_int operator&(const large_int &a, const large_int &b) {
    auto c = a;
    return std::move(c &= b);
}

large_int operator|(const large_int &a, const large_int &b) {
    auto c = a;
    return std::move(c |= b);
}

large_int operator^(const large_int &a, const large_int &b) {
    auto c = a;
    return std::move(c ^= b);
}

large_int operator+(const large_int &a, const large_int &b) {
    large_int c = a;
    return std::move(c += b);
}

large_int operator-(const large_int &a, const large_int &b) {
    large_int c = a;
    return std::move(c -= b);
}

large_int operator*(const large_int &a, const large_int &b) {
    auto c = a;
    return std::move(c *= b);
}

large_int operator/(const large_int &a, const large_int &b) {
    auto c = a;
    return std::move(c /= b);
}

large_int operator%(const large_int &a, const large_int &b) {
    auto c = a;
    return std::move(c %= b);
}

large_int::operator bool() const {
    return num_.size() != 1 || *num_.rbegin() != 0;
}

template <unsigned int Ary, class Char, class C = typename std::enable_if<(Ary > 1)>::type>
std::basic_ostream<Char> &output(std::basic_ostream<Char> &os, const large_int &n) {
    if (n.signed_) {
        os << '-';
    }
    const size_t length = bits_per_byte * n.num_.size() / (bit_size<Ary>::value - 1) + 2;
    std::vector<digit<Ary>> sum(length, 0u);
    std::vector<digit<Ary>> pow(length, 0u);
    pow[0]++;
    size_t pow_size = 1;
    auto bit_of = [&](const size_t &i) {
        auto div = std::lldiv(i, bits_per_byte);
        auto quot = static_cast<size_t>(div.quot);
        auto rem = static_cast<byte>(div.rem);
        return n.num_[quot] & (1 << rem);
    };
    for (size_t i = 0; i < n.num_.size() * bits_per_byte; ++i) {
        if (bit_of(i)) {
            sum[0] += pow[0];
            auto carry = sum[0].carry();
            auto last_carry = carry;
            for (size_t j = 1; j < pow_size; ++j) {
                sum[j] += last_carry;
                carry = sum[j].carry();
                sum[j] += pow[j];
                last_carry = sum[j].carry() + carry;
            }
            sum[pow_size] += last_carry;
        }
        pow[0] *= 2u;
        auto carry = pow[0].carry();
        auto last_carry = carry;
        for (size_t j = 1; j < pow_size; ++j) {
            pow[j] *= 2u;
            carry = pow[j].carry();
            pow[j] += last_carry;
            last_carry = pow[j].carry() + carry;
        }
        if (last_carry) {
            pow[pow_size++] = last_carry;
        }
    }
    auto i = pow_size - 1;
    for (; i > 0 && sum[i].get() == 0u; i--);
    ++i;
    std::basic_stringstream<Char> ss;
    ss.flags(os.flags());
    for (; i > 0; i--) {
        auto j = i - 1;
        ss << sum[j];
    }
    os << ss.str();
    return os;
}

template <class Char>
std::basic_ostream<Char> &operator<<(std::basic_ostream<Char> &os, const large_int &n) {
    const auto &flags = os.flags();
    if (flags & std::ios::oct) {
        return output<8>(os, n);
    } else if (flags & std::ios::dec) {
        return output<10>(os, n);
    } else if (flags & std::ios::hex) {
        return output<16>(os, n);
    }
    return os;
}

using namespace std;

string to_string(const large_int &n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

large_int sqrt(const large_int &n) {
    if (n < 0) {
        return 0;
    }
    large_int ret = (n >> 1) + 1;
    while (ret * ret > n) {
        ret = (ret + n / ret) >> 1;
    }
    return ret;
}

large_int first_nontrivial_factor(const large_int &n) {
    static const vector<large_int> factors = {2, 3, 5, 7, 11}; // 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
    for (size_t i = 0; i < factors.size(); ++i) {
        if (n % factors[i] == 0) {
            return factors[i];
        }
    }
    return 0;
}

large_int calc_num(uint64_t bin, size_t ary) {
    //cout << "calculating (" << bin << ")" << ary << endl;
    large_int num = 0;
    large_int base = 1;
    for (uint64_t num2 = bin; num2; num2 >>= 1) {
        num += (num2 & 1) * base;
        base *= ary;
    }
    return move(num);
}

int main(int argc, const char *argv[]) {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    size_t t;
    scanf("%zd", &t);
    for (size_t i = 0; i < t; ++i) {
        printf("Case #%zd:\n", i + 1);
        size_t n, m;
        scanf("%zd %zd", &n, &m);
        uint64_t lb = ((uint64_t)1 << ((uint64_t)n - 1)) + 1;
        uint64_t ub = ((uint64_t)1 << (uint64_t)n) - 1;
        for (uint64_t j = lb; (j <= ub) && m; j += 2) {
            //printf("calculating: %s\n", bitset<64>(j).to_string().substr(64 - n).c_str());
            vector<large_int> factors;
            for (size_t ary = 2; ary <= 10; ++ary) {
                large_int num = calc_num(j, ary);
                //printf("%s -(%zd)-> %s\n", bitset<64>(j).to_string().substr(64 - n).c_str(), ary, to_string(num).c_str());
                auto factor = first_nontrivial_factor(num);
                if (!factor) {
                    //printf("prime: %s -(%zd)-> %s\n", bitset<64>(j).to_string().substr(64 - n).c_str(), ary, to_string(num).c_str());
                    break;
                } else {
                    factors.push_back(factor);
                }
            }
            if (factors.size() == 9) {
                //printf("%zd. ", 501 - m);
                printf("%s", bitset<64>(j).to_string().substr(64 - n).c_str());
                for (const auto &factor : factors) {
                    printf(" %s", to_string(factor).c_str());
                }
                printf("\n");
                --m;
            }
        }
    }
    return EXIT_SUCCESS;
}
