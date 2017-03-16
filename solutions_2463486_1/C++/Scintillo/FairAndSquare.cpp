#include <iostream>
#include <vector>
// Available at http://www.boost.org/ (Tested working using version 1.52)
#include <boost/thread.hpp>
// Available at http://gmplib.org/ (Tested working using version 5.1.1)
#include <gmpxx.h>

bool isPal(std::string const& str)
{
    unsigned int a = 0;
    unsigned int b = str.length() - 1;

    while(a < b)
    {
        if(str[a] != str[b])
            return false;

        a++;
        b--;
    }

    return true;
}

struct Job
{
    mpz_class a;
    mpz_class b;
    uint64_t result;
};

boost::mutex jobsMutex;
std::vector<Job> jobs;
unsigned int jobNow = 0;

void solve()
{
    while(true)
    {
        jobsMutex.lock();
        if(jobNow == jobs.size())
        {
            jobsMutex.unlock();
            return;
        }

        Job& job = jobs[jobNow];
        jobNow++;
        jobsMutex.unlock();

        mpz_class& a = job.a;
        mpz_class& b = job.b;
        uint64_t& total = job.result;
        total = 0;

        mpz_class aSqrt = sqrt(a);
        mpz_class bSqrt = sqrt(b) + 1;

        unsigned int aSqrtLength = aSqrt.get_str().length();
        unsigned int bSqrtLength = bSqrt.get_str().length();

        unsigned int evenStart, oddStart;

        if(aSqrtLength % 2 == 0)
        {
            evenStart = aSqrtLength;
            oddStart = aSqrtLength + 1;
        }
        else
        {
            evenStart = aSqrtLength + 1;
            oddStart = aSqrtLength;
        }

        if(oddStart == 1)
        {
            for(unsigned int i = 0; i <= 9; i++)
            {
                mpz_class candidate = i * i;

                if(candidate >= a && candidate <= b && isPal(candidate.get_str()))
                {
                    total++;
                }
            }

            oddStart = 3;
        }

        for(unsigned int l = evenStart; l <= bSqrtLength; l += 2)
        {

            //std::cout << l << std::endl;

            mpz_class start, last;

            mpz_pow_ui(start.get_mpz_t(), mpz_class(10).get_mpz_t(), (l / 2) - 1);
            last = start * 10 - 1;

            //std::cout << start << " " << last << std::endl;

            for(mpz_class i = start; i <= last; i++)
            {
                std::string iStr = i.get_str();
                std::string iiStr = std::string(iStr.rbegin(), iStr.rend());

                mpz_class candidate(iStr + iiStr);
                candidate *= candidate;

                if(candidate >= a && candidate <= b && isPal(candidate.get_str()))
                {
                    total++;
                }
            }
        }

        for(unsigned int l = oddStart; l <= bSqrtLength; l += 2)
        {
            mpz_class start, last;

            mpz_pow_ui(start.get_mpz_t(), mpz_class(10).get_mpz_t(), (l / 2) - 1);
            last = start * 10 - 1;

            for(mpz_class i = start; i <= last; i++)
            {
                std::string iStr = i.get_str();
                std::string iiStr = std::string(iStr.rbegin(), iStr.rend());

                for(char middle = '0'; middle <= '9'; middle++)
                {
                    mpz_class candidate(iStr + middle + iiStr);
                    candidate *= candidate;

                    if(candidate >= a && candidate <= b && isPal(candidate.get_str()))
                    {
                        total++;
                    }
                }
            }
        }
    }
}

int main()
{
    std::vector<boost::thread> threads;

    unsigned int t;
    std::cin >> t;

    jobs.resize(t);
    threads.resize(4);

    for(Job& job : jobs)
    {
        std::cin >> job.a >> job.b;
    }

    for(boost::thread& thread : threads)
    {
        thread = boost::thread(boost::bind(solve));
    }

    for(boost::thread& thread : threads)
    {
        thread.join();
    }

    for(unsigned int i = 0; i < t; ++i)
    {
        std::cout << "Case #" << (i + 1) << ": " << jobs[i].result << std::endl;
    }

    return 0;
}
