pairs = set([])

def recycle(n,a,b):
    count = 0
    m = n
    n = str(n)    
    for _ in range(len(n)-1):
        n = n[-1]+n[:-1]
        if a <= int(n) < m <= b:
            pairs.add((int(n),m))
            count += 1
    return count

def increasing(n):
    n = str(n)
    for i in range(1,len(n)):
        if n[i] < n[i-1]: return False
    return True
    

data = open("recycled_numbers.in")
out = open("recycled_numbers.out","w")
cases = int(data.readline())

for case in range(cases):
    pairs = set([]) #to handle repeats
    a,b = map(int,data.readline().split())
    
    count = 0
    for n in range(a,b+1):
        count += recycle(n,a,b)
    out.write("Case #%i: %i\n" %(case+1,len(pairs)))
