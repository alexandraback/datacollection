import math
f = open('B-small-attempt2.in')
#f = open('test.in')
count = int(f.readline())
output = ''
for x in xrange(1, count + 1):
    arr = f.readline().split()
    K = int(arr[0])
    L = int(arr[1])
    S = int(arr[2])
    keyboard = f.readline()
    target = f.readline()

    keymap = {}
    for i in xrange(0, K):
        key = keyboard[i]
        if key in keymap.keys():
            keymap[key] += 1
        else:
            keymap[key] = 1

    start = int((L+1)/2)
    overlap = 0
    for m in xrange(start, L):
        n = 0
        if target[m] == target[n]:
            n = 1
            overlap = 1
            for p in xrange(m + 1, L):
                if target[p] == target[n]:
                    n += 1
                    overlap += 1
                else:
                    overlap = 0
                    break
    P = 1.0
    if overlap == 0:
        maxbanana = S / L
        for t in xrange(0, L):
            word = target[t]
            if word not in keymap.keys():
                maxbanana = 0
                P = 0.0
                break
            P *= float(keymap[word]) / K
            if P < 0.0000001:
                P = 0.0
                break
        ret = maxbanana * (1 - P)
    else:
        if S % (L - overlap) >= overlap:
            maxbanana = S / (L - overlap)
        else:
            maxbanana = S / (L - overlap) - 1

        P1 = 1.0
        for t in xrange(0, L - overlap):
            word = target[t]
            if word not in keymap.keys():
                maxbanana = 0
                P1 = 0.0
                break
            P1 *= float(keymap[word]) / K
            if P1 < 0.0000001:
                P1 = 0.0
                break


        P2 = 1.0
        for t in xrange(overlap, L):
            word = target[t]
            if word not in keymap.keys():
                maxbanana = 0
                P2 = 0.0
                break
            P2 *= float(keymap[word]) / K
            if P2 < 0.0000001:
                P2 = 0.0
                break

        if maxbanana == 0 or P1 == 0.0 or P2 == 0.0:
            ret = 0.0
        else:
            remain = math.pow(P1, maxbanana)
            ret = maxbanana * (1 - P1) - maxbanana * remain * (1 - P2)



    output += 'Case #' + str(x) + ': %.7f\n' % ret

print(output)
newf = open('output.txt','w')
newf.write(output)
