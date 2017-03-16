attempt = "C-large"

import time
time.clock()

ijk_table = {
    ('1','1') : '1', ('-1','1') : '-1', ('1','-1') : '-1', ('-1','-1') : '1',
    ('1','i') : 'i', ('-1','i') : '-i', ('1','-i') : '-i', ('-1','-i') : 'i',
    ('1','j') : 'j', ('-1','j') : '-j', ('1','-j') : '-j', ('-1','-j') : 'j',
    ('1','k') : 'k', ('-1','k') : '-k', ('1','-k') : '-k', ('-1','-k') : 'k',
               
    ('i','1') : 'i', ('-i','1') : '-i', ('i','-1') : '-i', ('-i','-1') : 'i',
    ('i','i') : '-1', ('-i','i') : '1', ('i','-i') : '1', ('-i','-i') : '-1',
    ('i','j') : 'k', ('-i','j') : '-k', ('i','-j') : '-k', ('-i','-j') : 'k',
    ('i','k') : '-j', ('-i','k') : 'j', ('i','-k') : 'j', ('-i','-k') : '-j',
               
    ('j','1') : 'j', ('-j','1') : '-j', ('j','-1') : '-j', ('-j','-1') : 'j',
    ('j','i') : '-k', ('-j','i') : 'k', ('j','-i') : 'k', ('-j','-i') : '-k',
    ('j','j') : '-1', ('-j','j') : '1', ('j','-j') : '1', ('-j','-j') : '-1',
    ('j','k') : 'i', ('-j','k') : '-i', ('j','-k') : '-i', ('-j','-k') : 'i',
               
    ('k','1') : 'k', ('-k','1') : '-k', ('k','-1') : '-k', ('-k','-1') : 'k',
    ('k','i') : 'j', ('-k','i') : '-j', ('k','-i') : '-j', ('-k','-i') : 'j',
    ('k','j') : '-i', ('-k','j') : 'i', ('k','-j') : 'i', ('-k','-j') : '-i',
    ('k','k') : '-1', ('-k','k') : '1', ('k','-k') : '1', ('-k','-k') : '-1',
  }

def solve(fragment, repetitions):
  temp = '1'
  goal_letter = 'i'
  count_rep_i = 0
  count_rep_j = 0
  count_rep_k = 0
  count_rep_total = 1
  while True:
    for letter in range(len(fragment)):
      temp = ijk_table[(temp,fragment[letter])]
      if temp == goal_letter:
        if goal_letter == 'i':
          temp = '1'
          goal_letter = 'j'
        elif goal_letter == 'j':
          temp = '1'
          goal_letter = 'k'
        else:
          pass # if it's letter k we keep looking
    if count_rep_total < repetitions:
      if goal_letter == 'i':
        count_rep_i += 1
      elif goal_letter == 'j':
        count_rep_j += 1
      elif goal_letter == 'k':
        count_rep_k += 1
      if (
        ((count_rep_i >= 4) or (count_rep_j >= 5) or (count_rep_k >= 5)) 
        and 
        (count_rep_total%4 == repetitions%4)
        ):
        break
      count_rep_total += 1
    else:
      break
  if goal_letter != 'k' or goal_letter != temp:
    return "NO"
  return "YES"

def main():
  fin = open(attempt + ".in", 'r')
  fout = open(attempt + ".out",'w')

  numcases = int(fin.readline())

  for casenum in range(1,numcases+1):
    frag_len, repetitions = map(int, fin.readline().split())
    fragment = fin.readline().strip()
    fout.write('Case #' + repr(casenum) + ': ' + solve(fragment, repetitions) + "\n")

  fin.close()
  fout.close()

main()
print(time.clock())