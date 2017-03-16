attempt_list = ['A-test','A-small-attempt0','A-large']
attempt = attempt_list[2]

import time
time.clock()

def solve(n):
    digitsSeenAlready = set()
    x = 1
    while True:
        digitsSeenAlready.update(map(int, str(x*n)))
        if len(digitsSeenAlready) == 10:
            return str(x*n)
        if x >= 100:
            return 'INSOMNIA'
        x += 1


def main():
  fin = open(attempt + '.in', 'r')
  fout = open(attempt + '.out','w')

  numcases = int(fin.readline())

  for casenum in range(1,numcases+1):
    n = int(fin.readline())
    fout.write('Case #' + repr(casenum) + ': ' + solve(n) + '\n')

  fin.close()
  fout.close()

main()
print(time.clock())