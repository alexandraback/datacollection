
import sys
import math

orig_stdin = sys.stdin
#fin = open('example.in', 'r')
#fin = open('A-small-attempt0.in', 'r')
fin = open('A-large.in', 'r')
sys.stdin = fin

orig_stdout = sys.stdout
foutname = fin.name.replace(".in",".out.txt")
fout = open(foutname, 'w')
sys.stdout = fout


T = int(input())  #number of cases

for case in range(1,T+1):

    N = int(input())
    
    if N == 0:
        ans = 'INSOMNIA'
    else:
        curr = N
        s = str(curr)
        seen = set( c for c in s )

        for i in range(100000):
            curr += N
            s = str(curr)
            s2 = set( c for c in s )
            seen = seen.union(s2)
            if len(seen) == 10:
                break

        if len(seen) == 10:
            ans = curr
        else:
            ans = 'hiccup'



  
    print("Case #%d:" % case, ans)
    print("Case #%d:" % case, ans, file = sys.stderr)
    

sys.stdout = orig_stdout
sys.stdin = orig_stdin
fin.close()
fout.close()