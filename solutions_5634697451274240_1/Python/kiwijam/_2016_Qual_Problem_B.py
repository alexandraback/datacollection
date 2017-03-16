
import sys
import math

orig_stdin = sys.stdin
#fin = open('example.in', 'r')
#fin = open('B-small-attempt0.in', 'r')
fin = open('B-large.in', 'r')
sys.stdin = fin

orig_stdout = sys.stdout
foutname = fin.name.replace(".in",".out.txt")
fout = open(foutname, 'w')
sys.stdout = fout


T = int(input())  #number of cases

for case in range(1,T+1):

    s = input()
    n = len(s)

    if s.count('+') == n:
        ans = 0
        print("Case #%d:" % case, ans)
        print("Case #%d:" % case, ans, file = sys.stderr)
        continue

    
    numpieces = 0
    currc = '?'

    for c in s:
        if c != currc:
            numpieces += 1
            currc = c

    if c == '+':
        ans = numpieces-1
    else:
        ans = numpieces

    print("Case #%d:" % case, ans)
    print("Case #%d:" % case, ans, file = sys.stderr)
    

sys.stdout = orig_stdout
sys.stdin = orig_stdin
fin.close()
fout.close()