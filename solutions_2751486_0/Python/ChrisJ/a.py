import sys

f = sys.stdin

count = int(f.readline())

for index in range(1, count+1):
    parts = f.readline().split()
    name = "".join(parts[:-1])
    n = int(parts[-1])

    succCons = 0
    prevEnd = 0
    cnt = 0
    for i in range(len(name)):
        c = name[i]
        if c in "aeiou":
            succCons = 0
        else:
            succCons += 1
            if succCons >= n:
                # check
                end = i+1
                begin = i-n+1
                a = (begin-prevEnd)+1
                b = (len(name)-end)+1
                #print("--> {} * {}".format(a, b))
                cnt += a*b
                prevEnd = begin+1
        #print("{} {}".format(c, succCons))



    print("Case #{}: {}".format(index, cnt))
