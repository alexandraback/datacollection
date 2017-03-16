from random import randint

raw_input()
N, J = map(int, raw_input().split())

MAX_CHECK = 1000

print 'Case #1:'

used = set()

def find_divisor(x):
    for i in range(2, min(x - 1, MAX_CHECK)):
        if x % i == 0:
            return i
    return -1

def find_proof(s):
    proof = []
    for b in range(2, 11):
        proof.append(find_divisor(int(s, b)))
        if proof[-1] == -1:
            return []
    return proof

def get_random():
    s = '1'
    for i in range(N - 2):
        s += str(randint(0, 1))
    s += '1'
    return s

while len(used) < J:
    s = get_random()
    proof = find_proof(s)
    if proof and s not in used:
        print ' '.join([s] + map(str, proof))
        used.add(s)
