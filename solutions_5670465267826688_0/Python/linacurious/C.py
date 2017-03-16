attempt = "C-small-attempt0"

import time
time.clock()

ijk_table = {
    ('1','1') : '1', ('-1','1') : '-1',
    ('1','i') : 'i', ('-1','i') : '-i',
    ('1','j') : 'j', ('-1','j') : '-j',
    ('1','k') : 'k', ('-1','k') : '-k',

    ('i','1') : 'i', ('-i','1') : '-i',
    ('i','i') : '-1', ('-i','i') : '1',
    ('i','j') : 'k', ('-i','j') : '-k',
    ('i','k') : '-j', ('-i','k') : 'j',

    ('j','1') : 'j', ('-j','1') : '-j',
    ('j','i') : '-k', ('-j','i') : 'k',
    ('j','j') : '-1', ('-j','j') : '1',
    ('j','k') : 'i', ('-j','k') : '-i',

    ('k','1') : 'k', ('-k','1') : '-k',
    ('k','i') : 'j', ('-k','i') : '-j',
    ('k','j') : '-i', ('-k','j') : 'i',
    ('k','k') : '-1', ('-k','k') : '1',
  }

def solve(fragment, repetitions):
  string = fragment*repetitions
  string_len = len(string)
  temp = '1'
  goal_letter = 'i'
  for letter in range(string_len):
    temp = ijk_table[(temp,string[letter])]
    if temp == goal_letter:
      if goal_letter == 'i':
        temp = '1'
        goal_letter = 'j'
      elif goal_letter == 'j':
        temp = '1'
        goal_letter = 'k'
      else:
        pass # sould be letter k
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