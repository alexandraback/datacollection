#include <iostream>
#include <random>
#include <time.h>
#include <limits>
#include <vector>
#include <sstream>
using namespace std;


class Instance{
public:
  void read();
  void write();

  void compute();
private:
  int _n;
  vector<bool> _result;
  vector<string> _arrays;
  vector<long> _rep;
};


class Character{
public:
  Character(char c);

  Character multi(Character &right_c);
  void mult_minus();

 void print();

  int _type;
  bool _positive;
};


void Character::mult_minus()
{
  _positive = (_positive == false);
}

Character::Character(char c)
{
  _positive = true;
  _type = 0;
  if (c=='1') {
    _type = 0;
  }
  if (c=='i') {
    _type = 1;
  }
  if (c=='j') {
    _type = 2;
  }
  if (c=='k') {
    _type = 3;
  }
}


Character Character::multi
(Character &right_c)
{
 Character n('1');
 switch(_type) {
  case 0:
    n._type = right_c._type;
  break;
  case 1:
    switch(right_c._type) {
      case 0:
      n._type = 1;
      break;
      case 1:
      n._type = 0;
      n.mult_minus();
      break;
      case 2:
      n._type = 3;
      break;
      case 3:
      n._type = 2;
      n.mult_minus();
      break;
    }

  break;
  case 2:
    switch(right_c._type) {
      case 0:
      n._type =2;
      break;
      case 1:
      n._type =3;
      n.mult_minus();
      break;
      case 2:
      n._type =0;
      n.mult_minus();
      break;
      case 3:
      n._type =1;
      break;
    }
  break;
  case 3:
    switch(right_c._type) {
      case 0:
      n._type =3;
      break;
      case 1:
      n._type =2;
      break;
      case 2:
      n._type =1;
      n.mult_minus();
      break;
      case 3:
      n._type =0;
      n.mult_minus();
      break;
    }
  break;
 }

  if (!_positive) {
    n.mult_minus();
  }
  if (!right_c._positive) {
    n.mult_minus();
  }
  return n;
}


void Character::print()
{
 if (!_positive) {
   cout << "-";
 }
 switch (_type) {
   case 0:
   cout << "1";
   break;
   case 1:
   cout << "i";
   break;
   case 2:
   cout << "j";
   break;
   case 3:
   cout << "k";
   break;

 }
}


void Instance::read()
{
 cin >> _n;
  /*cout << "Found " << _n << endl;*/
  for (int i = 0; i < _n; ++i) {
    _result.push_back(false);
    long length_string, rep;
    cin >> length_string;
    cin >> rep;

//cout << rep << endl;

    string s;
    cin >> s;
    _arrays.push_back(s);
    _rep.push_back(rep);
    //std::sort(_arrays[i].begin(), _arrays[i].end(), std::greater<int>());
  }
}


void Instance::write()
{
   for (long i = 0; i < _n; ++i) {
    cout << "Case #"<< i+1 << ": " << (_result[i]? "YES":"NO") << endl;

/*    for (int j = 0; j < _arrays[i].size(); ++j) {
      cout << _arrays[i][j] << " ";
    }
    cout << endl;*/
  }
}


void Instance::compute()
{
  for (long i = 0; i < _n; ++i){
    _result[i] = false;
    string s = _arrays[i];
    long rep = _rep[i];


//cout << rep << endl;
//cout << "String has length " << s.length() << " rep= " << rep << endl;

    // String to short
    if (s.length()*rep < 3) {
      continue;
    }
    vector<Character> cs;
    for (int j = 0; j < s.length(); ++j){
      Character c(s[j]);
      cs.push_back(c);
    }

    // Multiply all values ...
    Character prod('1');
    for (int j = 0; j < cs.size(); ++j){
      prod = prod.multi(cs[j]);
    }

    int rep2 = rep;
    if (rep2 >=2){
      Character prod2 = prod.multi(prod);
      if (rep2 % 2 == 0){
        prod = Character('1');
      }
      rep2 /= 2;


      if (rep2 % 2 == 0){
        prod2 = prod2.multi(prod2);
      }
      prod = prod.multi(prod2);
    }
//    cout << "Product is "; prod.print(); cout << endl;

    // Found a candidate
    if ((prod._type == 0) && (prod._positive == false))
    {
      _result[i] = true;
    } else {
      continue;
    }

//cout << endl << "left" << endl;

    // contruct i on the left
    long length_left = 0;
    bool ended = false;
    Character left('1');

    for (long j=1; (j <= min(rep, 4*(long)cs.size()) ) && (ended == false); ++j ) {
      for (int h=0; h < cs.size(); ++h) {
        ++length_left;
        left = left.multi(cs[h]);

//        left.print();

        if ((left._type == 1) && (left._positive == true)){
          ended = true;
          break;
        }
      }
    }
    if (!ended) {
      _result[i] = false;
      continue;
    }

//cout << endl << "right" << endl;


    ended = false;
    long length_right = 0;
    Character right('1');
    for (long j=1; (j <= min(rep, 4*(long)cs.size()) ) && (ended == false); ++j ) {
      for (int h=cs.size()-1; h >= 0; --h) {
        ++length_right;
        right = cs[h].multi(right);

//        right.print();

        if ((right._type == 3) && (right._positive == true)){
          ended = true;
          break;
        }
      }
    }
    if (!ended) {
      _result[i] = false;
      continue;
    }

    // Not correct
    if (length_right + length_left +1 > (long)cs.size() * rep) {
      _result[i] = false;

      continue;
    }
  }

}


int main(int argc, char** argv){
  Instance I;
  I.read();

  I.compute();

  I.write();
}
