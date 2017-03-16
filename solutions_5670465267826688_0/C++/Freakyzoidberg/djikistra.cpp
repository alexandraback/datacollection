#include <iostream>
#include <string>

using namespace std;

char mul(char a, char b)
{
  switch (a) {
  case '1': {
    return b;
  }
  case 'i': {
    switch (b) {
    case '1': return 'i';
    case 'i': return '0';
    case 'j': return 'k';
    case 'k': return 'J';
    case '0': return 'I';
    case 'I': return '1';
    case 'J': return 'K';
    case 'K': return 'j';
    }
  }
  case 'j': {
    switch (b) {
    case '1': return 'j';
    case 'i': return 'K';
    case 'j': return '0';
    case 'k': return 'i';
    case '0': return 'J';
    case 'I': return 'k';
    case 'J': return '1';
    case 'K': return 'I';
    }
  }
  case 'k': {
    switch (b) {
    case '1': return 'k';
    case 'i': return 'j';
    case 'j': return 'I';
    case 'k': return '0';
    case '0': return 'K';
    case 'I': return 'J';
    case 'J': return 'i';
    case 'K': return '1';
    }
  }
  case '0': {
    switch (b) {
    case '1': return '0';
    case 'i': return 'I';
    case 'j': return 'J';
    case 'k': return 'K';
    case '0': return '1';
    case 'I': return 'i';
    case 'J': return 'j';
    case 'K': return 'k';
    }
  }
  case 'I': {
    switch (b) {
    case '1': return 'I';
    case 'i': return '1';
    case 'j': return 'K';
    case 'k': return 'j';
    case '0': return 'i';
    case 'I': return '0';
    case 'J': return 'k';
    case 'K': return 'J';
    }
  }
  case 'J': {
    switch (b) {
    case '1': return 'J';
    case 'i': return 'k';
    case 'j': return '1';
    case 'k': return 'I';
    case '0': return 'j';
    case 'I': return 'K';
    case 'J': return '0';
    case 'K': return 'i';
    }
  }
  case 'K': {
    switch (b) {
    case '1': return 'K';
    case 'i': return 'J';
    case 'j': return 'i';
    case 'k': return '1';
    case '0': return 'k';
    case 'I': return 'j';
    case 'J': return 'I';
    case 'K': return '0';
    }
  }
  }
  return '0';
}

char is(string s)
{
  char c = s[0];
  for (int i = 1; i < s.size(); i++)
    c = mul(c, s[i]);
  return c;
}

bool is_ijk(string &str)
{
  char c = '1';
  for (int i_e = 0 ; i_e < str.size(); i_e++)
    {
      char d = '1';
      c = mul(c, str[i_e]);
      if (c == 'i')
	{
	  for (int j_e = i_e + 1; j_e < str.size(); j_e++)
	    {
	      d = mul(d, str[j_e]);
	      if (d == 'j' && is(str.substr(j_e + 1)) == 'k')
		return true;
	    }
	}
    }
  return false;
}


int main(int argc, char** argv)
{
  int t_max;
  cin >> t_max;
  
  for (int t = 0; t < t_max; t++)
  {
    int sub, count;
    string str_sub, str;
    cin >> sub >> count;
    cin >> str_sub;
    str = str_sub;
    for (int c = 1; c < count; c++)
      str += str_sub;
    std::cout << "Case #" << t + 1<< ": " 
	      << (is_ijk(str) ? "YES" : "NO") << std::endl;
  }
}
