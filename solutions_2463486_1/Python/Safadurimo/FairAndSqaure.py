from itertools import *
digits = "012"

fairs =set()

def isPalin(x):
    return (x==x[::-1])

fairs.add(1)
fairs.add(4)
fairs.add(9)

# generating all palindromes of digits "012"
for k in range (1,8):
    for m in ["".join((x + x[::-1])) for x in product(digits, repeat=k) if x[0]!='0']:
        f=int(m)**2
        if(isPalin(str(f))):
            fairs.add(f)
    for m in ["".join(list(x) + [digit] +  list(x[::-1])) for x in product(digits, repeat=k) for digit in digits if x[0]!='0']:
        f=int(m)**2
        if(isPalin(str(f))):
            fairs.add(f)    

palindromesOdd = ["".join((x + x[::-1])) for x in permutations(digits, k) if x[0]!='0']

def count(A,B):
    global fairs
    c=0
    for fair in fairs:
        if(fair>=A and fair <=B):
            c=c+1
    return c

filename = "C-large-1.in"
output =open("output.txt",'w');
f = open(filename)
lines = f.readlines()
T=int(lines[0])
for t in range(1,T+1):
    ab =lines[t].split()
    a=int(ab[0])
    b=int(ab[1])
    output.write( "Case #" + str(t) + ": " + str(count(a,b)) + "\n")
output.close()
