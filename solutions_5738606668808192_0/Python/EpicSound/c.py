import sys
from math import sqrt
from math import floor

BASES = list(range(2,10+1))
def is_prime(n):
    if n == 2 or n == 3: return None
    if n < 2 or n%2 == 0: return 2
    if n < 9: return None 
    if n%3 == 0: return 3
    r = int(n**0.5)
    f = 5
    while f <= r:
        if n%f == 0: return f
        if n%(f+2) == 0: return f+2
        f +=6
    return None
##########"

def get_interp(s):
    interp= []
    for b in BASES:
        interp.append(int(s,b))
    return interp


def add_two(s):
    v=int(s,2)
    return bin(v+2)[2::]
def solve(n,j):
    minimum = "1"+"0"*(n-2)+"1"
    maximum = "1"*n
    curr = str(minimum)
    res = []
    while j > 0:
        found = False
        while not found:
            interpretations = get_interp(curr)
            found = True
            divisors = []
            for interpretation in interpretations:
                v = is_prime(interpretation)
                if v==None:
                    found = False
                    break
                else:
                    divisors.append(v)

            if found:
                divisors = [str(d) for d in divisors]
                divisors.insert(0,curr)
                res.append(divisors)
            curr = add_two(curr)
        j-=1
    return res 




t = int(input())
for i in range(1,t+1):
    n,j = list(map(int,input().split()))
    print("Case #"+str(i)+":")
    for j in solve(n,j):
        print(" ".join(j))

#s = "10010011101"
#print(int(s,2))
#print(int(add_two(s),2))

#for i in get_interp("1001"):
#    print(is_prime(i))
