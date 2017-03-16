#include <iostream>
#include <algorithm>

using namespace std;

double Ken[1000], Naomi[1000];

main()  {
  int T, N;
  cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N;
    for (int i=0; i<N; i++) cin >> Naomi[i];
    for (int i=0; i<N; i++) cin >> Ken[i];

    sort(Naomi,Naomi+N);
    sort(Ken,Ken+N);

    /*
    cout << "Naomi: ";
    for (int i=0; i<N; i++) cout << Naomi[i] << " ";
    cout << endl;
    cout << "Ken: ";
    for (int i=0; i<N; i++) cout << Ken[i] << " ";
    cout << endl;
    */

    int ken=N-1;
    for (int naomi=N-1; naomi>=0; naomi--)
      if (Ken[ken]>Naomi[naomi]) ken--;
    int naomi_war_score = ken+1;

    int ken_l=0, ken_h=N-1, naomi_l=0, naomi_h=N-1, naomi_score=0;

    while (naomi_l<=naomi_h) {
      if (Naomi[naomi_l]<Ken[ken_l]) naomi_l++,ken_h--;
      else naomi_score++, naomi_l++, ken_l++;
    }

    cout << "Case #" << t << ": " << naomi_score << " " << naomi_war_score << endl;
  };
};
