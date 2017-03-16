#include <stdio.h>
#include <string.h>

void sort_chars(char *string, int len) // selection sort because words are short
{
  char *end_p, *search, *max_p; // *end_p == last char before '\0'
  char max_val;

  for(end_p = string + len - 1; end_p > string ; end_p--){
    for(search = max_p = string, max_val = *max_p ; search <= end_p ; search++){
      if(*search > max_val){ max_p = search; max_val = *max_p; }
    }
    // max_p now points to largest element, so swap
    *max_p = *end_p;
    *end_p = max_val;
  }

}

int main()
{
  char s1[10000];
  char s2[10000];
  int left = 0;
  int right = 0;
  FILE *in = fopen("in.txt", "r");
  int middle = 5000;
  char buf[10000];
  int casen = 0;
  int i;
  fgets(buf, 1000, in);
  while(fgets(buf, 10000, in)){
    for(i = 0; i < 10000; i++)
      s1[i] = s2[i] = 0;
    buf[strlen(buf)-1] = '\0';

    strcpy(s1, buf);
    int current = 0;
    left = right = 0;
    s2[middle] = s1[current++];
    for(; current < strlen(s1); current++){
      if(s1[current] < s2[middle-left]){
	right++;
	s2[middle+right] = s1[current];
      }
      else{
	left++;
	s2[middle-left] = s1[current];

      }
    }
    casen++;
    printf("Case #%d: %s\n", casen, s2+middle-left);
  }


}
