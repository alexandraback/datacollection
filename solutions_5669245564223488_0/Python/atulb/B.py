import sys

T = int (sys.stdin.readline())
MOD  = 1000000007
MULT1 = 1

def fact(N):
    if (N<=1):
        return 1
    else:
        ret = 1
        for i in range(2,N+1):
            ret = ret * i
        return ret

def preprocess(s):
    ret = ''
    ret = ret + s[0]
    L = len(s)
    for i in range(1,L):
        if (s[i] == s[i-1]):
            continue
        else:
            ret = ret + s[i]
    return ret
    
def combine(cars):
    # for every pair combine the cars if they can be
    L = len(cars)
    MULT1 = 1
        
    for i in range(0,L):
        count = 1
        for j in range(i+1,L):
            if (i == j):
                continue
            elif (len(cars[i]) == 1 and len(cars[j])==1 and cars[i][0] == cars[j][0]):
                count = count + 1
        MULT1 = (MULT1 * fact(count)) % MOD
    
    for i in range(0,L):
        for j in range(0,L):
            if (i >= L or j >= L):
                continue
            elif (i==j):
                continue
            elif (cars[i][0] == cars[j][-1]):
                temp = cars[j] + cars[i]
                temp1 = preprocess(temp)
                cars[i] = temp1
                cars.pop(j)
                L = L - 1
            elif (cars[j][0] == cars[i][-1]):
                temp = cars[i] + cars[j]
                temp1 = preprocess(temp)
                cars[j] = temp1
                cars.pop(i)
                L = L - 1
    return MULT1

def check(cars):
    # for every char check if it exists in more than 1 car
    for i in range(97, 122 + 1):
        ch = chr(i)
        found = 0
        for car in cars:
            if (car.find(ch) != -1):
                found = found + 1
        if (found > 1):
            return False
        
    return True


def solve():
    N = int (sys.stdin.readline())
    cars = sys.stdin.readline().strip().split()
    cars1 = []
    for i in range(0,N):
        car = preprocess(cars[i])
        cars1.append(car)
#     print cars1
    MULT1 = combine(cars1)
#     print cars1
    if (not check(cars1)):
        return 0

    
    N = len(cars1)
    return  ((MULT1*fact(N)) % MOD)


for case in range(1,T+1):
    print "Case #" + str(case) + ": " + str(solve())