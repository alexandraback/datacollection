#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;
using Triple = tuple<int,string,string>;

Triple fill(string s1, string s2, int i)
{
  if(s1.size() == i)
    return make_tuple(abs(stoi(s1)-stoi(s2)), s1, s2);
		      
  if(s1[i] != '?' and s2[i] != '?')
    return fill(s1, s2, i+1);


  int left1 = stoi(s1.substr(0, i)), left2 = stoi(s2.substr(0, i));

  if(s1[i] == '?' and s2[i] == '?') {
    if(left1 == left2) {
      s1[i] = s2[i] = '0';
      Triple a = fill(s1, s2, i+1);

      s1[i] = '0';
      s2[i] = '1';
      Triple b = fill(s1, s2, i+1);

      s1[i] = '1';
      s2[i] = '0';
      Triple c = fill(s1, s2, i+1);

      return min(a, min(b, c));
    }
    else if(left1 > left2) {
      
      s1[i] = '0';
      s2[i] = '9';
      Triple a = fill(s1, s2, i+1);
      return a;
    }
    else if(left2 > left1) {
      s1[i] = '9';
      s2[i] = '0';
      Triple a = fill(s1, s2, i+1);
      return a;
      
    }
  }
  
    if(s1[i] == '?') {
      if(left1 == left2) {
	s1[i] = s2[i];
	Triple a = fill(s1, s2, i+1);
	
	s1[i] = (s2[i]-'0'+10-1)%10+'0';
	Triple b = fill(s1, s2, i+1);

	s1[i] = (s2[i]-'0'+1)%10+'0';
	Triple c = fill(s1, s2, i+1);
	


	return min(a, min(b, c));
      }
      else if(left1 > left2) {
	s1[i] = '0';
	Triple a = fill(s1, s2, i+1);
	return a;
      }
      else {
	s1[i] = '9';
	Triple a = fill(s1, s2, i+1);
	return a;
      }
    }
    else {
      if(left1 == left2) {
      	s2[i] = s1[i];
	Triple a = fill(s1, s2, i+1);
	
	s2[i] = (s1[i]-'0'+10-1)%10+'0';
	Triple b = fill(s1, s2, i+1);

	s2[i] = (s1[i]-'0'+1)%10+'0';

	Triple c = fill(s1, s2, i+1);

	return min(a, min(b, c));
      }
      else if(left1 > left2) {
	s2[i] = '9';
	Triple a = fill(s1, s2, i+1);
	return a;
      }
      else {
	s2[i] = '0';
	Triple a = fill(s1, s2, i+1);
	return a;
      }
    }
  
  
}

int main()
{
  int N;
  cin >> N;
  for(int i = 1; i <= N; ++i) {
    string s1, s2;
    cin >> s1 >> s2;

    s1 = "0" + s1;
    s2 = "0" + s2;
    Triple a = fill(s1, s2, 0);
    
    cout << "Case #" << i << ": ";
    cout << get<1>(a).substr(1) << " " << get<2>(a).substr(1);
    cout << endl;
  }
}
