import math

for n in range(int(raw_input())):
    case = n+1
    [k,c,s] = [int(c) for c in raw_input().split(' ')]
    sn = math.ceil(1.0*k/c)
    if(s < sn):
        print("Case #" + str(case) + ": IMPOSSIBLE")
        continue;
    i = 0
    values = []
    for j in range(int(sn)):
        check = 0
        for depth in range(c):
            check += i * pow(k, c - 1 - depth)
            i+=1
            if(i >= k): i = 0

        values.append(check+1)

    print ("Case #" + str(case) + ": " + " ".join([str(x) for x in values]))

