#include <iostream>

using namespace std;

enum Quaternion {
  ONE = 1,
  I = 2,
  J = 3,
  K = 4,
  MINUS_ONE = -1,
  MINUS_I = -2,
  MINUS_J = -3,
  MINUS_K = -4
};

Quaternion operator*(Quaternion const& lhs, Quaternion const& rhs) {
  int sign = 1;
  int l = lhs;
  int r = rhs;
  if(l< 0) {
    l= -l;
    sign *= -1;
  }
  if(r< 0) {
    r= -r;
    sign *= -1;
  }
  if(l == ONE) {
    return (Quaternion)(r * sign);
  }
  if(r == ONE) {
    return (Quaternion)(l * sign);
  }

  if(l == I && r == I) {
    return (Quaternion)(MINUS_ONE * sign);
  }
  if(l == I && r == J) {
    return (Quaternion)(K * sign);
  }
  if(l == I && r == K) {
    return (Quaternion)(MINUS_J * sign);
  }
  if(l == J && r == I) {
    return (Quaternion)(MINUS_K * sign);
  }
  if(l == J && r == J) {
    return (Quaternion)(MINUS_ONE * sign);
  }
  if(l == J && r == K) {
    return (Quaternion)(I * sign);
  }
  if(l == K && r == I) {
    return (Quaternion)(J * sign);
  }
  if(l == K && r == J) {
    return (Quaternion)(MINUS_I * sign);
  }
  if(l == K && r == K) {
    return (Quaternion)(MINUS_ONE * sign);
  }
}

ostream& operator<<(ostream& os, const Quaternion& a) {
  switch(a) {
    case ONE:
      cout<<" 1"; break;
    case I:
      cout<<" I"; break;
    case J:
      cout<<" J"; break;
    case K:
      cout<<" K"; break;
    case MINUS_ONE:
      cout<<"-1"; break;
    case MINUS_I:
      cout<<"-I"; break;
    case MINUS_J:
      cout<<"-J"; break;
    case MINUS_K:
      cout<<"-K"; break;
  }
}

Quaternion toq(char c) {
  switch(c) {
    case 'i':
      return I;
    case 'j':
      return J;
    case 'k':
      return K;
    default:
      cerr<<"Unknown character "<<c<<endl;
      return ONE;
  }
}

Quaternion pow(Quaternion const& q, long long int p) {
  Quaternion res = ONE;
  for(long long int i=0;i<(p%4);++i) {
    res = res * q;
  }
  return res;
}

bool runtc() {
  long long int l, x;
  string s;
  cin>>l>>x>>s;
  // First evaluate S
  Quaternion svalue = ONE;
  for(long long int i=0;i<l;++i) {
    svalue = svalue * toq(s[i]);
  }
  // if s^x != I*J*K, there is no chance
  if(pow(svalue, x) != I*J*K) {
    //cerr<<"s^x != I*J*K"<<endl;
    return false;
  }

  // Try to get I from a prefix of s^4
  Quaternion res = ONE;
  long long int ipos = 0;
  bool iok = false;
  for(long long int i=0;i<4;++i) {
    for(long long int j=0;j<l;++j) {
      ipos++;
      res = res * toq(s[j]);
      //cerr<<res;
      if(res == I) {
        iok = true;
        goto outer1;
      }
    }
  }
outer1:
  1;
  //cerr<<endl;
  // Try to get K from a suffix of s^4
  res = ONE;
  long long int kpos = 0;
  bool kok = false;
  for(long long int i=0;i<4;++i) {
    for(long long int j=l-1;j>=0;--j) {
      kpos++;
      res = toq(s[j]) * res;
      //cerr<<res;
      if(res == K) {
        kok = true;
        goto outer2;
      }
    }
  }
outer2:
  1;
  //cerr<<endl;

  if(ipos + kpos < x*l) {
    return iok and kok;
  }

  return false;
}

int main(int argc, char** argv) {
  int ntc;
  cin>>ntc;
  for(int tc=0;tc<ntc;++tc) {
    //cerr<<endl;
    bool result = runtc();
    cout<<"Case #"<<(tc+1)<<": ";
    if(result) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}

