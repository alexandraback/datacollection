
import sys
import math

orig_stdin = sys.stdin
#fin = open('example.in', 'r')
#fin = open('D-small-attempt0.in', 'r')
fin = open('D-large.in', 'r')
sys.stdin = fin

orig_stdout = sys.stdout
foutname = fin.name.replace(".in",".out.txt")
fout = open(foutname, 'w')
sys.stdout = fout


T = int(input())  #number of cases

for case in range(1,T+1):

    K, C, S = [int(x) for x in input().split()]
    
    #print(math.ceil(K / C), file = sys.stderr)

    if S < math.ceil(K / C):
        ans = 'IMPOSSIBLE'
        print("Case #%d:" % case, ans)
        print("Case #%d:" % case, ans, file = sys.stderr)
        continue

    ans = []

    for i in range(1,K+1,C):
        j = list(range(i,i+C))
        

        s = 1
        for x, y in enumerate(range(i,i+C)):
            y = min(y,K)
            s += (y-1)*K**(C-x-1)

        #print(i, j, s, file = sys.stderr)

        ans.append(str(s))
    
        #print(i, j, s, ans, file = sys.stderr)

    print("Case #%d:" % case, ' '.join(ans) )
    print("Case #%d:" % case, ' '.join(ans),  file = sys.stderr)
    

sys.stdout = orig_stdout
sys.stdin = orig_stdin
fin.close()
fout.close()