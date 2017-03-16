#include <stdio.h>
#include <stdlib.h>

// Solve the problem

void solve(int s1[], int s2[], int n) {
   int i, j, t;
   int s1a[2000], s2a[2000];   // Sorted according to 2-star min.
   int s1b[2000], s2b[2000];   // Sorted according to 1-star min.

   // Brute-force bubble sort.

   for(i=0; i<n; i++) { s1a[i] = s1[i]; s2a[i] = s2[i]; }

   for(i=n-1; i>=1; i--)
   for(j=0; j<=i-1; j++)
      if (s2a[j] > s2a[j+1]) { t = s2a[j]; s2a[j] = s2a[j+1]; s2a[j+1]=t; 
                               t = s1a[j]; s1a[j] = s1a[j+1]; s1a[j+1]=t; }

   for(i=0; i<n; i++) { s1b[i] = s1[i]; s2b[i] = s2[i]; }

   for(i=n-1; i>=1; i--)
   for(j=0; j<=i-1; j++)
      if (s1b[j] > s1b[j+1]) { t = s1b[j]; s1b[j] = s1b[j+1]; s1b[j+1] = t;
                               t = s2b[j]; s2b[j] = s2b[j+1]; s2b[j+1] = t; }

//for(i=0; i<n; i++) printf("-- %d %d\n", s1b[i], s2b[i]);

   // Start from list 1 - top down.

   int curr_star = 0, rounds = 0, one_stars=0;

   for(i=0; i<n; i++) 
      if (curr_star >= s2a[i]) {
         curr_star+=2; rounds++;
      } else {   // Top up with 1-stars.
         for(j=one_stars; j<n; j++) {
            if (s1b[j] > curr_star) { printf("Too Bad\n"); return; }
            curr_star++; one_stars++; rounds++;
//printf("===%d\n", j);
	    if (curr_star >= s2a[i]) {
               rounds++;                 // Enough 1-stars.
               curr_star += 2;
               break;
	    }
	 }
         if (j==n) { printf("Too Bad\n"); return; }
      }

   printf("%d\n", rounds);
}


int main() {
   int t, i, j;

   scanf("%d", &t);
   for(i=0; i<t; i++) {
      int n;
      int s1[2000], s2[2000];

      scanf("%d", &n);

      for(j=0; j<n; j++)
         scanf("%d %d", &s1[j], &s2[j]);

      printf("Case #%d: ", i+1);
      solve(s1, s2, n);
   }

   return 0;
}
