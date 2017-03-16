from operator import mul
import fileinput

num_strings = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
digit_order = [0,2,4,6,8,7,5,3,9,1]
special_char = ['Z','W','U','X','G','S','F','R','I','O']

num_cases = int(raw_input())
for case in range(1,num_cases+1):
  shuffled_num = raw_input()
  char_dict = {}
  for j in shuffled_num:
    if j in char_dict:
      char_dict[j] = char_dict[j] + 1
    else:
      char_dict[j] = 1
  answer = []
  for i in range(len(digit_order)):
    if special_char[i] in char_dict:
      num_cur = char_dict[special_char[i]]
      for j in num_strings[digit_order[i]]:
        if j in char_dict:
          char_dict[j] = char_dict[j] - num_cur
        else:
          assert(num_cur == 0)
      answer = answer + num_cur * [digit_order[i]]
    else:
      num_cur = 0
  answer.sort()
  print("Case #%d: %s" % (case, "".join(map(lambda x: str(x), answer))))
