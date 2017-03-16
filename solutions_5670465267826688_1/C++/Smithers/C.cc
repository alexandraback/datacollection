// Google Code Jam Qualification Round 2015
// Problem C. Dijkstra
// Solution in C++
// By Smithers

#include <iostream>
#include <vector>

class quaternion
{
    friend bool operator ==(quaternion lhs, quaternion rhs);
    friend quaternion operator -(quaternion x);
    
    enum quatval
    {
        ONE, I, J, K, MONE, MI, MJ, MK
    };
    quatval m_value;
    
    quatval dir(quatval v) { return quatval(v & 3); }
    quatval sgn(quatval v) { return quatval(v & 4); }
    
public:
    quaternion() : m_value(ONE) { }
    explicit quaternion(char c)
    {
        switch (c)
        {
            case 'i': m_value = I; break;
            case 'j': m_value = J; break;
            case 'k': m_value = K; break;
        }
    }
    quaternion & operator *=(quaternion rhs)
    {
        static const quatval results[4][4] =
        {
            {ONE, I,    J,    K},
            {I,   MONE, K,    MJ},
            {J,   MK,   MONE, I},
            {K,   J,    MI,   MONE}
        };
        m_value = quatval(results[dir(m_value)][dir(rhs.m_value)] ^ sgn(m_value) ^ sgn(rhs.m_value));
        return *this;
    }
};

bool operator ==(quaternion lhs, quaternion rhs)
{
    return lhs.m_value == rhs.m_value;
}
bool operator !=(quaternion lhs, quaternion rhs)
{
    return !(lhs == rhs);
}

quaternion operator -(quaternion val)
{
    val.m_value = quaternion::quatval(val.m_value ^ 4);
    return val;
}

quaternion operator *(quaternion lhs, quaternion rhs)
{
    return lhs *= rhs;
}

quaternion pow(quaternion lhs, int rhs)
{
    rhs %= 4;
    if (rhs < 0)
        rhs += 4;
    quaternion result;
    while (rhs--)
        result *= lhs;
    return result;
}

bool solve_case(int L, int X, std::string const & s)
{
    quaternion test;
    
    for (int i = 0; i < L; ++i)
        test *= quaternion(s[i]);
    
    if (pow(test, X) != -quaternion())
        return false;
    
    int limit = L * std::min(X, 8);
    int i = 0;
    
    test = quaternion();
    for (; i < limit; ++i)
    {
        test *= quaternion(s[i % L]);
        if (test == quaternion('i'))
            break;
    }
    if (i == limit)
        return false;
    
    test = quaternion();
    for (++i; i < limit; ++i)
    {
        test *= quaternion(s[i % L]);
        if (test == quaternion('j'))
            break;
    }
    if (i == limit)
        return false;
    
    return true;
}

int main()
{
    int T;
    std::cin >> T;
    for (int x = 1; x <= T; ++x)
    {
        int L, X;
        std::string s;
        
        std::cin >> L >> X >> s;
        
        std::cout << "Case #" << x << ": " << (solve_case(L, X, s) ? "YES" : "NO") << std::endl;
    }
    
    return 0;
}
