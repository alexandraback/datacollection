import sys

def readfile():
    afile = None
    if len(sys.argv) > 1:
        afile = open(sys.argv[1])
    else:
        afile = sys.stdin
    return map(lambda x: x.strip(), afile.readlines())

def takeby(n, array):
    for i in range(len(array)/n):
        yield array[i*n:i*n+n]
