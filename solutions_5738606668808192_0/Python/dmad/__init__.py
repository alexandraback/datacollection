import sys
sys.setrecursionlimit(1000)
x = int(input())

bases = {}
for i in [2,3,4,5,6,7,8,9,10]:
    bases[i] = []
    for j in range(16+1):
        bases[i].append(i**j)

def recurse(n, prefix, arr):
    if n == 1:
        arr.append(prefix + "1")
        return arr
    else:
        arr = recurse(n-1, prefix + "0", arr)
        arr = recurse(n-1, prefix + "1", arr)
    return arr


import json
import math
#perms = {1:['1']}
#for n in range(1,16):
#    perms[n+1] = recurse(n,"1",[])
#with open('perms.json', 'w') as outfile:
#    json.dump(perms, outfile)


def isprime(n):
    if n % 2 == 0 and n > 2: 
        return False, 2
    l = [n % i for i in range(3, int(math.sqrt(n)) + 1, 2)]
    try:
        X = l[l.index(0)]
    except:
        return True, -1
    return all(l), 3+2*l.index(0)

def num(S,base):
    num = 0
    i = len(S)
    while i > 0:
        i -= 1
        if S[i] == '1':
            num += base[i]

    return num


with open('perms.json') as infile:    
    perms = json.load(infile)

for _ in range(x):
    N,J = [int(a) for a in input().split()]
    perm = perms[str(N)]
    print("Case #" + str(_+1) +":")
    while J > 0:
        p = perm.pop()
        P = True
        t = []
        for i in range(2,11):
            A = num(p,bases[i])
            prime, n = isprime(A)
            if not prime:
                t.append(str(n))
            else:
                P = False
                break
        if P:
            J -= 1
            print(str(p[::-1])+" " + " ".join(t))