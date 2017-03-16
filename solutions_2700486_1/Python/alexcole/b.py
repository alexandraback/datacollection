import math
fin = open('/Users/alex/Desktop/codejam2/b/B-large.in', 'r')
fout = open('/Users/alex/Desktop/codejam2/b/B-large.out', 'w')

def binom(n, k):
    answer = 1.0
    for i in range(1, k+1):
        answer*= (n+1-i)
        answer/= i
    return answer
# chance of at least k heads in n coins
def coins(n, k):
    total = 0
    for i in range(k+1):
        total+=binom(n, i)
    return total*2**(-n)

def prob(n, x, y):
    x = abs(x)
    
    if (x+y)%2 ==1:
        return 0.0
    l = x+y
    # Need diamonds to fill diamond between -l and l.
    needed = l*(l-1) /2
    if needed>=n:
        return 0.0
    great = (l+1)*(l+2)/2
    if n>=great:
        return 1.0
    if n> needed + l+y:
        return 1.0
    if x==0:
        return 0.0
    return 1-coins(n-needed, y)


numcases = int(fin.readline().strip())

for case in range(numcases):
    (n, x, y) = [int(i) for i in fin.readline().strip().split()]
    answer = "Case #"+str(case+1)+": "+str(prob(n, x, y)) + "\n"
    fout.write(answer)
    print (n, x, y), answer

fin.close()
fout.close()
