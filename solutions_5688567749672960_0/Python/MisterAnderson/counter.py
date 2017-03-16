import sys

def log(*args, sep=" ", end="\n", file= sys.stderr, flush= False):
    file.write(sep.join(str(a) for a in args) + end)
    if flush:
        file.flush()

d= {"1":1}
m= 1

def fillDictUpTo(n):
    global d, m
    for ii in range(m+1, n+1):
        i= str(ii)
        rev= "".join(reversed(i))
        if rev in d and d[rev] < d[str(ii-1)]:
            d[i]= d[rev] + 1
        else:
            d[i]= d[str(int(i)-1)] + 1
    m= n

def numberCount(n):
    fillDictUpTo(n)
    return d[str(n)]
   
if __name__ == "__main__":
    nCases= int(input())
    for iCase in range(1, nCases + 1):
        n= int(input())
        
        result= numberCount(n)

        print("Case #{:d}: {:d}".format(iCase, result))
