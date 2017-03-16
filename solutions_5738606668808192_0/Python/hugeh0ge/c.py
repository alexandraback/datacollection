import random
from random import randint

ans = []

def is_possible_prime(q, k=50):
    q = abs(q)
    if q == 2: return True
    if q < 2 or q%2 == 0: return False

    d = (q-1) >> 1
    while d%2 == 0:
        d /= 2
    
    for i in xrange(k):
        a = random.randint(1,q-1)
        t = d
        y = pow(a,t,q)
        while t != q-1 and y != 1 and y != q-1: 
            y = pow(y,2,q)
            t <<= 1
        if y != q-1 and t&1 == 0:
            return False

    return True

def get_divisor(x):
    for i in xrange(2, x):
        if x%i == 0:
            return i
    return -1

def check(x):
    global n
    global ans

    _x = x
    binary = []
    for i in xrange(n):
        binary.append(x%2);
        x /= 2

    for base in xrange(2, 11):
        value = 0
        mul = 1
        for i in xrange(n):
            value += binary[i] * mul
            mul *= base
        if is_possible_prime(value):
            return False

    dic = {}
    dic["divisors"] = []
    for base in xrange(2, 11):
        value = 0
        mul = 1
        for i in xrange(n):
            value += binary[i] * mul
            mul *= base
        dic["divisors"].append(get_divisor(value))
        if dic["divisors"][-1] == -1:
            return False

    dic["key"] = _x
    ans.append(dic)
    return True

def main():
    global n
    global num
    global ans

    T = int(raw_input())
    for Case in xrange(1, T+1):
        n, num = map(int, raw_input().split())

        lim = 1 << (n-2);
        prefix = 1 << (n-1);
        considered = {}
        while num:
            t = randint(0, lim-1);
            if t in considered:
                continue
            considered[t] = 1;

            key = prefix | (t << 1) | 1;
            if check(key):
                num -= 1

        print "Case #{}:".format(Case)
        for a in ans:
            stream = bin(a["key"])[2:]
            for i in xrange(2, 11):
                stream += " {}".format(a["divisors"][i-2])
            print stream

if __name__ == '__main__':
    main()
