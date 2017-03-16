
#include "Shared.h"

using namespace std;

//-----------------------------------------------------------------------------
template<typename T>
void Split(const string& rsIn, const char* psDelimit, vector<T>& rvOut, T(*convert)(const string& rsIn))
{
    string::size_type iPos = 0;

    while (true)
    {
        int iMatch = rsIn.find_first_of(psDelimit, iPos);

        if (iMatch == string::npos)
        {
            if (iPos < rsIn.length())
            {
                rvOut.push_back(convert(rsIn.substr(iPos, rsIn.length() - iPos)));
            }

            break;
        }
        else
        {
            rvOut.push_back(convert(rsIn.substr(iPos, iMatch - iPos)));

            iPos = iMatch + 1;
        }
    }
}

//-----------------------------------------------------------------------------
string NoConv(const string& rsIn)
{
    return rsIn;
}
//-----------------------------------------------------------------------------
int ToInt(const string& rsIn)
{
    return atoi(rsIn.c_str());
}
//-----------------------------------------------------------------------------
unsigned int ToUInt(const string& rsIn)
{
    return strtoul(rsIn.c_str(), NULL, 0);
}
//-----------------------------------------------------------------------------
void Split(const string& rsIn, const char* psDelimit, vector<string>& rvOut)
{
    Split(rsIn, psDelimit, rvOut, NoConv);
}
//-----------------------------------------------------------------------------
void Split(const string& rsIn, const char* psDelimit, vector<int>& rvOut)
{
    Split(rsIn, psDelimit, rvOut, ToInt);
}
//-----------------------------------------------------------------------------
void Split(const string& rsIn, const char* psDelimit, vector<unsigned int>& rvOut)
{
    Split(rsIn, psDelimit, rvOut, ToUInt);
}

//-----------------------------------------------------------------------------
char _ToStringBuf[12];

std::string ToString(unsigned int i)
{
    return ultoa(i, _ToStringBuf, 10);     
}
//-----------------------------------------------------------------------------
unsigned int ToUInt(const char* ps)
{
    return strtoul(ps, NULL, 10);
}
