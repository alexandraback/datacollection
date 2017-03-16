import sys

inputFile = sys.argv[1]
outputFile = sys.argv[1][:-3] + ".out"
result = []

def digits(num): return len(str(num))

def cal(n, A,B, match):
    d = digits(n)
    
    total = 0
    m=n
    multi = pow(10, d-1)
    for _ in range(d-1):
        m = m//10 + m%10 * multi 
        if A <= n < m <= B and match.get((n,m)) == None:
            total += 1
            match[(n,m)] = True
#            current = match.get(n, [])
#            current.append(m)
#            match[n] = current
                
    return total

for i,case in enumerate(open(inputFile)):
    if i == 0: continue #drop first line
    
    A,B = list(map(int, case.strip().split(' ')))
    
    print(A)
    print(B)
        
    total = 0
    match = {}
    for n in range(A, B+1):        
        total += cal(n,A,B, match)
    
    ans = "Case #%d: %s" % (i, total)
    result.append(ans)
    print(ans)

f = open(outputFile,'w')
f.write('\n'.join(result))