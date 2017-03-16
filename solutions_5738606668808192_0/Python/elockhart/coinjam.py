import sys
fi = sys.stdin

def readint():
    return int(fi.readline())

def readints():
    return [int(X) for X in fi.readline().split()]

T = readint()
N, J = readints()

def pad(X):
    return '11'+'0'*(N-4-len(X))+X+'11'

def b11(X):
    return pad(bin(X)[2:].replace('1', '11'))

print("Case #1:")
for X in range(J):
    print(b11(X) + " 3 4 5 6 7 8 9 10 11")


