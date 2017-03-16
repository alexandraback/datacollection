
import sys
import math

from itertools import chain, cycle, accumulate # last of which is Python 3 only
 

def prime_powers(n):
        # c goes through 2, 3, 5, then the infinite (6n+1, 6n+5) series
        for c in accumulate(chain([2, 1, 2], cycle([2,4]))):
            if c*c > n: 
                return(0)
            if n%c == 0: 
                return(c)
            


orig_stdin = sys.stdin
fin = open('example.in', 'r')
#fin = open('C-small-attempt0.in', 'r')
#fin = open('C-large.in', 'r')
sys.stdin = fin

orig_stdout = sys.stdout
foutname = fin.name.replace(".in",".out.txt")
fout = open(foutname, 'w')
sys.stdout = fout


T = 1  #number of cases

case = 1

print("Case #%d:" % case)
print("Case #%d:" % case, file = sys.stderr)


#N, J = 6, 3
N, J = 16, 50
#N, J = 16, 50

found = 0

for i in range(2**(N-2)):
    badi = 0
    bini = bin(i)[2:].zfill(N-2)
    coin = '1'+bini+'1'

    factors = [0]*9
    for j in range(2,10+1):
        basej = int(coin,j)
        factors[j-2] = prime_powers(basej)
        if factors[j-2] == 0:
            badi=1
            break
        #print(coin, basej, *factors, file = sys.stderr)

    if badi:
        continue

    print(coin, *factors)
    print(coin, *factors, file = sys.stderr)
    found += 1
    if found == J:
        exit()

   

    

sys.stdout = orig_stdout
sys.stdin = orig_stdin
fin.close()
fout.close()
