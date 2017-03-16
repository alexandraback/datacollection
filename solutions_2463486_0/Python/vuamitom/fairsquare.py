import math
palin_cache = {}
def with_cache(fn):
    def wrapper(N):
        try:
            return palin_cache[N]
        except KeyError:
            r = fn(N)
            palin_cache[N] = r
            return r
    return wrapper
#@with_cache
def get_palins(N):
    """ get palins for N digits """
    if N == 1: 
        return range(0,10) 
    elif N == 2:
        return [ (i*10 + i) for i in range(0,10)] 
    else:
        c = N - 2
        numbers = []
        while c > 0:
            sub_palins = get_palins(c)
            for i in range (1,10):
                n = i * pow(10,N-1) + i
                for s in sub_palins:
                    numbers.append(n + s*pow(10, (N-c)/2))
            c -= 2
        return numbers
            
def is_square(number):
    """ check if a number is square""" 
    s = number * number
    return is_palindrome(s)
    
def is_palindrome(n):
    """ check if a number is palindrome"""
    d = digits(n)
    r = int("".join([str(i) for i in d]))
    return n == r

def digits(number):
    """ number of digits"""
    d = [] 
    while number > 0 : 
        d.append(number%10)
        number /= 10
    return d

def count_fair(M, N):
    A = int(M ** .5)
    B = int(N ** .5) 
    d1 = len(digits(A))
    d2 = len(digits(B))
    #print "A " + str(A) + " B" + str(B)
    count = 0
    for i in range(d1,d2+1):
        palins = get_palins(i)
        for p in palins:
            if p <= B and p >= A :
                square = p * p 
                if is_palindrome(square) and square <= N and square >= M:
                    count += 1
                    #print "palin " + str(p)
    return count
    

if __name__ == "__main__":
    with open("input_small") as f:
        lines = f.readlines()
    N = int(lines[0])
    l = 1
    for case in range(0, N):
        (M, N) = lines[l].strip().split()
        M = int(M)
        N = int(N)
        print "Case #" + str(case + 1) + ": " + str(count_fair(M, N))
        l += 1
        

