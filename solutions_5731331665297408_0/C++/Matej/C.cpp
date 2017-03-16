#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int P[59];
int X[2500];
int Y[2500];
int S[2500]; // 0 = unused, 1 = went to X, 2 = went to Y, 3 = used

// cities visited using an outbound flight
bool outTo[59];

// order of visited cities
int seq[112];
int seqLength;

int bestSeq[112];
int bestSeqLength;

void recurse(int city) {
  // check if we are at the end
  bool endGame = (city == seq[0]);
  for (int i = 0; i < N; ++i)
    if (!outTo[i]) {
      endGame = false;
      break;
    }
  for (int i = 0; i < M; ++i)
    if (S[i] == 1 || S[i] == 2) {
      endGame = false;
      break;
    }
  // check best solution if endGame
  if (endGame) {
    //for (int i = 0; i < seqLength; ++i) printf("%d ", seq[i]);
    
    bool better = (seqLength <= bestSeqLength);
    if (seqLength == bestSeqLength)
      for (int i = 0; i < seqLength; ++i) {        
        if (P[seq[i]] > P[bestSeq[i]]) {
          better = false;
          break;
        }
        else if (P[seq[i]] < P[bestSeq[i]])
          break;
      }
      
    if (better) {
      //printf(" better");
      bestSeqLength = seqLength;
      for (int i = 0; i < seqLength; ++i)
        bestSeq[i] = seq[i];
    }
    //printf("\n");
    return;
  }
  
  // try to use a flight
  for (int i = 0; i < M; ++i) {
    // outbound to X
    if (Y[i] == city && S[i] == 0 && !outTo[X[i]]) {
      outTo[X[i]] = true;
      S[i] = 1;
      seq[seqLength] = X[i];
      seqLength++;
      //
      recurse(X[i]);
      //
      seqLength--;
      S[i] = 0;
      outTo[X[i]] = false;
    }
    // outbound to Y
    if (X[i] == city && S[i] == 0 && !outTo[Y[i]]) {
      outTo[Y[i]] = true;
      S[i] = 2;
      seq[seqLength] = Y[i];
      seqLength++;
      //
      recurse(Y[i]);
      //
      seqLength--;
      S[i] = 0;
      outTo[Y[i]] = false;
    }
    // return to X
    if (Y[i] == city && S[i] == 2) {
      S[i] = 3;
      //seq[seqLength] = X[i];
      //seqLength++;
      //
      recurse(X[i]);
      //
      //seqLength--;
      S[i] = 2;
    }
    // return to Y
    if (X[i] == city && S[i] == 1) {
      S[i] = 3;
      //seq[seqLength] = Y[i];
      //seqLength++;
      //
      recurse(Y[i]);
      //
      //seqLength--;
      S[i] = 1;
    }
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // init & input
    seqLength = 0;
    bestSeqLength = 1000000;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &P[i]);
      outTo[i] = false;
    }
    for (int i = 0; i < M; ++i) {
      scanf("%d %d", &X[i], &Y[i]);
      X[i]--;
      Y[i]--;
      S[i] = 0;
    }
    
    // pick starting city
    for (int si = 0; si < N; ++si) {
      outTo[si] = true;
      seqLength = 1;
      seq[0] = si;
      //
      recurse(si);
      //
      outTo[si] = false;
    }
   
    // output best solution
    printf("Case #%d: ", Ti);
    for (int i = 0; i < bestSeqLength; ++i)
      printf("%d", P[bestSeq[i]]);
    printf("\n");
  }
  return 0;
}
