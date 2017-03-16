import sys

def get_line():
    return sys.stdin.readline()

def get_ints():
    return [int(i) for i in get_line().split()]

for e,n in enumerate(range(get_ints()[0])):
    n,s = get_line().split()
    n = [int(c) for c in s]
    heap = 0
    miss = 0
    for i in n:
        if i>0:
            heap += i - 1
        elif i==0:
            if heap > 0:
                heap -= 1;
            else:
                miss += 1;
    print("Case #%i: %i" % (e+1, miss))
                