import sys

def naive_recycle(start, stop):
    pairs = set()
    for i in range(start, stop):
        r = list(str(i))
        for j in range(len(r)):
            r = r[-1:] + r[:-1]
            rint = int(''.join(r))
            if rint > i and rint <= stop:
                pairs.add((i,rint))
    return len(pairs)

def recycle(start, stop):
    return naive_recycle(start, stop)



if __name__ == '__main__':
    for i in range(input()):
        inputs = raw_input().split()
        print "Case #{0}: {1}".format(i+1, naive_recycle(int(inputs[0]), int(inputs[1])))
        