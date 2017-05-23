#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

//*************************
//****  DECEITFUL_WAR  ****
//************************* 

class DeceitfulWar
{
public:
       DeceitfulWar(int );
       void setplayer1(const vector<float>&);
       void setplayer2(const vector<float>&);
       void examine();
       void printMessage(int ,ostream & = std::cout) const;
private:
        const int N;
        int fairScore;
        int cheatScore;
        list<float> naomi;
        list<float> ken;
        void determineFairScore();
        void determineCheatScore();
};

DeceitfulWar::DeceitfulWar(int n):N(n)
{ naomi = list<float>(N);  ken = list<float>(N);  cheatScore = fairScore = 0; }

void DeceitfulWar::setplayer1(const vector<float>&v) 
{ naomi = list<float>(v.begin(),v.end()); }

void DeceitfulWar::setplayer2(const vector<float>&v) 
{ ken = list<float>(v.begin(),v.end()); }

void DeceitfulWar::examine()
{
  naomi.sort();
  ken.sort();
  
  determineCheatScore();
  determineFairScore();
}

void DeceitfulWar::printMessage(int k,ostream &out) const
{ out << "Case #" << k << ": " << cheatScore << " " << fairScore; }

void DeceitfulWar::determineFairScore()
{
  fairScore = 0;
  list<float>::reverse_iterator niter;
  
  for (niter=naomi.rbegin();niter!=naomi.rend();niter++){
      if (*niter < *ken.rbegin()) ken.erase(--ken.end());
      else{ fairScore++; ken.erase(ken.begin()); }
  }
            
}

void DeceitfulWar::determineCheatScore()
{
  list<float>::reverse_iterator niter,kiter;
  niter = naomi.rbegin();
  kiter = ken.rbegin();
  cheatScore = 0;
  while (kiter != ken.rend()){
        if (*niter > *kiter) { cheatScore++; niter++; }
        kiter++;
  }
}

//*******************
//*****  MAIN   *****
//*******************

int main()
{
  ifstream input("D-large.in");
  if (!input) exit(1);
  ofstream output("out.txt");
  if (!output) exit(1);
  
  int T,N;
  input >> T;
  
  for (int k=1;k<=T;k++){
      input >> N;
      vector<float> player1(N);
      vector<float> player2(N);
      float w;
      for (int i=0;i<N;i++) { input>>w; player1[i]=w; }
      for (int i=0;i<N;i++) { input>>w; player2[i]=w; }
      DeceitfulWar dw(N);
      dw.setplayer1(player1); dw.setplayer2(player2);
      dw.examine();
      dw.printMessage(k,output);
      output << endl;
  }
  
  scanf("%*c");
  return 0;
}
