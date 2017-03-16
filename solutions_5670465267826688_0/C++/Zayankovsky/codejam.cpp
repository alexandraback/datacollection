#include <fstream>
#include <vector>


signed char multiply_main(char mul1, char mul2)
{
    if (mul1 == 1)
    {
        return mul2;
    }
    if (mul2 == 1)
    {
        return mul1;
    }
    if (mul1 == mul2)
    {
        return -1;
    }
    if (mul1 == 'i')
    {
        if (mul2 == 'j')
        {
            return 'k';
        }
        if (mul2 == 'k')
        {
            return -'j';
        }
    }
    if (mul1 == 'j')
    {
        if (mul2 == 'i')
        {
            return -'k';
        }
        if (mul2 == 'k')
        {
            return 'i';
        }
    }
    if (mul1 == 'k')
    {
        if (mul2 == 'i')
        {
            return 'j';
        }
        if (mul2 == 'j')
        {
            return -'i';
        }
    }
    return 0;
}

signed char multiply(signed char mul1, signed char mul2)
{
    signed char result = 1;
    if (mul1 < 0)
    {
        result = -result;
        mul1 = -mul1;
    }
    if (mul2 < 0)
    {
        result = -result;
        mul2 = -mul2;
    }
    return result * multiply_main(mul1, mul2);
}

int main()
{
    std::ifstream fin("input.txt");
    size_t T;
    fin >> T;
    std::vector<bool> answers(T);
    unsigned long long L, X;
    std::string str;
    signed char partial_product, product;
    unsigned long long first_i, last_k;
    for (size_t i = 0; i < T; ++i)
    {
        fin >> L >> X >> str;
        partial_product = 1;
        for (unsigned long long j = 0; j < L; ++j)
        {
            partial_product = multiply(partial_product, str[j]);
        }
        product = partial_product;
        for (unsigned long long k = 1; k < X; ++k)
        {
            product = multiply(product, partial_product);
        }
        if (product != -1)
        {
            continue;
        }
        product = 1;
        first_i = -1;
        for (unsigned long long k = 0; k < X; ++k)
        {
            for (unsigned long long j = 0; j < L; ++j)
            {
                product = multiply(product, str[j]);
                if (product == 'i')
                {
                    first_i = k * L + j;
                    goto first_i_found;
                }
            }
        }
first_i_found:
        if (first_i == -1)
        {
            continue;
        }
        product = 1;
        last_k = -1;
        for (unsigned long long k = X; k --> 0;)
        {
            for (unsigned long long j = L; j --> 0;)
            {
                product = multiply(str[j], product);
                if (product == 'k')
                {
                    last_k = k * L + j;
                    goto last_k_found;
                }
            }
        }
last_k_found:
        if (last_k == -1)
        {
            continue;
        }
        answers[i] = first_i < last_k;
    }
    fin.close();
    std::ofstream fout("output.txt");
    for (size_t i = 0; i < T; ++i)
    {
        fout << "Case #" << i + 1 << ": " << (answers[i] ? "YES" : "NO") << std::endl;
    }
    fout.close();
    return 0;
}
