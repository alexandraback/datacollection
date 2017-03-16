#include <iostream>
#include <vector>

using namespace std;

int main(){
  double t_cases,p,p2,jsum,jsum2,temp;
  vector<double> jscore;
  cout.precision(10);
  cin >> t_cases;
  for(int i=1;i<=t_cases;i++){
    cin >> p;
    p2 = p;
    jscore.clear();
    jsum=0;
    jsum2=0;
    for(int j=0;j<p;j++){
      cin >> temp;
      jscore.push_back(temp);
      jsum += temp;
    }
    for(int j=0;j<p;j++){
      if (2 >= ((p*jscore[j])/jsum) ){
	jsum2 += jscore[j];
      }
      else{
	p2--;
      }
    }
    cout << "Case #"<< i << ": ";
    for(int j=0;j<p;j++){
      if(2 >= ((p*jscore[j])/jsum) ){
	temp = (1 - (((p2-1)*jscore[j] - (jsum2-jscore[j]))/jsum))/p2 * 100;
      }
      else{
	temp = 0;
      }
      cout << temp << " ";
    }
    cout << endl;
  }
  return 0;
}
