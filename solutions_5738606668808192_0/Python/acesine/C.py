import sys
from math import sqrt

def binary_string_to_num(n, b):
    r = 0
    B = 1
    for d in n[::-1]:
        if d == '1':
            r += B
        B *= b
    return r

def base_10_num_to_binary_string(num):
    n = ""
    while num > 0:
        x = num % 2
        if x == 1:
            n += '1'
        else:
            n += '0'
        num /= 2
    return n[::-1]

def next_n(n):
    # convert to base 10
    x = binary_string_to_num(n, 2)
    # plus 2
    x += 2
    # convert back
    return base_10_num_to_binary_string(x)

def is_prime(n):
    if n == 2:
        return -1
    # set a limit here to same time
    for x in range(2, min(int(sqrt(n))+1, 20000)):
        if n % x == 0:
            return x
    return -1

def solve(N, J):
    ret = []
    num = '1'+'0'*(N-2)+'1'
    while len(ret) < J:
        '''
        print("Testing "+num)
        print(len(ret))
        '''
        r = [num]
        for b in range(2, 11):
            x = binary_string_to_num(num, b)
            divisor = is_prime(x)
            if divisor == -1:
                break
            r.append(divisor)
        if len(r) == 10:
             ret.append(r)
        num = next_n(num)
    return ret

def verify(r):
    n = r[0]
    for i in range(1, 10):
        num = binary_string_to_num(n, i+1)
        if num % r[i] != 0:
            print("WRONG!")
            sys.exit()
            return False
        #print("%d can be divided by %d" % (num, r[i]))
    return True

T = int(raw_input())
for t in range(1, T+1):
    [N, J] = [int(x) for x in raw_input().rstrip().split(" ")]
    r = solve(N, J)
    print("Case #%d:" % t)
    for i in range(J):
        if(verify(r[i])):
            print(" ".join(str(x) for x in r[i]))
