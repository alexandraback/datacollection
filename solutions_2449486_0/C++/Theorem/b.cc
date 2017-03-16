
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int n, m;
int lawn[100][100];
int mrows[100];
int mcols[100];


void solve (int CASE)
{
    cin >> n >> m;

    memset(mrows, 0, sizeof mrows);
    memset(mcols, 0, sizeof mcols);

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> lawn[i][j];
        mrows[i] = std::max(mrows[i], lawn[i][j]);
        mcols[j] = std::max(mcols[j], lawn[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int h = lawn[i][j];
            if (h != mrows[i] && h != mcols[j]) {
                printf("Case #%d: NO\n", CASE);
                return;
            }
        }
    }

    printf("Case #%d: YES\n", CASE);
}

int main ()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) solve(i);
  return 0;
}

