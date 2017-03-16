import sys,math

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

# If all +: ok
# Otherwise there is a last group of - (idx i to j), we ignore what is after
# If the first pancake is -, we flip all up to j, now j and after are all +
# If the first pancake is +, we flip all up to i-1, now the first is -
# Overall the number of operations is at most 2*L

def find_last_minus(s,l):
    i = j = None
    cur = None
    n = -1
    for c in s:
        n += 1
        if cur and c == cur:
            pass
        elif c == '-':
            i = n
        elif cur == '-':
            j = n
        cur = c
    if (i is not None) and (j is None):
        j = l
    return (i,j)

def flip_one(c):
    if c == '+':
        return '-'
    else:
        return '+'

def flip(s,l,i):
    res = s.copy()
    for j in range(i):
        res[j] = flip_one(s[i-j-1])
    return res

def main(s):
    l = len(s)
    time = 0
    while True :
        i,j = find_last_minus(s,l)
        printerr(l,time,s,i,j)
        if i is None:
            return time
        else:
            if s[0] == '+':
                s = flip(s,l,i)
            else:
                s = flip(s,l,j)
            time += 1
    

if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        s = list(input())

        ## Processing
        res = main(s)

        ## Output
        print("Case #{}: {}".format(c+1,res))


