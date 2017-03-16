
import sys
import math

orig_stdin = sys.stdin
#fin = open('example.in', 'r')
fin = open('A-small-attempt0.in', 'r')
#fin = open('A-large.in', 'r')
sys.stdin = fin

orig_stdout = sys.stdout
foutname = fin.name.replace(".in",".out.txt")
fout = open(foutname, 'w')
sys.stdout = fout


T = int(input())  #number of cases

for case in range(1,T+1):

    S = input()
    
    n = len(S)

    ans = ''

    for c in S:
        a = c+ans
        b = ans+c
        ans = max(a,b)



  
    print("Case #%d:" % case, ans)
    print("Case #%d:" % case, ans, file = sys.stderr)
    

sys.stdout = orig_stdout
sys.stdin = orig_stdin
fin.close()
fout.close()