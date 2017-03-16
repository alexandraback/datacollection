import string
import operator
import math
def readint():
    return int(raw_input())
def readfloat():
    return float(raw_input())
def readarray(N, foo=raw_input):
    return [foo() for i in xrange(N)]
def readlinearray(foo=int):
    return map(foo, raw_input().split())

def NOD(a, b):
    while b:
        a,b = b, a%b
    return a

def gen_primes(max):
    primes = [1]*(max+1)
    for i in range(2, max+1):
        if primes[i]:
            for j in range(i+i, max+1, i):
                primes[j] = 0
    primes[0] = 0
    return [x for x in range(max+1) if primes[x]]

def is_prime(N):
    i = 3
    if not(N % 2):
        return 0
    while i*i < N:
        if not(N % i):
            return 0
        i += 3
    return 1

def analyze(s):
    begin = s[0]
    end = s[-1]
    medium = []
    p = s[0]
    was = set()
    for c in s[1:-1]:
        if c != p:
            if c in was:
                return False
            was.add(p)
            p = c
        if c != begin and c != end:
            if c not in medium:
                medium.append(c)
    return (begin, end, medium)

NN = 1000000007

case_number = readint()
for case in xrange(case_number):
    readint()
    cars = map(analyze, raw_input().split())
    letters = dict((l, [list(), list(), False, 0]) for l in string.ascii_lowercase)
    fail = False
    for car in cars:
        if not car:
            fail = True
            break
        if car[0] == car[1]:
            if len(car[2]):
                fail = True
                break
            letters[car[0]][3] += 1
        else:
            letters[car[0]][1].append(car[1])
            letters[car[1]][0].append(car[0])
        for l in car[2]:
            letters[l][2] = True
    if fail:
        print "Case #%s: %s" % (case + 1, '0')
        continue
    for l in letters:
        if len(letters[l][0]) > 1 or len(letters[l][1]) > 1 or (letters[l][2] and (letters[l][0] or letters[l][1])):
            fail = True
            break

    chains = []
    was_letters = set()
    for l in letters:
        if not letters[l][0] and (letters[l][1] or letters[l][3]):
            c = l
            chain = 1
            while True:
                if c in was_letters:
                    fail = True
                    break
                was_letters.add(c)
                chain *= math.factorial(letters[c][3])
                if letters[c][1]:
                    c = letters[c][1][0]
                else:
                    break
            chains.append(chain)
    for l in letters:
        if letters[l][0] or letters[l][1] or letters[l][3]:
            if l not in was_letters:
                fail = True
                break
    if fail:
        print "Case #%s: %s" % (case + 1, '0')
        continue
    print "Case #%s: %d" % (case + 1, (math.factorial(len(chains)) * reduce(operator.mul, chains, 1)) % NN, )
